
#include "ConsoleOutControl.hpp"
#include "TestControl.hpp"
#include "FindHottestSpot.h"



/*
int main(int argc, char **argv)
{
	ConsoleOutControl coc;

	coc.MoveArm(vector2(20, 30));

	double measurement = coc.TakeMeasurement();

	std::cout << "Measured value: " << measurement << std::endl;
}
*/


int main(int argc, char **argv)
{
	TestControl tc;
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			tc.temperatures[i * 100 + j] = i * j;
		}
	}

	tc.temperatures[50 * 100 + 50] = 1000000000.0;

	vector2 result = FindHottestSpot(tc);

	if (result.x == 50 && result.y == 50)
	{
		std::cout << "Juhuuu... Algorithm works correctly.. probably..." << std::endl;
	} 
	else
	{
		std::cout << "bbbugggyyy ..." << std::endl;
	}

}