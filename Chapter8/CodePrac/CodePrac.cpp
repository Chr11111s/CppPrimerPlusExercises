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

//Q4.下面为一个程序框架，存在两个show()函数，且都使用默认参数。尽可能使用const参数。set()使用new分配足够的空间存储指定的字符串，
//#include <cstring> //strlen()，strcpy()
//struct stringy {
//	char* str; //points to a string
//	int ct; //length of string (not counting '\0')
//};
//
//void set(stringy& beany, const char* testing) {
//	beany.ct = strlen(testing);
//	beany.str = new char[beany.ct + 1]; //因为结构体中str定义就是char*，这里我是第一次见
//	strcpy(beany.str, testing);
//}
//
//void show(stringy& beany, int count = 1 ) { //针对前两个show()
//	std::cout << beany.str << std::endl;
//}
//
//void show(const char* str, int count = 1) { //针对后两个show()
//	for (int i = 0; i < count; i++) std::cout << str << std::endl;
//}
//
//int main() {
//	stringy beany;
//	char testing[] = "Reality isn't what it used to be.";
//
//	set(beany, testing); //first argument is a reference, allocates space to hold copy of testing, sets str member of beany to point to the new block, copies testing to new block, and sets ct member of beany
//	show(beany); //prints member string once
//	show(beany, 2); //prints member of string twice
//	testing[0] = 'D';
//	testing[1] = 'u';
//	show(testing); //prints testing string once
//	show(testing, 3); //prints testing string thrice
//	show("Done!");
//	return 0;
//}

//Q5.编写模板函数max5()，它将一个包含5个T类型元素的数组作为参数，并返回数组中最大的元素(由于长度固定，因此可以在循环中使用硬编码，而不必通过参数来传递)。在程序中使用该函数，将T替换为一个包含5个int值的数组和一个包含5个double值的数组测试函数。
//template<typename T>
//T max_one(T arr[5]) {
//	T maxOne = arr[0];
//	for (int i = 0; i < 5; i++) {
//		if (arr[i] > maxOne) maxOne = arr[i];
//	}
//	return maxOne;
//}
//
//int main() {
//	int arr1[5] = { 1,2,3,4,5 };
//	std::cout << max_one(arr1);
//	std::cout << std::endl;
//	double arr2[5] = { 1.1,2.2,3.3,4.4,5.5 };
//	std::cout << max_one(arr2);
//}

//Q6.编写模板函数maxn()，它将由一个T类型元素组成的数组和一个表示数组元素数目的整数作为参数，并返回数组中最大的元素。在程序中测试它，该程序使用一个包含6个int元素的数组和一个包含4个double元素的数组来调用该函数。
//程序还包含一个具体化，它将char指针数组和数组中的指针数量作为参数，并返回最长的字符串的地址。如果有多个这样的字符串则返回其中第一个字符串的地址。使用由5个字符串指针组成的数组来测试该具体化
//#include <cstring> //strlen()
//template<typename T>
//T max_one(T arr[], int count) {
//	T maxOne = arr[0];
//	for (int i = 0; i < count; i++) {
//		if (maxOne < arr[i])maxOne = arr[i];
//	}
//	return maxOne;
//}
//
//template<>
//char* max_one(char* arr[], int count) {
//	if (count == 0)return nullptr; //若数组为空调用strlen()就会导致程序崩溃，应加入数组为空直接返回空指针保障安全。
//
//	int longest = strlen(arr[0]);
//	for (int i = 0; i < count; i++) {
//		if (longest < strlen(arr[i])) longest = strlen(arr[i]);
//	}
//	for (int i = 0; i < count; i++) {
//		if (strlen(arr[i]) == longest) {
//			return arr[i]; //break是多余的，因为return会直接跳出当前函数(连带着循环一起)，也不需要有指针指向arr[i]，因为arr[i]本身就是指针，return arr[i]就是返回其地址
//
//		}
//	}
//}

//Q7.修改程序使其使用两个名为SumArray()的模板函数来返回数组元素的总和，而不是显示数组的内容。程序应显示thing的总和以及所有debt的总和。
//template<typename T>
//T SumArray(T arr[], int n);
//
//template<typename T>
//T SumArray(T* arr[], int n);
//
//struct debts {
//	char name[50];
//	double amount;
//};
//
//int main() {
//	using namespace std;
//	int things[6] = { 13,31,103,301,310,130 };
//	struct debts mr_E[3] =
//	{
//		{"Ima Wolfe", 2400.0},
//		{"Ura Foxe", 1300.0},
//		{"Iby Stout", 1800.0}
//	};
//	double* pd[3];
//
//	for (int i = 0; i < 3; i++) pd[i] = &mr_E[i].amount;
//	cout << "Listing Mr.E's counts of things:"<< SumArray(things, 6);
//	cout << "Listing Mr.E's debts:"<<SumArray(pd, 3);
//	return 0;
//}
//
//template<typename T>
//T SumArray(T arr[], int n) {
//	using namespace std;
//	T total = 0;
//	cout << "template A\n";
//	for (int i = 0; i < n; i++) total += arr[i];
//	return total;
//}
//
//template<typename T>
//T SumArray(T* arr[], int n) {
//	using namespace std;
//	T total = 0;
//	cout << "template B\n";
//	for (int i = 0; i < n; i++)total += *arr[i];
//	return total;
//}