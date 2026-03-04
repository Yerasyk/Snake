#pragma once

struct Pos
{
	int x, y;

	bool operator==(const Pos& other) const{
		return x == other.x && y == other.y;
	}

	Pos& operator*=(int a) {
		x *= a;
		y *= a;
		return *this;
	}

	Pos operator*(int a) const{
		Pos temp = *this;
		temp *= a;
		return temp;
	}

	Pos operator+(const Pos& other) const{
		Pos temp = *this;
		temp.x += other.x;
		temp.y += other.y;
		return temp;
	}
};