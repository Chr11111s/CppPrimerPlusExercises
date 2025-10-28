//Q1.假设String类有以下私有成员：
class String {
private:
	char* str; //points to the string allocated by new
	int len;   //holds length of string
//...
};
a.下述默认构造函数有什么问题？
String::String(){} //问题在于没有初始化指针str与int值len，结果str是野指针(指向未知内存)，len值也未定义。导致任何使用该对象的成员函数(如  析构函数delete str[]  或  cout<<str  )都会造成未定义行为或程序崩溃
b.下述构造函数有什么问题？
String::String(const char* s) {
	str = s; //问题在于直接让str指向了传入的参数s，没有动态分配新空间。可能导致的后果：①浅拷贝问题：若s是临时字符串如"FuckU"则str会指向常量区内存，若另一个String对象也用这个字符串构造则它的str也会指向这块内存，导致两个对象共享同一块内存。
			 //																		   ②析构函数删除错误：析构函数中通常会写  delete[] str  ,但此时str不是通过new分配的，所以delete[]会导致崩溃。
	len = strlen(s);
}
c.下述构造函数有什么问题？
String::String(const char* s) {
	strcpy(str, s); //问题在于strcpy()需要目标缓冲区有足够空间，而str此时是个未初始化的指针，没有分配内存给它。所以直接strcpy()会将数据写进一个未定义地址，必然导致程序崩溃。
	len = strlen(s);
}
/*
-为什么前几章都没有遇到过这种问题？
-前几章类一般这么写：class Stock {                                          
				     private:                                                                                                                    
						std::string company;  // std::string自己管理内存                                                                                              
						double shares;                                                                                                                             
					 };        

或者是：             class Time {
					 private:
					 	int hours;
				 	    int minutes;
					 };

这些类型要么是：

-内置类型（int, double）—— 自动分配在栈上；

-标准类类型（std::string, std::array, std::vector）—— 它们已经在内部帮你写好了构造函数、析构函数、拷贝构造函数和赋值运算符。

所以用户不需要操心内存管理，编译器生成的“默认拷贝构造函数”等都是安全的浅拷贝。


而第12章重点在于：当类中包含指针成员（尤其是用 new 分配的内存）时，必须正确管理资源。
这通常称为：

“三大函数法则（Rule of Three）”

-析构函数（~String()）

-拷贝构造函数（String(const String&)）

-赋值运算符（operator=）

如果手动管理内存，就必须自己实现这三个。
*/

//Q2.如果定义了一个类，其指针成员是使用new初始化的，请指出可能出现的3个问题以及如何纠正这些问题(动态内存三大陷阱——漏写了(没定义)三大函数会很要命！！！)
/*
①漏写析构函数导致的内存泄漏：如果你没有写析构函数，编译器自动生成的析构函数不会 delete 任何东西。这样当对象销毁时，new 分配的内存永远不会被释放(分配的内存不释放 = 内存泄漏)。所以需要写一个析构函数(~ClassName::ClassName(){delete[] str;})释放内存。

②漏写拷贝构造函数(用一个已存在的对象初始化一个新对象)导致浅拷贝，而浅拷贝导致二次释放后程序崩溃：编译器自动生成的拷贝构造函数只会复制对象中的指针地址(只复制指针值，也即浅拷贝)，而不会复制指针指向的数据，
也就导致当我们初始化了A想用  ‘=’  直接给B赋值时(比如ClassName A("FuckU");  ClassName B = A;)，A.str和B.str都指向同一块内存。程序结束时逐个销毁对象，当一个对象析构后，另一个开始析构时就会delete已被释放的内存，程序会崩溃(二次释放)。
解决方法是深拷贝，也即给B在堆上new一块新内存，然后把A的内容拷贝进去。

③漏写或写错赋值运算符重载函数(即 = )，漏写的话两个对象就会共享同一块内存(浅拷贝)，会二次释放导致程序崩溃；写错比如忘记释放旧内存(A=B, 忘记释放A原先内存了)，会导致内存泄漏；

写错还有如没有处理自赋值情况，在a = a时流程是赋值函数先把左边的 a 的内存删了；

但右边的 a 用的其实也是同一块内存；

所以一删，右边的内容也没了；

接下来又想从右边复制数据过去；

可右边的内存已经被删掉 → 崩溃！
*/


//Q2小tips:普通变量、对象(int/double/ClassName c)创建时是分配栈内存的；如果用new则是分配堆内存

//Q3.若没有显式提供类方法，编译器将自动生成哪些类方法？请描述这些隐式生成的函数的行为
/*
函数				触发时机	            自动行为	        潜在问题

默认构造			创建对象但未提供参数	成员默认初始化	    内置类型随机值
拷贝构造			用已有对象创建新对象	浅拷贝成员	        指针共享导致崩溃
赋值运算符			已存在对象赋值	        浅拷贝成员	        内存泄漏 / 自赋值问题
析构函数			对象销毁	            自动调用成员析构	不会释放动态内存
移动构造 / 赋值		对象资源转移	        浅移动	            一般安全但可能效率低
*/

//Q4.找出并改正下述类声明中的错误：
class nifty {
	char personality[]; //❌ 不允许在类中定义不确定长度的数组，必须给长度或者用指针，改为 char* personality;
	int talents;
	//❌ 缺少public，成员默认是 private，外部无法访问构造函数
	nifty();
	nifty(char* s);
	ostream& operator<<(ostream& os, nifty& n);//❌ 应写成友元函数
}//❌ 类定义结尾必须有分号

nifty::nifty() {
	personality = NULL;//❌ 不能直接赋值给数组成员（更何况 personality 改为指针后要 new），改成 personality = nullptr;
	talents = 0;
}
nifty::nifty(char* s) {
	personality = new char[strlen(s)];//❌ 现在personality指向新开内存的地址
	personality = s;//❌ 现在又把personality改成指向s的地址，那之前新开内存的地址就没人能再访问到了，也就永远无法delete掉，即内存泄漏。应改为 personality = new char[strlen(s) + 1]; strcpy(personality, s);
	talents = 0;
}
ostream& nifty::operator<<(ostream& os, nifty& n) {
	os << n; //❌ os << n.personality << ", " << n.talents;
	//最后还应return os;
}

//Q5.对于下面的类声明：
class Golfer {
private:
	char* fullname;
	int games;
	int* scores;
public:
	Golfer(); //①
	Golfer(const char* name, int g = 0); //②
	Golfer(const Golfer& g); //③
	
	~Golfer();
};

下列各条语句将调用哪些类方法？
Golfer nancy; //①
Golfer lulu("Little LuLu"); //②
Golfer roy("Roy Hobbs", 12); //②
Golfer* par = new Golfer; //①，在堆上调用默认构造函数构造对象
Golfer next = lulu; //调用拷贝构造函数，即③
Golfer hazzard = "Weed Thwacker"; //"Weed Thwacker"是const char*，调用②，不加括号也行
*par = nancy; //*par已经存在，所以是赋值语句，但是类中并没有重载赋值运算符，所以编译器会自动生成浅拷贝版本
nancy = "Nancy Putter"; //赋值语句，仍然生成浅拷贝版本

很明显，类需要有另外几个方法才能更有用，但是类需要哪些方法才能防止数据被损坏呢？
-析构函数、拷贝构造函数、拷贝赋值运算符