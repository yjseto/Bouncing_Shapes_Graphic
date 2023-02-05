#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
    public:
    Circle();
    Circle(int value);

    void draw();
};

