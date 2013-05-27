#pragma once

#include <iostream>
#include "vector2.hpp"

template<typename T>
std::ostream& operator<<(std::ostream &out, const vector2<T> &v)
{
	out << "(" << v.x << "," << v.y << ")";
	return out;
}