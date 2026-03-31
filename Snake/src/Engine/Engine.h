#pragma once

class Game;
class Renderer;
class InputSystem;

class Engine
{
	public:
	Engine();
	~Engine();
	void Run(Game&, Renderer&, InputSystem&);
};