
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


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

    int points = 0;
    for (int i = 0; i < import.size(); i++) {
        switch (import[i][0])
        {
        case 'A':
            switch (import[i][2])
            {
            case 'X':
                points += 1;
                points += 3;
                break;
            case 'Y':
                points += 2;
                points += 6;
                break;

            case 'Z':
                points += 3;
                points += 0;
                break;
            }
            break;
        case 'B':
            switch (import[i][2])
            {
            case 'X':
                points += 1;
                points += 0;
                break;
            case 'Y':
                points += 2;
                points += 3;
                break;

            case 'Z':
                points += 3;
                points += 6;
                break;
            }
            break;

        case 'C':
            switch (import[i][2])
            {
            case 'X':
                points += 1;
                points += 6;
                break;
            case 'Y':
                points += 2;
                points += 0;
                break;

            case 'Z':
                points += 3;
                points += 3;
                break;
            }
            break;

        default:
            break;
        }
    }
    std::cout << points << std::endl;

    points = 0;
    for (int i = 0; i < import.size(); i++) {
        switch (import[i][0])
        {
        case 'A':
            switch (import[i][2])
            {
            case 'X':
                points += 3;
                points += 0;
                break;
            case 'Y':
                points += 1;
                points += 3;
                break;

            case 'Z':
                points += 2;
                points += 6;
                break;
            }
            break;
        case 'B':
            switch (import[i][2])
            {
            case 'X':
                points += 1;
                points += 0;
                break;
            case 'Y':
                points += 2;
                points += 3;
                break;

            case 'Z':
                points += 3;
                points += 6;
                break;
            }
            break;

        case 'C':
            switch (import[i][2])
            {
            case 'X':
                points += 2;
                points += 0;
                break;
            case 'Y':
                points += 3;
                points += 3;
                break;

            case 'Z':
                points += 1;
                points += 6;
                break;
            }
            break;

        default:
            break;
        }
    }
    std::cout << points << std::endl;
   
   
}
