#include "Camera.h"
Camera::Camera()
: m_pos(0, 0, 0)
, m_rotation(0, 0, 0)
, m_xRotMultiplier(1.f)
, m_yRotMultiplier(1.f)
, m_xPosMultiplier(1.f)
, m_yPosMultiplier(1.f)
, m_zPosMultiplier(1.f)
{

}

void Camera::movex(float xmmod)
{
	m_pos += m_rotation * Vector3(xmmod, 0.0f, 0.0f);

	//do move
}

void Camera::movey(float ymmod)
{
	m_pos.setY(m_pos.getX() - ymmod);

	//do move
}

void Camera::movez(float zmmod)
{
	m_pos = m_pos + (m_rotation * Vector3(0.0f, 0.0f, -zmmod));

	//Do move
}

void Camera::rotatex(float xrmod)
{
	//Quaternion nrot;
	//nrot.FromAxis(Vector3(1.0f, 0.0f, 0.0f), xrmod * PIOVER180);
	//m_rotation = m_rotation * nrot;

	//Do rotate
}

void Camera::rotatey(float yrmod)
{
	//Quaternion nrot;
	//nrot.FromAxis(Vector3(0.0f, 1.0f, 0.0f), yrmod * PIOVER180);
	//m_rotation = nrot * m_rotation;

	//Do rotate
}

void Camera::tick(float seconds)
{
	if (m_xRotMultiplier != 0.0f) rotatex(m_xRotMultiplier * seconds);
	if (m_yRotMultiplier != 0.0f) rotatey(m_yRotMultiplier * seconds);

	if (m_xPosMultiplier != 0.0f) movex(m_xPosMultiplier * seconds);
	if (m_yPosMultiplier != 0.0f) movey(m_yPosMultiplier * seconds);
	if (m_zPosMultiplier != 0.0f) movez(m_zPosMultiplier * seconds);
}
