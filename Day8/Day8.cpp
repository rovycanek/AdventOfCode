#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>  


bool areSegmentsIn(std::string big, std::string part) {
	for (char segment : part) {
		if (big.find(segment) == std::string::npos)
			return false;
	}
	return true;
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

	int counter = 0;
	for (int i = 0; i < Input.size(); i) {
		std::vector<std::string> mangledWords{};
		for (int j=0; j < 10; j++) {
			mangledWords.push_back(Input[i]);
			i++;
		}
		// skip the separator
		i++;
		std::vector<std::string> targetWords{};
		for (int j=0; j < 4; j++) {
			targetWords.push_back(Input[i]);
			i++;
		}

		// decode Number 1
		std::string one;
		for (std::string word : mangledWords) {
			if (word.size() == 2) {
				one = word;
			}
		}
		// decode Number 4
		std::string four;
		for (std::string word : mangledWords) {
			if (word.size() == 4) {
				four = word;
			}
		}
		// decode Number 7
		std::string seven;
		for (std::string word : mangledWords) {
			if (word.size() == 3) {
				seven = word;
			}
		}
		// decode Number 8
		std::string eight;
		for (std::string word : mangledWords) {
			if (word.size() == 7) {
				eight = word;
			}
		}
		// decode Number 3
		std::string three;
		for (std::string word : mangledWords) {
			if (word.size() == 5 && areSegmentsIn(word, seven)) {
				three = word;
			}
		}

		// decode Number 6
		std::string six;
		for (std::string word : mangledWords) {
			if (word.size() == 6 && !areSegmentsIn(word, one)) {
				six = word;
			}
		}
		// decode Number 9
		std::string nine;
		for (std::string word : mangledWords) {
			if (word.size() == 6 && areSegmentsIn(word, three)) {
				nine = word;
			}
		}
		// decode Number 0
		std::string zero;
		for (std::string word : mangledWords) {
			if (word.size() == 6 && !areSegmentsIn(word, nine) && !areSegmentsIn(word, six)) {
				zero = word;
			}
		}
		// decode Number 5
		std::string five;
		for (std::string word : mangledWords) {
			if (word.size() == 5 && areSegmentsIn(six, word)) {
				five = word;
			}
		}

		// decode Number 2
		std::string two;
		for (std::string word : mangledWords) {
			if (word.size() == 5 && !areSegmentsIn(word, five) && !areSegmentsIn(word, three)) {
				two = word;
			}
		}

		/*std::cout << "0: "<< zero << std::endl;
		std::cout << "1: " << one << std::endl;
		std::cout << "2: " << two << std::endl;
		std::cout << "3: " << three << std::endl;
		std::cout << "4: " << four << std::endl;
		std::cout << "5: " << five << std::endl;
		std::cout << "6: " << six << std::endl;
		std::cout << "7: " << seven << std::endl;
		std::cout << "8: " << eight << std::endl;
		std::cout << "9: " << nine << std::endl;*/
		/*for (std::string target : targetWords) {
			if (areSegmentsIn(target, one) && areSegmentsIn(one, target))
				counter++;
			if (areSegmentsIn(target, four) && areSegmentsIn(four, target))
				counter++;
			if (areSegmentsIn(target, seven) && areSegmentsIn(seven, target))
				counter++;
			if (areSegmentsIn(target, eight) && areSegmentsIn(eight, target))
				counter++;
		}*/
		
		for (int j = 0; j < targetWords.size(); j++) {
			if (areSegmentsIn(targetWords[j], zero) && areSegmentsIn(zero, targetWords[j]))
				counter += pow(10, 3 - j) * 0;
			if (areSegmentsIn(targetWords[j], one) && areSegmentsIn(one, targetWords[j]))
				counter += pow(10, 3 - j) * 1;
			if (areSegmentsIn(targetWords[j], two) && areSegmentsIn(two, targetWords[j]))
				counter += pow(10, 3 - j) * 2;
			if (areSegmentsIn(targetWords[j], three) && areSegmentsIn(three, targetWords[j]))
				counter += pow(10, 3 - j) * 3;
			if (areSegmentsIn(targetWords[j], four) && areSegmentsIn(four, targetWords[j]))
				counter += pow(10, 3 - j) * 4;
			if (areSegmentsIn(targetWords[j], five) && areSegmentsIn(five, targetWords[j]))
				counter += pow(10, 3 - j) * 5;
			if (areSegmentsIn(targetWords[j], six) && areSegmentsIn(six, targetWords[j]))
				counter += pow(10, 3 - j) * 6;
			if (areSegmentsIn(targetWords[j], seven) && areSegmentsIn(seven, targetWords[j]))
				counter += pow(10, 3 - j) * 7;
			if (areSegmentsIn(targetWords[j], eight) && areSegmentsIn(eight, targetWords[j]))
				counter += pow(10, 3 - j) * 8;
			if (areSegmentsIn(targetWords[j], nine) && areSegmentsIn(nine, targetWords[j]))
				counter += pow(10, 3 - j) * 9;

		}





	}
	std::cout << counter << std::endl;
	
}
