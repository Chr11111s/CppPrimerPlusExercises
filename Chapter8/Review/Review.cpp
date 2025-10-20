//Q1.哪种函数适合定义为内联函数——逻辑简单且短小，需要频繁调用
//
//Q2.假设song()函数的原型如下：void song(const char* name, int times);
//a.如何修改原型，使times的默认值为1？
//void song(const char* name, int times = 1)
//b.函数定义需要做哪些修改？
//定义中不需要再次为times提供默认值
//c.能否为name提供默认值"O.My Papa"？
//当然可以，void song(const char* name = "O.My Papa", int times = 1);
//同时，调用参数时也可以传入新的不一样的实参覆盖掉默认值。
//
//Q3.编写iquote()的重载版本——显示其用双引号括起的参数。编写3个版本：一个用于int参数，一个用于double参数，另一个用于string参数。
//void iquote(int n);
//void iquote(double n);
//void iquote(std::string& str); //其实这里直接std::string str传值也是可以的，但这样做会将string对象复制到函数内部导致额外内存复制，字符串较大时会影响程序性能。
//
//Q4.结构模板如下：
//struct box {
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
//a.编写函数，它将box结构的引用作为形参，并显示每个成员的值
//void func1(box& b) {
//	std::cout << b.maker << b.height << b.width << b.length << b.volume;
//}
//b.编写函数，它将box结构的引用作为形参，并将volume成员设置为其它三边的乘积
//void func2(box& b) {
//	b.volume = b.height * b.width * b.length;
//}
//
//Q5.修改程序，使函数fill()和show()使用引用参数
//#include <iostream>
//#include <array>
//#include <string>
//
//const int Seasons = 4;
//const std::array<std::string, Seasons> Snames = { "Spring","Summer","Fall","Winter" };
//
//void fill(std::array<double, Seasons>* pa);
//void show(std::array<double, Seasons>da);
//
//int main() {
//	std::array<double, Seasons> expenses;
//	fill(&expenses);
//	show(expenses);
//	return 0;
//}
//
//void fill(std::array<double, Seasons>* pa) {
//	using namespace std;
//	for (int i = 0; i < Seasons; i++) {
//		cout << "Enter" << Snames[i] << "expenses: ";
//		cin >> (*pa)[i]; //需要解引用指针才能修改数组内容，对于结构体则是p->member;对于动态创建的结构体数组则是p[i].member
//	}
//}
//
//void show(std::array<double, Seasons> da) {
//	using namespace std;
//	double total = 0.0;
//	cout << "\nEXPENSES\n";
//	for (int i = 0; i < Seasons; i++) {
//		cout << Snames[i] << ": $" << da[i] << endl;
//		total += da[i];
//	}
//	cout << "Total Expenses: $" << total << endl;
//}
//
////修改后
//void fill(std::array<double, Seasons>&pa);
//void show(std::array<double, Seasons>&da);
//
//int main() {
//	std::array<double, Seasons> expenses;
//	fill(expenses); //声明用&后调用时可以不加修饰直接传
//	show(expenses); //声明用&后调用时可以不加修饰直接传
//	return 0;
//}
//
//void fill(std::array<double, Seasons>&pa) {
//	using namespace std;
//	for (int i = 0; i < Seasons; i++) {
//		cout << "Enter" << Snames[i] << "expenses: ";
//		cin >> pa[i]; //直接修改数组内容
//	}
//}
//
//void show(std::array<double, Seasons>&da) {
//	using namespace std;
//	double total = 0.0;
//	cout << "\nEXPENSES\n";
//	for (int i = 0; i < Seasons; i++) {
//		cout << Snames[i] << ": $" << da[i] << endl;
//		total += da[i];
//	}
//	cout << "Total Expenses: $" << total << endl;
//}
//
//Q6.指出下面每个目标是否可以使用默认参数或函数重载完成，或者这两种方法都无法完成，并提供合适的原型
//a.mass(density, volume)返回密度为density、体积为volume的物体的质量，而mass(density)返回密度为density、体积为1.0立方米的物体的质量。这些值类型均为double
//double mass(double density, double volume) {
//	return density * volume;
//}
//
//double mass(double density, double volume = 1.0) { //默认参数必须出现在函数声明里！！！
//	return density * volume;
//}
//
//b.repeat(10,"I'm OK")将指定的字符串显示10次，而repeat("But you're kind of stupid")将指定的字符串显示5次
//void repeat(times, std::string& str) {
//	for (int i = 0; i < times; i++)std::cout << str << std::endl;
//}
//
//void repeat(std::string& str) {
//	for (int i = 0; i < 5; i++)std::cout << str << std::endl;
//}
//
//c.average(3,6)返回两个int参数的平均值(int 类型)，而average(3.0,6.0)返回两个double值的平均值(double类型)
//int average(int a, int b) {
//	return (a + b) / 2;
//}
//
//double average(double a, double b) { //函数重载只看参数类型以及参数数量的，返回值类型无所谓
//	return (a + b) / 2;
//}
//
//d.mangle("I'm glad to meet you")根据是将值赋给char变量还是char* 变量，分别返回字符I和指向字符串"I'm mad to gleet you"的指针
//这个目标不适合使用函数重载，原因是 C++ 中 不能将 char[] 与 char* 类型作为重载的参数类型。它们都被视为指针类型，无法仅通过类型来区分。对于这种情况，最好使用类型识别（typeid）或模板来实现。
////使用模板实现
//#include <iostream>
//
////模板重载：mangle() 函数是模板函数，可以接受任何类型的参数。
//template <typename T>
//char mangle(T arr) {
//	return 'I';  // 如果是 char 数组，返回 'I'
//}
//
//template <> //显式具体化：通过特化模板（template <>），针对 char* 类型返回特定的值 "I'm mad to gleet you"。
//char* mangle<char*>(char* arr) {
//	return "I'm mad to gleet you";  // 如果是 char*，返回字符串指针
//}
//
//int main() {
//	char arr[] = "I'm glad to meet you";
//	char* ptr = arr;
//
//	std::cout << mangle(arr) << std::endl;  // 输出 'I'
//	std::cout << mangle(ptr) << std::endl;  // 输出 "I'm mad to gleet you"
//
//	return 0;
//}
//
//Q7.编写返回两个参数中较大值的函数模板
////在 C++ 中，普通函数必须明确指定类型(int/double)——这会导致大量重复代码。为了解决这种类型重复问题，C++ 引入了 模板机制：允许你写一个「类型不确定」的函数或类，在编译时再由编译器根据实参自动推导出类型。
////而关键中的关键，就是typename。整体是template<typename T>，这个typename可以辅助编译器识别任意类型数据，之后用T就能指代任何类型数据了。这一行不存在逗号
//
//template<typename T> //一般名字都叫T
//T max(T& a, T& b) {
//	return (a > b) ? a : b;
//}
//
//Q8.给定Q7中模板和Q4的box结构，提供一个模板具体化，它接受两个box参数，并返回体积较大的那个box
//struct box {
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
////通用模板
//template<typename T>
//T bigger(T& a, T& b) { //避免与标准库里的max函数重名
//	return (a > b) ? a : b;
//}
////针对 box 类型的显式具体化。它告诉编译器：当你发现模板参数是 box 类型时，不要用上面那个通用模板，而是用我这里写的“特制版本”。其实不用模板直接这么写也行，但是为了符合题意嘛！
//template<>
//box bigger(box& a, box& b) {
//	return (a.volume > b.volume) ? a : b;
//}
//
//int main() {
//	box a = { "abc",1.0, 2.0,3.0, 6.0 };
//	box b = { "ccb", 10.0,20.0,30.0,6000.0 };
//	
//	box bigger = bigger(a, b);
//	std::cout << bigger.maker << "的箱子更大";
//}
//
//Q9.在下述代码中，v1—v5分别是哪种类型
//int g(int x);
//...
//float m = 5.5f;
//float& rm = m;
//decltype(m) v1 = m; //float
//decltype(rm) v2 = m; //float&
//decltype((m)) v3 = m; //float&
//decltype(g(100)) v4; //int
//decltype(2.0 * m) v5; //double
//
//其实只需要注意加修饰的就行了(比如(x)是x&/func(x)是函数返回值类型)，其他的本身是啥就是啥
//
///*
//🧩 一、规则回顾（C++ Primer Plus 第8章补充内容）
//
//decltype(expr) 的类型推导遵循以下规则：
//
//①如果表达式是一个不加括号的标识符（变量名），则结果类型为该变量的声明类型。
//
//int a;  decltype(a)  → int
//
//
//②如果表达式是一个左值（加了括号的变量名），则结果为 T& （引用类型）。
//
//int a; decltype((a)) → int&
//
//
//③如果表达式是右值（如算术表达式、函数返回值），结果就是它的值类型。
//
//decltype(2 + 3.0) → double
//
//
//④函数调用表达式的 decltype 结果是该函数的返回类型。
//
//🧠 二、逐个分析：
//🔹1️⃣ decltype(m) v1 = m;
//
//m 是一个普通变量（float 类型）。
//
//规则①：表达式是变量名 → 返回它的声明类型。
//
//✅ v1 的类型是： float
//
//🔹2️⃣ decltype(rm) v2 = m;
//
//rm 是一个 float& （引用类型）。
//
//规则①：表达式是变量名 → 返回变量的声明类型（保持引用属性）。
//
//✅ v2 的类型是： float&
//
//🔹3️⃣ decltype((m)) v3 = m;
//
//注意这里有 括号：(m) 是一个表达式，不是变量名。
//
//规则②：表达式是左值 → 推导为引用类型。
//
//✅ v3 的类型是： float&
//
//（⚠️ 这是 decltype 最常考陷阱点：多了括号就变引用）
//
//🔹4️⃣ decltype(g(100)) v4;
//
//g(100) 是函数调用表达式。
//
//根据规则④，decltype 取函数返回类型。
//
//题中：int g(int x);
//
//✅ v4 的类型是： int
//
//🔹5️⃣ decltype(2.0 * m) v5;
//
//2.0 是 double 字面值。
//
//m 是 float。
//
//表达式 2.0 * m 会按 usual arithmetic conversion 转换为 double。
//
//✅ v5 的类型是： double
//*/