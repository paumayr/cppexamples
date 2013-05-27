
#include "Logger.hpp"
#include <string>

Logger &Logger::Instance()
{
	static Logger logger;
	return logger;
}

Logger::~Logger()
{
	shutdown();
}

void Logger::initialize(const std::string &filePath, int _logLevel)
{
	logLevel = _logLevel;
	file.open(filePath.c_str(), std::ios_base::app);
}

void Logger::shutdown()
{
	if (file.is_open())
	{
		file.close();
	}
}

void Logger::log(int level, const std::string& message)
{
	if (level > logLevel)
	{
		file << "Log Message: " << std::endl;
		file << "==================================" << std::endl;
		file << message << std::endl;
		file << "==================================" << std::endl;
		file.flush();
	}
}