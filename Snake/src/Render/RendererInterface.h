#pragma once

#include <string>

enum class CellType {
	Empty,
	SnakeHead,
	SnakeBody,
	Food,
	Wall
};

class Renderer{
public:
	virtual ~Renderer() = default;
	virtual void Display() = 0;
	virtual void Clear() = 0;
	virtual void DrawCell(int x, int y, CellType cell) = 0;
	virtual void DrawChar(int x, int y, char a) = 0;
	virtual void DrawString(int x, int y, const std::string& text) = 0;
};