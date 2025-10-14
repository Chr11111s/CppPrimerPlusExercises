#include <iostream>

//Q1.用户输入一个整数指出自己身高(英寸)，然后转换为英尺和英寸。使用const表示转换因子
//int main() {
//	const int OneFeet_OneInch = 12; //1英尺 = 12英寸
//	int height;
//	std::cout << "输入身高：";
//	std::cin >> height;  //byd的cout和cin一起整才能凑出个python的input()效果
//
//	int feet = height / OneFeet_OneInch;
//	int restInch = height % OneFeet_OneInch;
//	
//	std::cout << "身高为 " << feet << "英尺" << restInch << "英寸" << std::endl;
//}

//Q2.输入身高(英尺英寸)，输入体重(磅)，使用三个变量储存。计算BMI指数：体重(千克)除以身高(米)的平方，1英尺 = 12英寸、1英寸 = 0.0254米、1千克 = 2.2磅。
//int main() {
//	int ft, in, ib; //ft-英尺，in-英寸，ib-磅
//
//	std::cout << "输入身高(英尺 + 英寸): ";
//	std::cin >> ft >> in;
//	std::cout << "输入体重(磅): ";
//	std::cin >> ib;
//
//	int totalInch = ft * 12 + in;
//	double meters = totalInch * 0.0254;
//	double kg = ib / 2.2;
//
//	double BMI = kg / (meters * meters);
//	std::cout << "BMI指数为：" << BMI;
//}

//Q3.以整数方式输入度、分、秒表示一个纬度，然后以度为单位显示该纬度。1度 = 60分，1分 = 60秒，以常量符号表示这些值。用三个变量储存输入值。
//int main() {
//	const int MINUTES_IN_DEGREE = 60;
//	const int SECONDS_IN_MINUTE = 60;
//
//	int deg, min, sec;
//	std::cout << "Enter a latitude in degrees, minutes, and seconds:\n";
//	std::cout << "First, enter the degrees: ";
//	std::cin >> deg;
//	std::cout << "Next, enter the minutes of arc: ";
//	std::cin >> min;
//	std::cout << "Finallly, enter the seconds of arc: ";
//	std::cin >> sec;
//
//	double res = deg + min / 60.0 + sec / 360.0;
//	std::cout << deg << " degrees, " << min << " minutes, " << sec << " seconds = " << res << " degrees";
//}

//Q4.以整数形式读入秒数，用long或long long存储。然后以天、小时、分钟、秒的方式显示时间。使用常量符号表示换算关系。
//int main() {
//	const int HOURS_IN_DAY = 24;
//	const int MINUTES_IN_HOUR = 60;
//	const int SECONDS_IN_MINUTE = 60;
//
//	long long total_secs;
//	std::cout << "Enter the number of seconds: ";
//	std::cin >> total_secs;
//	int days = total_secs / (HOURS_IN_DAY * MINUTES_IN_HOUR * SECONDS_IN_MINUTE);
//	int rest_sec1 = total_secs % (HOURS_IN_DAY * MINUTES_IN_HOUR * SECONDS_IN_MINUTE);
//
//	int hours = rest_sec1 / (MINUTES_IN_HOUR * SECONDS_IN_MINUTE);
//	int rest_sec2 = rest_sec1 % (MINUTES_IN_HOUR * SECONDS_IN_MINUTE);
//
//	int mins = rest_sec2 / SECONDS_IN_MINUTE;
//	int rest_sec3 = rest_sec2 % SECONDS_IN_MINUTE;
//
//	std::cout << total_secs << " seconds = " << days << " days, " << hours << " hours, " << mins << " minutes, " << rest_sec3 << " seconds";
//}

//Q5.读入全球总人口和美国当前人口，用long long存储，显示美国人口占全球人口。
//int main() {
//	long long global, us;
//	std::cout << "Enter the world's population: ";
//	std::cin >> global;
//	std::cout << "Enter the population of the US: ";
//	std::cin >> us;
//
//	double pers = (static_cast<double>(us) / static_cast<double>(global)) * 100;
//	std::cout << "The population of the US is " << pers << "% of the world population";
//}

//Q6.读入驱车里程(英里)和使用汽油量(加仑)，计算每加仑够行驶多少英里，即 多少英里/加仑。
//int main() {
//	double mi, gas;
//	std::cout << "提供总英里与总使用量：";
//	std::cin >> mi >> gas;
//	std::cout << (mi / gas) << "英里/加仑";
//}

//Q7.读入欧洲风格汽车耗油量(多少升/100公里)，然后转换为美国风格(多少英里/加仑)。100公里 = 62.14英里，1加仑 = 3.785升。
int main() {
	double gasL;
	std::cout << "输入每100公里损耗油量(升): ";
	std::cin >> gasL;

	double gasG = gasL / 3.785; //现在是 多少加仑/62.14英里
	double res = 62.14 / gasG;  //除以加仑数获取 1加仑/多少英里
	std::cout << res << " 英里/加仑";
}