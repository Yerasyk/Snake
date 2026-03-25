//#include <SDL3/SDL.h>
//#include <iostream>
//
//int main(int argc, char* argv[]) {
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::printf("SDL couldn't be initialized");
//        return -1;
//    }
//    int w=500, h = 500;
//    SDL_Window* window = SDL_CreateWindow(
//        "MySDLWindow",
//        w, h,
//        (SDL_WINDOW_RESIZABLE)
//    );
//
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
//    bool running = true;
//    SDL_Event event;
//
//    while (running) {
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_EVENT_QUIT) {
//                running = false;
//            }
//
//            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_W) {
//                int w, h;
//                SDL_GetWindowSize(window, &w, &h);
//
//                SDL_SetWindowSize(window, w + 10, h + 10);
//            }
//        }
//        
//        //Update Frame
//
//        //Render
//        SDL_SetRenderDrawColor(renderer, 240, 60, 120, 200);
//        SDL_RenderClear(renderer);
//
//        //Draw stuff into buffer
//        SDL_FRect rect = { 100,100, 200,150 };
//        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
//        SDL_RenderFillRect(renderer, &rect);
//
//        //Outputs buffer
//        SDL_RenderPresent(renderer);
//    }
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}