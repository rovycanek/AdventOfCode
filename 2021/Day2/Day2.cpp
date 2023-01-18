#include <iostream>
#include <fstream>
#include <vector>

struct Command
{
    std::string string;
    int value;
};

struct Position
{
    int depth;
    int horizontalPossition;
    int aim;
};


int main()
{
    //opening of file and reading
    std::ifstream file("data.txt");
    std::vector<Command> import;
    Command command;
    while (file.eof() == false)
    {
        file >> command.string;
        file >> command.value;
        import.push_back(command);
    }
    file.close();

    //counting the trajectory
    Position position = {0, 0, 0};
    for (size_t i = 0; i < import.size(); i++)
    {
        if (!strcmp(import[i].string.c_str(), "forward"))
            position.horizontalPossition += import[i].value;

        else if (!strcmp(import[i].string.c_str(), "down"))
            position.depth += import[i].value;

        else if (!strcmp(import[i].string.c_str(), "up"))
            position.depth -= import[i].value;
    }

    std::cout << "Total depth: " << position.depth << std::endl;
    std::cout << "Total horizontal possition: " << position.horizontalPossition<< std::endl;
    std::cout << "Multiplycated values: " << position.depth * position.horizontalPossition << std::endl;

    //counting the trajectory for second case
    position = { 0, 0, 0 };
    for (size_t i = 0; i < import.size(); i++)
    {

        if (!strcmp(import[i].string.c_str(), "forward")) {
            position.horizontalPossition += import[i].value;
            position.depth += position.aim * import[i].value;
        }
        else if (!strcmp(import[i].string.c_str(), "down"))
            position.aim += import[i].value;

        else if (!strcmp(import[i].string.c_str(), "up"))
            position.aim -= import[i].value;
    }

    std::cout << "Total depth B: " << position.depth << std::endl;
    std::cout << "Total horizontal possition B: " << position.horizontalPossition << std::endl;
    std::cout << "Multiplycated values B: " << position.depth * position.horizontalPossition << std::endl;
}