#pragma once

#include <string>

class FilePath
{
public:
	FilePath(const std::string& path);

	FilePath GetCanonicalPath() const;
	FilePath GetAbsolutePath() const;
	FilePath GetRelativePath(const FilePath& relativeTo) const;

	bool Exists() const;
	bool IsRegularFile() const;
	bool IsDirectory() const;
	bool IsAbsolute() const;
	bool IsRelative() const;

	const std::string& ToString() const;

	//std::string operator/(const std::string& otherPath) const;
	//FilePath operator/(const FilePath& otherPath) const;
private:
	std::string _path;
};