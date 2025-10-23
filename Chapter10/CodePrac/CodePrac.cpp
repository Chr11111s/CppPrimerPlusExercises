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
struct customer {
	char fullname[35];
	double payment;
};

