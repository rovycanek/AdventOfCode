#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<cmath>

int getMostCommonAtPossition(std::vector<std::string> import, int position, bool inverse) {
    int mostCommon = 0;

    for (size_t i = 0; i < import.size(); i++)
    {
        mostCommon += import[i].at(position) == '0' ? -1 : 1;
    }

    return (!inverse) ? (mostCommon >= 0 ? 1 : 0) : (mostCommon >= 0 ? 0 : 1);
}

int main()
{
    //opening of file and reading
    std::ifstream file("data.txt");
    std::vector<std::string> import;
    std::string scan;
    while (file >> scan)
    {
        import.push_back(scan);
    }
    file.close();

    int finallCount = 0;
    for (size_t i = 0; i < import[0].length(); i++)
    {
        finallCount += pow(2, i) * getMostCommonAtPossition(import, 11 - i, false);
    }

    int finallCountInverse = 0;
    for (size_t i = 0; i < import[0].length(); i++)
    {
        finallCountInverse += pow(2, i) * getMostCommonAtPossition(import, 11 - i, true);
    }
    std::cout << finallCount * finallCountInverse << std::endl;

    int currentPosition = 0;
    std::vector<std::string> tmp1 = import;
    while (tmp1.size() != 1) {
        std::vector<std::string> newtmp;
        char common = getMostCommonAtPossition(tmp1, currentPosition, false) + '0';
        for (std::string var : tmp1)
        {
            if (var[currentPosition] == common)
                newtmp.push_back(var);
        }
        tmp1 = newtmp;
        currentPosition++;
    }

    currentPosition = 0;
    std::vector<std::string> tmp2 = import;
    while (tmp2.size() != 1) {
        std::vector<std::string> newtmp;
        char common = getMostCommonAtPossition(tmp2, currentPosition, true) + '0';
        for (std::string var : tmp2)
        {
            if (var[currentPosition] == common)
                newtmp.push_back(var);
        }
        tmp2 = newtmp;
        currentPosition++;
    }
    std::cout << std::stoi(tmp2[0], nullptr, 2) * std::stoi(tmp1[0], nullptr, 2) << std::endl;
}