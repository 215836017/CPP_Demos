#include <iostream>

using namespace std;

// 友元函数

/*
类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。

友元可以是一个函数，该函数被称为友元函数；
友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend，如下所示：
class Box
{
   double width;
public:
   double length;
   friend void printWidth( Box box );
   void setWidth( double wid );
};


声明类 ClassTwo 的所有成员函数作为类 ClassOne 的友元，需要在类 ClassOne 的定义中放置如下声明：
friend class ClassTwo;
*/

class Box
{
    double width;

public:
    friend void printWidth(Box box);
    void setWidth(double w);
};

// 成员函数定义
void Box::setWidth(double w)
{
    width = w;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width << endl;
}

void test1()
{
    Box box;
    // 使用成员函数设置宽度
    box.setWidth(10.0);
    // 使用友元函数输出宽度
    printWidth(box);
}

// 使用友元类
class Box1
{
    double width;

public:
    friend void printWidth(Box1 box);  // 友元函数
    friend class BigBox;  // 友元类
    void setWidth(double wid);
};

class BigBox
{
public:
    void Print(int width, Box1 &box)
    {
        // BigBox是Box的友元类，它可以直接访问Box类的任何成员
        box.setWidth(width);
        cout << "Width of box : " << box.width << endl;
    }
};

// 成员函数定义
void Box1::setWidth(double wid)
{
    width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box1 box)
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width << endl;
}
void test2()
{
    Box1 box;
    BigBox big;

    // 使用成员函数设置宽度
    box.setWidth(10.0);

    // 使用友元函数输出宽度
    printWidth(box);

    // 使用友元类中的方法设置宽度
    big.Print(20, box);
}
int main()
{
    cout << "test 1111111" << endl;
    test1();

    cout << "\n\ntest 22222222" << endl;
    test2();

    return 0;
}