#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

void fill_random(std::vector<int>& data, int max_value)
{
    std::srand(0); // Random seed
    for (int i = 0; i < data.size(); ++i) {
        data.at(i) = std::rand() % max_value;
    }
}

void selection_sort(std::vector<int>& data)
{
    for (int i = 0; i < data.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < data.size(); ++j) {
            if (data.at(j) < data.at(min_index)) {
                min_index = j;
            }
        }
        std::swap(data.at(min_index), data.at(i));
    }
}

int main()
{
    const int MAX = 1000;
    const int SIZE = 10'000;

    std::vector<int> v(SIZE);

    // for (int elem: v) {
    //     std::cout << elem << " ";
    // }
    // std::cout << "\n";

    std::cout << "Is sorted? " << std::is_sorted(v.begin(), v.end()) << "\n";

    fill_random(v, MAX);

    // for (int elem: v) {
    //     std::cout << elem << " ";
    // }
    // std::cout << "\n";

    std::cout << "Is sorted? " << std::is_sorted(v.begin(), v.end()) << "\n";

    auto start = std::chrono::high_resolution_clock::now();
    selection_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1E6; // convert to seconds

    std::cout << "Total time = " << total_time << " seconds\n";

    std::cout << "Is sorted? " << std::is_sorted(v.begin(), v.end()) << "\n";

    // for (int elem: v) {
    //     std::cout << elem << " ";
    // }
    // std::cout << "\n";

    return 0;
}
