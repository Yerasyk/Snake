//#include "SDLInput.h"
//#include <SDL3/SDL_events.h>
//
//namespace {
//	Key GetInput(SDL_Keycode key) {
//		switch (key) {
//		case SDLK_W: return Key::Up;
//		case SDLK_S: return Key::Down;
//		case SDLK_A: return Key::Left;
//		case SDLK_D: return Key::Right;
//		case SDLK_Q: return Key::Quit;
//		case SDLK_R: return Key::Restart;
//		}
//		return Key::None;
//	}
//}
//
//Key SDLInput::Poll() {
//	SDL_Event event;
//	Key result = Key::None;
//	while (SDL_PollEvent(&event)) {
//		if (event.type == SDL_EVENT_KEY_DOWN)  
//			result = GetInput(event.key.key);
//
//		if (event.type == SDL_EVENT_QUIT) 
//			result = Key::Quit;
//	}
//	return result;
//}