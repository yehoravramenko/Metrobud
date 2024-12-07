#pragma once

#include <common.hpp>

class Client {
public:
  bool isRunning;
  void Init();
  void Update();
  void Exit();
};