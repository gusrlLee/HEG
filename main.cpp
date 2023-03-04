#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"

#include <iostream>

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        spdlog::error("Failed to initialize the SDL\n");
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

    if ( !window ) 
    {
        spdlog::error("Failed to create SDL window, Try Again\n");
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        spdlog::error("Failed to get the surface from the window\n");
        return -1;
    }

    spdlog::info("Start Hyeon Rendering Engine!\n");
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);

    return 0;
}