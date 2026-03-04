#include "Board.h"
#include "Pos.h"

Board::Board(int width, int height) : width(width), height(height){}

bool Board::InBounds(const Pos& p) const {
	return p.x>=0 && p.x < width && 
		p.y >= 0 && p.y < height;
}

int Board::getWidth() const{
	return width;
}

int Board::getHeight() const{
	return height;
}

