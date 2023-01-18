
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <algorithm>    // std::min_element, std::max_element


int main()
{
    //opening of file and reading
    std::ifstream file("Data.txt");
    std::vector<std::string> import;
    std::string scan;
    while (std::getline(file, scan))
    {
        import.push_back(scan);
    }
    file.close();

    std::vector<int> food;
    for (int i = 0; i < import.size(); i++) {
        int size = 0;
        for (i; i < import.size() && !import[i].empty(); i++) {
            size += stoi(import[i]);
        }
        food.push_back(size);
    }
    sort(food.begin(), food.end());



    std::cout << food[food.size() -1 ] << std::endl;
    std::cout << food[food.size() - 1] + food[food.size() - 1] + food[food.size() - 1] << std::endl;
}
