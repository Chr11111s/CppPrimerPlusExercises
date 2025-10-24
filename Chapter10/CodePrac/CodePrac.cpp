#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//Q1.下面是一个类定义,完成成员函数定义并且编写程序演示使用
//#include<string>
//#include<cstring>
//using namespace std;
//
//class Person {
//private:
//	static const int LIMIT = 25;
//	string lname;
//	char fname[LIMIT];
//public:
//	Person() { lname = ""; fname[0] = '\0'; }
//	Person(const string& ln, const char* fn = "Heyyou") {
//		lname = ln;
//		strcpy(fname, fn);
//	}
//	void Show()const { //first-last
//		cout << fname << " " << lname << endl;
//	}
//	void FormalShow()const { //last-first
//		cout << lname << " " << fname << endl;
//	}
//};
//
//int main() {
//	Person one;
//	Person two("Smythecraft");
//	Person three("Dimwiddy", "Sam");
//	one.Show();
//	cout << endl;
//	one.FormalShow();
//	
//	two.Show();
//	cout << endl;
//	two.FormalShow();
//	
//	three.Show();
//	cout << endl;
//	three.FormalShow();
//}

//Q2.用类的知识改写下方代码
//#include <cstring>
//using namespace std;
//
//const int Len = 40;
//class golf
//{
//private:
//	char fullname[Len];
//public:
//	int handicap;
//	//直接赋值:
//	void setgolf(const char* name, int hc) {
//		strcpy(fullname, name);
//		handicap = hc;
//	}
//
//	//用户输入:
//	int setgolf() {
//		cout << "输入fullname: ";
//		cin.getline(fullname, Len);
//		if (fullname[0] == '\0')return 0;
//		cout << "输入handicap: ";
//		cin >> handicap;
//		cin.ignore();
//		return 1;
//	}
//
//	//function resets handicap to new value
//	void handicap(int hc) {
//		handicap = hc;
//	}
//
//	//function displays contents of golf structure
//	void showgolf() {
//		cout << fullname << " " << handicap << endl;
//	}
//
//};
//
//int main() {
//	//用户交互演示
//	golf arr[5];
//	int count = 0;
//
//	while (count < 5 && arr[count].setgolf()) //这里很巧妙，setgolf()本身返回值为1说明用户输入合法，循环继续。且用户停止输入返回0让循环结束
//		count++;
//
//	for (int i = 0; i < count; i++) arr[i].showgolf();
//
//	//非用户交互演示
//	golf a; //创建对象
//	a.setgolf("a", 1); //对象调用自己的函数(这才是c++风格)
//	a.showgolf();
//	a.handicap(2);
//	a.showgolf();
//}
///*
//C 风格结构体 + 独立函数 showgolf(a) 传入结构体变量当参数
//C++ 类成员函数  a.showgolf() 由对象自己调用自己的函数
//*/

////Q3.用类的知识改写下方代码，用构造函数实现两个setSales()
//using namespace std;
//
//const int QUARTERS = 4;
//class Sales {
//private:
//    double sales[QUARTERS];
//    double average;
//    double max;
//    double min;
//public:
//    Sales(const double ar[], int n) {
//        double total = 0;
//        max = ar[0];
//        min = ar[0];
//        for (int i = 0; i < n; i++) sales[i] = ar[i];
//        for (int i = 0; i < n; i++) {
//            total += ar[i];
//            if (max < ar[i]) max = ar[i];
//            if (min > ar[i]) min = ar[i];
//        }
//        average = total / n;
//    }
//    Sales() {
//        cout << "输入sales数组值" << endl;
//        for (int i = 0; i < 4; i++) {
//            cin >> sales[i];
//        }
//        double total = 0;
//        max = sales[0];
//        min = sales[0];
//        for (int i = 0; i < 4; i++) {
//            total += sales[i];
//            if (max < sales[i]) max = sales[i];
//            if (min > sales[i]) min = sales[i];
//        }
//        average = total / 4;
//    }
//    void showSales() {
//        for (int i = 0; i < 4; i++) cout << sales[i];
//        cout << endl;
//        cout << average << max << min;
//    }
//
//};
//int main() {
//    Sales a;
//    Sales b;
//
//    const double ar[] = { 1.0,2.0,3.0,4.0 };
//    Sales a(ar, 4);
//    a.showSales();
//
//    Sales b();
//    b.showSales();
//}

