
#pragma once
#include <vector>

#include "VirusScanCallback.hpp"


class VirusScanSubject
{
public:

	void registerCallback(VirusScanCallback* callback);
	
	std::vector<VirusScanCallback*> callbacks;

protected:
	void notifyOnStart();
	void notifyOnVirusFound();
	void notifyOnFinished();

};