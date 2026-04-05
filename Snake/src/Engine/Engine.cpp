#include "Engine.h"
#include "Game/SnakeGame.h"
//Renderers
#include "Render/ConsoleRenderer.h"
#include "Render/GUIRenderer.h"
//Inputs
#include "Input/SDLInput.h"
#include "Input/ConsoleInput.h"
//Others
#include <iostream>
#include <chrono> // For timing
#include <thread> // For sleep_for

#include <SDL3/SDL.h>

using SteadyClock = std::chrono::steady_clock;

Engine::Engine()
{
}

Engine::~Engine()
{
}	

void Engine::Run(Game& game, Renderer& renderer, InputSystem& input)
{
	const int UPS = 7;
	const auto tickDuration = std::chrono::milliseconds(1000 / UPS);
	auto lastTime = SteadyClock::now();
	auto accumulator = std::chrono::nanoseconds(0);
	Key key;

	game.Init();

	while (true)
	{	
		// Input Handling
		key = input.Poll();	
		if (key == Key::Quit) return;
		if (key != Key::None) game.HandleInput(key); //Handles movements and reset
	

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

#define USE_SDL 0

int main()
{
	// w + 4 - for side walls and gaps
	// h + 6 - for side walls(2), title(2), score(1), gameover (5)

#if USE_SDL
	int w=30, h=30;
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
		return 1;
	}

	GUIRenderer renderer(w + 4, h + 10, 16);
	SDLInput input;
#else
	int w = 30, h = 18;
	ConsoleRenderer renderer(w + 4, h + 10);
	ConsoleInput input;
#endif

	Engine engine;
	SnakeGame game (w,h);

	engine.Run(game, renderer, input);

#if USE_SDL
	SDL_Quit();
#endif

	return 0;
}