#pragma once

class Shape
{
protected:
	static const int WIDTH = 720;
	static const int HEIGHT = 480;
	float x;
	float y;
	float deltaX;
	float deltaY;
	//int type;		// Identifies type of shape being stored.  See list below.
	int radius;		// If its a circle this is the radius
	int diameter;	// If its a square this is the diameter
public:
	Shape();
	Shape(int value); // Type: 0=Square, 1=Circle, 2=MultiColorCircle.    Value:  Radius or Diameter

	~Shape();
	virtual void draw();
	void updateCoordinates();
};

