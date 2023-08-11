#include <iostream>
#include "fact.h"

int main()
{
    int n = 5;
    int r = fact(n);
    std::cout << "fact(" << n << ") = " << r << "\n";
    std::cout << "The End.\n";
    return 0;
}
