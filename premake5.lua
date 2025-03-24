
local SRC_ROOT = "src/"
local INC_VENDOR = "vendor/include"

workspace "Metrobud"
  configurations { "Debug", "Release" }
  location "projects/"
  targetdir "build/%{cfg.buildcfg}"
  objdir "build/obj"
  startproject "Metrobud"
  cppdialect "C++latest"
  architecture "x86_64"
  staticruntime "on"
  defines {"GLFW_INCLUDE_NONE"}
  
project "AuraEngine"
  kind "StaticLib"
  language "C++"

  local AE_SRC = "src/AuraEngine/"

  files { AE_SRC .. "**.cpp", AE_SRC .. "**.hpp", "vendor/src/glad.c", "vendor/RGFW/RGFW.c" }

  includedirs {SRC_ROOT, INC_VENDOR, "vendor/RGFW"}

  disablewarnings {"4133"}

  filter "configurations:Debug"
  defines { "DEBUG" }
  symbols "On"
  
  filter "configurations:Release"
  defines { "NDEBUG" }
  optimize "On"


project "Metrobud"
  kind "ConsoleApp"
  language "C++"
  debugdir "game/bin/"

  local METROBUD_SRC = "src/Metrobud/"
  
  files { METROBUD_SRC .. "**.cpp", METROBUD_SRC .. "**.hpp" }
  
  includedirs {SRC_ROOT, INC_VENDOR}
  
  libdirs {"vendor/glfw-3.4.bin.WIN64/lib-vc2022"}
  --links {"AuraEngine", "glfw3.lib", "User32.lib", "Gdi32.lib", "Shell32.lib"}
  links {"AuraEngine", "glfw3_mt.lib"}
  
  postbuildcommands { "{MKDIR} %[game/bin]","{COPYFILE} %{cfg.buildtarget.relpath} %[game/bin/]" }

  filter "configurations:Debug"
  defines { "DEBUG" }
  symbols "On"
  
  filter "configurations:Release"
  defines { "NDEBUG" }
  optimize "On"