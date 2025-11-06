/*
Q1.Wine类有一个string类对象成员和一个Pair对象；其中前者用于存储酒的名称，而后者有两个valarray<int>对象，这两个valarray<int>对象分别保存了酒的年份和该年生产瓶数。
例如，Pair的第1个valarray<int>对象为1988、1992和1996年，第2个valarray<int>对象为24、48和144瓶。Wine最好有1个int成员用于存储年份数量。
另外，一些typedef可能有助于简化编程工作:
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
这样，PairArray表示的是类型Pair<std::valarray<int>, std::valarray<int>>。使用包含来实现Wine类，并用一个简单的程序对其进行测试。Wine类应该有一个默认构造函数以及如下构造函数:

//initialize label to l, number of years to y, vintage years to yr[], bottles to bot[]
Wine(const char* l, int y, const int yr[], const int bot[]);
//initialize label to l, number of years to y, create array objects of length y
Wine(const char* l, int y);

Wine类应该有一个GetBottles()方法，它根据Wine对象能够存储几种年份(y)，提示用户输入年份和瓶数。方法Label()返回一个指向葡萄酒名称的引用。sum()方法返回Pair对象中第二个valarray<int>对象中的瓶数总和。
测试程序应提示用户输入酒名称、元素个数以及每个元素存储的年份和瓶数等信息。程序将使用这些数据来构造一个Wine对象，然后显示对象中保存的信息。

测试程序如下：
#include <iostream>
#include "winec.h"
using namespace std;

int main(){
	cout<<"Enter name of wine: ";
	char lab[50];
	cin.getline(lab,50);
	cout<<"Enter number of years: ";
	int yrs;
	cin>>yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = {48, 60, 72};
	//create new object, initialize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout<<"Total bottles for"<<more.Label()<<": "<<more.sum()<<endl;
	cout<<"Bye\n";
	return 0;
}
*/

//wine.h
#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <valarray>
#include <string>
#include "pair.h"
using namespace std;

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
private:
	string label;
	int num_of_year;
	PairArray data;
public:
	Wine() :label("none"), num_of_year(0), data() {}
	Wine(const char* l, int y, const int yr[], const int bot[]) :label(l), num_of_year(y), data(ArrayInt(yr, y), ArrayInt(bot, y)) {}
	Wine(const char* l, int y):label(l),num_of_year(y),data(ArrayInt(y),ArrayInt(y)){}
	void GetBottles() {
		cout << "Enter " << label << " data for " << num_of_year << " year(s): " << endl;
		for (int i = 0; i < num_of_year; i++) {
			cout << "Enter year: ";
			cin >> data.first[i];
			cout << "Enter bottles for that year: ";
			cin >> data.second[i];
		}
	}
	void Show() {
		cout << "Wine: " << label << endl;
		cout << "Year     Bottles" << endl;
		for (int i = 0; i < num_of_year; i++) cout << data.first[i] << "    " << data.second[i];
	}
	string& Label() { return label; }
	int sum() {
		int count = 0;
		for (int i = 0; i < num_of_year; i++) count += data.second[i]; //直接return data.second().sun()即可
		return count;
	}
};
#endif

/*
Q2.采用私有继承而不是包含来完成Q1，另外需要考虑如下语句定义：
PairArray::operator=(PairArray(ArrayInt(), ArrayInt()));
cout<<(const string&)(*this);
*/

class Wine :private string, private PairArray {
private:
	int num_of_year;
public:
	Wine():string("none"), num_of_year(0), PairArray() {}
	Wine(const char* l, int y, const int yr[], const int bot[]) : string(l), num_of_year(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}
	Wine(const char* l, int y) : string(l), num_of_year(y), PairArray(ArrayInt(y), ArrayInt(y)) {}
	void GetBottles() {
		cout << "Enter " << Label() << " data for " << years << " year(s):\n";
		for (int i = 0; i < years; i++) {
			cout << "Enter year: ";
			cin >> PairArray::first()[i];
			cout << "Enter bottles for that year: ";
			cin >> PairArray::second()[i];
		}
	}
	const string& Label() const {return (const string&)(*this);}
	int sum() const {return PairArray::second().sum();}
	void Show() const {
		cout << "Wine: " << Label() << endl;
		cout << "\tYear\tBottles\n";
		for (int i = 0; i < num_of_year; i++)
			cout << "\t" << PairArray::first()[i]
			<< "\t" << PairArray::second()[i] << endl;
	}
};