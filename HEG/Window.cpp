#include "Window.h"

namespace HEG {
    Window::Window(uint32_t width, uint32_t height, std::string title): m_width(width), m_height(height), m_title(title)
    {   
        HEG_CORE_INFO("[SYSTEM] Init Engine!");
        this->Init();
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::Init() 
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        // create window
        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    }

    void Window::Update()
    {
        glfwSwapBuffers( m_window );
    }
}