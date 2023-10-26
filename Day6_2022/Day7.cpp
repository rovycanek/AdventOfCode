#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <vector>
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


	
}
