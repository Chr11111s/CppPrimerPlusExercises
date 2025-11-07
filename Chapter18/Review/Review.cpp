//Q1.使用大括号括起的初始化列表重写下述代码。重写后的代码不应使用数组ar
class Z200 {
private:
	int j;
	char ch;
	double z;
public:
	Z200(int jv,char chv,double zv):j(jv),ch(chv),z(zv){}
	...
};
double x{ 8.8 };//double x = 8.8;
string s{ "What a bracing effect!" };//std::string s = "What a bracing effect!";
int k{ 99 };//int k(99);
Z200 zip{ 200, 'Z', 0.675 };//Z200 zip(200, 'Z', 0.675);
//std::vector<int>ai(5);
//int ar[5] = { 3,9,4,7,1 };
//for (auto pt = ai.begin(), int i = 0; pt != ai.end(); ++pt, ++i) *pt = ar[i];
vector<int> ai{ 3, 9, 4, 7, 1 };

//Q2.下面程序哪些函数调用不对？为什么？对于合法的函数调用，指出其引用参数指向的是什么

/*
左值：有名字、有地址、能出现在赋值号左边的对象。

右值：临时、没地址、通常出现在赋值号右边的值。

& 引用绑定左值，&& 引用绑定右值，const & 可以绑定任何。
*/

#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void r1(const double& rx) { cout << rx << endl; } //绑定任意double左值/右值
void r2(double& rx) { cout << rx << endl; } //仅绑定double左值
void r3(double&& rx) { cout << rx << endl; } //仅绑定doubel右值

int main() {
	double w = 10.0;
	r1(w); //✅
	r1(w + 1); //✅
	r1(up(w)); //✅
	r2(w); //✅
	r2(w + 1); //❌，w+1是右值
	r2(up(w)); //❌，up(w)返回值为右值
	r3(w); //❌
	r3(w + 1); //✅
	r3(up(w)); //✅
	return 0;
}

//Q3.下面程序显示什么？为什么？
a.
#include <iostream>
using namespace std;

double up(double x) { return 2.0 * x; }
void r1(const double& rx) { cout << "const double& rx\n"; }
void r1(double& rx) { cout << "double& rx\n"; }
int main() {
	double w = 10.0;
	r1(w);	   //double& rx
	r1(w + 1); //const double& rx
	r1(up(w)); //const double& rx
	return 0;
}

b.
#include <iostream>
using namespace std;

double up(double x) { return 2.0 * x; }
void r1(double& rx) { cout << "double& rx\n"; }
void r1(double&& rx) { cout << "double&& rx\n"; }
int main() {
	double w = 10.0;
	r1(w);	   //double& rx
	r1(w + 1); //double&& rx
	r1(up(w)); //double&& rx
	return 0;
}

c.
#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void r1(const double& rx) { cout << "const double& rx\n"; }
void r1(double&& rx) { cout << "double&& rx\n"; }
int main() {
	double w = 10.0;
	r1(w);		 //const double& rx
	r1(w + 1);	 //double&& rx
	r1(up(w));	 //double&& rx
	return 0;
}

//Q4.哪些成员函数是特殊的成员函数？它们特殊的原因是什么？
C++ 的“特殊成员函数”是：

默认构造函数、析构函数、
拷贝构造函数、拷贝赋值运算符、
移动构造函数、移动赋值运算符。


它们之所以特殊，是因为：

编译器会自动生成默认版本；

它们控制着对象的创建、复制、移动与销毁；

正确管理资源（尤其是动态内存）的关键就在于它们。

//Q5.假设类只有如下所示数据成员,为什么不适合给这个类定义移动构造函数？要让这个类适合定义移动构造函数，应如何修改存储4000个double值的方式？
class Fizzle {
private:
	double bubbles[4000];
	...
};
由于 double bubbles[4000] 是固定数组，无法转移内存所有权，因此定义移动构造函数没有意义；
若要使类支持高效移动，应改为使用 动态分配的数组（如 double* 或 std::vector<double>）。

//Q6.修改程序使其使用lambda表达式而不是f1()。请不要修改show2()。
#include <iostream>
template<typename T>
void show2(double x, T& fp) { std::cout << x << "->" << fp(x) << '\n'; }
//double f1(double x) { return 1.8 * x + 32; }
int main() {
	auto f1 = [](double x) { return 1.8 * x + 32; };
	show2(18.0, f1);
	return 0;
}

//Q7.使用lambda表达式而不是函数符Adder。不要修改sum()。
#include <iostream>
#include <array>
const int Size = 5;
template<typename T>
void sum(std::array<double, Size>a, T& fp) {
	for (auto x : a) fp(x);
}

int main() {
	std::array<double, Size> data{ 1.0, 2.0, 3.0, 4.0, 5.0 };
	double total = 0.0;

	// ✅ 使用 lambda 代替 Adder
	auto adder = [&](double w) { total += w; };

	sum(data, adder);  // 与使用 Adder 对象相同效果

//class Adder {
//	double tot;
//public:
//	Adder(double q=0):tot(q){}
//	void operator()(double w) { tot += w; }
//	double tot_v()const { return tot; }
//};