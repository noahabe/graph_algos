#include <iostream>
#include <random>

class Point;
std::ostream& operator<<(std::ostream& os,Point& p);

class Point{
public:
	double x;
	double y;
	Point(double _x, double _y) : x(_x),y(_y) {}
	friend std::ostream& operator<<(std::ostream& os,Point& p);
};

std::ostream& operator<<(std::ostream& os,Point& p){
	os << "(" << p.x << ", " << p.y << ")" << "\n";
	return os;
}

Point generate_random_point(double startx = -1.0,double endx = 1.0,
			double starty = -1.0,double endy = 1.0) {
	
	static std::random_device rndDevice;
	static std::mt19937 eng(rndDevice());

	static std::uniform_real_distribution<double> distx(startx,endx);
	static std::uniform_real_distribution<double> disty(starty,endy);
	
	return Point(distx(eng),disty(eng));	
}

int get_random_int(int start,int end) {
	static std::random_device rndDevice;
	static std::mt19937 eng(rndDevice());
	std::uniform_int_distribution<int> dist(start,end);
	return dist(eng);	
}

std::string get_random_string(int len=10) {
	std::string retval;
	for (int i = 0; i < len; ++i)
		retval += (char)get_random_int('A','z');	
	return retval;
}

