#pragma once

#include "Voxel.h"

class World
{
public:

	World(int width, int height, int depth);

	void generateWorld();
	void drawWorld();

	void setVoxel(int x, int y, int z);
	Voxel *getVoxel(int x, int y, int z) const;

	bool isEmptySpace(int x, int y, int z) const;

private:

	int m_width;
	int m_height;
	int m_depth;

	Voxel **m_voxels;
};
