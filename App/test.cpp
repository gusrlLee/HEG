#include "HEG/HEG.h"

int main()
{
    HEG::Log::Init();
    HEG_CORE_WARN("Init Hyeon Engine!");
    HEG_INFO("Hello Client!");


    HEG::Application* app = new HEG::Application();
    app->Run();
    delete app;
    return 0;
}