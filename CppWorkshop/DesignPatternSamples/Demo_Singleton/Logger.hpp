#pragma once

#include <string>
#include <fstream>

// singleton logger class.
class Logger
{
public:
	static Logger &Instance();
	~Logger();

	void initialize(const std::string &filePath, int _logLevel);
	void log(int level, const std::string& message);
private:
	void shutdown();

	int logLevel;
	std::fstream file;
};