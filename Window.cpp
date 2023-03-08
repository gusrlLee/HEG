#include "Window.h"

namespace HREG 
{
    Window::Window( std::string title, uint32_t width, uint32_t height ) :
        m_Window( NULL ), m_Renderer ( NULL ), m_Screen( NULL ), m_Running( false )
    {
        m_Title = title;
        m_Width = width;
        m_Height = height;

        m_Window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_SHOWN );
        if ( !m_Window ) 
        {
            spdlog::error(" Failed to create SDL window.");
        }

        m_Screen = SDL_GetWindowSurface( m_Window );
        if ( m_Screen == NULL) 
        {
            spdlog::error(" Failed to get SDL Screen.");
        }
        spdlog::info("Start Hyeon Rendering Engine!");
        m_Running = true;
    }

    bool Window::windowShouldClose() 
    {
        return m_Running;
    }

    void Window::setPixel(SDL_Surface* surface, int x, int y, uint8_t r, uint8_t g, uint8_t b)
    {
        SDL_LockSurface( surface );
        uint8_t* pixelArr = (uint8_t*)surface->pixels;
        for (int j=surface->h-1; j>=0; --j)
        {
            for (int i=0; i<surface->pitch; ++i)
            {
                auto r = double(i) / (surface->w - 1);
                auto g = double(j) / (surface->h - 1);
                auto b = 0.25;

                pixelArr[j * surface->pitch + i * surface->format->BytesPerPixel + 0] = static_cast<int>(255.999 * r);
                pixelArr[j * surface->pitch + i * surface->format->BytesPerPixel + 1] = static_cast<int>(255.999 * g);
                pixelArr[j * surface->pitch + i * surface->format->BytesPerPixel + 2] = static_cast<int>(255.999 * b);
            }
        }
        SDL_UnlockSurface( surface );
    }

    void Window::Render()
    {
        int x, y;
        Uint32 buttons = SDL_GetMouseState(&x, &y);
        while ( SDL_PollEvent( &m_Event ))
        {
            if ( m_Event.type == SDL_QUIT )
            {
                m_Running = false;
            }
        } 

        setPixel(m_Screen, x, y, 255, 0, 0);
    }

    void Window::Clear()
    {

    }

    void Window::CleanUp()
    {
        SDL_DestroyWindow( m_Window );
    }

    void Window::Display()
    {
        SDL_UpdateWindowSurface( m_Window );
    }

}