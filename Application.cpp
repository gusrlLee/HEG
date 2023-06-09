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

    m_Renderer = SDL_CreateRenderer(m_Window, -1,  SDL_RENDERER_ACCELERATED);
    if (m_Renderer == 0)
    {
        printf("SDL Renderer Initialization Fail : %s\n", SDL_GetError());
        exit(-1);
    }

    m_Display = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STATIC, window_width, window_height);
    if (!m_Display)
    {
        printf("SDL Screen Initialization Fail : %s\n", SDL_GetError());
        exit(-1);
    }

    m_Frame = new HREG::Frame(window_width, window_height, 3);
    m_Tracer = new HREG::Tracer();
    m_Is_Running = true;
}

void Application::Run()
{
    int i=0;
    SDL_Event event;
    while ( m_Is_Running ) {
        m_Tracer->Trace(m_Frame);

        SDL_UpdateTexture(m_Display, NULL, m_Frame->getFrameData(), m_Frame->getFrameWidth() * sizeof(Uint8) * m_Frame->getFrameChannel());
        SDL_RenderCopy(m_Renderer, m_Display, NULL, NULL);
        SDL_RenderPresent(m_Renderer);

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
    delete m_Frame;
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyTexture(m_Display);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}


