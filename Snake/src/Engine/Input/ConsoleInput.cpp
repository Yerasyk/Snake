#include "ConsoleInput.h"
#include <conio.h> 

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

Key ConsoleInput::Poll() {
	return GetInput();
}