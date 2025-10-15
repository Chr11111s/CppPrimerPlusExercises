#include <iostream>

//Q1.用户输入两个整数，计算输出这两个整数之间(包括这两个整数)所有整数的和。
//int main() {
//	int m, n;
//	std::cout << "输入两个整数(小的在前大的在后)：";
//	std::cin >> m >> n;
//	int res = 0;
//	for (int i = m; i <= n; i++) {
//		res += i;
//	}
//	std::cout << res;
//}

//Q2.使用array对象和long double编写程序(数组存储对应下标阶乘)，计算100!的值。
//#include <array>
//int main() {
//	std::array<long double, 101> factorials;
//	factorials[1] = factorials[0] = 1;
//
//	for (int i = 2; i < 101; i++) {
//		factorials[i] = i * factorials[i - 1];
//	}
//	std::cout << "100! = " << factorials[100];
//}

//Q3.用户输入数字。每次输入后，程序都将报告到目前为止，所有输入的累计和。用户输入0结束
//int main() {
//	double res = 0;
//	double i;
//	while (true) {  //循环次数不确定就用while，次数确定就用for
//		std::cout << "输入数字：";
//		std::cin >> i;
//		if (i == 0)break;
//		res += i;
//		std::cout << "当前总和："<<res<<std::endl;
//	}
//	std::cout << "循环已退出。";
//}

//Q4.D以10%的单利投资100美元，每年固定10元利润。C以5%复利投资100美元，每年获得当前存款5%利润。多少年后C的总资产会大于D的？
//int main() {
//	int i = 0;
//	double total_D = 100;
//	double total_C = 100;
//	while (1) {
//		total_D += 10;
//		total_C *= 1.05;
//		i++;
//		if (total_C > total_D) break;
//	}
//	std::cout << "第" << i << "年C超D";
//}

//Q5.销售一本书，编写程序输入全年每个月销售量。程序通过循环，使用初始化为月份字符串的char*数组(或string对象数组)逐月进行提示，并将输入数据存在一个int数组里。计算一年总销售量。
//#include <string>
//int main() {
//	std::string month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
//	int arr[12];
//	for (int i = 0; i < 12; i++) {
//		std::cout << "现在是" << month[i] << ", 输入本月销售量(本)：";
//		std::cin >> arr[i];
//	}
//
//	int res = 0;
//	for (int i = 0; i < 12; i++) {
//		res += arr[i];
//	}
//	std::cout << "总销售量：" << res<<"本";
//}

//Q6.用一个二维数组存储输入---3年中每个月的销售量。程序将报告每年销售量及三年总销售量
//#include <string>
//
//int main() {
//	std::string month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//	int arr[3][12];
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 12; j++) {
//			std::cout << "现在是第" << i+1 << "年" << month[j] << ", 输入这个月的销售量：";
//			std::cin >> arr[i][j];
//		}
//	}
//	int each_year = 0;
//	int all_years = 0;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 12; j++) {
//			each_year += arr[i][j];
//		}
//		std::cout << "第" << i+1 << "年的销售量为：" << each_year<<std::endl;
//		all_years += each_year;
//		each_year = 0;
//	}
//	std::cout << "三年总销售量为: " << all_years;
//}

//Q7.设计一个名为car的结构，存储生产商、生产年份。编写程序询问用户有几辆车。随后程序使用new创建一个有相应数量的car结构组成的动态数组。接下来程序提示用户输入每辆车的生产商(可能由多个单词组成)和年份信息。注意是交替读取字符串和数值。
//最后显示每个结构内容

//#include <string>
//
//struct car {
//	std::string brand;
//	int produced_year;
//};
//int main() {
//	int n;
//	std::cout << "你准备买几辆车：";
//	std::cin >> n;
//	std::cin.ignore(); //注意在读取完数字后如果下一个数据用getline()读取则需要立即在这个读取数字的cin下一行写上cin.ignore()去忽略\n换行符以防getline()异常结束
//	car* p = new car[n];
//
//	for (int i = 0; i < n; i++) {
//		std::cout << "Car #" << i + 1 << ":" << std::endl;
//		std::cout << "Enter the make: ";
//		getline(std::cin, p[i].brand); //结构体数组用.而非->指代数据
//		std::cout << "Enter the year made: ";
//		std::cin >> p[i].produced_year;
//		std::cin.ignore();
//	}
//	std::cout << "Here is your collection: " << std::endl;
//	for (int i = 0; i < n; i++) {
//		std::cout << p[i].produced_year<<" "<<p[i].brand<<std::endl;
//	}
//
//	delete[] p; //切记创建动态数组后一定要delete掉并置为空指针
//	p = nullptr;
//}

//Q8.使用char数组和循环来每次读取一个单词，直到用户输入done为止。随后指出用户一共输入了多少个单词(不算done)
//int main() {
//	char word[100];//记录每次读取的单词，每次会被下一个覆盖
//	int count = 0;
//	std::cout << "开始输入单词: " << std::endl;
//	while (true) {
//		std::cin >> word;
//		count++;
//		if (!strcmp(word, "done")) {//strcmp()在两个单词相同时返回0
//			count--;
//			break;
//		}
//	}
//	std::cout << "已输入" << count << "个单词";
//}

//Q9.使用string对象完成Q8
//#include <string>
//int main() {
//	std::string word;
//	int count = 0;
//	std::cout << "开始输入单词：" << std::endl;
//	while (true) {
//		std::cin >> word;
//		count++;
//		if (word == "done") { //string可以直接用关系符比较
//			count--;
//			break;
//		}
//	}
//	std::cout << "已输入" << count << "个单词";
//}

//Q10.编写嵌套循环程序，要求用户输入一个值，指出显示多少行。然后程序显示相应行数的星号，其中第一行包含一个星号，第二行两个...每一行字符数等于输入值，不够用‘.’凑。
//int main() {
//	int n;
//	std::cout << "输入行数：";
//	std::cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - (i + 1); j++) std::cout << '.';
//		for (int k = 0; k < i + 1; k++)std::cout << '*';
//		std::cout << std::endl;
//	}
//}