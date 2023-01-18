#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <vector>

class Point {
public:
	int x;
	int y;
	Point() {
		x = 0;
		y = 0;
	}
	Point(std::string str) {
		std::stringstream strStream{ str };
		std::string numberX;
		std::string numberY;
		std::vector<int> CalledNumbers;
		std::getline(strStream, numberX, ',');
		std::getline(strStream, numberY, ',');
		x = std::stoi(numberX);
		y = std::stoi(numberY);
	}
};

template <typename T>
void ascending(T& dFirst, T& dSecond)
{
	if (dFirst > dSecond)
		std::swap(dFirst, dSecond);
}

void addPointsToGrid(Point start, Point end, std::vector <std::vector <int>>& grid) {

	if (start.x == end.x) {
	ascending(start.y, end.y);
		for (int i = start.y; i <= end.y; i++) {
			grid[i][start.x]++;
		}
	}
	if (start.y == end.y) {
		ascending(start.x, end.x);
		for (int i = start.x; i <= end.x; i++) {
			grid[start.y][i]++;
		}
	}
	if (abs(end.x - start.x) == abs(end.y - start.y)) {
		int stepX = (end.x - start.x) / abs(end.x - start.x);
		int stepY = (end.y - start.y) / abs(end.y - start.y);
		for (int i = 0; i <= abs(end.x - start.x); i++) {
			grid[start.y+ stepY*i][start.x + stepX * i]++;
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
	std::vector <Point> points;
	for (int i = 0; i < Input.size(); i++) {
		// start 
		points.push_back(Point(Input[i]));
		i++;
		// arrow
		i++;
		// end
		points.push_back(Point(Input[i]));
	}
	
	// max x
	int maxX = 0;
	int maxY = 0;
	for (Point point : points) {
		if (point.x > maxX)
			maxX = point.x;
		if (point.y > maxY)
			maxY = point.y;
	}
	maxX++;
	maxY++;

	std::vector <std::vector <int>> grid;
	grid.resize(maxY);
	for (std::vector <int> &row : grid) {
		row.resize(maxX);
	}
	for (int i = 0; i < points.size(); i += 2) {
		addPointsToGrid(points[i], points[i + 1], grid);
	}

	int totalOverlaps = 0;
	for (std::vector <int> row : grid) {
		for (int element : row) {
			if (element >= 2)
				totalOverlaps++;
		}
	}
	std::cout << totalOverlaps << '\n';
}