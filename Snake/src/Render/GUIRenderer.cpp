#include "GUIRenderer.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdexcept>

namespace {
	void SetDrawColor(SDL_Renderer* renderer,CellType cell) {
		switch (cell) {
		case CellType::SnakeHead:
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // bright green
			break;

		case CellType::SnakeBody:
			SDL_SetRenderDrawColor(renderer, 0, 180, 0, 255); // darker green
			break;

		case CellType::Food:
			SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255); // brighter red
			break;

		case CellType::Wall:
			SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255); // darker gray
			break;

		case CellType::Empty:
			SDL_SetRenderDrawColor(renderer, 30, 30, 50, 255); // match background
			break;
		default: 
			//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			break;
		}
	};
}

GUIRenderer::GUIRenderer(int width, int height, int cellSize) : 
	windowWidth(width), windowHeight(height), cellSize(cellSize)
{
	// Initializing extension for working with text
	if (!TTF_Init()) {
		throw std::runtime_error(SDL_GetError());
	}

	font = TTF_OpenFont("assets/arial.ttf", cellSize);
	if (!font) {
		throw std::runtime_error(SDL_GetError());
	}

	//Creating window
	window = SDL_CreateWindow(
		"Snake", 
		windowWidth*cellSize, 
		windowHeight*cellSize, 
		0);

	if (!window) {
		throw std::runtime_error(SDL_GetError());
	}

	//Creating Renderer
	renderer = SDL_CreateRenderer(window, nullptr);

	if (!renderer) {
		SDL_DestroyWindow(window);
		throw std::runtime_error(SDL_GetError());
	}
}

GUIRenderer::~GUIRenderer() {
	if(renderer) SDL_DestroyRenderer(renderer);
	if(window) SDL_DestroyWindow(window);
	if (font) TTF_CloseFont(font);
	TTF_Quit();
}

void GUIRenderer::Clear()
{
	SetDrawColor(renderer, CellType::Empty);
	SDL_RenderClear(renderer);
}

void GUIRenderer::Display()
{
	SDL_RenderPresent(renderer);
}

void GUIRenderer::DrawChar(int x, int y, char symbol) {

}

void GUIRenderer::DrawCell(int x, int y, CellType cell)
{
	float pad = cellSize * 0.1f;

	SDL_FRect rect = {
		x * cellSize + pad,
		y * cellSize + pad,
		cellSize - 2 * pad,
		cellSize - 2 * pad
	};
	SetDrawColor(renderer, cell);
	SDL_RenderFillRect(renderer, &rect);
}

void GUIRenderer::DrawString(int x, int y, const std::string& text)
{
	SDL_Color color = { 255, 255, 255, 255 };

	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), color);
	if (!surface) return;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) return;

	SDL_FRect dst = {
		x * cellSize,
		y * cellSize,
		(float)surface->w,
		(float)surface->h
	};

	SDL_DestroySurface(surface);

	SDL_RenderTexture(renderer, texture, nullptr, &dst);
	SDL_DestroyTexture(texture);
}

