#pragma once

#include <Arduino.h>

#include <functional>

class ButtonHandler {
  static constexpr uint32_t DEBOUNCE_DELAY_US = 200000; // 200 Milliseconds in Microseconds

public:
  ButtonHandler(gpio_num_t pin);

  void init();
  bool wasPressed();
  void reset();

private:
  // ISR
  void IRAM_ATTR buttonPressed();

  gpio_num_t     m_pin;
  bool           m_wasPressed{false};
};