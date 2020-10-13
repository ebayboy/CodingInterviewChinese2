#include <bits/stdc++.h>

//如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

using namespace std;

class CMyString
{
public:
    //构造函数
    CMyString(char *pData = nullptr)
    {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }

    ~CMyString()
    {
        if (m_pData)
        {
            delete[] m_pData;
        }
    }

    //拷贝构造函数
    CMyString(const CMyString &str)
    {
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }

#if 1
    CMyString & operator=(CMyString &str)
    {
        cout << "operator=" << endl;
        if (this->m_pData) {
            delete [] this->m_pData;
        }
        this->m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(this->m_pData, str.m_pData);

        //this是指向该对象的指针，*this返回该对象。
        return *this;
    }
#else
    //删除=赋值运算符
    CMyString &operator=(CMyString &str) = delete;
#endif

    char *GetData()
    {
        return m_pData;
    }

private:
    char *m_pData;
};

int main(int argc, const char **argv)
{
    CMyString mystr((char *)"hello");
    cout << "mystr:" << mystr.GetData() << endl;

    CMyString mystr2(mystr);
    cout << "mystr2:" << mystr2.GetData() << endl;

    CMyString mystr3((char *)"hello2");
    cout << "mystr3 before= :" << mystr3.GetData() << endl;
    mystr3 = mystr;
    cout << "mystr3 after =:" << mystr3.GetData() << endl;

    return 0;
}
