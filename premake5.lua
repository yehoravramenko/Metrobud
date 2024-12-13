workspace "Metrobud"
  configurations {"Debug", "Release"}
  language "C++"
  cppdialect "C++23"
  
  defines { 
    "_CRT_SECURE_NO_WARNINGS", 
    "GLM_FORCE_DEFAULT_ALIGNED_GENTYPES",
    "GLM_FORCE_LEFT_HANDED",
    "GLM_FORCE_AVX",
    }

  filter "configurations:Debug"
  defines { "DEBUG" }
  symbols "On"

  filter "configurations:Release"
  defines { "NDEBUG" }
  optimize "On"

project "metrobud"
  filter "configurations:Debug"
    kind "ConsoleApp"
  filter "configurations:Release"
    kind "WindowedApp"

  filter {}

  targetdir "bin/%{cfg.buildcfg}"

  includedirs {
    "src",
    "include",
    -- "external/imgui",
  }

  files {
    "src/**.cpp",
    "src/**.c",
    
    "external/**.c",
    "external/**.cpp",
    }

  libdirs {"lib"}
  links {"opengl32", "shell32", "gdi32", "winmm", "m", "stdc++exp"}
