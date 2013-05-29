#pragma once

#include "VirusScanSubject.hpp"
#include <vector>

class VirusScanner : public VirusScanSubject
{
public:
	int virusesFound;

	VirusScanner();
	void runScan();
};