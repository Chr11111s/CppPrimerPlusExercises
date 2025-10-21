//Q1.下列情况应使用哪种存储方案
//a.homer是函数的形参——局部变量自动存储
//b.secret变量由两个文件共享——文件1中定义(int a)，文件2中extern int a声明即可
//c.topsecret变量由一个文件中的所有函数共享，但对于其它文件来说是隐藏的——通过static静态存储
//d.beencalled记录包含它的函数被调用的次数——通过static静态存储
//
//Q2.using 声明和using编译指令之间的区别
//using 声明：只把命名空间中的一个标识符引入当前作用域，例如 using std::cout; 。控制精确、安全，不易冲突。
//
//using 编译指令：把整个命名空间的所有名字引入当前作用域，例如 using namespace std; 。方便但容易冲突。
//
//Q3.重新编写代码，使其不使用using声明和using编译指令
//#include <iostream>
//
//int main() {
//	double x;
//	std::cout << "Enter value: ";
//	while (!(std::cin >> x)) {
//		std::cout << "Bad input. Please enter a number: ";
//		std::cin.clear();
//		while (std::cin.get() != '\n') continue;
//	}
//	std::cout << "Value =" << x << std::endl;
//	return 0;
//}
//
//Q4.重新编写代码，使之使用using声明，而不是using编译指令
//#include <iostream>
//using std::cout;
//using std::cin;
//using std::endl;
//int main() {
//	double x;
//	std::cout << "Enter value: ";
//	while (!(std::cin >> x)) {
//		std::cout << "Bad input. Please enter a number: ";
//		std::cin.clear();
//		while (std::cin.get() != '\n')continue;
//	}
//	std::cout << "Value = " << x << std::endl;
//	return 0;
//}
//
//Q5.如何实现：在一个文件中调用average(3, 6)函数时，它返回两个int参数的int平均值，在同一个程序的另一个文件中调用时，它返回两个int参数的double平均值。
//A : 通过加上static后在分别在各自文件中声明，(file1.cpp) static int average(int, int)以及(file2.cpp) static double average(int, int)即可，如果不加static会在链接阶段报错(编译不报错)。
//
//在 C++ 中，普通函数默认具有外部链接（external linkage）。
//也就是说：编译器会把每个函数的名字导出到目标文件的符号表中，链接器在合并多个目标文件时，要求同名外部符号只能出现一次。
//因此：如果两个.cpp 文件中都定义了同名的非 static 函数（比如 average），链接器在合并时无法区分，认为你定义了两个相同函数，从而报错 “multiple definition”。
//
//Q6.下面的程序由两个文件组成，该程序显示什么内容？
////file1.cpp
//#include <iostream>
//using namespace std;
//void other();
//void another();
//int x = 10;
//int y;
//
//int main() {
//	cout << x << endl; //打印全局变量10
//	{
//		int x = 4;
//		cout << x << endl; //打印局部变量4
//		cout << y << endl; //x = 10, 而y 没有显式初始化，属于静态存储期变量(0)，打印0
//	}
//	other(); //打印全局变量10和函数内局部变量1(隐藏全局变量)
//	another(); //打印引用的全局变量10以及匿名命名空间局部变量-4
//	return 0;
//}
//
//void other() {
//	int y = 1;
//	cout << "Other: " << x << ", " << y << endl;
//}
//
////file2.cpp
//#include <iostream>
//using namespace std;
//extern int x; //引用file1.cpp中的全局变量x=10
//namespace
//{
//	int y = -4; //匿名命名空间类似static，使变量仅在当前文件中可见(内部链接)
//}
//
//void another()
//{
//	cout << "another():  " << x << ", " << y << endl;
//}
//
//Q7.下面代码将显示什么内容
//#include <iostream>
//using namespace std;
//void other();
//namespace n1
//{
//	int x = 1;
//}
//
//namespace n2
//{
//	int x = 2;
//}
//
//int main() {
//	using namespace n1;
//	cout << x << endl; //打印n1中x值，1
//	{
//		int x = 4;
//		cout << x << ", " << n1::x << ", " << n2::x << endl; //打印局部x，n1中x，n2中x，分别为4、1、2
//	}
//	using n2::x;
//	cout << x << endl; //打印n2中x值，2
//	other(); //2、4、1、2、2
//	return 0;
//}
//
//void other()
//{
//	using namespace n2;
//	cout << x << endl; //打印n2中x值，2
//	{
//		int x = 4;
//		cout << x << ", " << n1::x << ", " << n2::x << endl; //打印局部x，n1中x，n2中x，分别为4、1，2
//	}
//	using n2::x;
//	cout << x << endl; //打印n2中x值，2
//}
//综上：1、4、1、2、2、2、4、1、2、2