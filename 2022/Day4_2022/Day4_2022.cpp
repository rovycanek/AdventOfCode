
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using Range = std::pair<int32_t, int32_t>;
using RangePair = std::pair<Range, Range>;
using RangePairs = std::vector<RangePair>;

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


    RangePairs rangePairs{};
    for (std::string line : import) {
        RangePair rangePair{};
        sscanf_s(line.c_str(), "%d-%d,%d-%d", &rangePair.first.first, &rangePair.first.second,
            &rangePair.second.first, &rangePair.second.second);
        rangePairs.push_back(rangePair);
    }

    int count = 0;
    for (RangePair pairs : rangePairs) {
        if (pairs.first.first <= pairs.second.first && pairs.first.second >= pairs.second.second ||
            pairs.first.first >= pairs.second.first && pairs.first.second <= pairs.second.second)
            count++;
    }
    std::cout << count << std::endl;

    count = 0;
    for (RangePair pairs : rangePairs) {
        if (pairs.first.first <= pairs.second.second && pairs.second.second <= pairs.first.second ||
            pairs.first.first <= pairs.second.first && pairs.second.first <= pairs.first.second ||
            pairs.second.first <= pairs.first.first && pairs.first.first <= pairs.second.second ||
            pairs.second.first <= pairs.first.second && pairs.first.second <= pairs.second.second)
            count++;
    }
    std::cout << count << std::endl;



}
