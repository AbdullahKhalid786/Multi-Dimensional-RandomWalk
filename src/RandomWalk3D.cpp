#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

struct Point3D {
	int x, y, z;
};

Point3D NextPoint(const Point3D& current) {
	int direction[6][3]= {{0,1,0}, {0,-1,0}, {1,0,0} , {-1,0,0}, {0,0,1}, {0,0,-1}};
	int step = rand() % 6;

	Point3D NewPoint = {current.x + direction[step][0], current.y + direction[step][1], current.z + direction[step][2]};
	
	return NewPoint; 
};

std::vector<Point3D> RandomWalk(Point3D& current) {
	std::vector<Point3D> path;

	for (int i = 0; i < 100; i++) {
		current = NextPoint(current);
		path.push_back(current);
	}
	
	return path;
}

void exportToCSV(std::vector<Point3D> path, const std::string& filename){
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cerr << "File could not be opened" << std::endl;
		return;
	}
	
	file << "Step X,Y,Z\n";
	
	for (auto& point : path) {
		file << point.x << "," << point.y << "," << point.z << "\n";
	}

	file.close();
	std::cout << "Random Walk succesfully exported to "<< filename << "\n";
}


int main() {
	Point3D InitialPoint = {0, 0, 0};
	std::vector<Point3D> path;

	path = RandomWalk(InitialPoint);
	exportToCSV(path, "../data/RandomWalk3D.csv");
	return 0;
}
