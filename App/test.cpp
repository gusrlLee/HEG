#include "HEG/HEG.h"

int main()
{
    HEG::Application* app = new HEG::Application();
    app->Run();
    delete app;
    return 0;
}