#include "Vector3.h"
#include <math.h>

Vector3::Vector3(double x, double y, double z)
: m_x(x)
, m_y(y)
, m_z(z)
{
}

Vector3::~Vector3()
{
}

double vectorMag(const Vector3& v)
{
   return sqrt(v.getX()*v.getX() + v.getY()*v.getY() + v.getZ()*v.getZ());
}

double distance(const Vector3& p1, const Vector3& p2)
{
   double dx = p1.getX() - p2.getX();
   double dy = p1.getX() - p2.getY();
   double dz = p1.getZ() - p2.getZ();
   return sqrt(dx*dx + dy*dy + dz*dz);
}
