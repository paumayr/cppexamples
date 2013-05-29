
#include "VirusScanner.h"

VirusScanner::VirusScanner()
	: virusesFound(0),
	callback(nullptr)
{
}
void VirusScanner::runScan()
{
	if (callback != nullptr)
	{
		callback->onScanStarted();
	}

	for (int i = 0; i < 10000; i++)
	{
		if (i == 666)
		{
			virusesFound++;

			if (callback != nullptr)
			{
				callback->onVirusFound();
			}
		}
	}

	if (callback != nullptr)
	{
		callback->onScanFinished();
	}
}