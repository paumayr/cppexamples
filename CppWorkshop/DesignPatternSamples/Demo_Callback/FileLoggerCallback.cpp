

#include "FileLoggerCallback.hpp"

FileLoggerCallback::FileLoggerCallback(const std::string& filename)
	: outputStream(filename)
{
}

FileLoggerCallback::~FileLoggerCallback()
{
	outputStream.close();
}

void FileLoggerCallback::onScanStarted()
{
	outputStream << "scan started" << std::endl;
}

void FileLoggerCallback::onVirusFound()
{
	outputStream << "virus found" << std::endl;
}

void FileLoggerCallback::onScanFinished()
{
	outputStream << "scan finished" << std::endl;
}