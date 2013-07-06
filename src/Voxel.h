#pragma once

#include <GL/glfw.h>
#include "Vector3.h"


enum Material{
	Bedrock, Stone, Dirt
};

class Voxel
{
public:
	Voxel(Material material, Vector3 pos) ;
	Voxel();
	void draw() const;
	Material getMaterial(){return m_material;}

private:
	void setMaterial() const;

	Material m_material;
	Vector3 m_pos;
};
