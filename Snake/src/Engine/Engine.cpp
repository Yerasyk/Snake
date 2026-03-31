#include "Engine.h"
#include "Game/SnakeGame.h"
//Renderers
#include "Render/ConsoleRenderer.h"
#include "Render/UIRenderer.h"
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
	const int UPS = 5;
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


int main()
{

	//if (!SDL_Init(SDL_INIT_VIDEO)) {
	//	std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
	//	return 1;
	//}

	int w=20, h=10;

	Engine engine;
	SnakeGame game;
	
	// w + 4 - for side walls and gaps
	// h + 6 - for side walls(2), title(2), score(1), gameover (5)

	// Renderers
	ConsoleRenderer renderer(w + 4, h + 10);
	//UIRenderer renderer(w + 4, h + 10, 32);

	//Input
	ConsoleInput input;

	engine.Run(game, renderer, input);
	
	return 0;
}