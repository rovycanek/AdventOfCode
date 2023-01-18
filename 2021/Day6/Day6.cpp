#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <vector>
#include <array>
#include <numeric>


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
	constexpr int DaysInCycle = 9;
	std::array<int64_t, DaysInCycle> CurrentFish{};
	std::stringstream fishSchoolsStream(Input[0]);
	std::string newPool;
	while (std::getline(fishSchoolsStream, newPool, ','))
	{
		CurrentFish[std::stoi(newPool)]++;
	}

	int days = 256;
	for (int j = 0; j < days; j++) {
		std::array<int64_t, DaysInCycle> NextFish{};

		for (int j = 1; j < CurrentFish.size(); ++j)
		{
			NextFish[j - 1] += CurrentFish[j];
		}

		NextFish[6] += CurrentFish[0];
		NextFish[8] = CurrentFish[0];
		CurrentFish = NextFish;
	}

	std::cout << std::accumulate(CurrentFish.begin(), CurrentFish.end(), 0ull) << '\n';
}
