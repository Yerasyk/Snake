#pragma once

#include <string>

class Renderer{
public:
	virtual ~Renderer() = default;
	virtual void Display() = 0;
	virtual void Clear() = 0;
	virtual void Draw(int x, int y, char symbol) = 0;
	virtual void DrawString(int x, int y, const std::string& text) = 0;
	virtual void DrawGameOver(int y) = 0;
};