//Q1.C++程序的模块叫什么
//A.函数，程序由一个 / 多个函数组成，main()是程序入口函数，其他函数用来把问题分解成更小模块。
//
//Q2.这行预处理器编译指令有什么用：#include <iostream>
//A.这是一段预处理指令，把标准头文件iostream的内容在编译前包含进当前源文件，从而能让coder使用其内部声明的函数、类和对象。
//
//Q3.这行语句有什么用：using namespace std
//A.将命名空间中的名字(标识符，包括函数、类、对象等)导入当前作用域。优点是方便书写，缺点易与自定义或其他库重名(自己起名vector, 而std::vector也存在)。
//
//Q4.如何打印"Hello, world"然后开始新的一行
//A.cout << "Hello, world" << endl;
//
//Q5.如何创建名为cheeses的整数变量
//A.int cheeses;
//
//Q6.如何将值32赋给变量cheeses
//A.cheeses = 32;
//
//Q7.如何将从键盘输入的值读入变量cheeses
//A.int cheeses;
//  std::cin >> cheeses;
//
//Q8.如何打印"We have X vsrieties of cheese",其中X为变量cheeses当前值。
//A.cout<<"We have"<cheeses<<"varieties of cheese";
//
//Q9.下面函数声明指出了关于函数的哪些信息
//int froop(double t)-- - 返回值类型为int，传入一个形参(即调用时传入参数)t，类型为double类型。
//void rattle(int n)-- - 无返回值，传入一个形参n，类型为int。
//int prune(void)-- - 返回值类型为int，无传入参数。
//
//Q10.定义函数时，什么时候不必使用关键字return
//A.①当返回类型为void时不强求使用，但如果需要提前返回也还是要用return的(比如递归)。②在写main函数到末尾时加不加return 0都无所谓，因为标准规定会隐式返回0
//③非void型函数到末尾时必须要返回一个与声明一致的值，否则会报错(未定义行为)。
//
//Q11.假设你编写的main()函数包含以下代码
//cout << "Please enter your PIN: ";
//而编辑器指出cout是一个未知标识符。导致这种问题的原因可能是什么？给出3种解决方案
//A.cout 属于 标准命名空间 std，报未知标识符可能是未包含头文件或者是未将名字引入当前作用域
//①未包含头文件，检查是否#include <iostream>  ②未将名字引入当前作用域，修改代码为std::cout<<... ③使用using声明，using namespace std或者using std::cout