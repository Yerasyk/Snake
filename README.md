# Snake

A Snake game built in C++ as a personal engine-architecture learning project. It supports two render modes — a classic terminal view and a hardware-accelerated SDL3 window — without changing any game logic.

---

## Demo

**SDL Mode**

![SDL_MODE](https://github.com/Yerasyk/Snake/blob/master/SDL-snake.gif)

**Console Mode**

![CONSOLE_MODE](https://github.com/Yerasyk/Snake/blob/master/Console-snake.gif)

---

## How it works

The project is split into three independent layers that talk to each other through abstract interfaces:

```
Engine
  ├── Game  (SnakeGame)
  ├── Renderer  (ConsoleRenderer / GUIRenderer)
  └── InputSystem  (ConsoleInput / SDLInput)
```

- **Engine** runs the game loop at a fixed 7 updates per second (adjustable), handles timing, and wires the three layers together.
- **Game** (`Game` interface → `SnakeGame`) owns all the rules: snake movement, food spawning, collision detection, scoring, and game-over state.
- **Renderer** (`Renderer` interface) draws the board cell by cell. Swap `ConsoleRenderer` for `GUIRenderer` and the game looks completely different — the logic doesn't change.
- **InputSystem** (`InputSystem` interface) translates raw key events into a shared `Key` enum. Console and SDL each have their own implementation.

Switching between modes is a single `#define USE_SDL` flag in `Engine.cpp`.

---

## Tech stack

| What | Why |
|---|---|
| C++ | Core language |
| SDL3 | Window, rendering, and input for GUI mode |
| SDL3-ttf | Text rendering (score, game-over screen) |
| vcpkg | Dependency management |

---

## Building

Dependencies are managed via vcpkg. Open the solution in Visual Studio, make sure the vcpkg integration is active, and build. No manual library setup needed.

---

## Project structure

```
Snake/src/
├── Domain/          # Pure game data: Snake, Board, Pos
├── Game/            # SnakeGame logic, GameInterface
├── Engine/
│   ├── Engine       # Game loop
│   └── Input/       # InputSystem interface + Console & SDL backends
└── Render/          # Renderer interface + Console & SDL backends
```
