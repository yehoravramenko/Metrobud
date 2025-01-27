workspace "Metrobud"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}"

project "AuraEngine"
	location "AuraEngine"
	kind "SharedLib"

	language "C++"
	cppdialect "C++20"
	staticruntime "Off"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
		"thirdparty/src/glad.c"
	}

	includedirs
	{
		"thirdparty/include"
	}

	libdirs
	{
		"thirdparty/lib"
	}

	links
	{
		"opengl32", "glfw3"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"AE_PLATFORM_WINDOWS",
		"AE_BUILD_DLL",
	}

	postbuildcommands 
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Metrobud")
	}

	filter "configurations:Debug"
		defines "AE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "AE_RELEASE"
		optimize "On"

project "Metrobud"
	location "Metrobud"
	kind "ConsoleApp"

	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
		"thirdparty/src/glad.c"
	}

	includedirs
	{
		"thirdparty/include",
		"AuraEngine/src"
	}

	links
	{
		"AuraEngine"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"AE_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "AE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "AE_RELEASE"
		optimize "On"