//Q1.下面建立友元的尝试有什么错误？
a. class snap {
	friend clasp; //试图将 clasp 声明为 snap 的友元类，但此时 clasp 尚未被声明，编译器根本不知道 clasp 是什么类型。所以必须在 snap 定义前先声明 clasp：
	...
};
class clasp{...}; 

b.class cuff {
public:
	void snip(muff&){...} //此时 cuff 类中的成员函数 snip() 定义引用了muff，但 muff 还未声明，所以编译器在编译 cuff 时不知道 muff 是什么类型。所以需要在cuff(snip)之前声明muff
	...
};
class muff {
	friend void cuff::snip(muff&);
	...
};

c.class muff {
	friend void cuff::snip(muff&); //muff 声明中提到 cuff::snip() 是友元，但此时 cuff 根本 还未定义（甚至未声明）。编译器不知道 cuff::snip 是什么函数。所以需要在muff之前声明cuff
	...
};
class cuff {
public:
	void snip(muff&){...}
	...
};

//Q2.如何建立相互类友元？可否创建一种更为严格的友情关系，即类B只有部分成员是类A的友元，而类A只有部分成员是类B的友元吗？请解释原因。
①建立方法：
class B;   // 前向声明

class A {
	friend class B;   // A 把 B 设为友元
private:
	int secretA;
public:
	A() : secretA(42) {}
};

class B {
	friend class A;   // B 把 A 设为友元
private:
	int secretB;
public:
	B() : secretB(99) {}
	void showA(A& a) { cout << a.secretA << endl; } // 访问 A 的私有成员
};

void showB(B& b, A& a) {
	cout << b.secretB << endl;
}
②两个类可以部分为对方友元，C++ 的友元机制支持：

整个类作为友元 → friend class B;

某个特定函数作为友元 → friend void B::func();

#include <iostream>
using namespace std;

class A;   // 前向声明

class B {
public:
	void visitA(A& a);
	void notFriend(A& a);
};

class A {
	friend void B::visitA(A&);   // 只让 B 的 visitA() 成为朋友
private:
	int secretA = 10;
public:
	void show() { cout << "A.secretA = " << secretA << endl; }
};

void B::visitA(A& a) {
	cout << "B::visitA sees " << a.secretA << endl;  // ✅ 有访问权限
}
void B::notFriend(A& a) {
	cout << a.secretA; // ❌ 报错：不是友元函数
	cout << "B::notFriend can't see A.secretA" << endl;
}

int main() {
	A a;
	B b;
	b.visitA(a);
	b.notFriend(a);
}

//Q3.下面的嵌套类声明中可能存在什么问题？
class Ribs {
private:
	class Sauce {
		int soy;
		int sugar;
	public:
		Sauce(int s1,int s2):soy(s1),sugar(s2){}
	};
	...
};
| 问题 | 原因 | 解决方式                            |

| 1外部无法访问 `Sauce` | `Sauce` 在 private 区 | 改成 `public:` 或提供接口           |
| 2Sauce` 不能访问 `Ribs` 的私有成员 | 嵌套类默认不是友元 | 在 Ribs 中加 `friend class Sauce; ` |
| 3`Ribs` 不能访问 `Sauce` 的私有成员 | 外层类也不是友元 | 在 Sauce 中加 `friend class Ribs; ` |

//Q4.throw和return之间区别何在？
| 对比项 | `return` | `throw`                                |

| 含义 | 正常返回结果 | 抛出异常（错误信号）                   |
| 流程控制 | 把控制权交回给 * *调用者 * *| 把控制权交给 * *异常处理器（catch） * *|
| 使用场景 | 函数执行完毕、返回计算结果 | 发生无法继续的错误或异常情况           |
| 返回值 | 可以返回任意类型的值 | 抛出任意类型的异常对象                 |
| 恢复执行位置 | 调用函数后 * *下一条语句 * *| 对应的 `catch` 块内                    |
| 栈处理 | 正常退栈（局部变量依次销毁） | 异常传播时退栈（依然销毁局部变量） |

//Q5.假设有一个从异常基类派生来的异常类层次结构，则应按什么样的顺序放置catch块？
catch 块应当按照“派生类在前，基类在后”的顺序排列。

C++ 的异常处理机制在 try 块后面会从上到下顺序匹配每个 catch：

一旦匹配成功，不会再继续匹配下面的 catch；

匹配规则是“类型兼容”——如果异常对象是派生类对象，它也可以被基类的 catch 捕获。

所以如果你把 基类的 catch 放在前面，它会先把所有派生类异常“拦住”，导致后面的派生类 catch 永远不会执行（被屏蔽）。

//Q6.对于本章定义的Grand、Superb、Magnificent类，假设pg为Grand*指针，并将其中某个类的对象的地址赋给了它，而ps为Superb*指针，则下面两个代码示例的行为有什么不同？
if (ps = dynamic_cast<Superb*>(pg))  ps->say();

if (typeid(*pg) == typeid(Superb))  (Superb*)pg->say();

🔹 dynamic_cast：问的是“这个对象是不是属于 Superb 或其子类？”
🔹 typeid：问的是“这个对象是不是正好就是 Superb？”

//Q7.static_cast和dynamic_cast有什么不同？
“能确定就用 static_cast；不确定就用 dynamic_cast。”

static_cast —— 编译时信任你；
dynamic_cast —— 运行时替你核查。