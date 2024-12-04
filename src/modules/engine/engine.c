#define _CRT_SECURE_NO_WARNINGS
#include "engine.h"

#include <stdio.h>
#include <stdarg.h>

void Engine_InitLog() {
  fclose(fopen("latest.log", "w"));
}

void Engine_WriteLog(const char *format, ...) {
  FILE *debug_log_f;
  debug_log_f = fopen("latest.log", "a+");

  va_list args;

  va_start(args, format);
  vfprintf(debug_log_f, format, args);
  va_end(args);
  fclose(debug_log_f);
}