#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"

#include "Frame.h"

#include <iostream>
#include <string>

class Application
{
public:
    void Init(std::string window_name, int window_width, int window_height);
    void Run();
    void Exit();

private: 
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    SDL_Texture* m_Image;

    HREG::Frame* m_Frame;
    char* image_data;
    bool m_Is_Running;
};
