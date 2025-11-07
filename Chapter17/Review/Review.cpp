//Q1.iostream文件在C++I/O中扮演何种角色？
iostream 是 C++ 输入输出系统的核心头文件，它定义了输入输出流类、标准流对象（如 cin、cout）、以及相关的运算符和控制符，使程序能够与外部设备（键盘、屏幕等）进行交互。

//Q2.为什么键入数字如121作为输入要求程序进行转换?
当键入数字如 121 时，键盘输入的是字符 '1' '2' '1'，而程序变量需要存放整数类型的数据，因此 cin 必须执行从字符到数值的类型转换。
输入流里最初的内容其实是：

49 50 49 10   // 这些是字符 '1' '2' '1' '\n' 的 ASCII 码

//Q3.标准输出与标准错误之间有什么区别？
标准输出（cout） 用于正常信息，带缓冲，可重定向；
标准错误（cerr） 用于错误信息，不带缓冲，默认直接显示在屏幕上。

//Q4.为什么在不为每个类型提供明确指示的情况下，cout仍然能够显示不同的C++类型？
cout 之所以能显示不同类型的 C++ 数据，是因为标准库为多种数据类型重载了输出运算符 << 。
编译器在编译时根据实参类型自动选择合适的重载版本，从而实现“自动识别类型”的效果。

//Q5.输出方法的定义的哪一特征让您能够拼接输出？
输出运算符 << 之所以能“拼接输出”，是因为它的返回类型是对输出流对象（ostream）的引用。
这样每次调用 << 后都返回同一个流对象，从而可以连续使用多个 << 连接输出。

//Q6.编写程序，要求用户输入一个整数，然后以十进制、八进制和十六进制显示该整数。在宽度为15个字符的字段中显示每种形式，并将它们显示在同一行上，同时使用C++数基前缀
#include <iostream>
#include <iomanip>   // for setw, showbase, etc.
using namespace std;

int main() {
    int n;
    cout << "请输入一个整数：";
    cin >> n;

    cout << "以不同进制形式输出：" << endl;

    cout << setw(15) << showbase << dec << n      // 十进制
        << setw(15) << showbase << oct << n      // 八进制
        << setw(15) << showbase << hex << n      // 十六进制
        << endl;

    return 0;
}

//Q7.编写程序要求用户输入下面信息并按照下面格式显示：
Enter your name: Billy Gruff
Enter your hourly wages: 12
Enter number of hours worked: 7.5
First format:
                       Billy Gruff: $    12.00: 7.5
Second format:
Billy Gruff                       : $12.00    : 7.5

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name;
    double wage, hours;

    cout << "Enter your name: ";
    getline(cin, name);   // 用 getline 以支持空格
    cout << "Enter your hourly wages: ";
    cin >> wage;
    cout << "Enter number of hours worked: ";
    cin >> hours;

    cout << "\nFirst format:\n";
    cout << right;  // 右对齐
    cout << setw(30) << name << ": "
        << "$" << setw(8) << fixed << setprecision(2) << wage << ": "
        << hours << endl;

    cout << "\nSecond format:\n";
    cout << left;   // 左对齐
    cout << setw(30) << name << ": "
        << "$" << setw(8) << fixed << setprecision(2) << wage << ": "
        << hours << endl;

    return 0;
}

//Q8.对于下面的程序：
#include <iostream>
int main() {
    using namespace std;
    char ch;
    int ct1 = 0;

    cin >> ch;
    while (ch != 'q') {
        ct1++;
        cin >> ch; //跳过空白，ct1=5
    }
    int ct2 = 0;
    cin.get(ch);
    while (ch != 'q') {
        ct2++;
        cin.get(ch); //不跳过空白，ct2=8
    }
    cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << "\n";

    return 0;
}

如果输入如下将打印什么内容？<Enter>表示回车键
I see aq<Enter>
I see aq<Enter>

//Q9.下面的两条语句都读取并丢弃行尾之前的所有字符(包括行尾)。这两条语句的行为在哪方面不同?
while (cin.get() != '\n') continue;
cin.ignore(80, '\n');

while (cin.get() != '\n') 是逐字符读取直到换行；
cin.ignore(80, '\n') 是一次性丢弃最多 80 个字符或到换行符为止。
前者无限制、较慢；后者有限制、更安全。