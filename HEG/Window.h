#pragma once
#include <iostream>

#include "Log.h"

#include "GLFW/glfw3.h"

namespace HEG {

    class Window 
    {
        public:
            Window::Window(uint32_t width=1280, uint32_t height=720, std::string title="HEG RENDERING ENGINE");
            ~Window();

            void Init();
            void Update();

            // get window info
            uint32_t getWindowWidth() { return m_width; };
            uint32_t getHeight() { return m_height; };
            std::string getWindowTitle() { return m_title; };

        private:
            GLFWwindow* m_window;
            uint32_t m_width;
            uint32_t m_height;
            std::string m_title;

    };
}