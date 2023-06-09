#ifndef __TRACER__
#define __TRACER__

#include "Frame.h"
#include <iostream>

namespace HREG {

class Tracer {

public:
    void Trace(HREG::Frame *frame);

private: 
    void update();
};
}


#endif