//Q4.考虑下面的结构声明,编写程序从栈中添加/删除customer结构(栈用Stack类声明表示)。每次customer结构被删除时，其payment的值都被加入到总数中，并报告总数。注意：应该可以直接使用Stack类而不做修改；只需修改typedef声明，使Item的类型为customer，而不是unsigned long即可。
//struct customer {
//	char fullname[35];
//	double payment;
//};
////stack.h
//#ifndef STACK_H_
//#define STACK_H_
//
//typedef customer Item;
//
//class Stack {
//private:
//	enum{MAX=10};
//	Item items[MAX];
//	int top;
//public:
//	Stack();
//	bool isempty()const;
//	bool isfull()const;
//	bool push(const Item& item);
//	bool pop(Item& item);
//};
//#endif
//
////stack.cpp
//#include "stack.h"
//Stack::Stack() {
//	top = 0;
//}
//bool Stack::isempty()const {
//	return top == 0;
//}
//bool Stack::isfull()const {
//	return top == MAX;
//}
//bool Stack::push(const Item& item) {
//	if (top < MAX) {
//		items[top++] = item;
//		return true;
//	}
//	else return false;
//}
//bool Stack::pop(Item & item) {
//	if (top > 0) {
//		item = items[--top];
//		return true;
//	}
//	else return false;
//}
//
////main.cpp
//#include <iostream>
//using namespace std;
//
//int main() {
//	Stack st;
//	double total = 0;
//
//	while (true) {
//		customer c;
//		int code;
//		cout << "输入指令(1压栈2出栈3退出)：";
//		cin >> code;
//		cin.ignore(); //输入数字后记得清空
//		if (code == 3)break;
//		else if (code == 1) {
//			if (st.isfull()) {
//				cout << "已满，请停止输入";
//				continue;
//			}
//			cout << "输入名字：";
//			cin.getline(c.fullname, 35);
//			cout << "输入payment：";
//			cin >> c.payment;
//			if (!st.isfull()) st.push(c);
//		}
//
//		else if (code == 2) {
//			if (st.isempty()) {
//				cout << "已空，请先输入一个";
//				continue;
//			}
//			st.pop(c);
//			total += c.payment; //因为栈内元素是private，必须要先pop出来才能对值进行操作
//
//			cout << "当前total：" << total << endl;
//		}
//		else {
//			cout << "无效指令，请输入1/2/3";
//			continue;
//		}
//	}
//}

//Q5.下面是一个类声明，请提供成员函数的定义和测试这个类的程序
//using namespace std;
//class Move {
//private:
//	double x;
//	double y;
//public:
//	Move(double a = 0, double b = 0) :x(a), y(b) {}; //构造对象时格式：例如Move m(1, 2)即将1，2赋值给m.x和m.y。
//	void showme()const {
//		cout << "x: " << x << " " << "y: " << y << endl;
//	}
//	Move add(const Move& m)const { //将新的m对象的x/y值加到当前对象的x/y值上，并且创建一个新对象赋上add后的x/y值并返回这个对象
//		Move new_m;
//		new_m.x = x + m.x;
//		new_m.y = y + m.y;
//		return new_m;
//	}
//
//	void reset(double a = 0, double b = 0) {
//		x = a;
//		y = b;
//	}
//};
//
//int main() {
//	Move m1;
//	m1.showme();
//
//	Move m2(1,2);
//	m2.showme();
//
//	m1 = m1.add(m2);
//	m1.showme();
//
//	m1.reset();
//	m1.showme();
//}

