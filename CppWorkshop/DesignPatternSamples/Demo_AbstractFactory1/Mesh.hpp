#pragma once

#include <vector>
#include "vector3f.hpp"

class Mesh
{
public:
	void addPoint(const Vector3f& p);

	virtual void render() = 0;
protected:
	std::vector<Vector3f> points;

};