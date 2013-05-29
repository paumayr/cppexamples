
#include "VirusScanner.h"

VirusScanner::VirusScanner()
	: virusesFound(0)
{
}
void VirusScanner::runScan()
{
	notifyOnStart();

	for (int i = 0; i < 10000; i++)
	{
		if (i == 666)
		{
			virusesFound++;
			notifyOnVirusFound();
		}
	}

	notifyOnFinished();
}
