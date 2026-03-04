#pragma once
#include <deque>
#include "Pos.h"

enum class Dir {Up, Down, Left, Right};

class Snake
{
private:
	std::deque<Pos> body;
	Dir dir;
public:
	Snake(Pos start, int initialLength = 3, Dir startDir = Dir::Right);
	const Pos& Head() const;
	const Pos& Tail() const;
	const std::deque<Pos>&  getBody() const;
	bool Contains(const Pos& pos) const;
	Dir Direction() const;
	void SetDirection(Dir newDir);
	Pos NextHead() const;
	void Step(bool grow=false);
};

