#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"
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
    bool m_Is_Running;
};
