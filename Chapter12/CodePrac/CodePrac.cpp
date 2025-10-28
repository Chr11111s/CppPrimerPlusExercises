//Q1.给以下类提供实现并编写程序演示所有成员函数
#include <iostream>
#include <cstring>
using namespace std;

class Cow {
	char name[20]; //固定长度字符串，系统自动分配与释放
	char* hobby;   //动态字符串，需手动分配与释放
	double weight;
public:
	Cow() { //无参构造函数(默认)，在创建语句为  Cow c;  时被调用。
		strcpy(name, ""); //strcpy需要传字符串
		hobby = nullptr;
		weight = 0;
	}
	Cow(const char* nm, const char* ho, double wt) { //有参构造函数，在创建语句为  Cow c2("Bella", "Grazing", 500.5);  时被调用
		strcpy(name, nm);
		if (ho) { //存在传入空指针嫌疑一定要判断非空再new
			hobby = new char[strlen(ho) + 1];
			strcpy(hobby, ho);
		}
		else {
			hobby = nullptr;
		}
		weight = wt;
	}

	Cow(const Cow& c) { //拷贝函数
		strcpy(name, c.name);
		if (c.hobby) { ////存在传入空指针嫌疑一定要判断非空再new
			hobby = new char[strlen(c.hobby) + 1];
			strcpy(hobby, c.hobby);
		}
		else {
			hobby = nullptr;
		}
		weight = c.weight;
	}

	~Cow() { //析构函数
		delete[] hobby;
	}
	Cow& operator=(const Cow& c) { //赋值运算符重载
		if (this == &c)return *this; //通过比较=左右两边地址是否相同防止自赋值

		strcpy(name, c.name);
		delete[] hobby; //释放旧内存
		if (c.hobby) { //存在传入空指针嫌疑一定要判断非空再new
			hobby = new char[strlen(c.hobby) + 1];
			strcpy(hobby, c.hobby);
		}
		else {
			hobby = nullptr;
		}
		weight = c.weight;
		return *this;
	}
	void ShowCow() const { //display all cow data
		cout << "name: " << name << endl;
		cout << "hobby: " << hobby << endl; //*hobby(指针指向的字符串中的第一个字符) 只打印字符串的第一个字符，只有hobby(指向字符串首字符的指针)才会打印整个字符串；因为关键是在于cout本身也是个对象，它会自动识别char*从而打印整个字符串
		cout << "weight: " << weight << endl;
	} 
};

/*拓展：第44行能否写成if(*this == c)？————不行，除非你已经重载了 == 可用于判断[两个对象]，否则 == 只能用于判断[值]是否一致。*/


//Q2.将String1.h升级改写：a.重载+运算符使之可以合成两个字符串；b.提供一个Stringlow()成员函数将字符串中所有的字母字符转换为小写(cctype)；
//c.提供String()成员函数将字符串中所有字母字符转换成大写；d.提供一个成员函数，他接受一个char参数，返回该字符在字符串中出现的次数

//string1.h

#ifndef STRING1_H_
#define STRING1_H_
#include <iostream> 
using std::ostream;
using std::istream;

class String {
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String();
	String(const String&);

	~String();
	int length()const { return len; }
	
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i)const;

	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);

	static int HowMany();
};
#endif

//string.cpp
#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

//初始化静态类成员
int String::num_strings = 0;
//静态方法
int String::HowMany() {
	return num_strings;
}

String::String(const char* s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}
String::String() {
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String& st) {
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}
String::~String() {
	--num_strings;
	delete[] str;
}
String& String::operator=(const String& st) {
	if (this == &st) return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
String& String::operator=(const char* s) {
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
char& String::operator[](int i) {
	return str[i];
}
const char& String::operator[](int i)const {
	return str[i];
}
bool operator<(const String& st1, const String& st2) {
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String st2) {
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2) {
	return (std::strcmp(st1.str, st2.str) == 0);
}
ostream& operator<<(ostream& os, const String& st) {
	os << st.str;
	return os;
}
istream& operator>>(istream& is, String& st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is) st = temp;
	while (is && is.get() != '\n')continue;
	return is;
}

//使用下面的程序测试：
#include <iostream>
using namespace std;
#include "string1.h"
int main() {
	String s1(" and I'm a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "The string\n" << s2 << "\ncontains " << s2.has('A') << "'A' characters in it,\n";
	s1 = "red";
	String rgb[3] = { String(s1),String("green"),String("blue") };
	cout << "Enter the name of a primary color for mixing linght: ";
	String ans;
	bool success = false;
	while (cin >> ans) {
		ans.stringlow();
		for (int i = 0; i < 3; i++) {
			if (ans == rgb[i]) {
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)break;
		else cout << "Try again!\n";
	}
	cout << "Bye\n";
	return 0;
}

