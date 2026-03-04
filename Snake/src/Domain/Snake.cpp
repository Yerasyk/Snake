#include "Snake.h"

#include <cassert>

namespace {
	Pos Delta(Dir dir) {
		switch (dir) {
		case Dir::Up: return Pos{ 0, -1 };
		case Dir::Down: return Pos{ 0, 1 };
		case Dir::Left: return Pos{ -1, 0 };
		case Dir::Right: return Pos{ 1,0 };
		default: return { 0,0 };
		}
	}

	bool IsOpposite(Dir a, Dir b) {
		return Delta(a) + Delta(b) == Pos{ 0,0 };
	}
}

Snake::Snake(Pos start, int initialLength, Dir startDir) {
	dir = startDir;
	Pos opp = Delta(dir) * (-1);
	for (int i = 0; i < initialLength; i++) {
		Pos next = start + opp*i;
		body.push_back(next);
	}
}

const std::deque<Pos>& Snake::getBody() const{
	return body;
}

const Pos& Snake::Head() const{
	return body.front();
}

const Pos& Snake::Tail() const {
	assert(!body.empty()); //Might not even need, since body shouldn't be empty(); same for the head.
	return body.back();
}

bool Snake::Contains(const Pos& pos) const {
	for (auto& el : body) {
		if (pos == el) return true;
	}
	return false;
}

Dir Snake::Direction() const {
	return dir;
}

void Snake::SetDirection(Dir newDir) {
	if(!IsOpposite(dir, newDir))
		dir = newDir;
}

Pos Snake::NextHead() const {
	return Head() + Delta(dir);
}

void Snake::Step(bool grow) {
	body.push_front(NextHead());
	if (!grow) body.pop_back();
}

