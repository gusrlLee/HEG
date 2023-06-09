#include "Tracer.h"

namespace HREG {
    void Tracer::Trace(HREG::Frame *frame) 
    {
        int frame_height = frame->getFrameHeight();
        int frame_width = frame->getFrameWidth();
        int frame_picth = frame->getFrameChannel() * frame_width;
        char* frame_data = frame->getFrameData();

        for (int j=frame_height - 1; j>=0; j--)
        {
            for (int i=0; i<frame_width; ++i)
            {
                auto r = double(i) / (frame_width - 1);
                auto g = double(frame_height - j) / (frame_height - 1);
                auto b = 0.25;

                frame_data[j * frame_picth + (3 * i) + 0] = static_cast<char>(255.999 * r);
                frame_data[j * frame_picth + (3 * i) + 1] = static_cast<char>(255.999 * g);
                frame_data[j * frame_picth + (3 * i) + 2] = static_cast<char>(255.999 * b);
            }
        }
    }


} // namespace 

