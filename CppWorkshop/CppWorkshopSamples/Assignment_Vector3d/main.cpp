
#include "vector3f.h"

int main(int argc, char **argv)
{
	Vector3f n;
	Vector3f a(1.0f, 1.0f, 1.0f);

	a += n; // should remain a 
	a -= n; // should remain a
	a = -a;
	a = a * 2.0f;
	a *= 2.0f;
	a /= 2.0f;
	a = a / 2.0f; // should be a again (almost at least)

	Vector3f c = cross(a, a);
	float dot = c * a;
}