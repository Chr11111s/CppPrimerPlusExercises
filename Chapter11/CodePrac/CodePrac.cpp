//Q1.修改程序，使之将一系列连续的随机漫步者位置写入到文件中。对于每个位置，用步号进行标示。另外，让该程序将初始条件(目标距离和步长)以及结果小结写入该文件。该文件的内容与下面类似：
/*
Target Distance : 100, Step Size : 20
0: (x,y) = (0, 0)
1: (x,y) = (-11.4715, 16.383)
2: (x,y) = (-8.68807, -3.42232)
...
26: (x,y) = (42.2919, -78.2594)
27: (x,y) = (58.6749, -89.7309)
After 27 steps, the subject has the following location:
(x,y) = (58.6749, -89.7309)
or
(m,a) = (107.212, -56.8194)
Average outward distance per step = 3.97081
*/

//vect.h--Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR {
	class Vector {
	public:
		enum Mode{RECT, POL};
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const { return mag; }
		double angval()const { return ang; }
		void polar_mode();
		void rect_mode();
		Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif

//vect.cpp
#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
	const double Rad_to_deg = 45.0 / atan(1.0);
	void Vector::set_mag() {
		mag = sqrt(x * x + y * y);
	}
	void Vector::set_ang() {
		if (x == 0.0 && y == 0.0)ang = 0.0;
		else ang = atan2(y, x);
	}
	void Vector::set_x() {
		x = mag * cos(ang);
	}
	void Vector::set_y() {
		y = mag * sin(ang);
	}
	Vector::Vector() {
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector(){}
	void Vector::polar_mode() { mode = POL; }
	void Vector::rect_mode() { mode = RECT; }
	Vector Vector::operator+(const Vector& b)const { return Vector(x + b.x, y + b.y); }
	Vector Vector::operator-(const Vector& b)const { return Vector(x - b.x, y - b.y); }
	Vector Vector::operator-()const { return Vector(-x, -y); }
	Vector Vector::operator*(double n)const { return Vector(n * x, n * y); }
	Vector operator*(double n, const Vector& a) { return a * n; }
	std::ostream& operator<<(std::ostream& os, const Vector& v) {
		if (v.mode == Vector::RECT) os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL) { os << "(m,a)=(" << v.mag << ", " << v.ang * Rad_to_deg << ")"; }
		else os << "Vector object mode is invalid";

		return os;
	}
}

//randwalk.cpp
#include <cstdlib>  // 为了使用 rand(), srand()
#include <ctime>    // 为了使用 time()
#include <fstream>   // 用于文件输出
#include "vect.h"

int main() {
    using namespace std;
    using VECTOR::Vector;
    
    srand(time(0));  // 初始化随机数种子
    
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    
    // 创建并打开文件
    ofstream fout("randwalk_output.txt");
    if (!fout) {
        cerr << "无法打开文件!" << endl;
        return 1;
    }
    
    // 循环获取用户输入
    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) break;
        
        // 将初始条件写入文件
        fout << "Target Distance : " << target << ", Step Size : " << dstep << endl;
        
        // 重置漫步者的位置
        result.reset(0.0, 0.0);
        steps = 0;
        
        // 开始模拟随机漫步
        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            
            // 写入每一步的位置
            fout << steps << ": " << result << endl;
        }
        
        // 写入结果和统计信息
        fout << "After " << steps << " steps, the subject has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << " or\n" << result << endl;
        fout << "Average outward distance per step = " << result.magval() / steps << endl;
        
        // 重置准备下一次输入
        steps = 0;
        result.reset(0.0, 0.0);
        fout << endl;
        
        // 提示用户继续输入
        cout << "Enter target distance (q to quit): ";
    }
    
    cout << "Bye!" << endl;
    
    // 关闭文件
    fout.close();
    cin.clear();
    while (cin.get() != '\n') continue;
    return 0;
}

//Q2.对Vector类的头文件和实现文件进行修改，使其不再存储矢量的长度和角度，而是在magval()和angval()被调用时计算它们,应对共有接口修改而非私有
//vect.h--Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <cmath>
using namespace std;
namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		Mode mode;
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const { return sqrt(x * x + y * y); }
		double angval()const {
			if (x == 0.0 && y == 0.0)return 0.0;
			else return atan2(y, x);
		}
		void polar_mode();
		void rect_mode();
		Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif

