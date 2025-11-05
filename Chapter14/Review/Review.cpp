//Q1.区分公有继承和私有继承
公有继承（public）：B 是一种 A → “is - a”
私有继承（private）：B 只是利用了 A 的功能 → “has - a”

//Q2.假设存在以下类，假设Gloam版本的tell()应显示glip和fb的值，请为这3个Gloam方法提供定义。
class Frabjous {
private:
	char fab[20];
public:
	Frabjous(const char* s="C++"):fab(s){} //其实这样写是错的，数组不支持初始化列表，不过为了题目方便表示就这么写了。
	virtual void tell() { cout << fab; }
};
class Gloam {
private:
	int glip;
	Frabjous fb; //Gloam 拥有一个 Frabjous 对象，而不是从它继承。所以这是【组合】
public:
	Gloam(int g = 0, const char* s = "C++") : glip(g), fb(s) {}; //调用Frabjous(const char* s)构造函数 
	Gloam(int g, const Frabjous& f) : glip(g), fb(f) {}; //调用隐式拷贝赋值函数(虽然是浅拷贝，但是没有指针，所以安全)
	void tell() {
		cout << "glip: " << glip<<"fab: ";
		fb.tell(); //调用基类tell()
	}
};

//Q3.假设以下类成立，而且Gloam版本的tell()应显示glip和fab的值，请为这3个Gloam方法提供定义。
class Frabjous {
private:
	char fab[20];
public:
	Frabjous(const char* s = "C++") :fab(s) {}
	virtual void tell() { cout << fab; }
};
class Gloam : private Frabjous{ //相当于 private 里面加了一个 Frabjous fb 的东西，这就是私有继承在内存层面上的实际效果
private:
	int glip;
public:
	Gloam(int g = 0, const char* s = "C++") :glip(g), Frabjous(s) {}; //调用Frabjous构造函数。初始化列表书写顺序可以随意改变，但是底层实际初始化是按照定义顺序来的
	Gloam(int g, const Frabjous& f) :glip(g), Frabjous(f) {}; //调用编译器自主生成的默认拷贝构造函数(浅拷贝)
	void tell() {
		cout << "glip: " << glip<<"fab: ";
		Frabjous::tell(); //调用基类tell()
	}
};

/*
| 关系     | 谁拥有 Frabjous | 调用方式            | 语义             |
| ------ | ------------      | ------------------- | -------------- |
| **组合** | 成员变量拥有    | `fb.tell();`        | “我让我的成员对象去做”   |
| **继承** | 自己包含        | `Frabjous::tell();` | “我自己用基类的那部分去做” |

*/

//Q4(类模板实例化考察).假设有下面的定义，它是基于Stack模板和Worker类的：Stack<Worker*>sw;  请写出将生成的类声明。只实现类声明，不实现非内联类方法。
// 当模板 Stack<Type> 被类型参数 Type = Worker* 实例化时，编译器会自动“展开”模板定义，生成一个专门存放 Worker* 指针的类。
//stacktp.h
//以下不是类，是模板
template <class Type>
class Stack {
private:
	enum{MAX=10};
	Type items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const Type& item);
	bool pop(Type& item);
};

//workermi.h---working classes with MI
#include <string>
using namespace std;

class Worker {
private:
	string fullname;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker():fullname("no one"),id(0L){}
	Worker(const string& s,long n):fullname(s),id(n){}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() = 0;
};

//Stack<Worker*>sw
template<>
class Stack<Worker*> {
private:
	enum{MAX=10};
	Worker* items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(Worker* const& item);
	bool pop(Worker*& item);
};

/*
| 写法                                   | 类定义类型 | 编译器是否需要类型参数 | 是否能直接创建对象        |
| -------------------------------------- | -----      | -----------            | ------------------------- |
| `class Stack {...};`                   | 普通类     | ❌ 不需要             | ✅ 可以直接写 `Stack s;`  |
| `template<class T> `                   | 类模板     | ✅ 必须指定类型参数   | ❌ 不行，必须写成 `Stack<int> s;` |
   class Stack {...};
*/

//Q5.使用本章的模板定义对下面内容进行定义：string对象数组；double 数组栈；指向Worker对象的指针的栈数组。以下程序生成了多少个模板类定义(即实例化了多少个模板类)
#include <iostream>
using namespace std;
#include "arraytp.h"
int main() {
	ArrayTP<int, 10>sums; //实例化x1
	ArrayTP<double, 10>aves; //实例化x2
	ArrayTP<ArrayTP<int, 5>, 10>twodee; //嵌套实例化，外层ArrayTP<ArrayTP, 10>，内层ArrayTP<int, 5>。实例化x2，共生成4个模板类定义

	int i, j;
	for (i = 0; i < 10; i++) {
		sums[i] = 0;
		for (j = 0; j < 5; j++) {
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sums[i] << ", average = " << aves[i] << endl;
	}
	cout << "Done.\n";

	return 0;
}

//arraytp.h
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
using namespace std;
#include <cstdlib>

template<class T,int n>
class ArrayTP {
private:
	T ar[n];
public:
	ArrayTP() {};
	explicit ArrayTP(const T& v);
	virtual T& operator[](int i);
	virtual T operator[](int i)const;
};

template<class T, int n>
ArrayTP<T, n>::ArrayTP(const T& v) {for (int i = 0; i < n; i++) ar[i] = v;}
template<class T, int n>
T& ArrayTP<T, n>::operator[](int i) {
	if (i < 0 || i >= n) {
		cerr << "Error in array limits: " << i << " is out of range\n";
		exit(EXIT_FAILURE);
	}
	return ar[i];
}
template <class T, int n>
T ArrayTP<T, n>::operator[](int i)const {
	if (i < 0 || i >= n) {
		cerr << "Error in array limits: " << i << " is out of range\n";
		exit(EXIT_FAILURE);
	}
	return ar[i];
}
#endif

/*
string对象数组：ArrayTP<string,10>sa;
double 数组栈：ArrayTP<double,10>da;
指向Worker对象的指针的栈数组：ArrayTP<Worker*,10>wa;
*/

//Q6.指出虚基类和非虚基类之间的区别
虚基类（virtual base class）：
让多重继承体系中的所有派生类共享同一个基类子对象，
用来解决“菱形继承”中的重复基类与二义性问题。

非虚基类：
每条继承路径都有自己独立的基类副本，
简单、开销小，但在多继承下可能产生冲突。

| 对比点         | 非虚基类                 | 虚基类                        |
| ------ -       | ---------------------- - | ------------------------------|
| 定义方式       | class D : public Base    | class D : virtual public Base |
| 基类副本数量   | 每条路径一份             | 所有路径共享一份              |
| 内存模型       | 多个独立 Base            | 共享一个 Base                 |
| 构造责任       | 各自构造                 | 最底层派生类构造              |
| 是否消除二义性 | ❌ 否                   | ✅ 是                         |
| 典型用途       | 单继承                   | 多重继承（钻石结构）          |

示例：
    Person
/            \
Student    Teacher
\            /
   TA（助教）
  