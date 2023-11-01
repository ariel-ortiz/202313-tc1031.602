#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

int main()
{
    std::unordered_map<std::string, int> nums;
    nums["one"] = 1;
    nums["two"] = 2;
    nums["three"] = 3;
    nums["four"] = 4;

    std::cout << nums["two"] << "\n";
    std::cout << nums["five"] << "\n";
    std::cout << nums.count("two") << "\n";
    std::cout << nums.count("six") << "\n";

    for (auto pair: nums) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    std::vector<int> v {1, 5, 2, 1, 3, 2, 1, 1, 1, 3, 2, 5, 1, 1, 2, 4, 2, 5};
    std::unordered_map<int, int> count_map;

    for (int x: v) {
        count_map[x]++;
    }

    std::vector<int> keys;

    for (auto pair: count_map) {
        keys.push_back(pair.first);
    }

    std::sort(keys.begin(), keys.end());

    std::cout << "-----------------------\n";
    for (int key: keys) {
        std::cout << key << ": " << count_map[key] << "\n";
    }

    return 0;
}