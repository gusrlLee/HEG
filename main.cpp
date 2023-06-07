#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"
#include "Application.h"

#include <iostream>
#include <string>

int main( int argc, char* argv[] )
{

    Application* app = new Application();
    app->Init("Hello world", 1280, 720);
    app->Run();

    return 0;
}
