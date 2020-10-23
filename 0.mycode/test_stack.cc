#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    std::stack<int> s;

    for (size_t i = 0; i < 5; i++)
    {
        s.push(i);
    }

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}