#include "stdafx.h"

#include <memory>
#include <vector>


class vector3
{
public:
	float x, y, z;
};

std::shared_ptr<vector3> createVector()
{
	std::shared_ptr<vector3> v(new vector3());
	v->x = 0.0f;
	v->y = 0.0f;
	v->z = 0.0f;
	return v;
}

TEST_CLASS(TestStdSharedPtr)
{
public:
	TEST_METHOD(TestStdSharedPtrMain)
	{
		std::shared_ptr<vector3> v;

		/* BAD CODE!
		vector3 stackvector3;
		{
		std::shared_ptr<vector3> badpointerX(&stackvector3);
		}
		*/

		/* BAD CODE
		{
		std::shared_ptr<vector3> manualDelete(new vector3());
		delete manualDelete.get();
		}
		*/

		/*
		vector3* dumbPointer = nullptr;
		{
		std::shared_ptr<vector3> manualDelete(new vector3());
		dumbPointer = manualDelete.get();
		}
		dumbPointer->x = 11.0;
		*/

		std::shared_ptr<vector3> ptrVec3(new vector3());

		{
			std::shared_ptr<vector3> ptrVec4 = ptrVec3;
		}

		std::shared_ptr<vector3> x = createVector();
	}
};