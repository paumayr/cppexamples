
#include "VirusScanSubject.hpp"


void VirusScanSubject::registerCallback(VirusScanCallback *callback)
{
	callbacks.push_back(callback);
}

void VirusScanSubject::notifyOnStart()
{
	for(int i = 0; i < callbacks.size(); i++)
	{
		callbacks[i]->onScanStarted();
	}
}

void VirusScanSubject::notifyOnVirusFound()
{
	for(int i = 0; i < callbacks.size(); i++)
	{
		callbacks[i]->onVirusFound();
	}
}

void VirusScanSubject::notifyOnFinished()
{
	for(int i = 0; i < callbacks.size(); i++)
	{
		callbacks[i]->onScanFinished();
	}
}