#include "Application.h"


void Application::Init( std::string window_name, int window_width, int window_height )
{
    m_Window = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL Initialization Fail: %s\n", SDL_GetError());
        exit(-1);
    }
    m_Window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);

    if (!m_Window) 
    {
        printf("SDL Initialization Fail %s\n", SDL_GetError());
        exit(-1);
    }

    m_Is_Running = true;
}

void Application::Run()
{
    SDL_Event event;
    while ( m_Is_Running ) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                m_Is_Running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    m_Is_Running = false;
                }
            }
        }
    }
    this->Exit();
}


void Application::Exit()
{
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}


