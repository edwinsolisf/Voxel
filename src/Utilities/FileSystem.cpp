#include "FileSystem.h"

#include "../Platform/Platform.h"

FilePath::FilePath(const std::string& path)
	:_path(path)
{
}

#ifdef PLATFORM_WINDOWS
#include <Windows.h>

FilePath FilePath::GetCanonicalPath() const
{
	char buffer[MAX_PATH];
	GetFullPathNameA(_path.c_str(), sizeof(buffer), buffer, nullptr);
	return FilePath(buffer);
}

FilePath FilePath::GetAbsolutePath() const
{
	return GetCanonicalPath();
}

FilePath FilePath::GetRelativePath(const FilePath& relativeTo) const
{
	return FilePath("");
}

bool FilePath::Exists() const
{
	return true;
}

bool FilePath::IsRegularFile() const
{
	return true;
}

bool FilePath::IsDirectory() const
{
	return false;
}

bool FilePath::IsAbsolute() const
{
	if (_path.substr(0, 3) == "C:\\" || _path.substr(0, 3) == "c:\\")
		return true;
	return false;
}

bool FilePath::IsRelative() const
{
	return !IsAbsolute();
}
	
const std::string& FilePath::ToString() const
{
	return _path;
}

#else
#include <stdlib.h>

#endif