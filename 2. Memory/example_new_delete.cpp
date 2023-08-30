#include <iostream>

int main()
{
    int* p = new int { 5 };
    std::cout << "*p = " << *p << "\n";
    delete p;

    int* a = new int[5] {4, 8, 15};
    std::cout << "*a = " << *a << "\n";
    std::cout << "*(a + 1) = " << *(a + 1) << "\n";
    std::cout << "a[1] = " << a[1] << "\n";
    std::cout << "2[a] = " << 2[a] << "\n";
    delete [] a;

    return 0;
}

