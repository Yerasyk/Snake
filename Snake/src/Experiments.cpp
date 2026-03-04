#include <iostream>

struct Pos {
	int x, y;

	bool operator==(const Pos& other) const {
		return x == other.x && y == other.y;
	}
};

//int main() {
//	Pos a { 1,2 };
//	Pos b { 1,4 };
//	if (a == b)
//		std::cout << "True";
//	else
//		std::cout << "False";
//}