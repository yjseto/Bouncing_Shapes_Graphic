// CSCE A211
// Graphics Framework by Matthew Devins
// This code uses OpenGL and demonstrates drawing some shapes and animating them.

#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "MulticolorCircle.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Function prototypes
std::chrono::milliseconds delayTime(5);	// Controls frame rate
void init();
void display();
void updateShape();

// Globals
const int WIDTH = 720;
const int HEIGHT = 480;
static int screenx = 0;
static int screeny = 0;

Shape* shapes[5]; // Array of pointers to 5 shapes


int main(int argc, char** argv)
{
	srand(time(NULL));
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bouncing Objects Demo");

	init();
	glutDisplayFunc(display);
	glutIdleFunc(updateShape); // The update function is called when the system is idle (not processing window events)
	// It is automatically called repeatedly so you don't have to put a loop in it!
	// In our case we have it update the location of the shapes
	display();
	glutMainLoop();

	return 0;
}

void init()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(screenx, screenx + WIDTH, screeny + HEIGHT, screeny);

	// This creates five shapes with either the specified radius or side of a square
	// Glut doesn't return from the main loop, so currently these ball objects are deleted only when the app exits.
	// If we had a keyboard handler or something we could check for an escape key or something and destroy these and exit.
	shapes[0] = new Circle(5);			// Circle with radius = 5
	shapes[1] = new Square(30);			// Square with diameter = 30
	shapes[2] = new Square(70);			// Square with diameter = 70
	shapes[3] = new MulticolorCircle(50);			// MultiColorCircle with radius = 50
	shapes[4] = new MulticolorCircle(100);			// MultiColorCircl with radius = 100
}



// This function updates the position of each shape then redraws it on the screen by calling display.
// This function is called by the GL framework for us when the window is idle. It is called repeatedly so
// we can rely on it being invoked whenever there is CPU processing available.  In other words, we don't need
// to make a loop that keeps calling updateBall() because GLUT will call it for us over and over again
// when the system is idle.
void updateShape()
{
	for (int i = 0; i < 5; i++)
		shapes[i]->updateCoordinates(); // The function updates the shape's location on the screen
	display();
	// The line below implements a delay; it specifies how many milliseconds to wait before exiting.  When this function
	// exits, GLUT will end up calling this function again when the system is idle, hence drawing the shapes in a new location.
	// If this line is removed then the display is updated as fast as possible.
	// Right now the delay is set at 5ms.  Set to 1000 if you wanted to wait one second before each update (slow).
	std::this_thread::sleep_for(delayTime);
}

// This draws the shapes on the screen
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Loop through each shape and draw it
	for (int i = 0; i < 5; i++)
		shapes[i]->draw();

	glutSwapBuffers();
	glFlush();

	return;
}

