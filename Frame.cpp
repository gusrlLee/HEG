#include "Frame.h"

namespace HREG 
{
// initialization 
Frame::Frame(int width, int height, int channel)
{
    m_frame_data = new char[width * height * channel];
    m_width = width;
    m_height = height;
    m_channel = channel;
    m_pitch = channel * width;
}

Frame::~Frame()
{
    delete[] m_frame_data;
}

void Frame::Update(char data)
{
    std::memset(m_frame_data, data, m_width * m_height * m_channel * sizeof(char));
    // std::memcpy(m_frame_data, data, m_width * m_height * m_channel * sizeof(Uint8));
}


} // namespace HREG
