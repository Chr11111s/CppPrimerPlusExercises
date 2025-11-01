//Q1.以下类声明为基础，派生出一个Classic类，并添加一组char成员，用于存储指出CD中主要作品的字符串。修改上述声明，使基类的所有函数都是虚的。如果上述定义声明的某个方法并不需要，则请删除它。使用下面程序测试
//base class
class Cd { //represents a CD disk
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime; //in minutes
public:
	Cd(const char* s1, const char* s2, int n, double x) { //C++中构造函数(包括拷贝构造函数)都不能virtual化
		strcpy(performers, s1);
		strcpy(label, s2);
		selections = n;
		playtime = x;
	}
	Cd(const Cd& d) { //与上同理
		strcpy(performers, d.performers);
		strcpy(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
	}
	Cd() { //与上同理
		strcpy(performers, "");
		strcpy(label, "");
		selections = 0;
		playtime = 0;
	}
	virtual ~Cd() {} //基类析构函数也需要virtual
	virtual void Report()const { //reports all CD data, Report() 是一个虚函数，在基类中定义为 virtual，因此你可以在派生类中重写它（覆盖）。这使得程序能够实现多态，通过基类指针调用 Report() 时，实际会根据对象的动态类型调用正确的 Report() 方法。
		cout << "performers: " << performers << endl;
		cout << "label: " << label << endl;
		cout << "selections: " << selections << endl;
		cout << "playtime: " << playtime << endl;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	Cd& operator=(const Cd& d) { //赋值运算符也不能virual化
		if (this == &d)return *this;
		strcpy(performers, d.performers);
		strcpy(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
		return *this;
	}
};

//派生类编写
class Classic :public Cd {
private:
	char works[20];
public:
	Classic(const char* s1, const char* s2, int n, double x, const char* w) : Cd(s1, s2, n, x){ //派生类的构造函数中要用初始化列表初始化基类
		strcpy(works, w);
	}
	Classic(const Classic& d) : Cd(d){ //派生类的拷贝构造函数也要用初始化列表拷贝基类对象的成员
		strcpy(works, d.works);
	}
	Classic() : Cd("", "", 0, 0) { //与上同理
		strcpy(works, "");
	}
	~Classic() {}
	void Report()const override { //reports all Classic data
		Cd::Report(); //
		cout << "works: " << works << endl;
	} 
	Classic& operator=(const Classic& d) { //赋值运算符不能virtual或者override,赋值运算符（operator=）是普通的成员函数，不参与多态。它不会使用虚函数机制，所以不需要 virtual。
		if (this == &d)return *this;
		Cd::operator=(d);
		strcpy(works, d.works);
		return *this;
	}
};

//测试程序
#include <iostream>
using namespace std;
#include "classic.h"
void Bravo(const Cd& disk);
int main() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd& pcd = &c1;
	
	cout << "Using object directly:\n";
	c1.Report(); //use CD method
	c2.Report(); //use Classic method

	cout << "Using type cd* pointer to objects:\n";
	pcd->Report(); //use CD method for cd object
	pcd = &c2;
	pcd->Report(); //use Classic method for classic object

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk) {
	disk.Report();
}

/*
静态多态：在编译时决定调用哪个函数，通常是函数重载和运算符重载。根据传入参数类型来判断。为什么不看函数返回类型，因为编译器决定函数重载的规则是基于【函数签名】（即函数名和参数类型），而不是返回类型。

动态多态：在运行时决定调用哪个函数，通常通过虚函数、基类指针 / 引用指向派生类对象来实现。根据指针指向的对象来判断

多态的核心就是“通过统一的接口调用不同的实现”
*/

//Q2.把Q1中改成两个类使用动态内存分配而不是长度固定的数组来记录字符串
//base class
class Cd { //represents a CD disk
private:
	char* performers;
	char* label;
	int selections;
	double playtime; //in minutes
public:
	Cd(const char* s1, const char* s2, int n, double x) { //C++中构造函数(包括拷贝构造函数)都不能virtual化
		performers = new char[strlen(s1) + 1];
		strcpy(performers, s1);
		label = new char[strlen(s2) + 1];
		strcpy(label, s2);
		selections = n;
		playtime = x;
	}
	Cd(const Cd& d) { //与上同理
		performers = new char[strlen(d.performers) + 1];
		strcpy(performers, d.performers);
		label = new char[strlen(d.label) + 1];
		strcpy(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
	
	Cd() { //与上同理
		performers = new char[1];
		strcpy(performers, "");
		label = new char[1];
		strcpy(label, "");
		selections = 0;
		playtime = 0;
	}
	virtual ~Cd() { delete[] performers; delete[] label; } //基类析构函数也需要virtual
	virtual void Report()const { //reports all CD data, Report() 是一个虚函数，在基类中定义为 virtual，因此你可以在派生类中重写它（覆盖）。这使得程序能够实现多态，通过基类指针调用 Report() 时，实际会根据对象的动态类型调用正确的 Report() 方法。
		cout << "performers: " << performers << endl;
		cout << "label: " << label << endl;
		cout << "selections: " << selections << endl;
		cout << "playtime: " << playtime << endl;
	}
	Cd& operator=(const Cd& d) { //赋值运算符也不能virual化
		if (this == &d)return *this;

		delete[] performers;
		delete[] label;

		performers = new char[strlen(d.performers) + 1];
		strcpy(performers, d.performers);
		label = new char[strlen(d.label) + 1];
		strcpy(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
		return *this;
	}
};

//派生类编写
class Classic :public Cd {
private:
	char* works;
public:
	Classic(const char* s1, const char* s2, int n, double x, const char* w) : Cd(s1, s2, n, x) { //派生类的构造函数中要用初始化列表初始化基类
		works = new char[strlen(w) + 1];
		strcpy(works, w);
	}
	Classic(const Classic& d) : Cd(d) { //派生类的拷贝构造函数也要用初始化列表拷贝基类对象的成员
		works = new char[strlen(d.works) + 1];
		strcpy(works, d.works);
	}
	Classic() : Cd("", "", 0, 0) { //与上同理
		works = new char[1];
		strcpy(works, "");
	}
	~Classic() { delete[] works; }
	void Report()const override { //reports all Classic data
		Cd::Report(); //
		cout << "works: " << works << endl;
	}
	Classic& operator=(const Classic& d) { //赋值运算符不能virtual或者override,赋值运算符（operator=）是普通的成员函数，不参与多态。它不会使用虚函数机制，所以不需要 virtual。
		if (this == &d)return *this;
		Cd::operator=(d);
		works = new char[strlen(d.works) + 1];
		strcpy(works, d.works);
		return *this;
	}
};

//Q3.修改baseDMA-lackDMA-hasDMA类层次，让三个类都从一个ABC派生而来，然后使用与程序清单13.10相似的程序对结果进行测试。也即它应使用ABC指针数组，并让用户决定要创建的对象类型。在类定义中添加virtual View()方法以处理数据显示。
