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

//#ifndef STRING1_H_
//#define STRING1_H_
//#include <iostream> 
//using std::ostream;
//using std::istream;
//
//class String {
//private:
//	char* str;
//	int len;
//	static int num_strings;
//	static const int CINLIM = 80;
//public:
//	String(const char* s);
//	String();
//	String(const String&);
//
//	~String();
//	int length()const { return len; }
//	
//	String& operator=(const String&);
//	String& operator=(const char*);
//	char& operator[](int i);
//	const char& operator[](int i)const;
//
//	friend bool operator<(const String& st1, const String& st2);
//	friend bool operator>(const String& st1, const String& st2);
//	friend bool operator==(const String& st1, const String& st2);
//	friend ostream& operator<<(ostream& os, const String& st);
//	friend istream& operator>>(istream& is, String& st);
//
	//合成字符串+号重载
	friend String& operator+(const String& st1, const String& st2);
	//Stringlow()与Stringup()声明
	void Stringlow();
	void Stringup();
	//字符计数函数定义
	int count(char c)const;
//
//	static int HowMany();
//};
//#endif
//
////string.cpp
//#include <cstring>
//#include <cctype>
//#include "string1.h"
//using namespace std;
//
////初始化静态类成员
//int String::num_strings = 0;
////静态方法
//int String::HowMany() {
//	return num_strings;
//}
//
//String::String(const char* s) {
//	len = std::strlen(s);
//	str = new char[len + 1];
//	std::strcpy(str, s);
//	num_strings++;
//}
//String::String() {
//	len = 4;
//	str = new char[1];
//	str[0] = '\0';
//	num_strings++;
//}
//String::String(const String& st) {
//	num_strings++;
//	len = st.len;
//	str = new char[len + 1];
//	std::strcpy(str, st.str);
//}
//String::~String() {
//	--num_strings;
//	delete[] str;
//}
//String& String::operator=(const String& st) {
//	if (this == &st) return *this;
//	delete[] str;
//	len = st.len;
//	str = new char[len + 1];
//	std::strcpy(str, st.str);
//	return *this;
//}
//String& String::operator=(const char* s) {
//	delete[] str;
//	len = std::strlen(s);
//	str = new char[len + 1];
//	std::strcpy(str, s);
//	return *this;
//}
//char& String::operator[](int i) {
//	return str[i];
//}
//const char& String::operator[](int i)const {
//	return str[i];
//}
//bool operator<(const String& st1, const String& st2) {
//	return (std::strcmp(st1.str, st2.str) < 0);
//}
//bool operator>(const String& st1, const String st2) {
//	return st2 < st1;
//}
//bool operator==(const String& st1, const String& st2) {
//	return (std::strcmp(st1.str, st2.str) == 0);
//}
//ostream& operator<<(ostream& os, const String& st) {
//	os << st.str;
//	return os;
//}
//istream& operator>>(istream& is, String& st) {
//	char temp[String::CINLIM];
//	is.get(temp, String::CINLIM);
//	if (is) st = temp;
//	while (is && is.get() != '\n')continue;
//	return is;
}
String operator+(const String& st1, const String& st2) { //函数返回值类型声明加&说明是对已经存在的对象操作，不加就说明要返回一个新对象！！！！！！
	char* temp = new char[st1.len + st2.len + 1];
	strcpy(temp, st1.str);
	strcat(temp, st2.str); //strcat()连接字符串！！
	String res(temp);
	delete[] temp;
	return res;
}
void String::Stringlow() {
	for (int i = 0; i < len; i++) str[i] = tolower(str[i]);
}
void String::Stringup() {
	for (int i = 0; i < len; i++) str[i] = toupper(str[i]);
}
int String::count(char c)const {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == c) count++;
	}
	return count;
}


//使用下面的程序测试：
//#include <iostream>
//using namespace std;
//#include "string1.h"
//int main() {
//	String s1(" and I'm a C++ student.");
//	String s2 = "Please enter your name: ";
//	String s3;
//	cout << s2;
//	cin >> s3;
//	s2 = "My name is " + s3;
//	cout << s2 << ".\n";
//	s2 = s2 + s1;
//	s2.stringup();
//	cout << "The string\n" << s2 << "\ncontains " << s2.has('A') << "'A' characters in it,\n";
//	s1 = "red";
//	String rgb[3] = { String(s1),String("green"),String("blue") };
//	cout << "Enter the name of a primary color for mixing linght: ";
//	String ans;
//	bool success = false;
//	while (cin >> ans) {
//		ans.stringlow();
//		for (int i = 0; i < 3; i++) {
//			if (ans == rgb[i]) {
//				cout << "That's right!\n";
//				success = true;
//				break;
//			}
//		}
//		if (success)break;
//		else cout << "Try again!\n";
//	}
//	cout << "Bye\n";
//	return 0;
//}

