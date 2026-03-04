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
	void Clear() override;
	void Display() override;
	void Draw(int x, int y, char symbol) override;
	void DrawString(int x, int y, const std::string& text) override;
};

