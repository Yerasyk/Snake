#include "Engine.h"
#include "Game/SnakeGame.h"
#include "Render/ConsoleRenderer.h"
#include "Render/UIRenderer.h"
#include "Engine/Input.h"
#include <iostream>
#include <chrono> // For timing
#include <thread> // For sleep_for

//#include <conio.h> // For input handling _kbhit(), _getch() - replaced with SDL
#include <SDL3/SDL.h>

using SteadyClock = std::chrono::steady_clock;

namespace {
	Key GetInput(SDL_Keycode key) {
		switch (key) {
		case SDLK_W: return Key::Up;
		case SDLK_S: return Key::Down;
		case SDLK_A: return Key::Left;
		case SDLK_D: return Key::Right;
		case SDLK_Q: return Key::Quit;
		case SDLK_R: return Key::Restart;
		}
		return Key::None;
	}
}

Engine::Engine()
{
}

Engine::~Engine()
{
}	

void Engine::Run(Game& game, Renderer& renderer)
{
	const int UPS = 5;
	const auto tickDuration = std::chrono::milliseconds(1000 / UPS);
	auto lastTime = SteadyClock::now();
	auto accumulator = std::chrono::nanoseconds(0);
	SDL_Event event;
	Key key;

	game.Init();

	while (true)
	{	
		// Input Handling
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_KEY_DOWN) key = GetInput(event.key.key);
			if (event.type == SDL_EVENT_QUIT || key == Key::Quit) return;
			if (key == Key::Restart)
			{
				game.HandleInput(Key::Restart);
				lastTime = SteadyClock::now();
				continue;
			}
		}		

		if (key != Key::None) {
			game.HandleInput(key);
		}

		// Game Update
		auto now = SteadyClock::now();
		auto delta = now - lastTime;
		lastTime = now;

		accumulator += delta;

		while (accumulator >= tickDuration) {
			if (game.IsRunning()) {
				game.Update();
			}

			accumulator -= tickDuration;
		}

		//Rendering
		game.Render(renderer);
		
		//Sleep (needs for Rendering frames; later might be adjusted)
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


int main()
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
		return 1;
	}

	int w=20, h=10;

	Engine engine;
	SnakeGame game;
	
	// w + 4 - for side walls and gaps
	// h + 6 - for side walls(2), title(2), score(1), gameover (5)

	// Renderers
	ConsoleRenderer renderer(w + 4, h + 10);
	//UIRenderer renderer(w + 4, h + 10, 32);

	engine.Run(game, renderer);
	
	return 0;
}