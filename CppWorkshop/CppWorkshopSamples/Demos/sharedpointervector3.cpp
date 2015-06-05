#include "stdafx.h"



class Vector3
{
public:
	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z)
	{
	}

	float x, y, z;
};

class SmartVector3Pointer
{
	int *counter;
	Vector3 *value;
public:
	SmartVector3Pointer(Vector3 *original)
	{
		value = original;
		counter = new int(1);
	}

	~SmartVector3Pointer()
	{
		(*counter)--;
		if ((*counter) == 0)
		{
			delete value;
			delete counter;
		}
	}

	SmartVector3Pointer(SmartVector3Pointer &original)
	{
		value = original.value;
		counter = original.counter;
		(*counter)++;
	}

	Vector3& operator*()
	{
		return *value;
	}

	Vector3* operator->()
	{
		return value;
	}
};

TEST_CLASS(TestSharedPointerVector3)
{
	TEST_METHOD(TestSharedPointerVector3Main)
	{
		SmartVector3Pointer smart = SmartVector3Pointer(new Vector3(20.0f, 3.0f, 3.0f));

		{
			SmartVector3Pointer smart2 = smart;
		}
	}
};
