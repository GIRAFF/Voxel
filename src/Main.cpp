
//include header file for glfw library so that we can use OpenGL
#include <GL/glfw.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>  //needed for exit function
#include <iostream>
#include <math.h>

#include "Voxel.h"
#include "World.h"
#include "quat.h"
#include "Vector3.h"
#include "Camera.h"

using namespace std;

const int GRIDSIZE = 6; //EVEN NUMBER

World *world;
Camera *cam;


//Initializes 3D rendering
void initializeRendering()
{
    glfwInit();

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

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
	glEnable ( GL_COLOR_MATERIAL ) ;
	for(int lines = 0; lines <=GRIDSIZE; ++lines){
		glBegin(GL_LINES);

			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(-GRIDSIZE/2, 0, lines-(GRIDSIZE/2));
			glVertex3f(GRIDSIZE/2, 0, lines-(GRIDSIZE/2));

			glVertex3f(lines-(GRIDSIZE/2), 0, -GRIDSIZE/2);
			glVertex3f(lines-(GRIDSIZE/2), 0, GRIDSIZE/2);

		glEnd();
	}
	glDisable ( GL_COLOR_MATERIAL ) ;
}

void DrawXYZLines()
{
	glEnable ( GL_COLOR_MATERIAL ) ;
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0,0.0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0f,1.0,0.0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0f,0.0,1.0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
	glEnd();

	glDisable ( GL_COLOR_MATERIAL ) ;
}

void display()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); //clear background screen to black

    //Clear information from last draw
    glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	cam->tick();

	world->drawWorld();
	DrawGrid();
	DrawXYZLines();

    glfwSwapBuffers();

}
int main()
{
   // int     width, height;
    //int     frame = 0;
    bool    running = true;

    initializeRendering();



    if( !glfwOpenWindow( 512, // width of window
                         512, //height of window
                          1,  //redbits
                          0,  //greenbits
                          0,  //bluebits
                          0,  //alphabits
                          0,  //depthbits
                          0, //stencilbits
                          GLFW_WINDOW ) //mode
        ) //return false if window is not created
    {
        glfwTerminate(); //terminating glfw window
        return 0;
    }

    glfwSetWindowTitle("Voxel Test by Robin Reicher");
    glfwSetWindowSizeCallback(handleResize); //callback function of GLFW to handle window resize
    glfwSetKeyCallback(handleKeypress); //callback function to handle keypress

    //glDepthFunc(GL_LESS);

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
