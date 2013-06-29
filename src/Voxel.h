#pragma once

#include <GL/glfw.h>
#include "Vector3.h"

enum Material{
	Bedrock, Dirt
};

class Voxel
{
public:
	Voxel(Material material, Vector3 pos) ;
	Voxel();
	void draw() const;

private:
	Material m_material;
	Vector3 m_pos;
};
