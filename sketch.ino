// Now turn this trash into treasure!
#include <TM1637.h>

TM1637 TM;

const int BAR_0 = 14;
const int BAR_1 = 13;
const int BAR_2 = 12;
const int BAR_3 = 11;
const int BAR_4 = 10;
const int BAR_5 = 9;
const int BAR_6 = 8;
const int BAR_7 = 7;
const int BAR_8 = 6;
const int BAR_9 = 5;

const int BARS[10] = {
  BAR_0,
  BAR_1,
  BAR_2,
  BAR_3,
  BAR_4,
  BAR_5,
  BAR_6,
  BAR_7,
  BAR_8,
  BAR_9
};


void setup() {
  
  TM.begin(18,19,4);


  for (int pin : BARS) {
    pinMode(pin, HIGH);
  }
}
void loop() {
  for (int pin : BARS) {
    TM.displayCelsius(pin);
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
  }
}
