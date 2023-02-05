// CSCE A211
// Graphics Framework by Matthew Devins
// This code uses OpenGL and demonstrates drawing some text and some
// simple shapes, pixels, and color changes.
//
// To the reader: You only need to focus on the code in the "display" function
// for now.

#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"

#include <stdio.h>
#include <string.h>

#include <math.h>

void init();
void display();
void startScreen();
void handleButton(int button, int state, int x, int y);
void printText(int x, int y, const char *string);



void *font = GLUT_BITMAP_TIMES_ROMAN_24;//GLUT_STROKE_ROMAN;
const int WIDTH = 720;
const int HEIGHT = 480;

static int screenx = 0;
static int screeny = 0;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Just A Window");

	init();
	glutDisplayFunc(display);
	glutMouseFunc(handleButton);

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
}


/* For this lab you only need to work in this display function */
void display()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);
	printText(WIDTH/5, HEIGHT/4, "This demonstrates some simple 2D drawings");

	// Draw some points
	glBegin(GL_POINTS);
	// Change color to green  (r,g,b) where r,g,b is 0-1
	glColor3f(0, 1, 0);
	glVertex2f(100, 100);
	glColor3f(1, 1, 1);  // Color to white
	glVertex2f(10, 20);
	glEnd();

	// Draw a line
	glBegin(GL_LINES);
	glVertex2f(50, 50);
	glVertex2f(75, 150);
	glEnd();

	// Draw a rectangle given the four corners
	glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
	glVertex2f(200, 10); // x1,y1
	glVertex2f(300, 10); // x2, y1
	glVertex2f(300, 50); // x2, y2
	glVertex2f(200, 50); // x1, y2
	glEnd();

	// Draws a polygon given the coordinates
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0); // Change to red
	glVertex2f(410, 10);
	glVertex2f(510, 210);
	glVertex2f(410, 210);
	glVertex2f(401, 100);
	glVertex2f(410, 50);
	glEnd();

	glutSwapBuffers();
	glFlush();

	return;
}

/* Handles a mouse button, not needed for this program */
void handleButton(int button, int state, int x, int y)
{
	static int index = -1;

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			printText(30, HEIGHT / 2, "You clicked the mouse button!");
			glutSwapBuffers();
			glFlush();

		}
		if (state == GLUT_UP)
		{
			display();
		}

	}
}

// This function prints a string of text on the screen at coordinate x,y
void printText(int x, int y, const char *string)
{
	int i, length;

	glRasterPos2f(x, y);
	length = (int)strlen(string);
	for (i = 0; i < length; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}