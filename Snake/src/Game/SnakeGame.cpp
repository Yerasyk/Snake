#include "SnakeGame.h"

#include "Render/ConsoleRenderer.h"
// Engine Input
#include "Engine/Input/Input.h"

#include <iostream>
#include <random>

namespace {
	std::random_device rd;
	std::mt19937 gen(rd());
}


SnakeGame::SnakeGame(int width, int height): board(width, height), snake(Pos{5,5})
{
	pendingDir= snake.Direction();
	rand_x = std::uniform_int_distribution<> (0, board.getWidth()-1);
	rand_y = std::uniform_int_distribution<> (0, board.getHeight()-1);
	SpawnFood();
}

void SnakeGame::Init()
{
	gameOver = false;
	score = 0;
}

void SnakeGame::Reset() {
	
	snake = Snake(Pos{ 5,5 });
	pendingDir = Dir::Right;
	score = 0;
	SpawnFood();
	gameOver = false;
}

void SnakeGame::SpawnFood() {
	Pos f;
	while (true) {
		f = { rand_x(gen), rand_y(gen) };
		if (!snake.Contains(f))
			break;
	}
	food = f;
}

void SnakeGame::HandleInput(Key key) {
	// Set new direction
	switch (key) {
		//case Key::Down: pendingDir = Dir::Down; std::cout << "Down" << std::endl; break;
	case Key::Down: pendingDir = Dir::Down; break;
	case Key::Left: pendingDir = Dir::Left; break;
	case Key::Right: pendingDir = Dir::Right; break;
	case Key::Up: pendingDir = Dir::Up; break;
	case Key::Restart: Reset();
	default:;
	}
}

void SnakeGame::Update()
{
	bool grow = false;
	
	snake.SetDirection(pendingDir);

	// Check collisions
	Pos next = snake.NextHead();
	if (!board.InBounds(next) || (snake.Contains(next) && !(next == snake.Tail())))
		gameOver=true;

	// Check growing
	if (next == food) {
		grow = true; 
		score += 10;
		SpawnFood();
	}

	snake.Step(grow);
}

void SnakeGame::Render(Renderer& renderer)
{
	renderer.Clear();

	int title_y = 0;
	int play_area_top_y = 2; // Leaving a gap for Title

	int start_x = 2;

	int board_h = board.getHeight();
	int board_w = board.getWidth();

	//Title
	renderer.DrawString(start_x + (board_w / 2) - 2, title_y, "SNAKE");

	//Draw horizontals
	for (int i = -1; i <= board_w; i++) { // 2 walls
		renderer.DrawCell(i + start_x, play_area_top_y-1, CellType::Wall);
		renderer.DrawCell(i + start_x, board_h+play_area_top_y, CellType::Wall);
	}

	//Draw verticals 
	for (int i = 0; i < board_h; i++) { // 2 walls
		renderer.DrawCell(start_x - 1, i + play_area_top_y, CellType::Wall);
		renderer.DrawCell(start_x + board_w, i + play_area_top_y, CellType::Wall);
	}

	//Draw food
	renderer.DrawCell(food.x +start_x, food.y+ play_area_top_y, CellType::Food);

	//Draw Snake body
	for (const auto& segment : snake.getBody()) {
		renderer.DrawCell(segment.x+start_x, segment.y+ play_area_top_y, CellType::SnakeBody);
	}
	renderer.DrawCell(start_x + snake.Head().x, play_area_top_y + snake.Head().y, CellType::SnakeHead);
	
	//Score
	int score_y = play_area_top_y + board_h + 1;
	std::string scoreStr = "Score: " + std::to_string(score);
	renderer.DrawString(start_x, score_y, scoreStr);

	//Game Over
	if (gameOver) {
		renderer.DrawString(start_x, score_y+1, "============================");
		renderer.DrawString(start_x, score_y + 2, "       GAME OVER          ");
		renderer.DrawString(start_x, score_y + 3, "============================");
		renderer.DrawString(start_x, score_y + 4, "+ Press R to restart");
		renderer.DrawString(start_x, score_y + 5, "+ Press Q to quit");
	}

	renderer.Display();
}