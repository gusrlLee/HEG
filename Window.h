#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"

#include <iostream>

namespace HREG 
{
    class Window 
    {
        public:
            Window( std::string title, uint32_t width, uint32_t height );

            bool windowShouldClose();
            void Render();
            void CleanUp();
            void Clear();
            void Display();

        private:
            void setPixel(SDL_Surface* surface, int x, int y, uint8_t r, uint8_t g, uint8_t b);
            // SDL 
            SDL_Surface* m_Screen;
            SDL_Window* m_Window;
            SDL_Renderer* m_Renderer;
            SDL_Event m_Event;

            // Display Info
            uint32_t m_Width;
            uint32_t m_Height;
            std::string m_Title;
            bool m_Running; 
    };
}

#endif 