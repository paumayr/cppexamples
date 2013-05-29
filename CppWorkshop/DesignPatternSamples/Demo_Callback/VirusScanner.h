#pragma once

#include "VirusScanCallback.hpp"

class VirusScanner
{
public:
	int virusesFound;

	VirusScanCallback *callback;

	VirusScanner();
	void runScan();
};