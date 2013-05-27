
#pragma once

class VirusScanCallback
{
public:
	virtual void onScanStarted() = 0;
	virtual void onVirusFound() = 0;
	virtual void onScanFinished() = 0;
};
