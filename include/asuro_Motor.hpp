
class asuro_Motor {
private:
  /* data */
  static constexpr uint8_t ANALOG_CHAN_1    = 36;
  static constexpr uint8_t ANALOG_CHAN_1_ON = 32;

public:
  asuro_Motor(/* args */);
  ~asuro_Motor();
};

asuro_Motor::asuro_Motor(/* args */) {
}

asuro_Motor::~asuro_Motor() {
}
/* Set motor speed */
void asuro_Motor::MotorSpeed(unsigned char left_speed, unsigned char right_speed) {
}

/* Set motor direction */
void asuro_Motor::MotorDir(unsigned char left_dir, unsigned char right_dir) {
}