#pragma once

#include "Logging.h"

#include <iostream>

LogLevel Log::level = LogLevel::INFO;

void Log::Init()
{
}

void Log::ConsoleLog(const char* message, LogLevel level)
{
	if ((int)Log::level <= (int)level)
	{
		switch (level)
		{
			case LogLevel::INFO:
			{
				std::cout << "[INFO]: ";
				break;
			}
			case LogLevel::WARN:
			{
				std::cout << "[WARNING]: ";
				break;
			}
			case LogLevel::ERROR:
			{
				std::cout << "[ERROR]: ";
				break;
			}
			case LogLevel::FATAL:
			{
				std::cout << "[FATAL]: ";
				break;
			}
		}
		std::cout << message << '\n';
	}
}

void Log::ConsoleLog(const std::string& message, LogLevel level)
{
	if ((int)Log::level <= (int)level)
	{
		switch (level)
		{
			case LogLevel::INFO:
			{
				std::cout << "[INFO]:\t";
				break;
			}
			case LogLevel::WARN:
			{
				std::cout << "[WARNING]:\t";
				break;
			}
			case LogLevel::ERROR:
			{
				std::cout << "[ERROR]:\t";
				break;
			}
			case LogLevel::FATAL:
			{
				std::cout << "[FATAL]:\t";
				break;
			}
		}
		std::cout << message << '\n';
	}
}

void Log::SetLogLevel(LogLevel logLevel)
{
	Log::level = logLevel;
}