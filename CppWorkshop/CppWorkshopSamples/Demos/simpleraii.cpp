#include "stdafx.h"

class SimpleResource
{
	int *heapmemory;
public:
	SimpleResource()
		: heapmemory(new int[1024 * 1024])
	{
	}

	~SimpleResource()
	{
		delete[] heapmemory;
	}
};

TEST_CLASS(TestSimpleRAII)
{
public:
	TEST_METHOD(TestSimpleRAIIMain)
	{
		SimpleResource r1;
		{
			SimpleResource r2;
		}
	}
};