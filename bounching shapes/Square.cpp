#include "Square.h"
#include "Shape.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
#pragma once
using namespace std;
Square::Square() : Shape()
{

}

Square::Square(int value) : Shape(value)
{
	Shape::Shape(value);
}



void Square::draw() 
{
	Shape::draw();
}

void Square::updateCoordinates()
{
	Shape::updateCoordinates();
}
