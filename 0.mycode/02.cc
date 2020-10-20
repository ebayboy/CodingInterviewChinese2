#include <bits/stdc++>

class MyClass
{
public:
    MyClass() = default;
    MyClass(MyClass &&) = default;
    MyClass(const MyClass &) = default;
    MyClass &operator=(MyClass &&) = default;
    MyClass &operator=(const MyClass &) = default;
    ~MyClass() = default;

private:
    
};

int main(int argc, const char** argv) {
    return 0;
}