#pragma once

#include "GameInterface.h"

// Game Domain Objects
#include "Domain/Board.h"
#include "Domain/Pos.h"
#include "Domain/Snake.h"

#include <random>

enum class Key;
class Renderer;

class SnakeGame : public Game
{
private:
	Snake snake;
	Board board;
	Pos food;
	Dir pendingDir;
	int score = 0;
	std::uniform_int_distribution<> rand_x;
	std::uniform_int_distribution<> rand_y;
	bool gameOver = false;
	void SpawnFood();
public:
	SnakeGame(int w= 20, int h=10);
	void Update(Key key) override;
	void Render(Renderer&) override;
	void Init() override;
	void Reset() override;
	bool IsRunning() const override { return !gameOver; };
};
