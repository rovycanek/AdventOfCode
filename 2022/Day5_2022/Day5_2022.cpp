// Day5_2022.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Move
{
    int count;
    int src;
    int dst;
};

using Moves = std::vector<Move>;
using Stack = std::vector<char>;
using Stacks = std::vector<Stack>;

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

    Stacks stacks(9);
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 9; j++) {
            if (import[i][j * 4 + 1] != ' ')
                stacks[j].push_back(import[i][j * 4 + 1]);
        }
    }

    Moves moves;
    for (int i = 10; i < import.size(); i++) {
        Move move;
        sscanf_s(import[i].c_str(), "move %d from %d to %d", &move.count, &move.src, &move.dst);
        moves.push_back(move);
    }

    for (Move move : moves) {
        for (int i = 0; i < move.count; i++) {
            stacks[move.dst-1].push_back(stacks[move.src-1].back());
            stacks[move.src-1].pop_back();
        }
    }

    for (Stack stack : stacks) {
        std::cout << stack.back();
    }
    std::cout << std::endl;

    Stacks stacksnew(9);
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 9; j++) {
            if (import[i][j * 4 + 1] != ' ')
                stacksnew[j].push_back(import[i][j * 4 + 1]);
        }
    }

    for (Move move : moves) {
            stacksnew[move.dst - 1].insert(stacksnew[move.dst-1].end(), stacksnew[move.src-1].end() - move.count, stacksnew[move.src-1].end());
            stacksnew[move.src - 1].erase(stacksnew[move.src-1].end() - move.count, stacksnew[move.src-1].end());
    }

    for (Stack stack : stacksnew) {
        std::cout << stack.back();
    }
}
