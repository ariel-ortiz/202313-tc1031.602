#include <iostream>

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

    return 0;
}