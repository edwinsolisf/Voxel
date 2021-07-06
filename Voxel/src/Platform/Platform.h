#pragma once

#ifdef _WIN32
	#define PLATFORM_WINDOWS
	#define ARCHITECTURE_X86

#elif _WIN64
	#define PLATFORM_WINDOWS
	#define ARCHITECTURE_X64

#elif __APPLE__
	#define PLATFORM_MACOS

#else
	#error Platform not supported

#endif