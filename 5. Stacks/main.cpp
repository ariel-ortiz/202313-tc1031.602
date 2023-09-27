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

bool is_balanced(const std::string& input)
{
    Stack<char> s(input.size());

    for (char c: input) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                s.push(c);
                break;
            case ')':
                if (s.is_empty() or s.pop() != '(') {
                    return false;
                }
                break;
            case ']':
                if (s.is_empty() or s.pop() != '[') {
                    return false;
                }
                break;
            case '}':
                if (s.is_empty() or s.pop() != '{') {
                    return false;
                }
                break;
        }
    }
    return s.is_empty();
}

int main()
{
    // Stack<int> s1(3);
    // std::cout << "s1.size() = " << s1.size() << "\n";
    // std::cout << "s1.capacity() = " << s1.capacity() << "\n";
    // s1.push(1);
    // s1.push(2);
    // s1.push(3);
    // std::cout << "s1.size() = " << s1.size() << "\n";
    // std::cout << "s1.capacity() = " << s1.capacity() << "\n";
    // // s1.push(4); // Overflow
    // std::cout << "s1.pop() = " << s1.pop() << "\n";
    // std::cout << "s1.pop() = " << s1.pop() << "\n";
    // std::cout << "s1.pop() = " << s1.pop() << "\n";
    // // std::cout << "s1.pop() = " << s1.pop() << "\n"; // Underflow
    // std::cout << "s1.size() = " << s1.size() << "\n";
    // std::cout << "s1.capacity() = " << s1.capacity() << "\n";
    // std::string str1 = "sitonapotatopanotis";
    // std::cout << "is_palindrome(" << str1 << ") = " << is_palindrome(str1) << "\n";
    // std::string str2 = "moma";
    // std::cout << "is_palindrome(" << str2 << ") = " << is_palindrome(str2) << "\n";

    std::string e1 = "[()[]{}]";
    std::cout << "e1 = " << e1
        << ", is_balanced(e1) = "
        << is_balanced(e1) << "\n";
    std::string e2 = "(((]))";
    std::cout << "e2 = " << e2
        << ", is_balanced(e2) = "
        << is_balanced(e2) << "\n";
    std::string e3 = "([{([{(([[[[[{{";
    std::cout << "e3 = " << e3
        << ", is_balanced(e3) = "
        << is_balanced(e3) << "\n";
    std::string e4 = "[([{}])([{()()()}])((((()))))({}{}{})]";
    std::cout << "e4 = " << e4
        << ", is_balanced(e4) = "
        << is_balanced(e4) << "\n";
    return 0;
}
