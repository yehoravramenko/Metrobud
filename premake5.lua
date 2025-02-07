workspace "Metrobud"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}"

project "dearimgui"
	location "AuraEngine"
	kind "StaticLib"

	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/AuraEngine")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"thirdparty/src/imgui/**.cpp",
	}

	includedirs
	{
		"thirdparty/include/imgui",
		"thirdparty/include/SDL3",
	}

	links
	{
		"SDL3.dll"
	}

	filter "configurations:Debug"
		symbols "On"
	
	filter "configurations:Release"
		optimize "On"

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
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

		"thirdparty/src/glad.c",
	}

	includedirs
	{
		"%{prj.name}/src/AuraEngine",

		"thirdparty/include/glad",
		"thirdparty/include/SDL3",
		"thirdparty/include/stb",
		"thirdparty/include/glm",
		"thirdparty/include/imgui",
	}

	libdirs
	{
		"thirdparty/lib/SDL3",
		"bin/" .. outputdir .. "/%{prj.name}"
	}

	links
	{
		"opengl32", "SDL3", "dearimgui.lib"
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
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		-- "thirdparty/include",
		"thirdparty/include/SDL3",
		"thirdparty/include/glad",
		"thirdparty/include/glm",
		"thirdparty/include/imgui",
		"AuraEngine/src",
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

	postbuildcommands 
	{
		("{COPY} %{wks.location}/thirdparty/lib/SDL3/SDL3.dll ../bin/" .. outputdir .. "/Metrobud")
	}

	filter "configurations:Debug"
		defines "AE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "AE_RELEASE"
		optimize "On"