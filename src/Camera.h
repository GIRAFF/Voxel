#pragma once

#include "Vector3.h"

const float PIOVER180 = 3.14f/180.0f;

class Camera
{
public:
	Camera();
	void movex(float xmmod);
	void movey(float ymmod);
	void movez(float zmmod);

	void rotatex(float xrmod);
	void rotatey(float yrmod);

	void tick(float seconds);
private:
	Vector3 m_pos, m_rotation;
	float m_xRotMultiplier, m_yRotMultiplier;
	float m_xPosMultiplier, m_yPosMultiplier, m_zPosMultiplier;
};
