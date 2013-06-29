#include "Voxel.h"


Voxel::Voxel()
: m_material(Bedrock)
, m_pos(0, 0, 0)
{

}

Voxel::Voxel(Material material, Vector3 pos)
: m_material(material)
, m_pos(pos)
{

}

void Voxel::draw() const
{
	 glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

	 // Define vertices in counter-clockwise (CCW) order with normal pointing out
		 double pX = m_pos.getX();
		 double pY = m_pos.getY();
		 double pZ = m_pos.getZ();

	      // Top face (y = 0.5f)
		 glNormal3d(0, 1, 0);
	      glVertex3f( pX+ 0.5f, pY+ 0.5f, pZ- 0.5f);
	      glVertex3f( pX- 0.5f, pY+ 0.5f, pZ- 0.5f);
	      glVertex3f( pX- 0.5f, pY+ 0.5f, pZ+ 0.5f);
	      glVertex3f( pX+ 0.5f, pY+ 0.5f, pZ+ 0.5f);

	      // Bottom face (y = -0.5f)
	      glNormal3d(0, -1, 0);
	      glVertex3f( pX+ 0.5f, pY- 0.5f, pZ+ 0.5f);
	      glVertex3f( pX- 0.5f, pY- 0.5f, pZ+ 0.5f);
	      glVertex3f( pX- 0.5f, pY- 0.5f, pZ- 0.5f);
	      glVertex3f( pX+ 0.5f, pY- 0.5f, pZ- 0.5f);

	      // Front face  (z = 0.5f)
	      glNormal3d(0, 0, 1);
	      glVertex3f( pX+ 0.5f, pY+ 0.5f, pZ+ 0.5f);
	      glVertex3f( pX- 0.5f, pY+ 0.5f, pZ+ 0.5f);
	      glVertex3f( pX- 0.5f, pY- 0.5f, pZ+ 0.5f);
	      glVertex3f( pX+ 0.5f, pY- 0.5f, pZ+ 0.5f);

	      // Back face (z = -0.5f)
	      glNormal3d(0, 0, -1);
	      glVertex3f( pX+ 0.5f, pY- 0.5f, pZ- 0.5f);
	      glVertex3f( pX- 0.5f, pY- 0.5f, pZ- 0.5f);
	      glVertex3f( pX- 0.5f, pY+ 0.5f, pZ- 0.5f);
	      glVertex3f( pX+ 0.5f, pY+ 0.5f, pZ- 0.5f);

	      // Left face (x = -0.5f)
	      glNormal3d(-1, 0, 0);
	      glVertex3f( pX- 0.5f, pY+ 0.5f, pZ+ 0.5f);
	      glVertex3f( pX- 0.5f, pY + 0.5f, pZ- 0.5f);
	      glVertex3f( pX- 0.5f, pY- 0.5f, pZ- 0.5f);
	      glVertex3f( pX- 0.5f, pY- 0.5f, pZ+ 0.5f);

	      // Right face (x = 0.5f)
	      glNormal3d(1, 0, 0);
	      glVertex3f( pX+ 0.5f, pY+ 0.5f, pZ- 0.5f);
	      glVertex3f( pX+ 0.5f, pY+ 0.5f, pZ+ 0.5f);
	      glVertex3f( pX+ 0.5f, pY- 0.5f, pZ+ 0.5f);
	      glVertex3f( pX+ 0.5f, pY- 0.5f, pZ- 0.5f);
	   glEnd();  // End of drawing color-cube
}
