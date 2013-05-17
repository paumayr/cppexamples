#pragma once

#include <cmath>

class Vector3f
{
public:
	float x,y,z;

	Vector3f();
	Vector3f(float _x, float _y, float _z);

	void operator+=(const Vector3f&rh);
	void operator-=(const Vector3f&rh);
	void operator*=(float rh);
	void operator/=(float rh);

	float length() const;
};


Vector3f operator+(const Vector3f &lh, const Vector3f &rh);
Vector3f operator-(const Vector3f &rh);
Vector3f operator-(const Vector3f &lh, const Vector3f &rh);
Vector3f operator*(const Vector3f &lh, float rh);
float operator*(const Vector3f &lh, const Vector3f &rh);
Vector3f operator/(const Vector3f &lh, float rh);

Vector3f cross(const Vector3f &lh, const Vector3f &rh);