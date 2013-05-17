#include <iostream>

int main(int argc, char**argv)
{
	while(std::cin.get() != 'n')
	{
		// allocate another block of memory
		std::cout << "allocating more memory..." << std::endl;
		int * arr= new int[1024 * 1024];

		// do some cool calculations
		for (int i = 0; i < 1024 * 1024; i++)
		{
			arr[i] = i * 2;
		}

		// more more more 
		std::cout << "done with complicated calculations" << std::endl;

		// forget to free the memory
		// delete [] arr;
	}
}