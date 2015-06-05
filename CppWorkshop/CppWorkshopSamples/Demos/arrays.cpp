#include "stdafx.h"

TEST_CLASS(TestArrays)
{
public:
	TEST_METHOD(TestStackArrays)
	{
		// fixed size heap
		int a[100];
		a[4] = 10;
		a[10] = 12;

		int *b = a;

		// stack arrays must be of fixed size 
		// (without compiler extensions)
		// int v = 200;
		// int b[v];
	}

	TEST_METHOD(TestHeapArrays)
	{
		int* a = new int[100];
		a[5] = 20;
		delete[] a;
	}
};