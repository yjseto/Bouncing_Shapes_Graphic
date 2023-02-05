#pragma once
#include "Shape.h"
class MulticolorCircle :
    public Shape
{
public:
    MulticolorCircle();
    MulticolorCircle(int value);
    
    void draw();
};

