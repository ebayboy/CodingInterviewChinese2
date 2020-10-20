#include <bits/stdc++.h>

using namespace std;
//singleton : 不是线程安全的

class CSingleton
{
public:
    static CSingleton *GetInstance()
    {
        if (m_pInstance == nullptr)
        {
            m_pInstance = new CSingleton();
        }

        return m_pInstance;
    }

private:
    static CSingleton *m_pInstance;
    CSingleton() { cout << "constructor..." << endl; } //
};

CSingleton *CSingleton::m_pInstance = NULL;

int main(int argc, const char **argv)
{
    CSingleton c1();
    CSingleton *c = CSingleton::GetInstance();

    cout << "hello" << endl;
    cout << "c:" << c << endl;
    cout << "c1:" << c1 << endl;

    return 0;
}