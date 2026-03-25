#pragma once

#include "RendererInterface.h"

struct SDL_Window;
struct SDL_Renderer;

class SDLRenderer : public Renderer
{
public:
	SDLRenderer(int width, int height, int cellSize);
	~SDLRenderer() override;

	void Clear() override;
	void Display() override;
	void Draw(int x, int y, char symbol) override;
	void DrawString(int x, int y, const std::string& text) override;
	void DrawGameOver(int y) override;

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	int windowWidth;
	int windowHeight;
	int cellSize;
};

