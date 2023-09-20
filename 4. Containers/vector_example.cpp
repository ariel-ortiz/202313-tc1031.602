#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    v.reserve(10);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v.capacity() = " << v.capacity() << "\n";

    v.push_back(4);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v.capacity() = " << v.capacity() << "\n";

    v.push_back(8);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v.capacity() = " << v.capacity() << "\n";

    v.push_back(15);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v.capacity() = " << v.capacity() << "\n";

    v.push_back(16);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v.capacity() = " << v.capacity() << "\n";

    v.push_back(23);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v.capacity() = " << v.capacity() << "\n";

    v.resize(8);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v.capacity() = " << v.capacity() << "\n";

    // std::cout << "v.at(3) = " << v.at(3) << "\n";

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << "*it = " << *it << "\n";
    }

    for (int value: v) {
        std::cout << "value = " << value << "\n";
    }

    return 0;
}
