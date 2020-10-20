#include <bits/stdc++.h>

using namespace std;
//singleton : 不是线程安全的

//我们可以使用 static 关键字来把类成员定义为静态的。
//当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。
//静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，
//所有的静态数据都会被初始化为零。我们不能把静态成员的初始化放置在类的定义中，
//但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化，如下面的实例所示。

//注意到实现中m_pInstance和GetInstance都是静态的，所以没有创建对象就已经存在了。通过调用GetInstance来创建或者获取唯一的对象
#include <iostream>
using namespace std;
class CSingleton
{
private:
    CSingleton() {}                 //1.构造函数是私有的，不能通过构造函数创建该类的实例
    static CSingleton *m_pInstance; //2.静态成员变量，且是私有的，指向一个CSingleton实例，同一时间只存在一个这个变量，所以只能存在一个CSingleton的实例

public:
    static CSingleton *GetInstance()
    { //3.只能通过这个函数来创建并获得一个CSingleton实例，且这个实例是唯一的（因为没有其他途径创建CSingleton实例，构造函数是私有的）
        if (m_pInstance == NULL)
        {
            m_pInstance = new CSingleton;
        }

        return m_pInstance;
    }
};

CSingleton *CSingleton::m_pInstance = NULL; //4.初始化类的静态成员变量

int main(int argc, const char **argv)
{
    CSingleton *c = CSingleton::GetInstance();

    cout << "hello" << endl;
    cout << "c:" << c << endl;

    return 0;
}