#pragma once

#ifdef _WIN32
#ifdef AE_DLL
#define AE_API __declspec(dllexport)
#else
#define AE_API __declspec(dllimport)
#endif
#else
#error "Aura Engine is avaliable only on Windows!"
#endif