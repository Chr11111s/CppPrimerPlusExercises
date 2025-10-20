#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//Q1.编写通常接受一个参数(字符串的地址)，并打印该字符串的函数。然而，若提供了第二个参数(int类型)，且该参数不为0，则该函数打印字符串的次数将为该函数被调用的次数(注意，字符串的打印次数不等于第二个参数的值，而等于函数被调用次数)
//核心思路：我们可以利用一个 静态局部变量（static） 来记录函数被调用的次数。静态局部变量在函数退出后不会销毁，下次调用会保留上次的值。
//#include <string>
//void printStr(const char* str, int flag = 0) { //默认参数为0确保忘记调用时传入flag参数时程序也能正常运行
//	static int count = 0;
//	count++; //读题，count必须放在开头否则如果第一次调用就带非零参数打印次数就是0了
//	if (flag == 0) std::cout << str << std::endl;
//	else {
//		for (int i = 0; i < count; i++) {
//			std::cout << str << std::endl; //注意到这里和上方都是直接输出str而没有加*解引用，因为当 std::cout 遇到 char* 或 const char* 参数时，会调用标准库中为字符串指针重载的 operator<<。该版本会自动输出从该地址开始、直到遇到 '\0' 为止的所有字符。因此 cout << str 会打印整个字符串，而 * str 只表示首字符。
//		}
//	}
//}
//
//int main() {
//	//如果是std::string* str的话，就要先std::string s = "Fuck u"，然后传入printStr(&s)，不能直接传字符串。
//	printStr("Fuck u");//对于形参为const char* str可以直接传字符串调用，因为被传给函数时会自动退化成const char*指针
//	printStr("Fuck u", 2);
//}

//Q2.CandyBar结构包含3个成员。第一个成员存储candy bar的品牌名称；第二个成员存储candy bar的重量(可能有小数)；第三个成员存储candy bar的热量(整数)。
//编写程序，使用将CandyBar的引用、char指针、double和int作为参数的函数，并用最后3个值设置相应的结构成员。最后3个参数的默认值分别为"Millennium Munch"、2.85和350。另外，该程序还包含一个以CandyBar的引用为参数，并显示结构内容的函数。
//尽可能使用const
//#include <cstring>   // 为了strcpy()
//struct CandyBar {
//	char brand[30];
//	double weight;
//	int cal;
//};
//
//void setInfo(CandyBar& cb, const char* brand = "Millennium Munch", double weight = 2.85, int cal = 350) {
//	std::strcpy(cb.brand, brand); //cb.brand 是一个 字符数组（char[30]），而数组名在 C++ 中不是可赋值的左值，不能用 = 给它整体赋值。只能用<cstring>中的strcpy()赋值
//	cb.weight = weight;
//	cb.cal = cal;
//}
//
//void showInfo(CandyBar& cb) {
//	std::cout << cb.brand <<" " << cb.weight << " " << cb.cal<<std::endl;
//}
//
//int main() {
//	CandyBar cb;
//	setInfo(cb);
//	showInfo(cb);
//
//	setInfo(cb, "Fucker God", 6.66, 666);
//	showInfo(cb);
//}

//Q3.编写函数，它接受一个指向string对象的引用作为参数，并将该string对象的内容转换为大写，可使用toupper()函数(在<cctype>中)。编写程序使用一个循环持续读入转换，直到输入q结束。
//#include <string>
//#include <cctype>
//
//void toUpper(std::string& s) {
//	for (int i = 0; i < s.size(); i++) s[i] = std::toupper(s[i]);
//}
//
//int main() {
//	std::string s;
//
//	std::cout << "Enter a string(q to quit): "<<std::endl;
//	while (getline(std::cin, s)) {
//		if (s == "q")break;
//		else {
//			toUpper(s);
//			std::cout << s << std::endl;
//		}
//		std::cout << "Next string(q to quit): ";
//	}
//	std::cout << "Bye.";
//}