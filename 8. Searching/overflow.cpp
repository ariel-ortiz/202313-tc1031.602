#include <iostream>

int main()
{
    int min = 1;
    int max = 2'147'483'647;
    int mid = min + (max - min) / 2;
    std::cout << "min = " << min << "\n";
    std::cout << "max = " << max << "\n";
    std::cout << "mid = " << mid << "\n";
    return 0;
}