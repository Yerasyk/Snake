#pragma once

struct Pos;

class Board
{
private:
	int width;
	int height;
public:
	Board(int width, int height);
	bool InBounds(const Pos& pos) const;
	int getWidth() const;
	int getHeight() const;
};