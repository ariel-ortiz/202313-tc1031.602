#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& data)
{
    for (T elem: data) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

bool compare_string_size(const std::string& a, const std::string& b)
{
    return a.size() < b.size();
}

bool compare_int_descending(int a, int b)
{
    return a > b;
}

int main()
{
    std::vector<std::string> vs {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    print_vector(vs);
    // std::sort(vs.begin() + 2, vs.end() - 2);
    std::sort(vs.begin(), vs.end(), compare_string_size);
    print_vector(vs);

    std::vector<int> vi {15, 4, 23, 42, 8, 16};
    print_vector(vi);
    std::sort(vi.begin(), vi.end(), compare_int_descending);
    print_vector(vi);
}
