#define _CRT_SECURE_NO_WARNINGS

//Q1.下面是一个头文件;
////golf.h
//const int Len = 40;
//struct golf
//{
//	char fullname[Len];
//	int handicap;
//};
////直接赋值:
//void setgolf(golf& g, const char* name, int hc);
//
////用户输入:
//int setgolf(golf& g);
//
////function resets handicap to new value
//void handicap(golf& g, int hc);
//
////function displays contents of golf structure
//void showgolf(const golf& g);
//
//根据这个头文件，创建一个多文件程序。其中一个文件名为golf.cpp，它提供了与头文件中的原型匹配的函数定义；另一个文件应包含main()，并演示原型化函数的所有特性。例如，包含一个让用户输入的循环，并使用输入的数据来填充一个由golf结构组成的数组(假设最多填5个)，
//数组被填满或用户将高尔夫选手的姓名设置为空字符串时循环将结束。main()函数只使用头文件中原型化的函数来访问golf结构。
//
//A:那么分为三文件：golf.h、golf.cpp、main.cpp，已有golf.h，下面实现golf.cpp
//
////golf.cpp，负责实现golf.h中声明的函数
//#include <iostream>
//#include "golf.h"
//#include <cstring> //获取strcpy()
//void setgolf(golf& g, const char* name, int hc) {
//	std::strcpy(g.fullname, name); //C风格字符串赋值使用strcpy()
//	g.handicap = hc;
//}
//int setgolf(golf& g) {
//	std::cout << "输入fullname: ";
//	cin.getline(g.fullname, Len); //cin.getline(读入的字符串所赋值给的对象， 读入长度)
//
//	if (g.fullname[0] == '\0') return 0; //空字符串返回0
//
//	std::cout << "输入handicap: ";
//	cin >> g.handicap;
//	cin.ignore(); //为循环输入提前准备
//
//	return 1;
//}
//
//void handicap(golf& g, int hc) {
//	g.handicap = hc;
//}
//
//void showgolf(const golf& g) {
//	std::cout << g.fullname << " " << g.handicap<<std::endl;
//}
//
//
////main.cpp
//#include <iostream>
//#include <golf.h>
//
//int main() {
//	//用户交互演示
//	golf arr[5];
//	int count = 0;
//
//	while (count < 5 && setgolf(arr[count])) //这里很巧妙，setgolf()本身返回值为1说明用户输入合法，循环继续。且用户停止输入返回0让循环结束
//		count++;
//
//	for (int i = 0; i < count; i++) showgolf(arr[i]);
//
//	//非用户交互演示
//	golf a;
//	setgolf(a, "a", 1);
//	showgolf(a);
//	handicap(a, 2);
//	showgolf(a);
//}

//Q2.修改程序清单9.9，用string对象代替字符数组。这样程序将不再需要检查输入的字符串是否过长，同时可以将输入字符串同字符串""进行比较，以判断是否为空行。
//static.cpp
//#include <iostream>
//#include <string>
//using namespace std;
//
//void strcount(string* str);
//
//int main() {
//	string input;
//
//	cout << "Enter a line:\n";
//	
//	while (getline(cin, input) && input != "") { //直接判断即可，无需考虑换行符
//		strcount(&input);
//		cout << "Enter next line(empty line to quit):\n";
//	}
//	cout << "Bye\n";
//	return 0;
//}
//
//void strcount(string* str) {
//	static int total = 0;
//	int count = str->length(); //string对象可直接获取字符串长度，length()
//
//	cout << "\"" << *str << "\"contains ";
//	total += count;
//	cout << count << " characters\n";
//	cout << total << " characters total\n";
//}

//Q3.下面是一个结构声明,编写程序使用定位new运算符将一个包含两个这种结构的数组放在一个缓冲区中.然后,给结构的成员赋值(对于char数组,使用函数strcpy()),并使用一个循环来显示内容.一种方法是像程序清单9.10将一个静态数组用作缓冲区;另一种方法是使用常规new运算符分配缓冲区.
//未使用定位new版本
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//struct chaff {
//	char dross[20];
//	int slag;
//};
//
//int main() {
//	chaff* arr = new chaff[2];
//
//	strcpy(arr[0].dross, "a");
//	arr[0].slag = 0;
//	strcpy(arr[1].dross, "b");
//	arr[1].slag = 1;
//
//	for (int i = 0; i < 2; i++) {
//		cout << arr[i].dross << " " << arr[i].slag << endl;
//	}
//}

////使用定位new，以下是唯一不同点
//#include <new>       // 为 placement new 提供定义
//
//const int BUF_SIZE = 512;   // 缓冲区大小
//char buffer[BUF_SIZE];      // 静态缓冲区
//
//int main() {
//    // 在缓冲区上构造两个 chaff 对象（placement new）
//    chaff* arr = new (buffer) chaff[2];
//}

//Q4.基于下面名称空间编写一个由3个文件组成的程序,第一个文件为头文件(包含名称空间)；第二个是源代码文件，对这个名称空间进行扩展以提供三个函数定义；第三个声明两个Sales对象，并使用setSales()的交互式版本为一个结构提供值，
//然后使用setSales()的非交互式版本为另一个结构提供值。另外它还使用showSales()来显示这两个结构的内容。

////xxx.h
//namespace SALES {
//    const int QUARTERS = 4;
//    struct Sales {
//        double sales[QUARTERS];
//        double average;
//        double max;
//        double min;
//    };
//    void setSales(Sales& s, const double ar[], int n);
//    void setSales(Sales& s);
//    void showSales(const Sales& s);
//}
//
////xxx.cpp
//#include <iostream>
//#include "xxx.h"
//using namespace std;
//
//void setSales(Sales& s, const double ar[], int n) {
//    double total = 0;
//    s.max = ar[0];
//    s.min = ar[0];
//    for (int i = 0; i < n; i++) s.sales[i] = ar[i];
//    for (int i = 0; i < n; i++) {
//        total += ar[i];
//        if (s.max < ar[i]) s.max = ar[i];
//        if (s.min > ar[i]) s.min = ar[i];
//    }
//    s.average = total / n;
//}
//
//void setSales(Sales& s) {
//    cout << "输入sales数组值" << endl;
//    for (int i = 0; i < 4; i++) {
//        cin >> s.sales[i];
//    }
//    double total = 0;
//    s.max = s.sales[0];
//    s.min = s.sales[0];
//    for (int i = 0; i < 4; i++) {
//        total += s.sales[i];
//        if (s.max < s.sales[i]) s.max = s.sales[i];
//        if (s.min > s.sales[i]) s.min = s.sales[i];
//    }
//    s.average = total / 4;
//}
//
//
//void showSales(const Sales& s)
//{
//    for (int i = 0; i < 4; i++) cout << s.sales[i];
//    cout << endl;
//    cout << s.average << s.max << s.min;
//}
//
////main.cpp
//#include <iostream>
//#include "xxx.h"
//int main() {
//    Sales a;
//    Sales b;
//
//    const double ar[] = { 1.0,2.0,3.0,4.0 };
//    setSales(a, ar, 4);
//    showSales(a);
//
//    setSales(b);
//    showSales(b);
//}