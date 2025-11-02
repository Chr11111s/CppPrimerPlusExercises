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

//Q3.修改baseDMA-lackDMA-hasDMA类层次，让三个类都从一个ABC(包含至少一个纯虚函数)派生而来，然后使用与程序清单13.10相似的程序对结果进行测试。也即它应使用ABC指针数组，并让用户决定要创建的对象类型。在类定义中添加virtual View()方法以处理数据显示。
//dma.h
//#ifndef DMA_H_
//#define DMA_H_
//#include <iostream>
//using namespace std;
//
//class baseDMA {
//private:
//	char* label;
//	int rating;
//public:
//	baseDMA(const char* l = "null", int r = 0);
//	baseDMA(const baseDMA& rs);
//	virtual ~baseDMA();
//	baseDMA& operator=(const baseDMA& rs);
//	friend ostream& operator<<(ostream& os, const baseDMA& rs);
	
	//将View()定义为纯虚函数即可(virtual和=0缺一不可，只有virtual只是普通虚函数，不强制派生类实现，只有=0语法错误；纯虚函数要求派生类必须实现View()方法)。有了纯虚函数baseDMA就是一个抽象基类
	virtual void View() = 0;
//};

//class lacksDMA : public baseDMA {
//private:
//	enum { COL_LEN = 40 };
//	char color[COL_LEN];
//public:
//	lacksDMA(const char* c = "blank", const char* l = "null",int r = 0);
//	lacksDMA(const char* c, const baseDMA& rs);
//	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
	void View()override {
		cout << "label: " << label << endl;
		cout << "rating: " << rating << endl;
		cout << "color: " << color << endl;
	}
//};

//class hasDMA :public baseDMA {
//private:
//	char* style;
//public:
//	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
//	hasDMA(const char* s, const baseDMA& rs);
//	hasDMA(const hasDMA& hs);
//	~hasDMA();
//	hasDMA& operator=(const hasDMA& rs);
//	friend ostream& operator<<(ostream& os, const hasDMA& rs);
	void View()override {
		cout << "label: " << label << endl;
		cout << "rating: " << rating << endl;
		cout << "style: " << style << endl;
	}
//};
//
//#endif
//
////dma.cpp
//#include "dma.h"
//#include <iostream>
//using namespace std;
//
//baseDMA::baseDMA(const char* l, int r) {
//	label = new char[strlen(l) + 1];
//	strcpy(label, l);
//	rating = r;
//}
//baseDMA::baseDMA(const baseDMA& rs) {
//	label = new char[strlen(rs.label) + 1];
//	strcpy(label, rs.label);
//	rating = rs.rating;
//}
//baseDMA::~baseDMA() { delete[] label; }
//baseDMA& baseDMA::operator=(const baseDMA& rs) {
//	if (this == &rs)return *this;
//	delete[] label;
//	label = new char[strlen(rs.label) + 1];
//	strcpy(label, rs.label);
//	rating = rs.rating;
//	return *this;
//}
//ostream& operator<<(ostream& os, const baseDMA& rs) {
//	os << "Label: " << rs.label << endl;
//	os << "Rating: " << rs.rating << endl;
//	return os;
//}
//
//lacksDMA::lacksDMA(const char* c, const char* l, int r) : baseDMA(l,r) {
//	strncpy(color, c, 39);
//	color[39] = '\0';
//}
//lacksDMA::lacksDMA(const char* c, const baseDMA& rs) :baseDMA(rs) {
//	strncpy(color, c, COL_LEN - 1);
//	color[COL_LEN - 1] = '\0';
//}
//ostream& operator<<(ostream& os, const lacksDMA& ls) {
//	os << (const baseDMA&)ls;
//	os << "Color: " << ls.color << endl;
//	return os;
//}
//
//hasDMA::hasDMA(const char* s, const char* l, int r) :baseDMA(l, r) {
//	style = new char[strlen(s) + 1];
//	strcpy(style, s);
//}
//hasDMA::hasDMA(const char* s, const baseDMA& rs) :baseDMA(rs) {
//	style = new char[strlen(s) + 1];
//	strcpy(style, s);
//}
//hasDMA::hasDMA(const hasDMA& hs) :baseDMA(hs) {
//	style = new char[strlen(hs.style) + 1];
//	strcpy(style, hs.style);
//}
//hasDMA::~hasDMA() { delete[] style; }
//hasDMA& hasDMA::operator=(const hasDMA& hs) {
//	if (this == &hs)return *this;
//	baseDMA::operator=(hs);
//	delete[] style;
//	style = new char[strlen(hs.style) + 1];
//	strcpy(style, hs.style);
//	return *this;
//}
//ostream& operator<<(ostream& os, const hasDMA& hs) {
//	os << (const baseDMA&)hs;
//	os << "Style: " << hs.style << endl;
//	return os;
//}

//main.cpp
#include <iostream>
#include "dma.h"
#include <string>
using namespace std;

