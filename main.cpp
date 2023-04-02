#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"
#include "Window.h"

#include <iostream>

void SetPixel(SDL_Surface* surface, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_LockSurface( surface );
    std::cout << "X = " << x << " Y = " << y << std::endl;
    uint8_t* pixelArr = (uint8_t*)surface->pixels;
    pixelArr[y * surface->pitch + x * surface->format->BytesPerPixel + 0] = r;
    pixelArr[y * surface->pitch + x * surface->format->BytesPerPixel + 1] = g;
    pixelArr[y * surface->pitch + x * surface->format->BytesPerPixel + 2] = b;
    SDL_UnlockSurface( surface );
}

int main( int argc, char* argv[] )
{

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        spdlog::error("Failed to initialize the SDL\n");
        return -1;
    }

    HREG::Window* window = new HREG::Window("HREG", 1280, 720);
    
    while ( window->windowShouldClose() )
    {
        window->Render();
        window->Display();
    }

    window->CleanUp();
	SDL_Quit();
    return 0;
}