//vect.cpp
#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
	const double Rad_to_deg = 45.0 / atan(1.0);
	Vector::Vector() {
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			x = n1 * cos(n2);
			y = n1 * sin(n2);
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			x = n1 * cos(n2);
			y = n1 * sin(n2);
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector() {}
	void Vector::polar_mode() { mode = POL; }
	void Vector::rect_mode() { mode = RECT; }
	Vector Vector::operator+(const Vector& b)const { return Vector(x + b.x, y + b.y); }
	Vector Vector::operator-(const Vector& b)const { return Vector(x - b.x, y - b.y); }
	Vector Vector::operator-()const { return Vector(-x, -y); }
	Vector Vector::operator*(double n)const { return Vector(n * x, n * y); }
	Vector operator*(double n, const Vector& a) { return a * n; }
	std::ostream& operator<<(std::ostream& os, const Vector& v) {
		if (v.mode == Vector::RECT) os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL) { os << "(m,a)=(" << v.magval() << ", " << v.angval() * Rad_to_deg << ")"; }
		else os << "Vector object mode is invalid";

		return os;
	}
}

//Q3.修改randwalk.cpp使之报告N次测试中的最高、最低和平均步数(其中N是用户输入的整数)。而不是每次报告的结果

//randwalk.cpp
#include <iostream>
#include <cstdlib>  // 为了rand(), srand()
#include <ctime>    // 为了time()
#include "vect.h"
#include <vector>
int main() {
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	
	int N;
	cout << "Enter the number of tests: ";
	cin >> N;

	vector<unsigned long>stepCounts;

	for (int i = 0; i < N; i++) {
		cout << "Enter target distance for test" << (i + 1) << ": ";
		cin >> target;
		cout << "Enter step length: ";
		if (!(cin >> dstep))break;

		steps = 0;
		result.reset(0.0, 0.0);

		while(result.magval()<target){
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
	    }

		stepCounts.push_back(steps);

		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		result.reset(0.0, 0.0);
	}
	if (stepCounts.empty()) {
		cout << "No tests performed.\n";
	}
	else {
		unsigned long maxSteps = *max_element(stepCounts.begin(), stepCounts.end());  // 获取最高步数
		unsigned long minSteps = *min_element(stepCounts.begin(), stepCounts.end());  // 获取最低步数
		unsigned long totalSteps = accumulate(stepCounts.begin(), stepCounts.end(), 0);  // 计算总步数
		double averageSteps = static_cast<double>(totalSteps) / stepCounts.size();  // 计算平均步数

		cout << "After " << N << " tests:\n";
		cout << "Highest steps: " << maxSteps << endl;
		cout << "Lowest steps: " << minSteps << endl;
		cout << "Average steps: " << averageSteps << endl;
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n') continue;
	return 0;
}

//Q4,重新编写Time类示例，使用友元函数来实现所有的重载运算符
//mytime.h
class Time {
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend Time operator*(const Time& t, double n);
	friend Time operator*(double m, const Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

//mytime.cpp
#include "mytime.h"
Time::Time() { hours = minutes = 0; }
Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}
void Time::AddMin(int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h) { hours += h; }
void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}
Time operator+(const Time& t1, const Time& t2) {
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time operator-(const Time& t1, const Time& t2) {
	Time diff;
	int tot1, tot2;
	tot1 = t1.minutes + 60 * t1.hours;
	tot2 = t2.minutes + 60 * t2.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}
Time operator*(const Time& t, double n) {
	Time result;
	long totalminutes = t.hours * n * 60 + t.minutes * n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator*(double m, const Time& t) {
	return m * t; //直接调用上面*
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}

//Q5.重新编写Stonewt类，使它有一个状态成员，由该成员控制对象应转换为英石格式、整数磅格式还是浮点磅格式。重载<<运算符，使用它来替换show_stn()和show_lbs()方法。重载加法、减法和乘法运算符以便对Stonewt值进行加、减、乘运算。编写一个使用所有类和友元的小程序来测试。
#include <iostream>
using namespace std;

class  Stonewt {
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	enum Format { STONE, POUNDS_INT, POUNDS_FLOAT };
	Format status;
public:
	Stonewt(double lbs, Format fmt = POUNDS_FLOAT);
	Stonewt(int stn, double lbs, Format fmt = POUNDS_FLOAT);
	Stonewt();
	~Stonewt();
	
	void set_format(Format fmt) { status = fmt; }

	Stonewt operator+(const Stonewt& stn)const;
	Stonewt operator-(const Stonewt& stn)const;
	Stonewt operator*(double n)const; //*左边数为对象时用成员函数定义
	friend Stonewt operator*(double n, const Stonewt& stn); //*左边数为常量值时用友元函数定义                                          
	friend ostream& operator<<(ostream& os, const Stonewt& stn);
};

////stonewt.cpp
#include <iostream>
using namespace std;
#include "stonewt.h"

Stonewt::Stonewt(double lbs, Format fmt = POUNDS_FLOAT) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	status = fmt;
}

Stonewt::Stonewt(int stn, double lbs, Format fmt = POUNDS_FLOAT) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	status = fmt;
}

Stonewt::Stonewt() {
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt(){}

Stonewt Stonewt::operator+(const Stonewt& stn)const {
	return Stonewt(pounds + stn.pounds, status);
}
Stonewt Stonewt::operator-(const Stonewt& stn)const {
	return Stonewt(pounds - stn.pounds, status);
}
Stonewt Stonewt::operator*(double n)const {
	return Stonewt(pounds * n, status);
}
Stonewt operator*(double n, const Stonewt& stn) {
	return Stonewt(stn.pounds * n, stn.status);
}
ostream& operator<<(ostream& os, const Stonewt& stn) {
	switch (stn.status) {
	case Stonewt::STONE:
		os << stn.stone << " stone " << stn.pds_left << " pounds";
		break;
	case Stonewt::POUNDS_INT:
		os << static_cast<int>(stn.pounds) << " pounds";
		break;
	case Stonewt::POUNDS_FLOAT:
		os << stn.pounds << " pounds";
		break;
	}
	return os;
}
//main.cpp
#include <iostream>
#include "stonewt.h"

int main() {
	Stonewt wt1(200.5);  // 以浮动磅格式初始化
	Stonewt wt2(10, 5.5);  // 以英石和磅数初始化

	cout << "wt1: " << wt1 << endl;  // 打印 wt1
	cout << "wt2: " << wt2 << endl;  // 打印 wt2

	// 测试加法
	Stonewt wt3 = wt1 + wt2;
	cout << "wt1 + wt2 = " << wt3 << endl;

	// 测试减法
	Stonewt wt4 = wt1 - wt2;
	cout << "wt1 - wt2 = " << wt4 << endl;

	// 测试乘法
	Stonewt wt5 = wt1 * 1.5;
	cout << "wt1 * 1.5 = " << wt5 << endl;

	// 测试反向乘法
	Stonewt wt6 = 2.0 * wt2;
	cout << "2.0 * wt2 = " << wt6 << endl;

	return 0;
}

//Q6.重新编写Stonewt类，重载全部6个关系运算符。运算符对pounds成员进行比较，并返回一个bool值。编写程序，它声明一个包含6个Stonewt对象的数组，并在数组声明中初始化前3个对象。然后使用循环来读取用于设置剩余3个数组元素的值。接着报告最小的元素、最大的元素以及大于或等于
//11英石的元素的数量(最简单的方法是创建一个Stonewt对象，并将其初始化为11英石，然后将其同其它对象进行比较)
#include <iostream>
using namespace std;

class  Stonewt {
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();

	bool operator>(const Stonewt& s)const {}
	bool operator<(const Stonewt& s)const {}
	bool operator>=(const Stonewt& s)const {}
	bool operator<=(const Stonewt& s)const {}
	bool operator==(const Stonewt& s)const {}
	bool operator!=(const Stonewt& s)const {}

	friend ostream& operator<<(ostream& os, const Stonewt& s);//<< 运算符是一个非成员函数，它需要接受一个流对象（如 ostream）作为第一个参数，并且还需要访问 Stonewt 对象的成员。
															  //如果我们使用成员函数来重载 << 运算符，成员函数的第一个参数会是类的 this 指针，而不是流对象 ostream。因此，成员函数并不能提供访问流对象的能力。而前面*的重载也解释的通了
};

////stonewt.cpp
#include <iostream>
using namespace std;
#include "stonewt.h"

Stonewt::Stonewt(double lbs) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() {
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt(){}

bool Stonewt::operator>(const Stonewt& s)const { return pounds > s.pounds; }
bool Stonewt::operator<(const Stonewt& s)const { return pounds < s.pounds; }
bool Stonewt::operator>=(const Stonewt& s)const { return pounds >= s.pounds; }
bool Stonewt::operator<=(const Stonewt& s)const { return pounds <= s.pounds; }
bool Stonewt::operator==(const Stonewt& s)const { return pounds == s.pounds; }
bool Stonewt::operator!=(const Stonewt& s)const { return pounds != s.pounds; }

ostream& operator<<(ostream& os, const Stonewt& s) {
	os << "stone: " << s.stone << "pounds" << s.pds_left << "totalPounds: " << s.pounds;
	return os;
}



//main.cpp
#include <iostream>
#include <stonewt.h>
using namespace std;

int main() {
	Stonewt arr[6] = { //定义数组时初始化前三个
		Stonewt(10,0),
		Stonewt(11,0),
		Stonewt(12,0),
	};
	for (int i = 3; i < 6; i++) {
		arr[i] = Stonewt (10 + i, i); //数组只能用=初始化，不能用构造函数初始化
	}
	Stonewt s(11, 0);
	Stonewt max = s;
	Stonewt min = s;
	int count = 0;
	for (int i = 0; i < 6; i++) {
		if (max < arr[i]) max = arr[i];
		else if (min > arr[i])min = arr[i];
		else if (arr[i] > s || arr[i] >= s)count++;
	}
	cout << "max: " << max << "min: " << min << "count(> or >=): " << count;
}

//Q7.复数由实数部分和虚数部分组成。负数一种书写方式为：(3.0, 4.0)，其中3.0是实数部分，4.0是虚数部分。假设a=(A,Bi), c=(C,Di)，下面是复数运算法则
//加法：a+c=(A+C, (B+D)i)；减法：a-c=(A-C, (B-D)i)；乘法1：a*c=(A*C-B*D, (A*D+B*C)i)；乘法2：x*c=(x*C, x*Di)，其中x为实数；共轭：~a=(A, -Bi)

//定义复数类complex0，以便下面程序可以使用其获得正确结果。必须重载运算符<<和>>，重载后cin>>c将提示用户输入实数部分和虚数部分。
/*
#include <iostream>
using namespace std;
#include "complex0.h"
int main() {
	complex a(3.0, 4.0);
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c) {
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return 0;
}
*/

//complex0.h
class complex {
private:
	double real;
	double imaginary;
public:
	complex(double r, double i) :real(r), imaginary(i) {};
	complex() :real(0), imaginary(0) {};

	complex operator+(complex& c)const;
	complex operator-(complex& c)const;
	complex operator*(complex& c)const;
	friend complex operator*(double x, complex& c);

	complex operator~()const;

	friend std::istream& operator>>(istream& is, complex& c); //绝对不能用成员函数定义数据流重载符号，数据流形参强制第一个为数据流is/os，若使用成员函数则会强制默认第一个为this。故输入输出符号重载只能使用友元函数！！！
	friend std::ostream& operator<<(istream& os, complex& c);
};

//complex0.cpp
#include <iostream>
using namespace std;
#include "complex0.h"

complex complex::operator+(complex& c)const {
	return complex(real + c.real, imaginary + c.imaginary);
}
complex complex::operator-(complex& c)const {
	return complex(real - c.real, imaginary - c.imaginary);
}
complex complex::operator*(complex& c)const {
	return complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}
complex operator*(double x, complex& c) {
	return complex(x * c.real, x * c.imaginary);
}
complex complex::operator~()const {
	return complex(real, 0 - imaginary);
}
std::istream& operator>>(istream& is, complex& c) {
	cout << "real：";
	if(!(is >> c.real)) return is;
	cout << endl;
	cout << "imaginary: ";
	is >> c.imaginary;
	return is;
}
std::ostream& operator<<(ostream& os, complex& c) {
	os << "(" << c.real << ", " << c.imaginary << "i)";
	return os;
}