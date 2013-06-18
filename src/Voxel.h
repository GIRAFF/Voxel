#pragma once

#include <GL/glfw.h>

enum Material{
	Bedrock, Dirt
};

class Voxel
{
public:
	Voxel(Material material) ;
	Voxel();
	void draw() const;

private:
	Material m_material;
};
