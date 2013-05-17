// NOTE this code is for demonstration purposes. It throws an error
// this is WANTED!
int main(int argc, char **argv)
{
	int * pointerToInt = new int;
	*pointerToInt = 5;
	// create a reference referencing the object on the heap.
	int &referenceToInt = *pointerToInt;

	// is ok! object is still alive
	referenceToInt = 15;
	delete pointerToInt;

	// this is undefined behaviour. the object referenced does not exist anymore
	referenceToInt = 10;
	
	// next allocation will check for memory errors 
	// debug runtime will crash here
	int *b = new int;

	// be nice and deallocate.
	delete b;
	return 0;
}