#pragma once

#include "Vector3.h"
#include "quat.h"

#include <GL/glfw.h>
#include <GL/gl.h>
#include <GL/glu.h>

const float PIOVER180 = PI/180.0f;

class Camera
{
public:
	Camera();
	void tick(float seconds = 0.0f);

protected:
	void movex(float xmmod);
	void movey(float ymmod);
	void movez(float zmmod);

	void rotateX(float xrmod);
	void rotateY(float yrmod);


private:
	Vector3 m_pos;
	Quaternion m_rotation;

	int m_mousef[2];

	float m_sensitivity;
};
