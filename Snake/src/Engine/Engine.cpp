#include "Engine.h"
#include "Game/SnakeGame.h"
#include "Render/ConsoleRenderer.h"
#include "Engine/Input.h"
#include <iostream>
#include <chrono> // For timing
#include <thread> // For sleep_for
#include <conio.h> // For _kbhit() -- get last pressed key; and _getch() -- get the key

using SteadyClock = std::chrono::steady_clock;

namespace {
	Key GetInput() {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 'w': return Key::Up;
			case 's': return Key::Down;
			case 'a': return Key::Left;
			case 'd': return Key::Right;
			case 'q': return Key::Quit;
			}
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
	auto tickStart = SteadyClock::now();
	int steps = 0;
	game.Init();
	while (true)
	{	
		if (!game.IsRunning()) {
			std::cout << "===========================" << std::endl;
			std::cout << "        GAME OVER          " << std::endl;
			std::cout << "===========================" << std::endl;
			break;
		}

		auto elapsed = SteadyClock::now() - tickStart;
		if (elapsed>=tickDuration) {
			Key key = GetInput();
			if (key == Key::Quit) break;
			game.Update(key);
			game.Render(renderer);
			tickStart +=tickDuration;
			steps++;
		}
		else {
			auto remainingTime = tickDuration - elapsed;
			std::this_thread::sleep_for(remainingTime);
		}
	}
}


int main()
{
	int w=20, h=10;

	Engine engine;
	SnakeGame game;
	// w + 4 - for side walls and gaps
	// h + 6 - for side walls, title and score
	ConsoleRenderer renderer(w+4, h+6);
	engine.Run(game, renderer);
	
	std::cin.get();
	return 0;
}