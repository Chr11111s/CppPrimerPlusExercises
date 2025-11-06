//Q1.考虑下面类声明,将其转换为使用string对象的声明。哪些方法不再需要显示定义？
class RQ1 {
private:
	char* st;
public:
	RQ1() { st = new char[1]; strcpy(st, ""); }
	RQ1(const char* s) { st = new char[strlen(s) + 1]; strcpy(st, s); }
	RQ1(const RQ1& rq) { st = new char[strlen(rq.st) + 1]; strcpy(st, rq.st); }
	~RQ1() { delete[] st; }
	RQ& operator=(const RQ& rq);
	...
};

//string版
class RQ1 {
private:
	string st;   // 替代 char*
public:
	RQ1() = default;                   // 默认构造函数
	RQ1(const string& s) : st(s) {}    // 构造函数
};
不需要：
拷贝构造函数 RQ1(const RQ1& rq)	      string 已自动实现深拷贝	
赋值运算符 operator=	              string 自动处理赋值	
析构函数 ~RQ1()	                      string 会自动释放内存

//Q2.在易于使用方面，指出string对象至少两个优于C风格字符串的地方
std::string 比 C风格字符串更易用，因为：

它自动管理内存，避免手动分配与释放；

它支持运算符重载与成员函数，能直接用 + 、 == 、.size() 等操作，使用更直观安全。

//Q3.编写一个函数，用string对象作为参数，将string对象转换为全部大写
#include <cctype>

void ToUpper(string& s) {
	for (char& c : s) c = toupper(static_cast<unsigned char>(c));
}

//Q4.从概念上或语法上说，下面哪个不是正确使用auto_ptr的方法？
auto_ptr<int> pia(new int[20]) //❌auto_ptr 只能管理 动态分配的单个对象，不能管理动态数组；它内部调用 delete，而不是 delete[]
auto_ptr<string>(new string) //✅这里创建了一个动态分配的 string 对象；auto_ptr 会自动在析构时调用 delete
int rigue = 7;
auto_ptr<int>pr(&rigue); //❌auto_ptr只能管理动态分配的对象
auto_ptr dbl(new double); //✅

//Q5.如果可以生成一个存储高尔夫球棍(而不是数字)的栈，为何它(从概念上说)是一个坏的高尔夫袋子？
正常袋子应该可以任意选取杆子，但是如果是栈每次只能选择顶上的

//Q6.为什么对于逐洞记录高尔夫成绩来说，用set很糟糕？
①set不允许元素重复，而成绩可以重
②set会自动排序元素(通常从小到大)，这样就丧失了顺序记录的意义

//Q7.既然指针是一个迭代器，为什么STL不用指针代替迭代器？
STL 不能只用指针，因为不是所有容器都能用指针遍历，
迭代器让所有容器都能以统一方式被算法访问。
某些容器如list(双向链表，每个元素在内存中分散存储)不能简单通过指针算法p++访问下一个元素

//Q8.为什么STL只定义了迭代器基类，而不使用继承来派生其它迭代器类型的类，并根据这些迭代器类来表示算法？
STL 不用继承体系来派生迭代器类型，
是因为它追求 编译期多态 + 零运行时开销 + 最大通用性。

它通过 模板 traits + category tag 实现“概念上的多态”，
而不是“继承上的多态”

//Q9.给出vector对象比常规数组方便的3个例子
①自动管理内存，能自动扩展大小
vector<int> v = { 1, 2, 3, 4, 5 };
v.push_back(6);   // 自动扩展容量，无需手动管理。如果是传统数组新增元素则需要定义新数组

②支持边界检查
数组写法（可能越界崩溃）：
int arr[3] = { 1, 2, 3 };
cout << arr[5];  // ❌ 未定义行为，可能读出垃圾值或崩溃

vector 写法：
vector<int> v = { 1, 2, 3 };
cout << v.at(5);  // ❌ 抛出异常 std::out_of_range，而不是默默出错

③插入 / 删除有.insert()和.erase()且支持STL算法如sort() / find() / reverse()

//Q10.某程序不用vector而用list实现则该程序哪些部分非法？非法部分能轻松修复吗？如果可以该怎么修复？
如果程序从 vector 改成 list：

所有用到“随机访问”（[]、at()、 + 、sort()）的地方都会非法；

但可以通过使用迭代器操作(advance) 或 list 自带成员函数(.sort()) 来轻松修复。

//Q11.下面代码有什么功能？赋给bo的是什么值？
bool bo = TooBig<int>(10)(15);

/*TooBig<int>(10)：创建临时 TooBig<int> 对象，内部 cutoff = 10。

后面的(15)：调用其 operator()(const T & v)，判断 15 > cutoff。赋给bool true
*/
已知：
// functor.cpp -- using a functor 
#include <iostream> 
#include <list> 
#include <iterator> 
#include <algorithm> 
template - class T > // functor class defines operator()()

class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) {}
	bool operator()(const T& v) { return v > cutoff; }
};
void outint(int n) { std::cout << n << ""; }
int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	TooBig< int>f100(100); // limit = 100 
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list< int>yadayada(vals, vals + 10); // range constructor 
	list< int> etcetera(vals, vals + 10);
	// C++11 can use the following instead 
	// list< int>yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}; 
	// list< int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}; 
	cout << "Original lists:\n";
	for _ each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for _ each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove _ if (f100); // use a named function object 
	etcetera.remove _ if (TooBig< int>(200)); // construct a function object 
	cout << "Trimmed lists:\n";
	for _ each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for _ each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	return 0;
}