//Q3.改写Stock类，使之使用动态分配的内存，而不是string类对象来存储股票名称。另外使用重载的operator<<()代替show()成员函数。
//stock.h
#ifndef STOCK_H_
#define STOCK_H_
#include <string>
#include <iostream>
using namespace std;

class Stock {
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const char* co, long n = 0, double pr = 0.0);
	~Stock();
	//当需要delete和new的时候不仅要有析构函数，还要有  【拷贝构造函数】  和  【赋值运算符重载】
	
	Stock(const Stock& s); //拷贝构造函数,用其它对象构造this
	Stock& operator=(const Stock& s); //赋值运算符重载，别人赋值给你

	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	//void show()const;
	const Stock& topval(const Stock& s)const;

	friend ostream& operator<<(ostream& os, const Stock& s); //operator<< 参数应该是 const Stock&，否则不能用const对象输出
};
#endif

//stock.cpp
#include <iostream>
#include <cstring>
#include "stock.h"
using namespace std;

Stock::Stock() {
	company = new char[strlen("No name") + 1];
	strcpy(company, "No name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char* co, long n, double pr) {
	company = new char[strlen(co) + 1];
	strcpy(company, co);
	if (n < 0) {
		cout << "Number of shares can't be negative;" << company << " shares set to 0.\n";
		shares = 0;
	}
	else shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock() { delete[] company; }

void Stock::buy(long num, double price) {
	if (num < 0) cout << "Number of shares can't be negative." << "Transaction is aborted.\n";
	else {
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price) {
	if (num < 0)cout << "Number of shares sold can't be negative." << "Transaction is aborted.\n";
	else if (num > shares)cout << "You can't sell more than you have!" << "Transaction is aborted.\n";
	else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price) {
	share_val = price;
	set_tot();
}
//void Stock::show()const {
//	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
//	streamsize prec = cout.precision(3);
//	cout << "Company: " << company << " Shares: " << shares << '\n';
//	cout << " Share Price: $" << share_val;
//	cout.precision(2);
//	cout << " Total Worth: $" << total_val << '\n';
//	cout.setf(orig, ios_base::floatfield);
//	cout.precision(prec);
//}
const Stock& Stock::topval(const Stock& s)const {
	if (s.total_val > total_val)return s;
	else return *this;
}
ostream& operator<<(ostream& os, Stock& s) {
	os<< "Company: " << s.company << " Shares: " << s.shares << '\n';
	os<< " Share Price: $" << s.share_val;
	os<< " Total Worth: $" << s.total_val << '\n';
	return os;
}
Stock::Stock(const Stock& s) {
	company = new char[strlen(s.company) + 1];
	strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}
Stock& Stock::operator=(const Stock& s) {
	if (this == &s)return *this; //防止自赋值
	delete[] company; //防止内存泄漏

	company = new char[strlen(s.company) + 1];
	strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
	return *this;
}

记住了，如果有new和delete需求一定要来三件套(析构函数、拷贝构造函数、赋值运算符重载)

拓展：为什么拷贝构造和赋值运算符重载代码几乎一模一样？
| 区别 | 拷贝构造函数 | 赋值运算符            |

| 发生时机 | “创建新对象”的时候 | “已有对象重新赋值”时|
| 被赋值对象是否已有旧数据 | ❌ 没有旧数据 | ✅ 已经有旧数据      |
| 是否需要先释放旧内存 | ❌ 不需要 | ✅ 必须释放旧内存    |
| 是否返回值 | ❌ 没有返回值 | ✅ 返回当前对象引用 |


//Q4.观察修改后的栈类(使用动态分配的数组保存栈项)，实现类成员函数(类方法)
//stack.h
typedef unsigned long Item;

class Stack {
	enum { MAX = 10 };
	Item* pitems;
	int size;
	int top;
public:
	Stack(int n = MAX);
	Stack(const Stack& st);
	~Stack();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& st);
};

//stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack(int n = MAX) {
	size = (n > 0) ? n : MAX;
	pitems = new Item[size];
	top = 0;
}
Stack::Stack(const Stack& st) {
	size = st.size;
	pitems = new Item[strlen(st.pitems) + 1];
	strcpy(pitems, st.pitems);
	top = st.top;
}
Stack::~Stack() { delete[] pitems; }
bool Stack::isempty()const { return top == 0; }
bool Stack::isfull()const { return top == size; } //注意是用top来计数的
bool Stack::push(const Item& item) {
	if (isfull())return false;
	pitems[top++] = item; //先进去再上移
	return true;
}
bool Stack::pop(Item& item) {
	if (isempty())return false;
	pitems[--top] = item; //先下移再出栈
	return true;
}
Stack& Stack::operator=(const Stack& st) {
	if (this == &st)return *this;
	delete[] pitems;

	pitems = new Item[st.size];
	for (int i = 0; i < st.size; i++) pitems[i] = st.pitems[i];
	size = st.size;
	top = st.top;
	return* this;
}

拓展：关于push与pop，涉及了栈的核心逻辑，即：入栈——先进去再移指针(top++)；出栈——先移指针再出去(--top)

//Q5.Heather银行进行的研究表明，客户不希望排队时间超过一分钟。使用queue.h进行模拟，找出要使平均等候时间为1分钟，各小时到达的客户数应为多少？(实验时间不短于100小时)

//queue.h
class Customer {
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when()const { return arrive; }
	int ptime()const { return processtime; }
};
typedef Customer Item;

class Queue {
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue& q) :qsize(0) {} //禁用拷贝构造
	Queue& operator=(const Queue& q) { return *this; } //禁用赋值运算符
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

//queue.cpp
#include "queue.h"
Queue::Queue(int qs) : qsize(qs) {
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue() {
	Node* temp;
	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const { return items == 0; }
bool Queue::isfull() const { return items == qsize; }
int Queue::queuecount() const { return items; }

bool Queue::enqueue(const Item& item) {
	if (isfull()) return false;
	Node* add = new Node;
	add->item = item;
	add->next = nullptr;
	if (front == nullptr) front = add;
	else rear->next = add;
	rear = add;
	items++;
	return true;
}

bool Queue::dequeue(Item& item) {
	if (isempty()) return false;
	item = front->item;
	Node* temp = front;
	front = front->next;
	delete temp;
	items--;
	if (items == 0) rear = nullptr;
	return true;
}

//main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"   
using namespace std;

const int MIN_PER_HR = 60;

bool newcustomer(double x);  // 是否有新客户到来

int main() {
	srand(time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;     // 拒绝的顾客数
	long customers = 0;     // 加入队列的顾客数
	long served = 0;        // 被服务的顾客数
	long sum_line = 0;      // 累计队列长度
	int wait_time = 0;      // 柜台当前等待时间
	long line_wait = 0;     // 顾客累计等待时间

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (line.isfull()) turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}

		if (wait_time <= 0 && !line.isempty()) {
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}

		if (wait_time > 0)
			wait_time--;

		sum_line += line.queuecount();
	}

	if (customers > 0) {
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	return 0;
}

bool newcustomer(double x) {
	return (rand() * x / RAND_MAX < 1);
}

//Q6.如果再开设一台ATM情况会如何？修改模拟包含两个队列。假设当第一台ATM前的排队人数少于第二台时，客户将排在第一队，否则将排在第二队。然后找出要使平均等候时间为1分钟，每小时到达的客户数应该为多少(这是非线性问题。即将ATM数量加倍也不能保证每小时处理的客户数量也翻倍，并确保客户等候的时间少于1分钟)
//main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
using namespace std;

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
	srand(time(0));
	cout << "Case Study: Bank of Heather Automatic Tellers (two queues)\n";

	cout << "Enter maximum size of each queue: ";
	int qs;
	cin >> qs;

	Queue line1(qs);   // 第一台ATM的队列
	Queue line2(qs);   // 第二台ATM的队列

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust = MIN_PER_HR / perhour;

	Item temp;      // 临时顾客
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		// 新顾客到来？
		if (newcustomer(min_per_cust)) {
			if (line1.isfull() && line2.isfull())
				turnaways++;
			else {
				customers++;
				temp.set(cycle);

				// 决定排在哪个队列
				if (line1.queuecount() <= line2.queuecount())
					line1.enqueue(temp);
				else
					line2.enqueue(temp);
			}
		}

		// 处理第一台ATM
		if (wait_time1 <= 0 && !line1.isempty()) {
			line1.dequeue(temp);
			wait_time1 = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time1 > 0)
			wait_time1--;

		// 处理第二台ATM
		if (wait_time2 <= 0 && !line2.isempty()) {
			line2.dequeue(temp);
			wait_time2 = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time2 > 0)
			wait_time2--;

		sum_line += line1.queuecount() + line2.queuecount();
	}

	if (customers > 0) {
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(2);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";

	cout << "Done!\n";
	return 0;
}

bool newcustomer(double x) {
	return (rand() * x / RAND_MAX < 1);
}
