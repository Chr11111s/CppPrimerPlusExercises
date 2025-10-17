#include <iostream>

//Q1.读取键盘输入，直到遇见@为止，并回显输入(数字除外)，同时将大写字符转换为小写，将小写字符转换为大写(别忘了cctype函数系列)
//#include <cctype>
//
//int main() {
//	char ch;
//	std::cout << "输入字符(输入@终止): ";
//	while (std::cin.get(ch)) {
//		if (ch == '@')break;
//		else if (isdigit(ch)) continue;//continue后，循环内任何操作都将对符合条件的不起作用
//		else if (islower(ch)) ch = toupper(ch);
//		else if (isupper(ch)) ch = tolower(ch);
//
//		std::cout << ch;
//	}
//
//}

//Q2.编写程序。最多将10个donation值读入到一个double数组中(用模板类array亦可)。程序遇到非数字输入时将结束输入，并报告这些数字的平均值以及数组中有多少个数字大于平均值
//#include <array>
//#include <cctype>
//int main() {
//	std::array<double, 10> donations;
//	double donation;
//	std::cout << "输入donation值(输入非数字将结束)：" << std::endl;
//	double total = 0;
//	int count = 0;
//	while (count < 10 && (std::cin >> donation)) {
//		donations[count] = donation;
//		count++;
//		total += donation;
//		
//	}
//	if (count == 0)std::cout << "无有效输入" << std::endl;
//
//	int bigger_nums = 0;
//	double avg = total / count;
//	for (int i = 0; i < count ; i++) {
//		if (donations[i] > avg)bigger_nums++;
//	}
//	std::cout << "均值：" << avg <<std::endl<< "有" << bigger_nums << "个数字大于此值。";
//}

//Q3.编写菜单驱动程序雏形。显示一个提供4个选项的菜单——每个选项用一个字母标记。若用户输入选项之外字母，程序会提示输入有效字母，直到用户输入合法。然后使用switch根据用户选择进行简单操作
//int main() {
//	std::cout << "Please enter one of the following choices:\n"
//		"c) carnivore p) pianist\n"
//		"t) tree g) game\n";
//
//	char ch;
//	while (std::cin >> ch) {
//		switch (ch) {
//		case 'c':
//			std::cout << "A maple is a carnivore.";
//			return 0;//没有后续步骤，直接return即可
//		case 'p':
//			std::cout << "A maple is a pianist.";
//			return 0;
//		case 't':
//			std::cout << "A maple is a tree.";
//			return 0;
//		case 'g':
//			std::cout << "A maple is a game.";
//			return 0;
//		default:
//			std::cout << "Please enter a: c, p, t, or g: ";
//			break;//还要继续读入，故break本段，继续从头switch判断
//		}
//	}
//}

//Q4.创建成员结构，其中包含真实姓名、头衔、化名和偏好。程序创建一个由此结构组成的小型数组，并将其初始化为适当的值。另外程序创建循环让用户在选项中选择
//struct bop {
//	char fullname[100];
//	char title[20];
//	char bopname[20];
//	int preference;
//};
//
//int main() {
//	bop members[2] = { {"Wimp Macho", "Senior Pro", "Red Hat", 1}, {"Raki Rode", "Junior Pro", "Green Hat", 2} }; //结构体数组本质上是一维数组
//	char ch;
//	std::cout << "BOP Report\n"
//		"a. display by name    b. display by title\n"
//		"c. display by bopname d. display by preference\n"
//		"q. quit\n";
//	std::cout << "Enter your choice: ";
//	while (std::cin >> ch) {
//		switch (ch) {
//		case 'a':
//			for (int i = 0; i < 2; i++)std::cout << members[i].fullname << std::endl;
//			break;
//		case 'b':
//			for (int i = 0; i < 2; i++)std::cout << members[i].title << std::endl;
//			break;
//		case 'c':
//			for (int i = 0; i < 2; i++)std::cout << members[i].bopname << std::endl;
//			break;
//		case 'd':
//			for (int i = 0; i < 2; i++) {
//				if (members[i].preference == 0) std::cout << members[i].fullname << std::endl;
//				else if (members[i].preference == 1) std::cout << members[i].title << std::endl;
//				else if (members[i].preference == 2) std::cout << members[i].bopname << std::endl;
//			}
//			break;
//		case 'q':
//			std::cout << "Bye!";
//			return 0;
//		}
//		std::cout << "Next choice: ";
//	}
//
//}

//Q5.某国货币单位是t,收入所得税计算方式如下: 5000t不收税，5001-15000t收10%，15001-35000t收15%，35000t以上收20%。比如收入38000t时须交税5000*0.00 + 10000*0.10 + 20000 * 0.15 + 3000*0.20 = 4600t。
//使用循环要求用户输入收入，并报告所得税。当用户输入负数或非数字时循环将结束
//int main() {
//	double salary;
//	std::cout << "收入为(输入非数字或负数退出)：";
//	while (true) { //cin表达式在整个仅允许循环体出现一次
//		if (!(std::cin >> salary) || salary < 0) {
//			std::cout << "输入非法";
//			break;
//		}
//		if (salary <= 5000 && salary >= 0)std::cout << "不收税"<<std::endl;
//		else if (salary >= 5001 && salary <= 15000)std::cout << "缴税：" << (salary - 5000) * 0.10 << std::endl;
//		else if (salary >= 15001 && salary <= 35000)std::cout << "缴税：" << 10000 * 0.10 + (salary - 15000) * 0.15 << std::endl;
//		else if (salary > 35000)std::cout << "缴税：" << 10000 * 0.10 + 20000 * 0.15 + (salary - 35000) * 0.20 << std::endl;
//		
//		std::cout << "再次输入：";
//	}
//}

