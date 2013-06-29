#include "World.h"

World::World()
{
};

void World::generateWorld()
{
	for(int x = 0; x < WIDTH; ++x){
		for(int y = 0; y < HEIGHT; ++y){
			for(int z = 0; z < DEPTH; ++z){
				m_voxels[x][y][z] = NULL;

				if(y == HEIGHT/2)
					setVoxel( x, y, z);
			}
		}
	}

}

void World::drawWorld()
{
	glTranslatef(-WIDTH/2.0f + 0.5f, -HEIGHT/2.0f - 0.51f, -DEPTH/2.0f + 0.5f);
	for(int x = 0; x < WIDTH; ++x)
	{
		for(int y = 0; y < HEIGHT; ++y)
		{
			for(int z = 0; z < DEPTH; ++z)
			{
				if(!isEmptySpace(x, y, z))
				{
					getVoxel(x, y, z)->draw();
				}
			}
		}
	}
	glTranslatef(WIDTH/2.0f - 0.5f, HEIGHT/2.0f + 0.5f, DEPTH/2.0f - 0.5f);
}
void World::setVoxel(int x, int y, int z)
{
	Vector3 pos(x, y, z);
	m_voxels[x][y][z]= new Voxel(Bedrock, pos);
}

Voxel *World::getVoxel(int x, int y, int z) const
{
	return m_voxels[x][y][z];
}

bool World::isEmptySpace(int x, int y, int z) const
{
	return (getVoxel(x, y, z) == NULL);
}