int main(){
	baseDMA* arr[1]; //有*，即arr是指向baseDMA类型对象的指针，加了[size]就是个指针数组了，因为是指针所以用->访问对象
	int choice;
	string label;
	int rating;
	string color;
	string style;

	while (true) {
		cout << "选择创建的对象类型：1.baseDMA  2.lacksDMA  3.hasDMA 4.退出" << endl;
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			cout << "此时创建baseDMA对象" << endl;
			cout << "label: ";
			getline(cin, label);
			cout << "rating: ";
			cin >> rating;
			arr[0] = new baseDMA(label, rating);
			arr[0]->View(); //指针需要用->来访问对象
			delete arr[0]; //delete用于释放new的单个对象，delete[]用于释放new的整个数组，这里指针指向的是堆上的内存，所以通过delete释放掉
		}
		else if (choice == 2) {
			cout << "此时创建lacksDMA对象" << endl;
			cout << "color: ";
			getline(cin, color);
			cout << "label: ";
			getline(cin, label);
			cout << "rating: ";
			cin >> rating;
			arr[0] = new lacksDMA(color, label, rating);
			arr[0]->View(); //指针需要用->来访问对象
			delete arr[0]; //delete用于释放new的单个对象，delete[]用于释放new的整个数组，这里指针指向的是堆上的内存，所以通过delete释放掉
		}
		else if (choice == 3) {
			cout << "此时创建hasDMA对象" << endl;
			cout << "style: ";
			getline(cin, style);
			cout << "label: ";
			getline(cin, label);
			cout << "rating: ";
			cin >> rating;
			arr[0] = new hasDMA(style, label, rating);
			arr[0]->View(); //指针需要用->来访问对象
			delete arr[0]; //delete用于释放new的单个对象，delete[]用于释放new的整个数组，这里指针指向的是堆上的内存，所以通过delete释放掉
		}
		else if (choice == 4) { break; }
		else {cout << "输入非法，请重新输入：";}
	}
}

/*
比方说之前创建结构体对象和结构体数组时，区别使用->和.访问
StructName* p = new StructName用->，因为通过p访问，而p是指针，指针用->访问。p->Method
StructName* p = new StructName[size]用.，因为通过p[i]访问，而p[i]是对象，对象用.访问。p[i].Method
但是最后都是通过delete p来释放内存，因为p是指针。本题中arr[i]是指针，所以是delete arr[i]释放内存。
*/

//Q4.设置Port类及其派生类VintagePort，完成所有函数定义，并解释①为什么有的函数被重新定义了而有些没有 ②为什么没有将operator=()和operator<<()声明为虚的

//class.h
#include <iostream>
using namespace std;
class Port {
private:
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int b = 0) {
		brand = new char[strlen(br) + 1];
		strcpy(brand, br);
		strcpy(style, st);
		bottles = b;
	}
	Port(const Port& p) {
		brand = new char[strlen(p.br) + 1];
		strcpy(brand, p.br);
		strcpy(style, p.st);
		bottles = p.b;
	}
	virtual ~Port() { delete[] brand; }
	Port& operator=(const Port& p) {
		if (this == &p)return *this;
		delete[] brand;
		brand = new char[strlen(p.br) + 1];
		strcpy(brand, p.br);
		strcpy(style, p.st);
		bottles = p.b;
		return *this;
	}
	Port& operator+=(int b) {
		bottles += b;
		return *this;
	}
	Port& operator-=(int b) {
		bottles -= b;
		return *this;
	}
	int BottleCount()const { return bottles; }
	virtual void Show()const {
		cout << "brand: " << brand << endl;
		cout << "style: " << style << endl;
		cout << "bottles: " << bottles << endl;
	}
	friend ostream& operator<<(ostream& os, const Port& p);
};

class VintagePort :public Port {
private:
	char* nickname;
	int year;
public:
	VintagePort() : Port("none", "none", 0) {
		nickname = new char[strlen("none") + 1];
		strcpy(nickname, "none");
		year = 0;
	}
	VintagePort(const char* br, int b, const char* nn, int y) : Port(br,"none", b) {
		nickname = new char[strlen(nn) + 1];
		strcpy(nickname, nn);
		year = y;
	}
	VintagePort(const VintagePort& vp) : Port(vp){
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
		year = vp.year;
	}
	~VintagePort() { delete[] nickname; }
	VintagePort& operator=(const VintagePort& vp) {
		if (this == &vp)return *this;
		Port::operator=(vp);
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
		year = vp.year;
		return *this;
	}
	void Show()const {
		Port::Show();
		cout << "nickname: " << nickname << endl;
		cout << "year: " << year << endl;
	}
	friend ostream& operator<<(ostream& os, const VintagePort& vp);
};

//class.cpp
#include "class.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Port& p) {
	os << "brand: " << p.brand << endl;
	os << "styles: " << p.style << endl;
	os << "bottles: " << p.bottles << endl;
	return os;
}
ostream& operator<<(ostream& os, const VintagePort& vp) {
	Port::operator<<(os,vp);
	os << "nickname: " << vp.nickname << endl;
	os << "years: " << vp.year << endl;
	return os;
}
/*
有些函数重新被定义，例如构造函数和析构函数，因为它们处理的是 多态。但是operator= 和 operator<< 不需要，它们是 静态绑定 的函数，只做简单操作，不依赖多态。

没有将它们声明为虚函数，因为它们并不需要多态，重写它们会引入不必要的复杂性。
*/