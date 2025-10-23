//Q1.什么是类？
//类是 C++ 中的一种用户自定义数据类型，它将数据和对数据的操作封装在一起，用于描述具有共同特征和行为的一类对象。类定义了对象的属性（成员变量）和行为（成员函数），是创建对象的模板。
//
//Q2.类如何实现抽象、封装和数据隐藏？
//类通过将数据和操作封装在一个整体中，实现了抽象、封装和数据隐藏：
//
//①抽象（Abstraction）：类将对象的共性属性和行为提取出来，形成一个模板，用来描述一类对象。
//
//②封装（Encapsulation）：类把 * *数据（成员变量）和操作这些数据的函数（成员函数） * *组织在一起，使之成为一个独立的逻辑单元。
//
//③数据隐藏（Data Hiding）：类通过 * *访问控制符（private、protected、public） * *限制外部对内部数据的访问，只允许通过公共接口（public函数）来操作数据，从而保护对象的内部状态不被随意修改。
//
//Q3.对象和类之间的关系是什么？
//类（class） 是一种用户自定义的数据类型，是对象的模板或蓝图；
//对象（object） 是类的实例（instance），是根据类定义创建的实际变量。
//
//类定义了对象的属性和行为，而对象则是这些属性和行为的具体表现。
//因此，类是抽象的概念，对象是具体的实体。
//
//Q4.除了是函数之外，类函数成员与类数据成员之间的区别是什么？
//类的数据成员用来描述对象的属性或状态，
//类的函数成员用来描述对象能执行的操作或行为。
//
//数据成员存储信息，函数成员对这些信息进行处理。
//数据成员通常每个对象都有一份副本，而函数成员则被类的所有对象共享，用于操作各自的数据成员。
//
//Q5.定义一个类来表示银行账户。数据成员包括储户姓名、账号(使用字符串)和存款。成员函数执行如下操作：①创建一个对象并将其初始化 ②显示储户姓名、账号和存款 ③存入参数指定的存款 ④取出参数指定的款项。请提供类声明，而不用给出方法实现。
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Account {
//private: //类中默认所有访问权限是private，这里不写也行，不过是为了美观。默认设计思路是数据封装起来(private)，操作公开(public)
//	string name;
//	string account;
//	double deposit;
//
//public:// 为了外部能使用函数进行操作
//	//初始化考虑构造函数
//	//利用构造函数初始化，且构造函数名字与类名一致(规定)。在创建对象的同时自动赋初始值，比如你写Account a("张三", "123456", 1000.0); 时系统会自动执行name = "张三"; account = "123456"; deposit = 1000.0;
//	//写法一
//	Account(const string& n, const string& a, double d) { //为什么是const string& ? 因为是为了能够传入临时变量(用户随便想的如"张三")，而且目前来说是只有像string这样的大类型变量(类对象)才需要考虑const，基本类型如int、double不需要const，因为复制很快
//		name = n;
//		account = a;
//		deposit = d;
//	}
//
//	//写法二(C++专供)，它在对象创建的最早阶段直接初始化成员变量，而不是先创建、再赋值。前面不需要类型声明直接写类名，后面跟函数一样，不过在{}前要加 ：成员变量1(前面声明的对应的形参1)，成员变量2(前面声明的对应的形参2)，... ，成员变量n(前面声明的对应的形参n) 最后一个没有‘，’
//	Account(const string& n, const string& a, double d) : name(n), account(a), deposit(d){} //一行解决好几行工作
//
//	//所以初始化可以直接写Account a("张三", "默认"， 0.0);  了
//
//	void Show() { //不需要再传入对象，类内函数自动操作自身
//		cout << name << account << deposit;
//	}
//	void Add(double money) {
//		deposit += money;
//	}
//	void Takeout(double money) {
//		deposit -= money;
//	}
//};
//
//Q6.类构造函数在何时被调用？类析构函数呢？
//构造函数在对象创建时被调用，如Account a("张三", "0000", 0.0);
//
//析构函数在对象销毁时被调用，如~Account()
//
////举例
//class Account {
//	string name;
//public:
//	Account(const string& n) : name(n) {
//		cout << "构造函数被调用：" << name << endl;
//	}
//	~Account() {
//		cout << "析构函数被调用：" << name << endl;
//	}
//};
//
//int main() {
//	cout << "进入 main()\n";
//	Account a("张三");
//	{
//		Account b("李四");
//	} // <-- 离开这个花括号时 b 被销毁
//	cout << "main() 即将结束\n";
//}
//
////输出结果
//进入 main()
//构造函数被调用：张三
//构造函数被调用：李四
//析构函数被调用：李四
//main() 即将结束
//析构函数被调用：张三
//
//
//Q7.给出Q5中构造函数代码：Account(const string& n, const string& a, double d):name(n),account(a),deposit(d){}
//
//Q8.什么是默认构造函数，拥有默认构造函数有何好处？
////举例
//class Account {
//private:
//	string name;
//	double balance;
//
//public:
//	// 默认构造函数(无参)
//	Account() {
//		name = "默认用户";
//		balance = 0.0;
//		cout << "默认构造函数被调用！" << endl;
//	}
//
//	// 带参数构造函数
//	Account(const string& n, double b)
//		: name(n), balance(b) {}
//
//	void show() {
//		cout << "姓名：" << name << "  余额：" << balance << endl;
//	}
//};
//
//int main() {
//	Account a;               // 调用默认构造函数
//	Account b("张三", 1000); // 调用带参数构造函数
//
//	a.show();
//	b.show();
//}
//
////输出结果
//默认构造函数被调用！
//姓名：默认用户  余额：0
//姓名：张三  余额：1000
//
//Q9.修改Stock类的定义(stock20.h中的版本)，使之包含返回各个数据成员值的成员函数。注意：返回公司名的成员函数不应为修改数组提供便利，也即不能简单地返回string引用
//#ifndef STOCK20_H_
//#define STOCK20_H_
//#include <string>
//using namespace std;
//
//class Stock {
//private:
//	string commpany;
//	int shares;
//	double share_val;
//	double total_val;
//	void set_tot() { total_val = shares * share_val; }
//
//public:
//	Stock();
//	Stock(const string& co, long n = 0, double pr = 0.0);
//	~Stock();
//	void buy(long num, double price);
//	void sell(long num, double price);
//	void update(double price);
//	void show()const;
//	const Stock& topval(const Stock& s/*这里不是本身this，而是新传入的对象*/)const;
//
//	//添加返回各个数据成员的函数
//	string get_comname()const;
//	int get_shares()const;
//	double get_share_val()const;
//	double get_total_val()const;
//};
//
//#endif
//
//Q9拓展：const三个位置的不同效果：①修饰形参(放在括号内),则此函数不得在内部修改此形参，否则报错，且修饰&可以在外部构造时输入临时值 
//								 ②修饰类成员函数(放在括号外尾部，大括号前)，而且只会出现显示类成员变量需求(且不会改变其值)的情况下使用
//								 ③修饰返回值，则外部不能通过返回值改变成员变量，否则报错，举例如下
//										class Account {
//										string name;
//										public:
//											const string& getName() const {
//												return name;
//											}
//									};
//
//									//使用：
//									Account a;
//									a.getName() = "改名"; // ❌ 报错，因为返回的是 const 引用
//
//
//Q10.this与*this区别？this类型为指针，是当前对象的地址；*this类型是对象引用，是当前对象本身。this只会出现在非静态类成员函数中
