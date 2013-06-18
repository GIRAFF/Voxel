#include "World.h"

World::World(int width, int height, int depth)
: m_width(width)
, m_height(height)
, m_depth(depth)
, m_voxels(new Voxel*[width*height*depth])
{
	for(long v = 0; v < width*height*depth; ++v)
		m_voxels[v] = NULL;
};

void World::generateWorld()
{
	setVoxel(0, 0, 0);
}

void World::drawWorld()
{
	for(int x = 0; x <m_width; ++x)
	{
		for(int y = 0; y <m_height; ++y)
		{
			for(int z = 0; z <m_depth; ++z)
			{
				if(!isEmptySpace(x, y, z))
				{
					glTranslatef ((double)x,(double) y, (double)z);
					getVoxel(x, y, z)->draw();
				}
			}
		}
	}
}
void World::setVoxel(int x, int y, int z)
{
	//Simplification of x + y * WIDTH + z * WIDTH * DEPTH
	m_voxels[x + m_width * (y + m_depth * z)] = new Voxel();
}

Voxel *World::getVoxel(int x, int y, int z) const
{
	return m_voxels[x + m_width * (y + m_depth * z)];
}

bool World::isEmptySpace(int x, int y, int z) const
{
	return (getVoxel(x, y, z) == NULL);
}
