
#include "VirusScanCallback.hpp"
#include "FileLoggerCallback.hpp"
#include "VirusScanner.h"
#include "ConsoleCallback.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	ConsoleCallback consoleCallback;
	FileLoggerCallback fileLogger("viruslogfile.txt");
	VirusScanner scanner;

	// set callback
	scanner.registerCallback(&consoleCallback);
	scanner.registerCallback(&fileLogger);

	scanner.runScan();
	return 0;
}