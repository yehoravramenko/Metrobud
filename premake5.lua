
local SRC_ROOT = "src/"

local SDL_FOLDER = "vendor/SDL3-3.2.8/"
local INC_SDL = SDL_FOLDER .."include"

local INC_GLAD = "vendor/glad/include"
local INC_GLM = "vendor/glm/include"
local INC_STB_IMAGE = "vendor/stb_image/include"
local INC_TINYOBJ = "vendor/tinyobjloader/include"

workspace "Metrobud"
  configurations { "Debug", "Release" }
  location "src/"
  targetdir "build/%{cfg.buildcfg}"
  objdir "build/obj"
  startproject "Metrobud"
  cppdialect "C++latest"
  architecture "x86_64"
  -- staticruntime "on"
  
project "AuraEngine"
  kind "SharedLib"
  language "C++"
  location "src/AuraEngine"

  local AE_SRC = "src/AuraEngine/"

  files { AE_SRC .. "**.cpp", AE_SRC .. "**.hpp", 
  "vendor/glad/src/glad.c",
  "vendor/stb_image/src/stb_image.cpp",
  "vendor/tinyobjloader/src/tinyobjloader.cpp",
  }

  defines {"AE_DLL"}

  includedirs {SRC_ROOT.."AuraEngine", INC_SDL, INC_GLAD, INC_GLM, INC_STB_IMAGE, INC_TINYOBJ}

  libdirs {SDL_FOLDER .. "lib/x64"}
  links {"SDL3.lib"}

  postbuildcommands { "{MKDIR} %[game/bin]","{COPYFILE} %{cfg.buildtarget.relpath} %[game/bin/]" }

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
  location "src/Metrobud"

  local METROBUD_SRC = "src/Metrobud/"
  
  files { METROBUD_SRC .. "**.cpp", METROBUD_SRC .. "**.hpp" }
  
  includedirs {SRC_ROOT, SRC_ROOT.."AuraEngine", INC_SDL, INC_GLAD, INC_GLM}
  
  links {"AuraEngine"}
  
  postbuildcommands { "{MKDIR} %[game/bin]","{COPYFILE} %{cfg.buildtarget.relpath} %[game/bin/]" }

  filter "configurations:Debug"
  defines { "DEBUG" }
  symbols "On"
  
  filter "configurations:Release"
  defines { "NDEBUG" }
  optimize "On"