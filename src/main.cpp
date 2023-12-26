#include <Arduino.h>

#include "asuro_Buttons.hpp"
#include "asuro_LEDs.hpp"

void setup() {
    Serial.begin(115200);
    Serial.println("Starting device");
}

void loop() {
    static asuro_LEDs leds;
    static asuro_Buttons buttons;
    Serial.println(buttons.update());
    delay(500);
    leds.setLED_1();

    delay(500);
    leds.setLED_2();
}
