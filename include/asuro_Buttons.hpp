class asuro_Buttons {
private:
  static constexpr uint8_t ANALOG_CHAN_1    = 36;
  static constexpr uint8_t ANALOG_CHAN_1_ON = 32;
  void                     setAnalogChan1On() {
    digitalWrite(ANALOG_CHAN_1_ON, HIGH);
  }
  void setAnalogChan1Off() {
    digitalWrite(ANALOG_CHAN_1_ON, LOW);
  }

public:
  asuro_Buttons(/* args */);
  ~asuro_Buttons();
  unsigned char update(void);
};

asuro_Buttons::asuro_Buttons(/* args */) {
  pinMode(ANALOG_CHAN_1_ON, OUTPUT);
  digitalWrite(ANALOG_CHAN_1_ON, HIGH);
}

asuro_Buttons::~asuro_Buttons() {
}

unsigned char asuro_Buttons::update() {
  setAnalogChan1On();
  delay(50);
  // read the input on analog pin 0:
  int sensorValue = analogRead(ANALOG_CHAN_1);
  // sensorValue += 96; // offset!?!
  //  print out the value you read:
  // U = Rx/Rx+1k * 4096
  // U / 3.3V = Rx / Rx+1k
  //  Rx ={ 2k, 4k, 8k,16k,32k,64k}
  //  2/3*4000 = 2666   2360
  //  4/5*4000 = 3200   2860
  //  8/9*4000 = 3555   3300
  //  16/17*4000 = 3764
  //  32/33*4000 = 3878  3780
  //  64/65*4000 = 3938  3900
  sensorValue = ((4096 * sensorValue) / 4000) + 150;

  Serial.println(sensorValue);
  setAnalogChan1Off();
  return ((unsigned char)(((4096.0 / (float)sensorValue - 1.0)) * 63.0 + 0.5));
}

// if (sw & 0x01)
//   MotorSpeed(200, 0);
// if (sw & 0x02) {
//   BackLED(OFF, ON);
//   tmp = ON;
// }
// if (sw & 0x04)
//   BackLED(ON, tmp);
// if (sw & 0x08)
//   FrontLED(ON);
// if (sw & 0x10)
//   RED_LED_ON;
// if (sw & 0x20)
//   GREEN_LED_ON;
