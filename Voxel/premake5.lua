workspace "Voxel"
	architecture
	{
		"x86", "x86_64"
	}

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Voxel"
	location "Voxel"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++14"

	targetdir ("bin/" .. outputdir .. "%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	include
	{
		"%{prj.name}/include"
	}

	libdirs
	{
		"%{prj.name}/lib"
	}

	filter { "configurations:Debug" }
		defines { "DEBUG" }
		symbols "On"

	filter { "configurations:Release" }
		defines { "NDEBUG" }
		optimize On

	filter { "system:windows" }
		staticruntime "On"
		systemversion "lastest"
		defines { "PLATFORM_WINDOWS" }

	filter { "system:macosx" }
		staticruntime "On"
		defines { "PLATFORM_MACOS" }
