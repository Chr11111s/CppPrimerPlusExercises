//Q1.使用[成员函数]为Stonewt类重载乘法运算符，该运算符将数据成员与double类型的值相乘。注意，用英石(stone)和磅(lbs)表示时，需要进位。也就是说，将10英石8磅乘以2等于21英石2磅。
////stonewt.h
//#ifndef STONEWT_H_
//#define STONEWT_H_
//class  Stonewt {
//private:
//	enum{Lbs_per_stn=14};
//	int stone;
//	double pds_left;
//	double pounds;
//public:
//	Stonewt(double lbs);
//	Stonewt(int stn, double lbs);
//	Stonewt();
//	~Stonewt();
//	void show_lbs()const;
//	void show_stn()const;
//
//	//面向对象特性：运算符重载(针对于类成员变量)，如果需要重载运算符则要在类成员函数处声明，格式为 return_type operator 目标运算符 (参数列表)
//	Stonewt operator * (double x)const;
//};
//#endif
//
////stonewt.cpp
//#include <iostream>
//using namespace std;
//#include "stonewt.h"
//
//Stonewt::Stonewt(double lbs) {
//	stone = int(lbs) / Lbs_per_stn;
//	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
//	pounds = lbs;
//}
//
//Stonewt::Stonewt(int stn, double lbs) {
//	stone = stn;
//	pds_left = lbs;
//	pounds = stn * Lbs_per_stn + lbs;
//}
//
//Stonewt::Stonewt() {
//	stone = pounds = pds_left = 0;
//}
//
//Stonewt::~Stonewt(){}
//
//void Stonewt::show_stn()const {
//	cout << stone << " stone, " << pds_left << " pounds\n";
//}
//
//void Stonewt::show_lbs()const {
//	cout << pounds << " pounds\n";
//}
//
////重载运算符函数具体实现
//Stonewt Stonewt::operator*(double x)const {
//	double total_pounds = ((stone * Lbs_per_stn) + pounds) * x;
//	int new_stone = (int)total_pounds / Lbs_per_stn;
//	double new_leftLbs = total_pounds - new_stone * Lbs_per_stn;
//	double new_pounds = new_leftLbs;
//
//	return Stonewt(new_stone, new_pounds);
//}
//
//Q2.友元函数与成员函数之间的区别是什么？
//成员函数：声明在类内部，实现在类内部。属于类成员，访问类私有变量。
//友元函数：声明在类内部(用friend标识)，实现在类外部。不属于类成员，访问类私有变量。
//
//示例：
//class Dick {
//private:
//	double length;
//public:
//	Dick (double x) :length(x) {};
//	void show_legth1() {
//		std::cout << "length: " << length << std::endl;
//	}
//	friend void show_length2(Dick& d);
//};
//
//void show_length2(Dick& d) {
//	std::cout << "length: " << d.length << std::endl;
//}
//
//int main() {
//	Dick d(18);
//	d.show_length1();
//
//	show_length2(d);
//}
//
//Q3.非成员函数必须是友元才能访问类成员——不一定，也可以通过类公共成员函数访问
//示例：
//class Dick {
//private:
//	double length;
//public:
//	void show() {
//		return length;
//	}
//};
//
//void func(Dick& d) {
//	std::cout << d.show() << std::endl;
//}
//
//int main() {
//	Dick d;
//	func(d);
//}

//Q4.使用[友元函数]为Stonewt类重载乘法运算符，该运算将double值和Stone值相乘。
////stonewt.h
//#ifndef STONEWT_H_
//#define STONEWT_H_
//class  Stonewt {
//private:
//	enum { Lbs_per_stn = 14 };
//	int stone;
//	double pds_left;
//	double pounds;
//public:
//	Stonewt(double lbs);
//	Stonewt(int stn, double lbs);
//	Stonewt();
//	~Stonewt();
//	void show_lbs()const;
//	void show_stn()const;
//
//	friend Stonewt operator * (Stonewt& s, double x); //非成员函数不允许加const修饰
//};
//#endif
//
////stonewt.cpp
//#include <iostream>
//using namespace std;
//#include "stonewt.h"
//
//Stonewt::Stonewt(double lbs) {
//	stone = int(lbs) / Lbs_per_stn;
//	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
//	pounds = lbs;
//}
//
//Stonewt::Stonewt(int stn, double lbs) {
//	stone = stn;
//	pds_left = lbs;
//	pounds = stn * Lbs_per_stn + lbs;
//}
//
//Stonewt::Stonewt() {
//	stone = pounds = pds_left = 0;
//}
//
//Stonewt::~Stonewt() {}
//
//void Stonewt::show_stn()const {
//	cout << stone << " stone, " << pds_left << " pounds\n";
//}
//
//void Stonewt::show_lbs()const {
//	cout << pounds << " pounds\n";
//}
//
////重载运算符函数具体实现
//Stonewt operator*(Stonewt& s, double x){
//	double total_pounds = s.pounds * x;
//	return Stonewt(total_pounds);
//}
//
////main.cpp
//#include <iostream>
//#include "stonewt.h"
//
//int main() {
//	Stonewt weight1(10, 8);  // 创建一个 Stonewt 对象，10英石8磅
//	Stonewt result;
//
//	// 显示原始重量
//	weight1.show_stn();
//
//	// 通过友元函数重载 * 运算符，将 weight1 乘以 2
//	result = weight1 * 2;  // 调用 operator*，传入 double 2
//	result.show_stn();  // 显示新结果：20英石16磅
//
//	return 0;
//}
//
//Q5.哪些运算符不能重载？
//
//作用域解析运算符（::）
//
//成员指针运算符（.*）
//
//sizeof, typeid, const_cast, dynamic_cast, reinterpret_cast
//
//new 和 delete（全局的 new 和 delete 运算符不能重载）
//
//sizeof...
//
//这些运算符通常涉及编译时或内存管理的底层操作，因此它们不能被重载。
//
//Q6.在重载运算符 = 、()、[]和->时，有什么限制？
//= (赋值)必须返回当前对象的引用（ * this），防止自赋值；需要处理自赋值的情况；不能返回 void。
//() (函数调用)	可以接受任意参数，返回类型由需要决定；可以是类成员函数；适用于仿函数等场景。
//[](下标)	必须返回元素的引用；可以重载常量版本以支持常量对象；不能接受多个参数。
//-> (箭头)必须返回指针类型；通常用于自定义智能指针类，允许通过自定义对象访问成员。
//
//Q7.为Vector类定义一个转换函数，将Vector类转换为一个double类型的值，后者表示矢量的长度。
//#include <iostream>
//#include <cmath> //为了sqrt()函数
//using namespace std;
//
//class Vector {
//private:
//	double x, y, z;
//public:
//	Vector(double given_x, double given_y, double given_z) :x(given_x), y(given_y), z(given_z) {};
//
//	//转换函数operator target_type() const;
//	operator double() {
//		return sqrt(x * x + y * y + z * z);
//	}
//};
//
//
//int main() {
//	Vector v(3.0, 4.0, 5.0);
//
//	double res = v;//转换函数声明新值会自动调用operator double()计算并返回矢量的长度
//	return res;
//}
//假设你有一个 Vector 类，表示一个矢量。你想要计算这个矢量的长度，也就是它的大小。如果你没有转换函数，你就需要手动编写代码，调用一些函数来获取这个矢量的长度。但是，如果你使用转换函数，你可以让 Vector 对象直接转换为一个表示其“长度”的 double 类型值。