#include <iostream>

int main()
{
    std::string s = "Hello, world!";
    int s_hash = std::hash<std::string>{}(s);

    std::cout << "s = " << s << ", hash(s) = " << s_hash << "\n";

    s += "!";
    s_hash = std::hash<std::string>{}(s);

    std::cout << "s = " << s << ", hash(s) = " << s_hash << "\n";

    int i = 42;
    int i_hash = std::hash<int>{}(i);

    std::cout << "i = " << i << ", hash(i) = " << i_hash << "\n";

    i *= 10'000'000;
    i_hash = std::hash<int>{}(i);

    std::cout << "i = " << i << ", hash(i) = " << i_hash << "\n";

    double d = 3.1416;
    int d_hash = std::hash<double>{}(d);

    std::cout << "d = " << d << ", hash(d) = " << d_hash << "\n";



    return 0;
}