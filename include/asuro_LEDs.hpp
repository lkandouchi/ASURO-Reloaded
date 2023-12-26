class asuro_LEDs
{
private:
    /* data */
    static constexpr uint8_t  LED_D11{22};
    static constexpr uint8_t  LED_DOU_GR{23};
    static constexpr uint8_t  LED_DOU_RD{3};
    static constexpr uint8_t  LED_IO2{2};

public:
    asuro_LEDs(/* args */);
    ~asuro_LEDs();
    void setLED_1();
    void setLED_2();
};

asuro_LEDs::asuro_LEDs(/* args */)
{
        // Set pin mode
  pinMode(LED_IO2,OUTPUT);
  pinMode(LED_DOU_RD,OUTPUT);
  pinMode(LED_DOU_GR,OUTPUT);
}

asuro_LEDs::~asuro_LEDs()
{
}

void asuro_LEDs::setLED_1(){
  digitalWrite(LED_IO2,HIGH);
  digitalWrite(LED_DOU_RD,HIGH);
  digitalWrite(LED_DOU_GR,LOW);
  digitalWrite(LED_D11,HIGH);
}
void asuro_LEDs::setLED_2(){
    digitalWrite(LED_IO2,LOW);
  digitalWrite(LED_DOU_RD,LOW);
  digitalWrite(LED_DOU_GR,HIGH);
  digitalWrite(LED_D11,LOW);
  
}
