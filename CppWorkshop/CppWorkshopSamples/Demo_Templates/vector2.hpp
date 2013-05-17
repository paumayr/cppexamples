#pragma once


template<typename T>
class vector3
{
public:
	T x, y, z;

	vector3(T _x, T _y, T _z) 
		: x(_x), y(_y), z(_z)
	{}
};

template<typename T>
vector3<T> operator+(vector3<T> left, vector3<T> right)
{
	return vector3<T>(left.x + right.x, 
								left.y + right.y, 
								left.z + right.z);
}

template<typename T>
class vector2 
{
public:
	T x, y;
	
	vector2(T _x, T _y) : x(_x), y(_y)
	{
	}

	vector2<T> operator+=(const vector2<T>& rh)
	{
		x += rh.x;
		y += rh.y;
	}

	vector2<T> operator-=(const vector2<T>&rh)
	{
		x -= rh.x;
		y -= rh.y;
	}

	T length()	
	{
		return sqrt(x * x + y * y);
	}
};

template<typename T>
vector2<T> operator+(const vector2<T> &lh, const vector2<T> &rh)
{
	return vector2<T>(lh.x + rh.x, lh.y + rh.y);
}

template<typename T>
vector2<T> operator-(const vector2<T> &lh, const vector2<T> &rh)
{
	return vector2<T>(lh.x + rh.x, lh.y + rh.y);
}

template<typename T>
vector2<T> operator*(const vector2<T> &lh, float rh)
{
	return vector2<T>(lh.x * rh, lh.y * rh);
}

template<typename T>
vector2<T> operator*(float lh, const vector2<T> &rh)
{
	return rh * lh;
}
