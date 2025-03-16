#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

struct Point2D {
	int x, y;
};

Point2D NextPoint(const Point2D& current) {
	int direction[4][2] = {{0,1}, {0,-1}, {1,0} , {-1,0}};
	int step = rand() % 4;

	Point2D NewPoint = {current.x + direction[step][0], current.y + direction[step][1]};
	
	return NewPoint; 
};

std::vector<Point2D> RandomWalk(Point2D& current) {
	std::vector<Point2D> path;

	for (int i = 0; i < 100; i++) {
		current = NextPoint(current);
		path.push_back(current);
	}
	
	return path;
}

void exportToCSV(std::vector<Point2D> path, const std::string& filename){
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cerr << "File could not be opened" << std::endl;
		return;
	}
	
	file << "Step X,Y\n";
	
	for (auto& point : path) {
		file << point.x << "," << point.y << "\n";
	}

	file.close();
	std::cout << "Random Walk succesfully exported to "<< filename << "\n";
}


int main() {
	Point2D InitialPoint = {0, 0};
	std::vector<Point2D> path;

	path = RandomWalk(InitialPoint);
	exportToCSV(path, "RandomWalk2D.csv");
	return 0;
}
