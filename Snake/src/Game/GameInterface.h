#pragma once

enum class Key;
class Renderer;

class Game {
public:
	virtual ~Game() = default;
	virtual void Update(Key) = 0;
	virtual void Init() = 0;
	virtual void Reset() = 0;
	virtual void Render(Renderer&) = 0;
	virtual bool IsRunning() const = 0;
};