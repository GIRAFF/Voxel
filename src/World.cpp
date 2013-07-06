#include "World.h"
#include "simplexnoise.h"

World::World()
{
};

void World::generateWorld()
{
	for(int x = 0; x < WIDTH; ++x){
		for(int y = 0; y < HEIGHT; ++y){
			for(int z = 0; z < DEPTH; ++z){
				m_voxels[x][y][z] = NULL;

				/*if(y == HEIGHT/2)
					setVoxel( x, y, z);*/

				float density = scaled_raw_noise_3d( 0.0, 1.0, x, y, z);
				float h = scaled_raw_noise_2d(0.0, 0.2, x, z);

				//get bedrock height here
				if(static_cast<float>(y)/static_cast<float>(HEIGHT) <= h)
					setVoxel( x, y, z, Bedrock);
				else if(density >= 0.7)
					setVoxel( x, y, z, Stone);
				else if(density >= 0.5)
					setVoxel( x, y, z, Dirt);
			}
		}
	}

	collapseWorld();

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
void World::setVoxel(int x, int y, int z, Material mat)
{
	Vector3 pos(x, y, z);
	m_voxels[x][y][z]= new Voxel(mat, pos);
}

void World::removeVoxel(int x, int y, int z)
{
	m_voxels[x][y][z]= NULL;
}

Voxel *World::getVoxel(int x, int y, int z) const
{
	return m_voxels[x][y][z];
}

bool World::isEmptySpace(int x, int y, int z) const
{
	return (getVoxel(x, y, z) == NULL);
}

void World::collapseWorld()
{
	for(int x = 0; x < WIDTH; ++x){
		for(int y = 1; y < HEIGHT; ++y){
			for(int z = 0; z < DEPTH; ++z){
				if( isEmptySpace(x, y, z) )
					continue;

				int h = emptySpaceUnder(x, y, z);
				if( h > 0){
					setVoxel(x, y-h, z, getVoxel(x, y, z)->getMaterial() );
					removeVoxel(x, y, z);
				}
			}
		}
	}
}

unsigned int World::numberOfConnections(Voxel* voxel) const
{
	return 0;
}

unsigned int World::emptySpaceUnder(int x, int y, int z) const
{
	for(int h = y-1; h >= 0; --h)
	{
		if( !isEmptySpace(x, h, z) )
			return y - h -1;
	}
	return 0;
}
