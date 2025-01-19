#include <sys/stat.h>

#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

#include "logger.hpp"

using namespace icuray;

Logger::Logger(const std::string& logFilePath) :

	m_logFilePath(logFilePath)
{
	setupLogFile();
}

Logger::~Logger()
{}

void Logger::log_info(const std::string& content) const
{
	auto formattedNow = getFormattedNow();
	std::ofstream logFile(m_logFilePath, std::ios::app);
	logFile
		<< std::put_time(std::localtime(&formattedNow), "%Y-%m-%d %X")
		<< " | INFO: "
		<< content
		<< '\n';
}

std::time_t Logger::getFormattedNow() const
{
	return
		std::chrono::system_clock::to_time_t(
			std::chrono::system_clock::now());
}

void Logger::printHello() const
{
	std::cout << "Hello " << m_name << '\n';
}

void Logger::setupLogFile() const
{
	std::ofstream fileStr;

	auto logDir = m_logFilePath;
	logDir.erase(logDir.find_last_of('/'));

	if (std::filesystem::exists(logDir))
		return;

	std::filesystem::path dir = logDir;
	auto created = std::filesystem::create_directory(dir) ;

    if (!created) {
        std::cerr << "Failed to create directory\n";
		return;
	}
}
