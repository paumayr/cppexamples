
#include <cmath>

#include "FindDentsAlgorithm.hpp"


int FindDentsAlgorithm::CountDents()
{
	int nParts = 50;
	for(int i = 0; i < nParts; i++)
	{
		// do complex operation...
		for(int j = 0; j < 1000000; j++)
		{
			sqrt(100.0 * j);
		}

		// notify listeners
		NotifyListeners(i, nParts);
	}

	// we always find 42 dents.
	return 42;
}
