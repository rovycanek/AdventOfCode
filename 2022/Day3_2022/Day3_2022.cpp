
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

char stringContains(std::string first, std::string second) {
    for (char ch : first) {
        if (second.find(ch) != std::string::npos)
            return ch;
    }
    return ' ';
}

char stringCommon(std::string first, std::string second, std::string third) {
    std::string common;
    for (char ch : first) {
        if (second.find(ch) != std::string::npos)
            common.push_back(ch);
    }

    for (char ch : common) {
        if (third.find(ch) != std::string::npos)
            return ch;
    }
    return ' ';
}

int priority(char item)
{
    if (std::isupper(item)) {
        return item - 'A' + 27;
    }
    return item - 'a' + 1;
}

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

    int totalPriority = 0;
    for (std::string line : import)
    {
        int size = line.size() /2;
        std::string firstPart = line.substr(0, size);
        std::string secondPart = line.substr(size, 2*size);
        int index = firstPart.compare(secondPart);
        char letter = stringContains(firstPart, secondPart);
        totalPriority += priority(letter);
    }

    std::cout << totalPriority << std::endl;

    totalPriority = 0;
    for (int i = 0; i < import.size(); i += 3) {
        char letter = stringCommon(import[0 + i], import[1 + i], import[2 + i]);
        totalPriority += priority(letter);
    }
    std::cout << totalPriority << std::endl;
}
