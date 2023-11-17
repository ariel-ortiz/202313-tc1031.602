#include <iostream>
#include <vector>
#include "treeset.h"

void print_values(int x)
{
    std::cout << x << " ";
}

std::vector<int> result_vector;

void add_to_vector(int x)
{
    result_vector.push_back(x);
}

int total = 0;

void add_numbers(int x) {
    total += x;
}

int main()
{
    TreeSet<int> a {10, 15, 5, 7, 2, 17, 12};
    // a.inorder(print_values);
    // std::cout << "\n";
    a.inorder(add_to_vector);

    for (int x : result_vector) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    a.inorder(add_numbers);

    std::cout << "Total = " << total << "\n";

    return 0;
}
