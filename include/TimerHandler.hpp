#pragma once

#include <Ticker.h>

class TimerHandler {
public:
  void restart(uint32_t seconds);
  void stop();
  bool isRunning();

private:
  Ticker m_timer{};
};
