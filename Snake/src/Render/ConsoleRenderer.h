#pragma once

#include "RendererInterface.h"
#include <vector>


class ConsoleRenderer: public Renderer
{
private:
	std::vector<char> buffer;
	int width, height;
		
public:
	ConsoleRenderer(int width, int height);
	~ConsoleRenderer();
	void Clear() override;
	void Display() override;
	void DrawCell(int x, int y, CellType cell) override;
	void DrawChar(int x, int y, char symbol) override;
	void DrawString(int x, int y, const std::string& text) override;
};

