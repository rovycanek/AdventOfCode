#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <vector>

struct BingoBoard
{
	void SolveBoard(const std::vector<int>& CalledNumbers);

	std::vector<int> Numbers;
	std::vector<bool> UsedNumbers;
	int Score;
	int Turn;
};

void BingoBoard::SolveBoard(const std::vector<int>& CalledNumbers)
{
	for (int i = 0; i < CalledNumbers.size(); ++i)
	{
		int CurrentNumber = CalledNumbers[i];
		std::vector<int>::iterator FindResult = std::find(Numbers.begin(), Numbers.end(), CurrentNumber);
		if (FindResult == Numbers.end())
		{
			continue;
		}

		ptrdiff_t CurrentNumberIndex = FindResult - Numbers.begin();
		UsedNumbers[CurrentNumberIndex] = true;

		int CurrentRow = static_cast<int>(CurrentNumberIndex) / 5;
		int RowStartIndex = CurrentRow * 5;
		bool bRowComplete = true;
		for (int j = RowStartIndex; j < RowStartIndex + 5; ++j)
		{
			if (!UsedNumbers[j])
			{
				bRowComplete = false;
				break;
			}
		}

		int CurrentColumn = static_cast<int>(CurrentNumberIndex) % 5;
		bool bColumnComplete = true;
		for (int j = CurrentColumn; j < UsedNumbers.size(); j += 5)
		{
			if (!UsedNumbers[j])
			{
				bColumnComplete = false;
				break;
			}
		}

		if (bRowComplete || bColumnComplete)
		{
			Turn = i;
			int SumOfUnUsedNumbers = 0;
			for (int j = 0; j < UsedNumbers.size(); ++j)
			{
				if (!UsedNumbers[j])
				{
					SumOfUnUsedNumbers += Numbers[j];
				}
			}
			Score = SumOfUnUsedNumbers * CurrentNumber;
			break;
		}
	}
}


int main()
{
	std::ifstream file("data.txt");
	std::vector<std::string> Input;
	std::string scan;
	while (file >> scan)
	{
		Input.push_back(scan);
	}
	file.close();

	std::stringstream CalledNumbersStream{ Input[0] };
	std::string CurrentCalledNumber;
	std::vector<int> CalledNumbers;
	while (std::getline(CalledNumbersStream, CurrentCalledNumber, ','))
	{
		CalledNumbers.push_back(std::atoi(CurrentCalledNumber.c_str()));
	}

	std::vector<BingoBoard> BingoBoards;
	int NextBingoBoardLine = 1;
	while (NextBingoBoardLine + 25 <= Input.size())
	{
		BingoBoard CurrentBoard;
		for (int i = NextBingoBoardLine; i < NextBingoBoardLine + 25; ++i)
		{
			CurrentBoard.Numbers.push_back(stoi(Input[i]));
			CurrentBoard.UsedNumbers.push_back(false);
		}
		BingoBoards.push_back(CurrentBoard);

		NextBingoBoardLine += 25;
	}

	for (BingoBoard& CurrentBoard : BingoBoards)
	{
		CurrentBoard.SolveBoard(CalledNumbers);
	}

	std::sort(BingoBoards.begin(), BingoBoards.end(),
		[](const BingoBoard& Left, const BingoBoard& Right)
		{
			return Left.Turn < Right.Turn;
		});

	// 35670
	std::cout << BingoBoards[0].Score << '\n';
	// 22704
	std::cout << BingoBoards[BingoBoards.size() - 1].Score << '\n';
}