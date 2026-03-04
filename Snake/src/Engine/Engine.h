#pragma once

class Game;
class Renderer;

class Engine
{
	public:
	Engine();
	~Engine();
	void Run(Game&, Renderer&);
};