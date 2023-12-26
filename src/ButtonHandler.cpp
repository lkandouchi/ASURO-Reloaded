#include "ButtonHandler.hpp"

#include <FunctionalInterrupt.h>

ButtonHandler::ButtonHandler(gpio_num_t pin) : m_pin(pin) {
}

void ButtonHandler::init() {
  pinMode(m_pin, INPUT_PULLUP);
  attachInterrupt(
      m_pin, [this]() { buttonPressed(); }, FALLING);
}

bool ButtonHandler::wasPressed() {
  return m_wasPressed;
}

void ButtonHandler::buttonPressed() {
  detachInterrupt(m_pin);
  delayMicroseconds(DEBOUNCE_DELAY_US); // lazy debounce
  m_wasPressed = true;
  attachInterrupt(
      m_pin, [this]() { buttonPressed(); }, FALLING);
}

void ButtonHandler::reset() {
  m_wasPressed = false;
}