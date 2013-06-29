#pragma once

#include "Voxel.h"

const int WIDTH = 6;
const int HEIGHT =6;
const int DEPTH = 6;

class World
{
public:

	World();

	void generateWorld();
	void drawWorld();

	void setVoxel(int x, int y, int z);
	Voxel *getVoxel(int x, int y, int z) const;

	bool isEmptySpace(int x, int y, int z) const;

private:

	Voxel *m_voxels[WIDTH][HEIGHT][DEPTH];
};
