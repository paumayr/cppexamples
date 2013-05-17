
void heaparrays()
{
	int* a = new int[100];
	a[5] = 20;
	delete[] a;
}

void basicarrays()
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

int main(int argc, char ** argv)
{
}