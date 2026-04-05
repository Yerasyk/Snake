//#pragma once
//
//#include "RendererInterface.h"
//
//struct SDL_Window;
//struct SDL_Renderer;
//
//class UIRenderer : public Renderer
//{
//public:
//	UIRenderer(int width, int height, int cellSize);
//	~UIRenderer() override;
//
//	void Clear() override;
//	void Display() override;
//	void DrawCell(int x, int y, CellType cell) override;
//	void DrawChar(int x, int y, char symbol) override;
//	void DrawString(int x, int y, const std::string& text) override;
//
//private:
//	SDL_Window* window = nullptr;
//	SDL_Renderer* renderer = nullptr;
//
//	int windowWidth;
//	int windowHeight;
//	int cellSize;
//};
//
