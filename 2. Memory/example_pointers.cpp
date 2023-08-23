#include <iostream>

void swap1(int x, int y)
{
    int t = x;
    x = y;
    y = t;
}

void swap2(int* p, int* q)
{
    int t = *p;
    *p = *q;
    *q = t;
}

int main()
{
    int x = 5;
    int* p = &x;
    int** pp = &p;

    std::cout << "x    = " << x << "\n";
    std::cout << "&x   = " << &x << "\n";
    std::cout << "p    = " << p << "\n";
    std::cout << "*p   = " << *p << "\n";
    std::cout << "&p   = " << &p << "\n";
    (*p)++;
    std::cout << "x    = " << x << "\n";
    std::cout << "pp   = " << pp << "\n";
    std::cout << "*pp  = " << *pp << "\n";
    std::cout << "**pp = " << **pp << "\n";

    int a = 5;
    int b = 8;
    std::cout << "a = " << a << ", b = " << b << "\n";
    swap1(a, b);
    std::cout << "a = " << a << ", b = " << b << "\n\n";

    std::cout << "a = " << a << ", b = " << b << "\n";
    swap2(&a, &b);
    std::cout << "a = " << a << ", b = " << b << "\n";


    return 0;
}
