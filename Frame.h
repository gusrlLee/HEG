#include "SDL2/SDL.h"
#include "spdlog/spdlog.h"

#include <iostream>
#include <stdio.h>
#include <string>


namespace HREG {

class Frame 
{
public: 
    Frame(int width, int height, int channel);
    ~Frame();
    void Update(char* data);
    void Update(char data);
    char* getFrameData() { return m_frame_data; }
    int getFrameWidth() { return m_width; }
    int getFrameHeight() { return m_height; }
    int getFrameChannel() { return m_channel; }

private:
    char* m_frame_data;
    int m_width;
    int m_height;
    int m_channel;
    int m_pitch;
};


}
