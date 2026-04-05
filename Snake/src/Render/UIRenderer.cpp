//#include "UIRenderer.h"
//#include <SDL3/SDL.h>
//#include <stdexcept>
//
//UIRenderer::UIRenderer(int width, int height, int cellSize) : 
//	windowWidth(width), windowHeight(height), cellSize(cellSize)
//{
//	window = SDL_CreateWindow(
//		"Snake", 
//		windowWidth*cellSize, 
//		windowHeight*cellSize, 
//		0);
//
//	if (!window) {
//		throw std::runtime_error(SDL_GetError());
//	}
//
//	renderer = SDL_CreateRenderer(window, nullptr);
//
//	if (!renderer) {
//		SDL_DestroyWindow(window);
//		throw std::runtime_error(SDL_GetError());
//	}
//}
//
//UIRenderer::~UIRenderer() {
//	if(renderer) SDL_DestroyRenderer(renderer);
//	if(window) SDL_DestroyWindow(window);
//}
//
//void UIRenderer::Clear()
//{
//	SDL_SetRenderDrawColor(renderer, 120, 120, 255, 255);
//	SDL_RenderClear(renderer);
//}
//
//void UIRenderer::Display()
//{
//	SDL_RenderPresent(renderer);
//}
//
//void UIRenderer::DrawCell(int x, int y, CellType cell) {
//
//}
//
//void UIRenderer::DrawChar(int x, int y, char symbol)
//{
//	SDL_FRect rect = { x * cellSize, y * cellSize, cellSize, cellSize };
//	switch (symbol) {
//		case 'X': 
//			SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
//			break;
//		case 'O': 
//			SDL_SetRenderDrawColor(renderer, 230, 10, 10, 255);
//			break;
//		case '#': 
//			SDL_SetRenderDrawColor(renderer, 10, 10, 250, 255);
//			break;
//		case '@': 
//			SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
//			break;
//		default:
//			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//			break;
//	}
//	SDL_RenderFillRect(renderer, &rect);
//}
//
//void UIRenderer::DrawString(int x, int y, const std::string& text)
//{
//}
//
