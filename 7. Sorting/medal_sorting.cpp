#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

struct Country {
    std::string name;
    int gold;
    int silver;
    int bronze;
};

void read_file(const std::string& file_name, std::vector<Country>& values)
{
    std::ifstream file(file_name);

    if (file.fail()) {
        std::cerr << "Unable to open file: " << file_name << "\n";
        std::exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        Country c;
        std::istringstream input(line);
        input >> c.name;
        input >> c.gold;
        input >> c.silver;
        input >> c.bronze;
        values.push_back(c);
    }
}

bool compare_countries(const Country& a, const Country& b)
{
    if (a.gold != b.gold) {
        return a.gold > b.gold;
    }
    if (a.silver != b.silver) {
        return a.silver > b.silver;
    }
    if (a.bronze != b.bronze) {
        return a.bronze > b.bronze;
    }
    return a.name < b.name;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Please specify the name of the input file.\n";
        std::exit(1);
    }

    std::string file_name = argv[1];
    std::vector<Country> values;
    read_file(file_name, values);
    std::sort(values.begin(), values.end(), compare_countries);
    for (Country c: values) {
        std::cout << c.name << " " << c.gold << " "
            << c.silver << " " << c.bronze << "\n";
    }
}
