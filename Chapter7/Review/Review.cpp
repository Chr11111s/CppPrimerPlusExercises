//Q1.使用函数的3个步骤
//声明、定义、调用(传参)
//
//Q2.创建与下面的描述匹配的函数原型
//a.igor()没有参数，且没有返回值---void igor()
//b.tofu()接受一个int参数，并返回一个float---float tofu(int n)
//c.mpg()接受两个double参数，并返回一个double--double mpg(double m, double n)
//d.summation()将long数组名和数组长度作为参数，并返回一个long值---long summation(long arr[], size_t length) //size_t常用于表示容器长度，其无符号整型特性确保不会出现负数
//e.doctor()接受一个字符串参数(不能修改该字符串)，并返回一个double值---double doctor(const std::string& str) //当传入对象较大时(如大数组、字符串、复杂类等)使用&，且用const保证不被外部修改
//f.ofcourse()将boss结构作为参数，不返回值---void ofcourse(struct boss b) //确保结构体boss已经定义
//g.plot()将map结构的指针作为参数，并返回一个字符串---std::string plot(map* p)
//
//Q3.编写一个接受3个参数的函数：int 数组名、数组长度和一个int值，并将数组所有元素都设置为该int值
//void func(int arr[], size_t length, int x) { //数组作为函数参数时不需要使用引用符号 &，只需要传递 int arr[] 或 int* arr，这会自动按引用传递数组。
//	for (int i = 0; i < length; i++) arr[i] = x;
//}
//
//Q4.编写一个接受3个参数的函数：指向数组区间中第一个元素的指针、指向数组区间最后一个元素后面的指针以及一个int值，并将数组中每个元素都设置为该int值。并将数组中每个元素都设置为该int值
//void func(int* begin, int* end, int value) {
//	while (begin != end) {
//		*begin = value;
//		begin++;
//	}
//}
//
//Q5.将double数组名和数组长度作为参数，并返回该数组中最大值。该函数不应修改数组的内容
//double func(double arr[], size_t length) {
//	if (length == 0)return 1; //数组长度为0则报错
//	double max = arr[0]; //将max初始化为arr[0]而不是0避免出现负数数组比不了情况
//	for (int i = 0; i < length; i++) {
//		if (arr[i] > max) max = arr[i];
//	}
//	return max;
//}
//
//Q6.为什么不对类型为基本类型的函数参数使用const限定符
//因为就算不用const函数内部也改变不了原始数据
//
//Q7.C++程序可使用哪3种C风格字符串格式
//字符数组：通过字符数组存储字符串，char str[] = "Hello";
//
//字符指针：通过字符指针指向字符串，const char* str = "Hello";
//
//常量字符指针：指针本身是常量，不能修改指针，但可以修改内容，char* const str = "Hello"; 
//
//Q8.函数原型如下：int replace(char* str, char c1, char c2); 该函数将字符串中所有c1替换成c2，并返回替换次数
//int replace(char* str, char c1, char c2) {
//	int count = 0;
//	while (*str != '\0') { //这是C风格字符串，没有end()成员，所以得解引用看*str是不是\0来判断有没有到末尾
//		if (*str == c1) *str = c2;
//		count++;
//		str++;
//	}
//	return count;
//}
//
//Q9.表达式*"pizza"的含义是什么？"taco"[2]呢？
//C++中，字符串常量就是一个指向字符数组的指针。
//所以"pizza"本质是一个指向这个字符串的指针，指向其第一个字符，("pizza" -> {'p', 'i', 'z', 'z', 'a', '\0'})，所以将其解引用后就是'p'
//"taco"[2]是对字符数组下标为2的元素访问，即为'c'
//
//Q10.C++允许按值传递结构，也允许传递结构的地址。如果glitz是一个结构变量，如何按值传递它？如何传递它的地址？这两种方式有何利弊？
//struct Glitz {
//	int value;
//};
////按值传递：
//void func(Glitz g) {
//	g.value = 1; //按值传递时，函数接收到的是结构体的副本，也就是说函数内部对结构体的修改不会影响到原始结构体。
//}
//int main() {
//	Glitz g = { 0 };
//	func(g);
//	cout << g.value;//由于更改的只有副本所以输出初始化给它的值，即为0
//}
//
////按地址传递(传指针)
//void func(Glitz* g) {
//	g->value = 1;
//}
//int main() {
//	Glitz g = { 0 };
//	func(&g);//记住形参有*调用时实参要加&!!!!!!!!
//	cout << g.value;//传地址即能改变原始数据，故输出1
//}
//
////按地址传递(传引用)
//void func(Glitz& g) {
//	g.value = 1;
//}
//int main() {
//	Glitz g = { 0 };
//	func(g);//函数声明时若形参是&引用，则相当于直接对原始对象操作，仅需不加任何修饰地传入对象即可
//	cout << g.value;
//}
//
//综上，按值传递适用于数据较小且不需要修改原始数据的情况，保证了数据的安全性；按地址传递适用于数据较大且需要在函数中修改原始数据的情况，但需要小心副作用和指针的管理。
//
//Q11.函数judge()返回类型为int，它将这样一个函数的地址作为参数：将const char指针作为参数，并返回一个int值。编写judge()函数的原型
//int judge(const char* p)
//
//例如：
//int judge(const char* p) {
//	if (p == nullptr) {
//		return -1;  // 如果传入的指针为空，则返回 -1
//	}
//
//	// 假设我们根据字符串的长度返回不同的值
//	int length = 0;
//	while (p[length] != '\0') {//C++特性，指针直接当数组使
//		length++;
//	}
//
//	return length;  // 返回字符串的长度
//}
//
//int main() {
//	const char* testStr = "Hello, world!";
//	int result = judge(testStr);
//	std::cout << "The length of the string is: " << result << std::endl;  // 输出字符串的长度
//	return 0;
//}
//
//Q12.假设有如下结构声明：
//struct applicant {
//	char name[30];
//	int credit_ratings[3];
//};
//a.编写函数，它将applicant结构作为参数，并显示该结构的内容
//void func(applicant a) {
//	cout << a.name << a.credit_ratings;
//}
//int main() {
//	applicant a = { a, b };
//	func(a);
//}
//b,编写函数，它将applicant结构的地址作为参数，并显示该参数指向的结构的内容
//void func(applicant* a) {
//	cout << a->name << a->credit_ratings;
//}
//int main() {
//	applicant a = { a, b };
//	func(&a);
//}
//
//Q13.假设函数f1()和f2()的原型如下：
//void f1(applicant* a);
//const char* f2(const applicant* a1, const applicant* a2);
//请将p1和p2分别声明为指向f1和f2的指针；将ap声明为一个数组，它包含5个类型于p1相同的指针；将pa声明为一个指针，它指向的数组包含10个类型与p2相同的指针。使用typedef辅助完成任务。
//
//// 使用 typedef 定义函数指针类型
//typedef void (*f1_ptr)(applicant*);
//typedef const char* (*f2_ptr)(const applicant*, const applicant*);
//
//int main() {
//	// 声明指向 f1 和 f2 的函数指针
//	f1_ptr p1;
//	f2_ptr p2;
//
//	// 初始化指向 f1 和 f2 函数的指针
//	p1 = f1;
//	p2 = f2;
//
//	// 声明指针数组 ap 和 pa
//	f1_ptr ap[5];  // ap 是一个包含 5 个指向 f1 函数的指针的数组
//	f2_ptr(*pa)[10];  // pa 是一个指向包含 10 个指向 f2 函数的指针的数组的指针
//
//	// 使用函数指针进行调用
//	applicant a = { "John Doe", {800, 700, 900} };
//	p1(&a);  // 调用 f1
//
//	cout << p2(&a, &a) << endl;  // 调用 f2