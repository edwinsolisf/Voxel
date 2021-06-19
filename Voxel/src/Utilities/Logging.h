#pragma once

#include <string>

#ifdef DEBUG
	#define LOG_INFO(x)		Log::ConsoleLog(x, LogLevel::INFO)
	#define LOG_WARN(x)		Log::ConsoleLog(x, LogLevel::WARN)
	#define LOG_ERROR(x)	Log::ConsoleLog(x, LogLevel::ERROR)
	#define LOG_FATAL(x)	Log::ConsoleLog(x, LogLevel::FATAL)
#else
	#define LOG_INFO(x)	
	#define LOG_WARN(x)	
	#define LOG_ERROR(x)
	#define LOG_FATAL(x)
#endif

enum class LogLevel
{
	INFO,
	WARN,
	ERROR,
	FATAL,
	NONE
};

class Log
{
public:
	static LogLevel level;
	static void Init();

	static void ConsoleLog(const char* message, LogLevel level);
	static void ConsoleLog(const std::string& message, LogLevel level);

	static void SetLogLevel(LogLevel logLevel);
};