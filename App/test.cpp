#include "HEG/HEG.h"

int main()
{
    HEG::Log::Init();
    HEG::Application* app = new HEG::Application();
    app->Run();
    delete app;
    return 0;
}