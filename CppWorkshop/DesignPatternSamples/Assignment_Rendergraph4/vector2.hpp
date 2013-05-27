#pragma once

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
	return vector2<T>(lh.x * f, lh.y * f);
}

template<typename T>
vector2<T> operator*(float lh, const vector2<T> &rh)
{
	return rh * lh;
}

typedef vector2<float> vector2f;