#pragma once
#include "Shape.h"

class Square :
    public Shape
{
	public:
	Square();
	Square(int value); // Type: 0=Square, 1=Circle, 2=MultiColorCircle.    Value:  Radius or Diameter
	void draw();
	void updateCoordinates();

};

