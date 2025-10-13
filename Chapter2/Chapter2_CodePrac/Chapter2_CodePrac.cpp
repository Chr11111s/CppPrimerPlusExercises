#include <iostream>

/*
Q1.编写程序,显示您的姓名与地址
int main(){
	cout << "姓名：Chris，地址：阿弥诺斯星" << endl;
}
*/


/*
Q2.编写程序，要求用户输入一个以long为单位的距离，然后将其转换为码(1 long = 220 码)
int main() {
	int dis, res;
	std::cout << "输入距离(long): ";
	std::cin >> dis;
	res = dis * 220;
	std::cout << "转换后距离为：" << res << "码";
}
*/


//Q3.编写程序，它使用3个用户定义的函数(包括main()),并生成下面的输出：
//Three blind mice
//Three blind mice
//See how they run
//See how they run
//其中一个函数要调用两次，该函数生成前两行；另一个函数也被调用两次，并生成其余的输出
//
//void first2lines(){
//	std::cout<<"Three blind mice"<<std::endl;
//	std::cout<<"Three blind mice"<<std::endl;
//}
//
//void second2lines(){
//	std::cout<<"See how they run"<<std::endl;
//	std::cout<<"See how they run"<<std::endl;
//}
//
//int main(){
//	first2lines();
//	second2lines();
//}

//Q4.编写程序，让用户输入其年龄，然后显示该年龄包含多少个月，例如29岁包含348个月
//int main() {
//	int age;
//	std::cout << "Enter your age: ";
//	std::cin >> age;
//	std::cout << "Your age in months is: " << age * 12 << ".";
//}

//Q5.编写程序，其中main()调用一个用户定义的函数(以摄氏温度值为参数，并返回相应的华氏温度)。已知华氏温度 = 1.8 x 摄氏温度 + 32.0
//double trans(double cel) {
//	return cel * 1.8 + 32.0;
//}
//
//int main() {
//	double cel, fah;
//	std::cout << "Please enter a Celsius value: ";
//	std::cin >> cel;
//	fah = trans(cel);
//	std::cout << cel << " degrees Celsius is " << fah<<" degrees Fahrenheit.";
//}

//Q6.编写程序，其main()调用一个用户定义的函数(以光年值为参数，并返回对应天文单位的值)。已知1 光年 = 63240 天文单位
//double trans(double ly) {
//	return ly * 63240;
//}
//
//int main() {
//	double ly, au;
//	std::cout << "Enter the number of light years: ";
//	std::cin >> ly;
//	au = trans(ly);
//	std::cout << ly << " light years = " << au << " astronomical units.";
//}

//Q7.编写程序，要求用户输入小时数和分钟数。在main()中将这两个值传递给一个void函数。以小时数:分钟数显示时间
//void show(int hour, int min) {
//	std::cout <<"Time: "<< hour << ":" << min;
//}
//
//int main() {
//	int hour, min;
//	std::cout << "Enter the number of hours: ";
//	std::cin >> hour;
//	std::cout << "Enter the number of minutes: ";
//	std::cin >> min;
//	show(hour, min);
//}