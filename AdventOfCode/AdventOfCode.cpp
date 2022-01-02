#include <iostream>
#include <fstream>
#include <vector>


int main()
{
    //opening of file and reading
    std::ifstream file("data.txt");
    std::vector<int> import;
    int scan;
    while (file >> scan)
    {
        import.push_back(scan);
    }
    file.close();

    //counting number of increases
    int counter = 0;
    for (size_t i = 1; i < import.size(); i++)
    {
        if (import[i - 1] < import[i])
            counter++;
    }

    std::cout << "Number of increases A: " << counter << std::endl;

    //counting number of increases
    counter = 0;
    for (size_t i = 1; i < import.size() - 2; i++)
    {
        if (import[i - 1] < import[i + 2])
            counter++;
    }

    std::cout << "Number of increases B: " << counter << std::endl;
}