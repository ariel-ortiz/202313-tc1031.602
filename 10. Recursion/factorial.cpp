#include <iostream>

long factorial(long n)
{
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main()
{
    long x = 5;

    std::cout << "factorial(" << x << ") = " << factorial(x) << "\n";

    x = 0;

    std::cout << "factorial(" << x << ") = " << factorial(x) << "\n";

    x = 20;

    std::cout << "factorial(" << x << ") = " << factorial(x) << "\n";

    return 0;
}
