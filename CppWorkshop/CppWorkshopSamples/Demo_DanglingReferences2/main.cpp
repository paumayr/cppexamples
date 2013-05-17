
/// WARNING: This code runs, but uses undefined behaviour
/// It is for DEMONSTRATION purposes only.
/// DO NOT DO THIS in 
/// error, returning a reference to a local variable!
int &func()
{
	int b = 10;
	return b;
}

int main(int argc, char **argv)
{
	// this will run, but it is undefined behaviour!
	// at exit of the function, b exits the scope as well
	int &ref = func();
	ref = 10;

	return 0;
}