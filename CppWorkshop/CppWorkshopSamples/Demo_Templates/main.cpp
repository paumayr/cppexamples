#include "vector2.hpp"


int main(int argc, char **argv)
{
	vector3<float> floatVector(1.0f, 2.0f, 1.0f);
	vector3<double> doubleVector(2.0f, 2.0f, 2.0f);

	vector3<float> b = floatVector;
	
	// reduce typing
	typedef vector3<float> vector3f;

	vector3f a = b;

	return 0;
}