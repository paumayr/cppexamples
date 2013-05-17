
#include "vector3f.h"
#include <cmath>

Vector3f::Vector3f()
: x(0.0f), y(0.0f), z(0.0f)
{
}
Vector3f::Vector3f(float _x, float _y, float _z)
: x(_x), y(_y), z(_z)
{
}

void Vector3f::operator+=(const Vector3f&rh)
{
	x += rh.x;
	y += rh.y;
	z += rh.z;
}

void Vector3f::operator-=(const Vector3f&rh)
{
	x -= rh.x;
	y -= rh.y;
	z -= rh.z;
}

void Vector3f::operator*=(float rh)
{
	x *= rh;
	y *= rh;
	z *= rh;
}

void Vector3f::operator/=(float rh)
{
	*this *= (1.0f / rh);
}

float Vector3f::length() const
{
	return sqrtf(x * x + y * y + z * z);
}

Vector3f operator+(const Vector3f &lh, const Vector3f &rh)
{
	return Vector3f(lh.x + rh.x, lh.y + rh.y, lh.z + rh.z);
}

Vector3f operator-(const Vector3f &lh, const Vector3f &rh)
{
	return Vector3f(lh.x - rh.x, lh.y - rh.y, lh.z - rh.z);
}

Vector3f operator-(const Vector3f &rh)
{
	return Vector3f(-rh.x, -rh.y, -rh.z);
}

Vector3f operator*(const Vector3f &lh, float rh)
{
	return Vector3f(lh.x * rh, lh.y * rh, lh.z * rh);
}

float operator*(const Vector3f &lh, const Vector3f &rh)
{
	return lh.x * rh.x + lh.y * rh.y + lh.z * rh.z;
}

Vector3f operator/(const Vector3f &lh, float rh)
{
	return lh * (1.0f / rh);
}

Vector3f cross(const Vector3f &lh, const Vector3f &rh)
{
	return Vector3f(
		lh.y * rh.z + lh.z * rh.y,
		- (lh.x * rh.z + lh.z * rh.x),
		lh.x * rh.y + lh.y * rh.x
		);
}