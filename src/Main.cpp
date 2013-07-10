
//include header file for glfw library so that we can use OpenGL
#include <GL/glfw.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>  //needed for exit function
#include <iostream>
#include <math.h>

#include "World.h"
#include "quat.h"
#include "Vector3.h"
#include "Camera.h"

#include "Helpers.h"

using namespace std;

const int GRIDSIZE = 6; //EVEN NUMBER

World *world;
Camera *cam;


//Initializes 3D rendering
void initializeRendering()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    cam = new Camera(); //add what type
}

//Called when a key is pressed
void GLFWCALL handleKeypress(int key,int press) //The key that was pressed
{
	switch (key) {
		case GLFW_KEY_ESC: //Escape key
			exit(0); //Exit the program
	}
}



//Called when the window is resized
void GLFWCALL handleResize(int width,int height)
{
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION ); //Switch to setting the camera perspective
    //Set the camera perspective
    glLoadIdentity(); //reset the camera
    gluPerspective( 45.0f,                      //camera angle
                (GLfloat)width/(GLfloat)height, //The width to height ratio
                 1.0f,                          //The near z clipping coordinate
                100.0f );                       //The far z clipping coordinate
}

void DrawGrid()
{
	GLfloat cube_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cube_diffuse);

	for(int lines = 0; lines <=GRIDSIZE; ++lines){
		glBegin(GL_LINES);
			glVertex3f(-GRIDSIZE/2, 0.01, lines-(GRIDSIZE/2));
			glVertex3f(GRIDSIZE/2, 0.01, lines-(GRIDSIZE/2));

			glVertex3f(lines-(GRIDSIZE/2), 0.1, -GRIDSIZE/2);
			glVertex3f(lines-(GRIDSIZE/2), 0.1, GRIDSIZE/2);

		glEnd();
	}
}

void DrawXYZLines()
{
	GLfloat cube_diffuseRed[] = { 1.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cube_diffuseRed);

	glBegin(GL_LINES);
		glColor3f(1.0f,0.0,0.0);
		glVertex3f(0, 0.01, 0);
		glVertex3f(1, 0.01, 0);
	glEnd();

	GLfloat cube_diffuseGreen[] = { 0.0, 1.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cube_diffuseGreen);


	glBegin(GL_LINES);
		glColor3f(0.0f,1.0,0.0);
		glVertex3f(0, 0.01, 0);
		glVertex3f(0, 1, 0);
	glEnd();

	GLfloat cube_diffuseBlue[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cube_diffuseBlue);

	glBegin(GL_LINES);
		glColor3f(0.0f,0.0,1.0);
		glVertex3f(0, 0.01, 0);
		glVertex3f(0, 0.01, 1);
	glEnd();

}

void display()
{
    //Clear information from last draw
	glClearColor (0.53 , 0.81, 0.99, 1.0);
    glClearDepth(100.0);            // set depth buffer to the most distant value
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

    GLfloat light_position[] = { 2.0, 2.0, 2.0, 0.0 };

	cam->tick();

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	world->drawWorld();
	//DrawGrid();
	DrawXYZLines();

	calcFPS(1.0, "Current FPS: ");


    glfwSwapBuffers();

}

int main()
{
	glfwInit();
    bool    running = true;



    if( !glfwOpenWindow(500, 500, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
    {
        glfwTerminate(); //terminating glfw window
        return 0;
    }

    initializeRendering();

    glfwSetWindowTitle("Voxel Test by Robin Reicher");
    glfwSetWindowSizeCallback(handleResize); //callback function of GLFW to handle window resize
    glfwSetKeyCallback(handleKeypress); //callback function to handle keypress

    world = new World();
	world->generateWorld();

    while(running) // infinite loop to draw object again and again
    {              // because once object is draw then window is terminated

        display();
        running = glfwGetWindowParam( GLFW_OPENED ); //when glfw window is opened then it return true
                                                     //if closed then return false
    }
    return 0;
}
