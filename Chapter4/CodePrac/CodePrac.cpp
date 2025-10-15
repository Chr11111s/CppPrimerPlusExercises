#define _CRT_SECURE_NO_WARNINGS //使用strcat()会导致vs编译器报错，提醒可能造成缓冲区溢出，因为strcat()不会检查目标数组够不够大，只会一股脑塞进去。而宏必须在所有头文件之前定义。
#include <iostream>

//Q1.输入用户的姓、名(包含多个单词)、成绩、年龄。成绩需要降一级。
//#include<string>
//int main() {
//	std::string first_name;
//	std::string last_name;
//	char grade;
//	int age;
//
//	std::cout << "What's your first name? ";
//	getline(std::cin, first_name);
//	std::cout << "What's your last name? ";
//	std::cin >> last_name;
//	std::cout << "What grade do you deserve? ";
//	std::cin >> grade;
//	std::cout << "What's your age? ";
//	std::cin >> age;
//
//	std::cout <<"Name: "<< last_name << ", " << first_name << std::endl;
//	std::cout << "Grade: " << static_cast<char>(grade + 1) << std::endl;
//	std::cout << "Age: " << age;
//}

//Q2.修改代码，使用C++string类而不是char数组。注意，读取函数也会因此改变，cin.getline()仅针对char数组，getline()仅针对string类。
//#include <string>
//int main() {
//	using namespace std;
//	const int Arsize = 20;
//	string name, dessert;
//
//	cout << "Your name: \n";
//	getline(cin, name);
//	cout << "Your favoourite dessert: \n";
//	getline(cin, dessert);
//
//	cout << "I have some delicious " << dessert;
//	cout << " for you, " << name << ".\n";
//}

//Q3.用户先输入名，后输入姓，然后用一个逗号和一个空格将姓名组合，并存储和显示组合结果。注意使用char数组和头文件cstring中函数
//#include <cstring> //包含strcpy()与strcat()函数
//int main() {
//	char first_name[10];
//	char last_name[10];
//	char full_name[20];
//
//	std::cout << "First name: ";
//	std::cin.getline(first_name, 10);
//	std::cout << "Last name: ";
//	std::cin.getline(last_name, 10);
//
//	std::strcpy(full_name, first_name);//第一个字符串要cpy赋值，后序仅需cat粘连即可
//	std::strcat(full_name, ", ");
//	std::strcat(full_name, last_name);
//
//	std::cout << "Full name: " << full_name;
//}

//Q4.使用string对象和头文件string中函数完成Q3任务
//#include <string> //为创建string对象必须导入此头文件
//int main() {
//	std::string first_name;
//	std::string last_name;
//	std::string full_name;
//
//	std::cout << "First name: ";
//	getline(std::cin, first_name);//getline()在iostream中被声明
//	std::cout << "Last name: ";
//	getline(std::cin, last_name);
//
//	full_name = first_name + ", " + last_name; //string类比char类好操作，仅需使用+号链接string字符串即可
//
//	std::cout << "Full name: " << full_name;
//}

//Q5.结构CandyBar包含3个成员。第一个成员存储糖的品牌，第二个存储糖的重量(可以有小数)，第三个存储糖的卡路里(整数)。声明这个结构，创建一个名为snack的CandyBar变量，并将其成员分别初始化为"Mocha Munch", 2.3和350。
//初始化应在声明snack时进行。最后，程序显示snack变量内容
//#include <string>
//struct CandyBar {
//	std::string brand;
//	double weight;
//	int cal;
//};
//int main() {
//	CandyBar snack = { "Mocha Munch", 2.3, 350 };
//	std::cout << "Brand: " << snack.brand << " Cal: " << snack.cal << " Weight: " << snack.weight;
//}

//Q6.结构CandyBar包含3个成员，如Q5所示。创建一个包含3个元素的CandyBar数组，并将它们初始化为所选择的值，然后显示每个结构的内容。
//#include <string>
//struct CandyBar {
//	std::string brand;
//	double weight;
//	int cal;
//};
//int main() {
//	CandyBar arr[3] = {
//		{"B1", 1.1, 1},
//		{"B2", 2.2, 2},
//		{"B3", 3.3, 3}
//	};
//	for (int i = 0; i < 3; i++) {
//		std::cout << "这是第 " << i + 1 << " 个成员：";
//		std::cout << "Brand: " << arr[i].brand << " Cal: " << arr[i].cal << " Weight: " << arr[i].weight << std::endl;
//	}
//}

//Q7.W会记录关于披萨的如下信息：①披萨公司的名称，可以由多个单词组成 ②披萨直径 ③披萨重量，请设计一个能存储这些信息的结构，并写一个使用此结构变量的程序。程序将请求用户输入上述信息然后显示。请使用cin(或它的方法)和cout
//#include <string>
//struct Pizza {
//	std::string brand;
//	double diameter;
//	double weight;
//};
//
//int main() {
//	std::string brand;
//	double diameter;
//	double weight;
//	std::cout << "输入披萨品牌：";
//	getline(std::cin, brand);
//	std::cout << "输入披萨直径：";
//	std::cin >> diameter;
//	std::cout << "输入披萨重量：";
//	std::cin >> weight;
//	Pizza pizza = { brand, diameter, weight};
//	std::cout << "品牌：" << pizza.brand << " 直径：" << pizza.diameter << " 重量：" << pizza.weight;
//}

//Q8.使用new为Q7中的结构分配内存，而不是声明一个结构变量。另外，让程序在请求输入披萨品牌之前输入披萨直径
//#include <string>
//struct Pizza {
//	std::string brand;
//	double diameter;
//	double weight;
//};
//int main() {
//	Pizza* p = new Pizza;
//	std::cout << "输入披萨直径：";
//	std::cin >> p->diameter;
//
//	std::cin.ignore();//这个必须要加，因为在第一个数字输入后输入缓冲区仍然存在着一个\n，导致后面在执行getline()时会直接读入这个\n后跳过。所以需要cin.ignore()清空缓冲区
//
//	std::cout << "输入披萨品牌：";
//	getline(std::cin, p->brand);
//	std::cout << "输入披萨重量：";
//	std::cin >> p->weight;
//	std::cout << "品牌：" << p->brand << " 直径：" << p->diameter << " 重量：" << p->weight;
//
//	delete p; //delete释放内存
//	p = nullptr;//置为空指针消除悬空指针成为野指针风险
//}

////Q9.针对Q6使用new来动态分配数组，而不是声明一个包含3个元素的CandyBar数组
//#include <string>
//struct CandyBar {
//	std::string brand;
//	double weight;
//	int cal;
//};
//int main() {
//	CandyBar* arr = new CandyBar[3];
//	arr[0] = { "B1", 1.1, 1 }; //注意第一个是0
//	arr[1] = { "B2", 2.2, 2 };
//	arr[2] = { "B3", 3.3, 3 };
//
//	std::cout << "品牌：" << arr[0].brand << " 重量：" << arr[0].weight<<" 能量："<<arr[0].cal;//输出示例
//
//	delete[] arr;
//	arr = nullptr;
//}

//Q10.用户输入三次40码跑的成绩(秒)，并显示次数和平均成绩。请使用一个array对象来存储数据
//#include <array>
//
//int main() {
//	std::array<double, 3> record;
//	for (int i = 0; i < 3; i++) {
//		std::cout << "输入第" << i + 1<<"次成绩: ";
//		std::cin >> record[i];
//	}
//	double total = 0.0;
//	for (int i = 0; i < 3; i++) {	
//		total += record[i];
//	}
//	double average = total / 3;
//	std::cout << "平均成绩：" << average;
//}