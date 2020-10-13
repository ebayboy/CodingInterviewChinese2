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

    ~CMyString() {
        if (m_pData) {
            delete [] m_pData;
        }
    }

    //拷贝构造函数
    CMyString(const CMyString &str);

    //赋值运算符函数
    CMyString &operator=(const CMyString &str);

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

    cout << mystr.GetData() << endl;

    return 0;
}
