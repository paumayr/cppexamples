
#include "VirusScanCallback.hpp"
#include "FileLoggerCallback.hpp"
#include "VirusScanner.h"
#include "ConsoleCallback.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	ConsoleCallback callback;

	FileLoggerCallback fileLoggerCallback("virusscanlogfile.log");

	VirusScanner scanner;

	// set callback
	scanner.callback = &fileLoggerCallback;

	scanner.runScan();
	return 0;
}