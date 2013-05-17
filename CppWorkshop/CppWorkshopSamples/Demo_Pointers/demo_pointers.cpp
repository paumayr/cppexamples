#include <stddef.h>

void basicpointertypes()
{
	// variable on the stack
	float a;
	// pointer to a variable on the stack (a)
	float *ptrA = &a;
	// pointer to a float variable on the heap
	float *ptrF = new float;

	// pointer to a double variable on the heap.
	double *ptrD = new double;

	// free variables on the heap
	delete ptrF;
	delete ptrD;

	// variables on the stack are automatically clean up.
}

void dereferencepointer()
{
	float a = 0.5f;
	float *ptrA = &a;
	float *ptrB = new float;

	// changes pointer value to the value of ptrB.
	ptrA = ptrB;

	// changes pointer to point to a (on the stack)
	ptrA = &a;

	// stores value pointed to by ptrA in location pointed to by ptrB
	*ptrB = *ptrA;

	// does not compile, (float*) cannot be converted to (float)
	// *ptrA = ptrB;
	
	// clean up heap memory
	delete ptrB;
}

void basicpointerarithmetic()
{
	int array[100];
	int *p = &array[0];

	ptrdiff_t x = &array[10] - &array[5];
	auto y = &array[10] - &array[5];

	p++; // increment the poitner (now p = &array[1])
}

int main(int argc, char **argv)
{
	basicpointertypes();
	dereferencepointer();
	return 0;
}