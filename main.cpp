#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"

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

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        spdlog::error("Failed to initialize the SDL\n");
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

    if ( !window ) 
    {
        spdlog::error("Failed to create SDL window, Try Again\n");
        return -1;
    }

    // if APPLE device
    // SDL_SetHint(SDL_HINT_RENDER_DRIVER, "metal");
    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // SDL_RendererInfo rendererInfo;
    // SDL_GetRendererInfo(renderer, &rendererInfo);
    // SDL_Log("Renderer: %s", rendererInfo.name);

    SDL_Surface* screen = SDL_GetWindowSurface( window );
    if ( screen == NULL )
    {
        spdlog::error("Nullptr screen!\n");
        return -1;
    }

    spdlog::info("Start Hyeon Rendering Engine!\n");
    bool systemRunning = true;


    while ( systemRunning ) 
    {
        SDL_Event event;
        int x, y;
        Uint32 buttons = SDL_GetMouseState(&x, &y);
        while ( SDL_PollEvent( &event )) 
        {
            if ( event.type == SDL_QUIT )
            {
                systemRunning = false;
            }
            if( event.button.button == SDL_BUTTON_LEFT )
            {
                SetPixel(screen, x, y, 255, 0, 0);
            } 
        }
        SDL_UpdateWindowSurface( window );
    }

	// SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}