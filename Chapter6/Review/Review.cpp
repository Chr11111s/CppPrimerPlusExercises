//Q1.比较两种代码并解释为什么第二种更好
////Version 1
//while (cin.get(ch)) //quit of eof
//{
//	if (ch == ' ')
//		spaces++;
//	if (ch == '\n')
//		newlines++;
//}
//
////Version 2
//while (cin.get(ch)) //quit on eof
//{
//	if (ch == ' ')
//		spaces++;
//	else if (ch == '\n')
//		newlines++;
//}
//
//V1中即使已经判断出了是空格依旧还是会再判断是否为换行，无论输入什么都会进行两次比较；V2中若已经判断出空格则会直接跳过第二个判断，节省一次操作。且这种写法可读性更高逻辑性更强

//Q2.下面代码用ch+1替换++ch会产生什么影响？
//#include <iostream>
//int main() {
//	char ch;
//	std::cout << "Type, and I shall repeat.\n";
//	std::cin.get(ch);
//	//判断每一个输入字符，除换行符原样输出外其它字符ASCII码+1后输出
//	while (ch != '.') {
//		if (ch == '\n')
//			std::cout << ch;
//		else
//			std::cout << ++ch; //++ch是char类型，输出的是char；ch+1是int类型，输出的是+1的ASCII值。另外char++更不可能，这是输出原值后再+1。
//		std::cin.get(ch);
//	}
//	std::cout << "\nPlease excuse the slight confusion.\n";
//	return 0;
//}

//Q3.认真考虑以下程序
/*假设输入如下(请在每行末尾按回车键)：
Hi!
Send $10 or $20 now!
则输出是什么(记住，输入被缓冲)*/
//#include <iostream>
//using namespace std;
//int main() {
//	char ch;
//	int ct1, ct2;
//
//	ct1 = ct2 = 0;
//	while ((ch = cin.get()) != '$')
//	{
//		cout << ch;
//		ct1++;
//		if (ch = '$') //这里不是==，而是恒成立的赋值语句，在字符输出后立即赋值为'$'(不论是字母、空格、换行符)然后输出，所以第一行是H$i$!$(换行)$
//			ct2++;
//		cout << ch;
//	}
//	cout << "ct1 = " << ct1 << ", ct2 = " << ct2 << "\n";
//	return 0;
//}
//
//综上，读一个赋值一个，ct1与ct2值相等，为已经读入字符(包含换行和空格)，循环直到读到$停止，之前读入字符共9个('H', 'i', '!', '\n', 'S', 'e', 'n', 'd', ' '), ct1 = ct2 = 9

//Q4.创建表示下述条件的逻辑表达式
//a.(weight>=115 && weight<125)
//b.(ch == 'q' || ch == 'Q')
//c.(x%2==0 && x!=26)
//d.(x%2==0 && x%26 !=0)
//e.((donation >= 1000 && donation <= 2000) || guest ==1)
//f.((ch <= 'z' && ch>='a') || (ch <= 'Z' && ch >= 'A'))

//Q5.C++中!!x和x是否相同？
//不相同，加了!类型变成bool了，假设x=8，!x就变成0(false)了,再加一个!也只是变成1(true)，无法回归原值

//Q6.创建一个条件表达式，其值为变量绝对值。也即变量x为正则表达式值为x;若x为负，则表达式值为-x
//res = (x>=0)?x:(-x)

//Q7.switch改写程序 //每个case都要加break，否则会把所有case执行一遍；所有情况以外的就是default默认了，也要加break
//switch (ch) {
//	case 'A':
//		a_grade++;
//		break;
//	case 'B':
//		b_grade++;
//		break;
//	case 'C':
//		c_grade++;
//		break;
//	case 'D':
//		d_grade++;
//		break;
//	default:
//		f_grade++;
//		break;
//}

//Q8.与使用数字表示菜单选项，用字符(如a,b)表示和case标签有何优点？(提示：想想输入q和5的情况)
//可读性更好，q可表示quit。

//Q9.重写下面代码片段，禁用break和continue
//int line = 0;
//char ch;
//while (cin.get(ch)) {
//	if (ch == 'Q')
//		break;//程序退出
//	if (ch != '\n')
//		continue;//如果不是换行符则继续读入
//	line++;//此时代表已经读到了换行符
//}
//
////改写
//int line = 0;
//char ch;
//bool flag = false; //使用flag加入循环判读代替break
//while (cin.get(ch) && !flag) {
//	if (ch == 'Q')
//		flag = true;
//	if (ch == '\n')
//		line ++;//根本不需要管不等于换行符的情况
//}

