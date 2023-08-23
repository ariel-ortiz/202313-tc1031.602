#include <iostream>

void swap3(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int x = 5;
    int& r = x;
    std::cout << "x = " << x << ", r = " << r << "\n";
    ++r;
    std::cout << "x = " << x << ", r = " << r << "\n";

    int a = 5;
    int b = 8;
    std::cout << "a = " << a << ", b = " << b << "\n";
    swap3(a, b);
    std::cout << "a = " << a << ", b = " << b << "\n";

    return 0;
}