Q1.如何声明下述数据
a.actor是由30个char组成的数组-- - char actor[30]
b.betsie是由100个short组成的数组-- - short betsie[100]
c.chuck是由13个float组成的数组-- - float chuck[13]
d.dipsea是由64个long double组成的数组-- - long double dipsea[64]

Q2.用模板类array而非数组完成Q1
a.std::array<char, 30> actor
b.std::array<short, 100> betsie
c.std::array<float, 13> chuck
d.std::array<long double, 64> dipsea

Q3.声明一个包含5个元素的int数组，并将其初始化为前5个正奇数
int a[5] = {1, 3, 5, 7, 9}  或  std::array<int, 5> a{1,3,5,7,9}//模板没有等号

Q4.将Q3数组中第一个元素和最后一个元素的和赋给变量even
int even = a[0] + a[4]// 对数组和模板类array都适用
或 int even = a.front() + a.back()//仅针对模板类array

Q4扩展：第二个和第三个呢？ ---a[1] + a[2] 或 a.at(1) + a.at(2)//带越界检查

Q5.显示float数组ideas中的第2个元素的值 float ideas[] = {1.1f, 1.2f, 1.3f} 或 std::array<float, 3> ideas{1.1f, 1.2f, 1.3f}
ideas[1] 或 ideas.at(1)//带越界检查

Q6.声明一个char数组，并将其初始化为字符串"cheeseburger"
char str[] = "cheeseburger" //可以自动推导
char str[13] = "cheeseburger" //注意申请的空间比字符串长度多1，因为字符串结尾默认跟\0会多一位，多申请一位才能包含整个字符串

Q7.声明一个string对象，并将其初始化为字符串"Waldorf Salad"
std::string dish = "Waldorf Salad"  或  std::string dish{"Waldorf Salad"}  或  std::string dish("Waldorf Salad")

Q8.设计一个描述鱼的结构声明。结构中应当包含品种、重量(整数，单位为盎司)和长度(英寸，包括小数)
#include <iostream>
struct Fish {
	std::string species;
	int weight;
	double length;
};

Fish fish{ "fish", 10, 10.5 }; //示例初始化

Q9.声明一个Q8中定义的结构的变量，并对它进行初始化
Fish fish1("fish1", 10, 10.5)

Q10.用enum定义一个名为Response的类型，它包含Yes、No和Maybe等枚举量，其中Yes的值为1，No为0，Maybe为2。
enum Response { Yes = 1, No = 0, Maybe = 2 };

Q11.ted是一个double变量，请声明一个指向ted的指针，并使用该指针来显示ted的值
double ted = 2;
double* p = &ted; // 指针指向地址
std::cout << "ted值为：" << *p; //将指针解引用显示该地址实际值

Q12.假设treacle是一个包含10元素的float数组，请声明一个指向该数组第一个元素的指针，并使用该指针来显示数组第一个及最后一个元素
float treacle[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}
float* p = &treacle[0]; //或直接float* p = treacle不加索引默认指向treacle[0]
cout << *p //指针当前指向第一个元素的地址，故解引用显示第一个元素值
cout << *(p + 9) //指针性质与索引类似，当前指向0下标，最后一个下标为9，故解引用(p + 9)即可

Q13.用户输入正整数，然后创建一个动态的int数组，其包含的元素数目等于输入值。首先使用new完成任务，再使用vector完成
int n;
cout << "请输入正整数：";
if (!(cin >> n) || n < 0) {
	cout << "输入不合法。"; 
	return 0;//提前返回
}
//new实现
int* arr = new int[n];
delete[] arr;//new[]申请内存一定要delete[]释放
arr = nullptr;//置为空指针防止成为野指针

//vector实现
vector<int> arr(n);

Q14.下面代码是否有效？如果有效将打印什么结果？
cout << (int*)"Home of the jolly bytes";
会返回字符串首字符地址而不是字符串本身。"..."类型为const char[]，在表达式里衰变成const char* ，此时强制转换成int * 后就不再匹配osteam里面打印字符串的重载const char* ，而是匹配到打印指针的重载const void* ，此时指针指向字符串数组的首字符，
故返回首字符地址。

Q15.给Q8中的结构动态分配内存，再读取该结构成员值
Fish* p = new Fish;
cout << "输入品种：";
cin >> p->species;//这种适合读取一个单词的名字，如果是多个单词就用getline(cin, p->species)知道回车再读取结束，用cin在输入空格或回车后就停止读入了。所有带空格的字符串都要用getline()
cout << "输入重量：";
cin >> p->weight;
cout << "输入长度：";
cin >> p->length;

...
delete p;//释放内存，p成为悬空指针
p = nullptr;//将p置为空指针防止成为野指针

Q16.如果将代码cin.getline(address, 80)改成cin >> address会有什么影响//注意是cin.getline()而不是getline()，这两个是完全不同的函数
将在读取到第一个空格时结束。cin.getline()可以读取整行

Q17.声明一个vector对象和array对象，它们都包含10个string对象。指出所需要的头文件，但不要使用using。使用const来指定要包含的string对象数。
#include <vector>
#include <array>
#include <string>

const int n = 10;

std::vector<std::string> vec(n);
std::array<std::string, n> arr;