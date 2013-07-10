#pragma once

#include "Voxel.h"

const int WIDTH = 20;
const int HEIGHT = 7;
const int DEPTH = 20;

class World
{
public:

	World();

	void generateWorld();
	void drawWorld();

private:

	void setVoxel(int x, int y, int z, Material mat);
	Voxel *getVoxel(int x, int y, int z) const;
	void removeVoxel(int x, int y, int z);

	bool isEmptySpace(int x, int y, int z) const;

	void collapseWorld();
	unsigned int emptySpaceUnder(int x, int y, int z) const;
	unsigned int numberOfConnections(Voxel* voxel) const;

	Voxel *m_voxels[WIDTH][HEIGHT][DEPTH];
};
