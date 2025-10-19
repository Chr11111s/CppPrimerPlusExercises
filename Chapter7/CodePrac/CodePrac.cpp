#include <iostream>

//Q1.不断要求用户输入两个数，直到其中的一个为0。对于每两个数，程序将使用一个函数来计算它们的调和平均数，并将结果返回给main()，而后者报告结果。调和平均数=2.0 * x * y / ( x + y )
//double cal(double x, double y) {
//	return 2.0 * x * y / (x + y);
//}
//
//int main() {
//	int x, y;
//	std::cout << "输入两数：";
//	while (std::cin>>x>>y) {
//		if (x == 0 || y == 0)break;
//
//		else {
//			std::cout << "调和平均数：" << cal(x, y) << std::endl;
//		}
//		std::cout << "输入两数："; //找不准合理的提示位置？其实可以忽略其他语句只看cout，我们希望出现顺序为：输入两数——显示调和平均数——再次提示，那就按这样去排cout
//	}
//}

////Q2.编写程序，要求用户输入最多10个高尔夫成绩，并将其存储在一个数组中。程序允许用户提早结束输入，并在一行上显示所有成绩，然后报告平均成绩。请使用3个数组处理函数来分别进行输入、显示和计算平均成绩。
//int input(double arr[]) {
//	double score;
//	int count = 0;
//	while (count < 10) {
//		std::cin >> score;
//		if (score < 0)break;
//		arr[count] = score;
//		count++;
//	}
//	return count;
//}
//
//void show(double arr[], int count) {
//	for (int i = 0; i < count; i++) {
//		std::cout << arr[i] << " ";
//	}
//	std::cout << std::endl;
//}
//
//double get_avg(double arr[], int count) {
//	double avg;
//	double total = 0;
//	for (int i = 0; i < count; i++) {
//		total += arr[i];
//	}
//	avg = total / count;
//	return avg;
//}
//
//int main() {
//	double arr[10];
//	std::cout << "输入成绩：";
//	int count = input(arr);
//	show(arr, count);
//	double avg = get_avg(arr, count);
//	std::cout << "均绩为：" << avg;
//}

//Q3/下面是一个结构声明：
//struct box {
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
//
//a.编写一个函数，按值传递box结构，并显示每个成员
//void func1(box b) {
//	std::cout << b.maker << b.height << b.width << b.length << b.volume;
//}
//b.编写一个函数，传递box结构的地址，并将volume成员设置为其它三维长度的乘积
//void func2(box* b) {
//	b->volume = (b->height) * (b->width) * (b->length);
//	std::cout << b.maker << b.height << b.width << b.length << b.volume;
//}
//c.编写一个使用这两个函数的简单程序
//int main() {
//	box b = { "abcd", 2.5,4.0,5.5, 1.0 };
//	func1(b);
//	func2(&b);
//}

//Q4.为赢得头奖，玩家需从47个号码中选取5个正确号码以及从27个号码中选取1个正确号码，两个几率的乘积即为中头奖概率。计算这种概率
//先说结论：概率是 1 / (C(47,5) * C(27,1))，所以需要先处理C(m, n)函数
//double comb(int m, int n) {
//	double Fenzi = 1;
//	double Fenmu = 1;
//	for (int i = m; i > m - n; i--)Fenzi *= i;
//	for (int i = n; i >= 1; i--)Fenmu *= i;
//
//	return Fenzi / Fenmu;
//}
//
//int main() {
//	double res;
//	res = 1 / (comb(47, 5) * comb(27, 1));
//
//	std::cout << "头奖概率：" << res;
//}

//Q5.定义一个递归函数，接受一个整数参数，并返回该参数阶乘。
//int fac(int n) {
//	if (n == 1)return 1; //触底逻辑(后一层层返回)
//	else return n * fac(n - 1); //触底前逻辑
//}
//
//int main() {
//	int n;
//	std::cout << "输入整数：";
//	std::cin >> n;
//	std::cout<<"阶乘为："<<fac(n);
//}

//Q6.某程序使用下列函数：
//Fill_array()将一个double数组的名称和长度作为参数。它提示用户输入double值，并将这些值存储到数组中。当数组被填满或用户输入了非数字时，输入将停止，并返回实际输入了多少个数字。
//Show_array()将一个double数组的名称和长度作为参数，并显示该数组的内容。
//Reverse_array()将一个double数组的名称和长度作为参数，并将存储在数组中的值的顺序反转。
//程序将使用这些函数填充数组，然后显示数组；反转数组，然后显示数组；反转数组中除第一个和最后一个元素之外的所有元素，然后显示数组。
//int Fill_array(double arr[], size_t length) {
//	std::cout << "输入数组元素(double): " << std::endl;
//	int count = 0;
//	while (count < length) {
//		if(!(std::cin >> arr[count]))break;
//		count++;
//	}
//	return count;
//}
//
//void Show_array(double arr[], size_t length) {
//	for (int i = 0; i < length; i++) std::cout << arr[i] << " ";
//	std::cout << std::endl;
//}
//
//void Reverse_array(double arr[], size_t length) {
//	double temp;
//	for (int i = 0; i < length / 2; i++) {
//		temp = arr[i];
//		arr[i] = arr[length - 1 - i];
//		arr[length - 1 - i] = temp;
//	}
//}
//
//int main() {
//	double arr[10];
//	std::cout<<"目前已输入"<<Fill_array(arr, 10)<<"个数据"<<std::endl;
//	Show_array(arr, 10);
//	Reverse_array(arr, 10);
//	std::cout << "反转后：" << std::endl;
//	Show_array(arr, 10);
//	int temp;
//	temp = arr[0];
//	arr[0] = arr[9];
//	arr[9] = temp;
//	std::cout << "交换首尾后：" << std::endl;
//	Show_array(arr, 10);
//}

