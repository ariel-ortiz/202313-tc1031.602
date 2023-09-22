#include <iostream>
#include "stack.h"

// Complexity: O(N)
bool is_palindrome(const std::string& input)
{
    Stack<char> s(input.size());

    for (char c: input) {
        s.push(c);
    }

    for (char c: input) {
        if (c != s.pop()) {
            return false;
        }
    }

    return true;
}

int main()
{
    Stack<int> s1(3);
    std::cout << "s1.size() = " << s1.size() << "\n";
    std::cout << "s1.capacity() = " << s1.capacity() << "\n";
    s1.push(1);
    s1.push(2);
    s1.push(3);
    std::cout << "s1.size() = " << s1.size() << "\n";
    std::cout << "s1.capacity() = " << s1.capacity() << "\n";
    // s1.push(4); // Overflow
    std::cout << "s1.pop() = " << s1.pop() << "\n";
    std::cout << "s1.pop() = " << s1.pop() << "\n";
    std::cout << "s1.pop() = " << s1.pop() << "\n";
    // std::cout << "s1.pop() = " << s1.pop() << "\n"; // Underflow
    std::cout << "s1.size() = " << s1.size() << "\n";
    std::cout << "s1.capacity() = " << s1.capacity() << "\n";
    std::string str1 = "sitonapotatopanotis";
    std::cout << "is_palindrome(" << str1 << ") = " << is_palindrome(str1) << "\n";
    std::string str2 = "moma";
    std::cout << "is_palindrome(" << str2 << ") = " << is_palindrome(str2) << "\n";
    return 0;
}
