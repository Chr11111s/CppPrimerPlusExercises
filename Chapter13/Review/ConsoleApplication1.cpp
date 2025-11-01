//派生类（Derived Class） 是 从另一个类（称为基类 Base Class）继承而来的类。


//Q1.派生类从基类那里继承了什么——所有数据成员、所有非构造成员函数、基类的访问控制和作用规则

//Q2.派生类不能从基类继什么——构造函数、析构函数、拷贝构造函数、赋值运算符、友元关系

//Q3.假设baseDMA::operator=()函数的返回类型为void，而不是baseDMA&会有什么后果？如果返回类型是baseDMA而不是baseDMA&又有什么后果？(标准写法是  baseDMA& baseDMA::operator=())

根据标准写法，它返回当前对象的引用(*this), 这样可以支持连续赋值如a=b=c

①  void baseDMA::operator=()  : 返回类型为void，赋值语句仍然有效，但不能进行链式赋值，即a=b=c会报错(b=c返回void，a=(void)非法)

②  baseDMA baseDMA::operator=()  : 返回类型为baseDMA，赋值功能和链式赋值功能都可以使用，但是会出现不必要的临时对象复制，性能低下，而且可能出现对象切片(即派生类部分被截断为基类部分)

//Q4.创建和删除派生类对象时，构造函数和析构函数调用的顺序是怎样的？
创建：基类构造函数——派生类构造函数

删除：派生类析构函数——基类析构函数

//Q5.如果派生类没有添加任何数据成员，它是否需要构造函数？
如果派生类没加新成员，也不需要特殊初始化，
C++ 会自动帮你生成一个构造函数，调用基类的默认构造函数。

但——如果基类没有默认构造函数，或者你想做点别的事，
就得自己写！

//Q6.如果基类和派生类定义了同名的方法，当派生类对象，当派生类对象调用该方法时，被调用的将是哪个方法？
派生类的函数会覆盖基类函数

//Q7.在什么情况下派生类应定义赋值运算符？
如果派生类或基类里有指针、动态内存、资源需要管理，
就要自己写赋值运算符。
否则让编译器帮你生成一个就够用了。

//Q8.可以将派生类对象的地址赋给基类指针吗？可以将基类对象的地址赋给派生类指针吗？
✔️ 可以把派生类对象的地址赋给基类指针（向上转型，安全）
❌ 不能把基类对象的地址赋给派生类指针（向下转型，不安全，除非用 dynamic_cast）
(也即爸爸可以指儿子，但儿子不能指爸爸)

//Q9.可以将派生类对象赋给基类对象吗？可以将基类对象赋给派生类对象吗？
✔️ 可以把派生类对象赋给基类对象，
❗ 但会发生 “对象切片” —— 派生类特有的数据全部丢失。

❌ 不能把基类对象赋给派生类对象。
因为基类对象缺少派生类部分的数据，无法安全转换。

//Q10.假设定义了一个函数，它将基类对象的引用作为参数。为什么该函数也可以将派生类对象作为参数？
派生类对象可以作为基类引用的参数传入，
因为派生类是基类的一种（向上转型），
而引用不会产生对象切片。

//Q11.假设定义了一个函数，它将基类对象作为参数(即函数按值传递基类对象)。为什么该函数也可以将派生类对象作为参数？
✔️ 派生类对象可以传给按值接收基类对象的函数，
因为派生类中“包含”基类部分；
❗但这会发生对象切片，丢失派生类特有的信息。

子能当父，但只剩父；
传进函数，子被切哭。

//Q12.为什么通常按引用传递对象比按值传递对象效率更高？
❌ 按值传递会复制整个对象，
✔️  按引用传递只传地址，速度快、内存小，还能保持多态。

//Q13.假设Corporation是基类，PublicCorporation是派生类。再假设两个类都定义了head()函数，ph是指向Corporation类型的指针，且被赋值给了一个PublicCorporation对象的地址。
//如果基类将head()定义为：a.常规非虚方法  b.虚方法
//则ph->head()将被如何解释？

a.非虚
class Corporation {
public:
    void head() { cout << "Corporation head()\n"; }
};

class PublicCorporation : public Corporation {
public:
    void head() { cout << "PublicCorporation head()\n"; }
};

int main() {
    Corporation* ph = new PublicCorporation;
    ph->head();  // 调父类
}

b.虚
class Corporation {
public:
    virtual void head() { cout << "Corporation head()\n"; }
};

class PublicCorporation : public Corporation {
public:
    void head() override { cout << "PublicCorporation head()\n"; }
};

int main() {
    Corporation* ph = new PublicCorporation;
    ph->head();   // 调派生类
}

总结：
如果 head() 是普通函数 → 看指针类型（基类版本）

如果 head() 是虚函数 → 看实际对象类型（派生类版本）

//Q14.下述代码的问题
class Kitchen {
private:
    double kit_sq_ft;
public:
    Kitchen() { kit_sq_ft = 0.0; }
    virtual double area()const { return kit_sq_ft * kit_sq_ft; }
};
class House :public Kitchen {
private:
    double all_sq_ft;
public:
    House() { all_sq_ft += kit_sq_ft; } //❌ 访问了基类私有成员    ❌ 且未初始化all_sq_ft就+=(好歹给个0)
    double area(const char* s)const { cout << s; return all_sq_ft; } //❌ 因为参数列表不同，C++ 认为这是一个全新的函数，它隐藏了基类的所有同名函数。导致无法调用无参的area()函数
};