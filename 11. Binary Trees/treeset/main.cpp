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
    TreeSet<int> b {10, 5, 15, 12, 20, 11, 14, 13};
    // a.inorder(print_values);
    // std::cout << "\n";
    // a.inorder(add_to_vector);
    // for (int x : result_vector) {
    //     std::cout << x << " ";
    // }
    // std::cout << "\n";
    // a.inorder(add_numbers);
    // std::cout << "Total = " << total << "\n";

    a.levelorder(add_to_vector);

    for (int x : result_vector) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    b.inorder(print_values);
    std::cout << "\n";
    b.preorder(print_values);
    std::cout << "\n";
    b.postorder(print_values);
    std::cout << "\n";
    b.levelorder(print_values);
    std::cout << "\n";

    std::cout << "a.height() = " << a.height() << "\n";
    std::cout << "b.height() = " << b.height() << "\n";

    std::cout << "a.is_full() = " << a.is_full() << "\n";
    std::cout << "b.is_full() = " << b.is_full() << "\n";

    std::cout << "a.leaf_count() = " << a.leaf_count() << "\n";
    std::cout << "b.leaf_count() = " << b.leaf_count() << "\n";

    std::cout << "a.is_perfect() = " << a.is_perfect() << "\n";
    std::cout << "b.is_perfect() = " << b.is_perfect() << "\n";

    return 0;
}
