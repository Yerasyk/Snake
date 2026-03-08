#include "Engine.h"
#include "Game/SnakeGame.h"
#include "Render/ConsoleRenderer.h"
#include "Engine/Input.h"
#include <iostream>
#include <chrono> // For timing
#include <thread> // For sleep_for
#include <conio.h> // For _kbhit(), _getch()

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
			case 'r': return Key::Restart;
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
			char key = _getch();
			if (key == 'r')
			{
				game.Reset();
				tickStart = SteadyClock::now();
				continue;
			}
			if (key == 'q') return;
			continue;
		}
		
		//Gmae is Running
		auto elapsed = SteadyClock::now() - tickStart;
		if (elapsed >= tickDuration) {
			Key key = GetInput();
			if (key == Key::Restart) game.Reset();
			if (key == Key::Quit) break;
			game.Update(key);
			game.Render(renderer);
			tickStart += tickDuration;
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
	// h + 6 - for side walls(2), title(2), score(1), gameover (5)
	ConsoleRenderer renderer(w+4, h+10);
	engine.Run(game, renderer);
	
	return 0;
}