//Q7.修改程序清单7.7中的3个数组处理函数，使之使用两个指针参数来表示区间。fill_array()函数不返回实际读取了多少个数字，而是返回一个指针，该指针指向最后被填充的位置；其它的函数可以将该指针作为第二个参数，以标识数据结尾
//double* fill_array(double* begin, double* end) {
//	double temp;
//	double* p = begin;
//
//	while (p != end) {
//		std::cout << "输入元素：";
//		std::cin >> temp;
//		*p = temp; //只有解引用才能将值存入数组!!!!
//		p++;
//	}
//	return p;
//}
//
//void show_array(double* begin, double* end) {
//	std::cout << "数组元素分别为：";
//	double* p = begin;
//	while (p != end) {
//		std::cout << *p << " ";
//		p++;
//	}
//	std::cout << std::endl;
//}
//
//double sum_of_array(double* begin, double* end) {
//	double sum = 0;
//	double* p = begin;
//	while (p != end) {
//		sum += *p;
//		p++;
//	}
//	return sum;
//}

//Q8.在不使用array类的情况下完成程序清单7.15所做的工作。编写两个这样的版本：
//a.使用const char* 数组存储表示季度名称的字符串，并使用double数组存储开支
//b.使用const char* 数组存储表示季度名称的字符串，并使用一个结构，该结构只有一个成员——一个用于存储开支的double数组。这种设计与使用array类的基本设计类似

//常用的创建存储多个字符串的数组的方式只有以下四种：
//① char* arr[] = {"str1", "str2", "str3"...}
//② char arr[m][n] = {...} //存储m个字符串，每个字符串长度最多为n-1，因为要每个都要包含\0结束符
//③ std::string arr[] = {...}
//④ vector<std::string> arr = {...} 或vector<char*> arr = {...} //记住vector创建数组是不加[]的！！！！

//a
//const char* arr[4] = { "Q1", "Q2", "Q3","Q4" };
//double cost[4] = { 100,200,300,400 };
//
////b
//struct a {
//	double cost[4];
//};
//const char* arr[4] = { "Q1","Q2","Q3","Q4" };
//a cost_data = { {100,200,300,400} };

//Q9.根据程序框架补全函数 //就这样吧，魔改成了自己喜欢的格式
//#include <string>
//struct student {
//	std::string fullname;
//	std::string hobby;
//	int ooplevel;
//};
////getinfo()有两参数：一个指向student结构的数组首元素的指针，以及一个int值表示数组元素数量。这个函数获取并存储学生的数据，并返回实际元素的数目。
//int getinfo(student pa[], int n) {
//	int count = 0;
//	while (count < n) {
//		std::cin.ignore();
//		getline(std::cin, pa[count].fullname);
//		getline(std::cin, pa[count].hobby);
//		std::cin >> pa[count].ooplevel;
//		count++;
//	}
//
//	return count;
//}
//
////display1()获取student结构作为参数并且显示其内容
//void display1(student st) {
//	std::cout << st.fullname << st.hobby << st.ooplevel << std::endl;
//}
//
////display2()获取student结构体的地址作为参数并且显示结构体内容
//void display2(const student* ps) {
//	std::cout << ps->fullname << ps->hobby << ps->ooplevel << std::endl;
//}
//
////display3()获取student结构体中一个数组的首元素地址以及数组元素数量作为参数并显示结构体内容
//void display3(const student pa[], int n) {
//	for (int i = 0; i < n; i++) {
//		std::cout << pa[i].fullname << pa[i].hobby << pa[i].ooplevel<<std::endl;
//	}
//}
//
//int main() {
//	std::cout << "Enter class size: ";
//	int class_size;
//	std::cin >> class_size;
//	while (std::cin.get() != '\n') continue;
//
//	student* ptr_stu = new student[class_size];
//	int entered = getinfo(ptr_stu, class_size);
//	for (int i = 0; i < entered; i++) {
//		display1(ptr_stu[i]);
//		display2(&ptr_stu[i]);
//	}
//	display3(ptr_stu, entered);
//	delete[] ptr_stu;
//	ptr_stu = nullptr;
//	std::cout << "Done\n";
//	return 0;
//}

//Q10.设计double类型calculate()函数，接受两个double值和一个指向函数的指针，而被指向的函数接受两个double参数，并返回一个double值。calculate()函数返回被指向的函数的使用calculate()的两个double参数计算得到的值。
//假设add()函数定义如下,也就是说calculate()是调用其他函数的函数
//double add(double x, double y) {
//	return x + y;
//}
//
//double calculate(double a, double b, double(*func)(double, double)) { //形参是指向其它函数的指针的设计(死记硬背)：指向函数的返回值类型(*func)(指向函数形参类型)
//	return func(a, b);
//}