//Q6.记录捐助资金。要求用户输入捐赠者数目，然后要求用户输入每一个捐赠者的姓名和款项。这些信息存在一个动态分配的结构数组中。每个结构有两个成员：用于存储姓名的字符数组(或string对象)和用来存储款项的double成员。
//读取所有数据后，程序显示所有捐款超过10000的人姓名和其捐赠数额。该列表前应包含一个标题，指出下面的捐款者是Grand Patrons。然后，程序列出其它捐赠者，该列表以Patrons开头。
//#include <string>
//struct members {
//	std::string name;
//	double value;
//};
//
//int main() {
//	int n;
//	std::cout << "输入捐赠者数目：";
//	std::cin >> n;
//
//	members* arr = new members[n]; //反正记住创建动态结构体数组用.访问结构体成员就行。
//	for (int i = 0; i < n; i++) {
//		std::cin.ignore();//记住在数字与字符串相继输入时一定要在输入字符串的代码上方(物理上方)加入cin.ignore()!!!!!!
//		std::cout << "捐赠者姓名：";
//		getline(std::cin,arr[i].name);
//		std::cout << "捐款数额：";
//		std::cin >> arr[i].value;
//	}
//	std::cout << "Grand Patrons: ";
//	for (int i = 0; i < n; i++) {
//		if (arr[i].value > 10000) std::cout << arr[i].name << ", 捐赠额：" << arr[i].value<<' ';
//	}
//	std::cout << std::endl;
//
//	std::cout << "Patrons: ";
//	for (int i = 0; i < n; i++) {
//		if (arr[i].value <= 10000) std::cout << arr[i].name << ", 捐赠额：" << arr[i].value<<" ";
//	}
//	delete[] arr;
//	arr = nullptr;
//}

//Q7,每次读取一个单词，直到用户只输入一个q。然后该程序指出多少个单词以元音打头，多少以辅音打头，还有多少不属于这两类。使用isalpha()确定是否是单词，然后对其使用if或switch来确定其种类。
//#include <cctype>
//#include <cstring>
//
//int main() {
//	char ch[20];
//	int vow = 0;
//	int con = 0;
//	int others = 0;
//	std::cout << "输入单词(q退出)：" << std::endl;
//	while (std::cin>>ch) {
//		if (!strcmp(ch, "q")) break; //只有string才能用==比较字符，char只能用strcmp
//
//		if (isalpha(ch[0])) {
//			if (ch[0] == 'a' || ch[0] == 'e' || ch[0] == 'i' || ch[0] == 'o' || ch[0] == 'u' || ch[0] == 'A' || ch[0] == 'E' || ch[0] == 'I' || ch[0] == 'O' || ch[0] == 'U') vow++;
//			else con++;
//		}
//		else others++; //初学阶段好好写if else 别想着省事，别问为什么！！！
//	}
//	std::cout << vow << "个单词元音打头" << std::endl;
//	std::cout << con << "个单词辅音打头" << std::endl;
//	std::cout << others << "个其它" << std::endl;
//}

//Q8.程序打开一个文本文件，逐个字符读取该文件，直到到达文件末尾，然后指出该文件包含多少字符
//#include <fstream>
//
//int main() {
//	std::ifstream fin;
//	fin.open("text.txt");//重要
//
//	if (!fin.is_open()) { 
//		std::cout << "文件打开异常" << std::endl;
//		return 1; 
//	}
//	char ch;
//	int count = 0;
//	while (fin.get(ch)) {
//		count++;
//	}
//
//	std::cout << "共" << count << "个字符";
//
//	fin.close();//重要
//}

//Q9.用读取文件方式完成Q6，该文件第一行为捐款人数，余下内容应为成对的行。在每一对中，第一行为捐款人姓名，第二行为捐款数额。
//#include <fstream>
//#include <string>
//
//struct members {
//    std::string name;
//    double value;
//};
//
//int main() {
//    std::ifstream fin("donations.txt");   // 打开文件
//    if (!fin.is_open()) {
//        std::cout << "无法打开文件 donations.txt。" << std::endl;
//        return 1;
//    }
//
//    int n;
//    fin >> n;           // 读取第一行捐赠者数量
//    fin.ignore();       // 忽略换行符，防止 getline() 读到空行
//
//    members* arr = new members[n];
//
//    // 逐个读取姓名与金额
//    for (int i = 0; i < n; i++) {
//        std::getline(fin, arr[i].name);   // 读取姓名（可能包含空格）
//        fin >> arr[i].value;              // 读取金额
//        fin.ignore();                     // 忽略该行剩余换行符
//    }
//
//    fin.close();  // 读取完关闭文件
//
//    ...
//
//    delete[] arr;
//    arr = nullptr;
//
//    return 0;
//}
