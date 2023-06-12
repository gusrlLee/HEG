#ifndef __TRACER__
#define __TRACER__

#include "Frame.h"
#include "ray.h"
#include "Vec3.h"
#include <iostream>


class Tracer {

    public:
        void Trace(Frame *frame);

    private: 
        void update();
};


#endif
