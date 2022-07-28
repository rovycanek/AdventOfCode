#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>  


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
	std::vector<int> crabsPosition{};
	std::stringstream crabsPositionStream(Input[0]);
	std::string newCrab;
	while (std::getline(crabsPositionStream, newCrab, ','))
	{
		crabsPosition.push_back(std::stoi(newCrab));
	}
	std::vector <int64_t> fuelRequirement;

	int max = *max_element(crabsPosition.begin(), crabsPosition.end());
	int min = *min_element(crabsPosition.begin(), crabsPosition.end());
	fuelRequirement.resize(max+1);
	for (int i = 0; i <= max; i++) {
		for (int crabPosition : crabsPosition) {
			for (int k = 0; k <= abs(crabPosition - i); k++) {
				fuelRequirement[i] += k;

			}
		}
	}

	max = *max_element(fuelRequirement.begin(), fuelRequirement.end());
	min = *min_element(fuelRequirement.begin(), fuelRequirement.end());

	std::cout << min << std::endl;
	std::cout << find(fuelRequirement.begin(), fuelRequirement.end(), min) - fuelRequirement.begin() << std::endl;
	
}
