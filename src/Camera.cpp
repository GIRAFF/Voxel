#include "Camera.h"

Camera::Camera()
: m_pos(0, 0, -5)
, m_rotation(0.0f, 0.0f, 0.0f) //create a fromAxis constructor
, m_sensitivity(0.01f)
{
	m_mousef[0] = 0;
	m_mousef[1] = 0;
	m_rotation = 	(Quaternion().FromAxis(PI/4, 0, 1, 0) * Quaternion().FromAxis(PI/4, 1, 0, 0));
}

void Camera::movex(float xmmod)
{
	m_pos += Vector3(xmmod, 0.0f, 0.0f);
}

void Camera::movey(float ymmod)
{
	m_pos += Vector3(0.0f, ymmod, 0.0f);
}

void Camera::movez(float zmmod)
{
	m_pos += Vector3(0.0f, 0.0f, zmmod);
}

void Camera::rotateX(float xrmod)
{
	Quaternion nrot;
	nrot.FromAxis(-xrmod * m_sensitivity, 0, 1, 0);
	m_rotation = nrot * m_rotation;
}

void Camera::rotateY(float yrmod)
{
	Quaternion nrot;
	nrot.FromAxis(-yrmod * m_sensitivity, 1, 0, 0);
	m_rotation = m_rotation * nrot;

}

void Camera::tick(float seconds)
{
	//Translate
	m_pos.setZ(-5.0+(double)glfwGetMouseWheel());
	glTranslatef(m_pos.getX(),m_pos.getY(),m_pos.getZ());

	//rotate
	int diff[2] = {m_mousef[0], m_mousef[1]};
	glfwGetMousePos(&m_mousef[0], &m_mousef[1]);
	diff[0] -= m_mousef[0];
	diff[1] -= m_mousef[1];

	if( glfwGetMouseButton(GLFW_MOUSE_BUTTON_MIDDLE) )
	{
		rotateX(diff[0]);
		rotateY(diff[1]);
	}

	float RotationMatrix[16];
	m_rotation.ToMatrix16(RotationMatrix);
	glMultMatrixf(RotationMatrix);
}
