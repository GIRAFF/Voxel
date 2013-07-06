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
	// vertex coords array
	GLfloat vertices[] = {0.5,0.5,0.5,  -0.5,0.5,0.5,  -0.5,-0.5,0.5,  0.5,-0.5,0.5,        // v0-v0.5-v2-v3
	                      0.5,0.5,0.5,  0.5,-0.5,0.5,  0.5,-0.5,-0.5,  0.5,0.5,-0.5,        // v0-v3-v4-v5
	                      0.5,0.5,0.5,  0.5,0.5,-0.5,  -0.5,0.5,-0.5,  -0.5,0.5,0.5,        // v0-v5-v6-v0.5
	                      -0.5,0.5,0.5,  -0.5,0.5,-0.5,  -0.5,-0.5,-0.5,  -0.5,-0.5,0.5,    // v0.5-v6-v7-v2
	                      -0.5,-0.5,-0.5,  0.5,-0.5,-0.5,  0.5,-0.5,0.5,  -0.5,-0.5,0.5,    // v7-v4-v3-v2
	                      0.5,-0.5,-0.5,  -0.5,-0.5,-0.5,  -0.5,0.5,-0.5,  0.5,0.5,-0.5};   // v4-v7-v6-v5

	// normal array
	GLfloat normals[] = {0,0,1,  0,0,1,  0,0,1,  0,0,1,             // v0-v1-v2-v3
	                     1,0,0,  1,0,0,  1,0,0, 1,0,0,              // v0-v3-v4-v5
	                     0,1,0,  0,1,0,  0,1,0, 0,1,0,              // v0-v5-v6-v1
	                     -1,0,0,  -1,0,0, -1,0,0,  -1,0,0,          // v1-v6-v7-v2
	                     0,-1,0,  0,-1,0,  0,-1,0,  0,-1,0,         // v7-v4-v3-v2
	                     0,0,-1,  0,0,-1,  0,0,-1,  0,0,-1};        // v4-v7-v6-v5

	// color array
	GLfloat colors[] = {1,1,1,  1,1,0,  1,0,0,  1,0,1,              // v0-v1-v2-v3
	                    1,1,1,  1,0,1,  0,0,1,  0,1,1,              // v0-v3-v4-v5
	                    1,1,1,  0,1,1,  0,1,0,  1,1,0,              // v0-v5-v6-v1
	                    1,1,0,  0,1,0,  0,0,0,  1,0,0,              // v1-v6-v7-v2
	                    0,0,0,  0,0,1,  1,0,1,  1,0,0,              // v7-v4-v3-v2
	                    0,0,1,  0,0,0,  0,1,0,  0,1,1};             // v4-v7-v6-v5

	// index array of vertex array for glDrawElements()
	// Notice the indices are listed straight from beginning to end as exactly
	// same order of vertex array without hopping, because of different normals at
	// a shared vertex. For this case, glDrawArrays() and glDrawElements() have no
	// difference.
	GLubyte indices[] = {0,1,2,3,
	                     4,5,6,7,
	                     8,9,10,11,
	                     12,13,14,15,
	                     16,17,18,19,
	                     20,21,22,23};

	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	double pX = m_pos.getX();
	double pY = m_pos.getY();
	double pZ = m_pos.getZ();


	// enable and specify pointers to vertex arrays
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normals);

	glPushMatrix();

	GLfloat cube_diffuse[] = { 0.3, 0.7, 0.1, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cube_diffuse);

	glTranslatef(pX, pY, pZ); //move to position
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
	glDisableClientState(GL_NORMAL_ARRAY);
}