//Q6.Betelgeusean plorg有这些特征——数据：plorg的名称不超过19个字符；plorg有满意指数(CI)，这是一个整数 || 操作：新的plorg将有名称，其CI值为50；plrog的CI可以修改；plorg可以报告其名称和CI;plorg的默认名称为"Plorga"
//编写Plorg类，包含成员变量及成员函数实现。然后编写程序演示Plorg类所有特性
//#include <cstring>
//using namespace std;
//
//class Plorg {
//private:
//	char name[19];
//	int CI;
//public:
//	Plorg() {
//		strcpy(name, "Plorga"); //初始化列表？不行，数组放不进去
//		CI = 50;
//	}
//	void change_CI(int new_CI) {
//		CI = new_CI;
//	}
//	void show() {
//		cout << "name: " << name<<endl;
//		cout << "CI: " << CI << endl;
//	}
//};
//
//int main() {
//	Plorg p;
//	p.show();
//
//	p.change_CI(100);
//	p.show();
//}

//Q7.简单列表如下：可储存0个或多个某种类型的列表；可创建空列表；可在列表中添加数据项；可确定列表是否为空；可确定列表是否为满；可访问列表中的每一个数据项，并对它们执行某种操作
//设计一个List类表示这种抽象类型。设计list.h与list.cpp，并且编写简短程序演示功能。

//list.h
//#ifndef LIST_H_ //这三行使得头文件可以安全地被多次包含
//#define LIST_H_ //这三行使得头文件可以安全地被多次包含
//
//typedef double Item;
//
//class List {
//private:
//	static const int MAX = 10; //最大容量
//	Item arr[MAX]; //数据存储容器
//	int count; //当前数量
//public:
//	List();
//	bool isempty()const; //修饰函数的const是针对当前成员变量，目的是该函数不可改变当前成员变量
//	bool isfull()const;
//	bool add(const Item& item); //本质是一个double值
//	void visit(void (*pf) (Item&)); //*****函数指针：我（List）里有很多元素，你告诉我一个函数 pf(你可以在主程序中自定义)，我就用这个函数去处理我所有的元素。*****
//	void show()const;
//};
//#endif //这三行使得头文件可以安全地被多次包含
//
////list.cpp
//#include <iostream>
//#include "list.h"
//using namespace std;
//
//List::List() {
//	count = 0;
//}
//bool List::isempty()const {
//	return count == 0;
//}
//bool List::isfull()const {
//	return count == MAX;
//}
//bool List::add(const Item& item) {
//	if (count < MAX) {
//		arr[count++] = item;
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void List::visit(void(*pf)(Item&)) {
//	for (int i = 0; i < count; i++) pf(arr[i]);
//}
//void List::show()const {
//	for (int i = 0; i < count; i++) cout<<arr[i];
//}
//
//
////main.cpp
//#include <iostream>
//#include "list.h"
//using namespace std;
//
//// 示例自定义函数1：打印每个元素
//void print_item(Item& x) {
//	cout << x << " ";
//}
//
//// 示例自定义函数2：把每个元素乘2
//void double_item(Item& x) {
//	x *= 2;
//}
//
//int main() {
//	List mylist;
//
//	cout << "列表是否为空？ " << (mylist.isempty() ? "是" : "否") << endl;
//
//	// 添加元素
//	for (int i = 1; i <= 5; i++)
//		mylist.add(i * 10);
//
//	mylist.show();
//
//	// 对每个元素执行操作：打印
//	cout << "访问每个元素：";
//	mylist.visit(print_item);
//	cout << endl;
//
//	// 对每个元素执行操作：乘以2
//	mylist.visit(double_item);
//
//	// 打印修改后的结果
//	mylist.show();
//
//	cout << "列表是否为满？ " << (mylist.isfull() ? "是" : "否") << endl;
//}
