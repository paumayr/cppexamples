

#include "ConsoleCallback.hpp"
#include <iostream>
#include <fstream>

class FileLoggerCallback : public VirusScanCallback
{
	std::ofstream outputStream;

public:
	FileLoggerCallback(const std::string& filename);
	~FileLoggerCallback();

	virtual void onScanStarted();
	virtual void onVirusFound();
	virtual void onScanFinished();
};