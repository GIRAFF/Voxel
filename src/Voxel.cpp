#include "Voxel.h"


Voxel::Voxel()
: m_material(Bedrock)
{

}

Voxel::Voxel(Material material)
: m_material(material)
{

}

void Voxel::draw() const
{
	 glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

		 GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
		 GLfloat cyan[] = {0.f, .8f, .8f, 1.f};
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, white);
		 GLfloat shininess[] = {50};
		 glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	      // Define vertices in counter-clockwise (CCW) order with normal pointing out

	      // Top face (y = 0.5f)
		 glNormal3d(0, 1, 0);
	      glVertex3f( 0.5f, 0.5f, -0.5f);
	      glVertex3f(-0.5f, 0.5f, -0.5f);
	      glVertex3f(-0.5f, 0.5f,  0.5f);
	      glVertex3f( 0.5f, 0.5f,  0.5f);

	      // Bottom face (y = -0.5f)
	      glNormal3d(0, -1, 0);
	      glVertex3f( 0.5f, -0.5f,  0.5f);
	      glVertex3f(-0.5f, -0.5f,  0.5f);
	      glVertex3f(-0.5f, -0.5f, -0.5f);
	      glVertex3f( 0.5f, -0.5f, -0.5f);

	      // Front face  (z = 0.5f)
	      glNormal3d(0, 0, 1);
	      glVertex3f( 0.5f,  0.5f, 0.5f);
	      glVertex3f(-0.5f,  0.5f, 0.5f);
	      glVertex3f(-0.5f, -0.5f, 0.5f);
	      glVertex3f( 0.5f, -0.5f, 0.5f);

	      // Back face (z = -0.5f)
	      glNormal3d(0, 0, -1);
	      glVertex3f( 0.5f, -0.5f, -0.5f);
	      glVertex3f(-0.5f, -0.5f, -0.5f);
	      glVertex3f(-0.5f,  0.5f, -0.5f);
	      glVertex3f( 0.5f,  0.5f, -0.5f);

	      // Left face (x = -0.5f)
	      glNormal3d(-1, 0, 0);
	      glVertex3f(-0.5f,  0.5f,  0.5f);
	      glVertex3f(-0.5f,  0.5f, -0.5f);
	      glVertex3f(-0.5f, -0.5f, -0.5f);
	      glVertex3f(-0.5f, -0.5f,  0.5f);

	      // Right face (x = 0.5f)
	      glNormal3d(1, 0, 0);
	      glVertex3f(0.5f,  0.5f, -0.5f);
	      glVertex3f(0.5f,  0.5f,  0.5f);
	      glVertex3f(0.5f, -0.5f,  0.5f);
	      glVertex3f(0.5f, -0.5f, -0.5f);
	   glEnd();  // End of drawing color-cube
}
