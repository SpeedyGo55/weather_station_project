// Now turn this trash into treasure!
#include <TM1637.h>
#include <DHT.h>

TM1637 TM;

#define BAR_0 14
#define BAR_1 13
#define BAR_2 12
#define BAR_3 11
#define BAR_4 10
#define BAR_5 9
#define BAR_6 8
#define BAR_7 7
#define BAR_8 6
#define BAR_9 5

#define DHT_PIN 15
#define DHTTYPE DHT22

DHT dht(DHT_PIN, DHTTYPE);

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
    pinMode(pin, OUTPUT);
  }
  dht.begin();
}
void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp)) {
    return;
  }

  int hum_bars = map(hum, 0, 100, 0, 10);
  
  for (int pin : BARS) {
    digitalWrite(pin, LOW);
  }
  for (int i = 0; i<hum_bars; i++) {
    digitalWrite(BARS[9-i], HIGH);
  }

  TM.displayCelsius(temp, (temp < -9) || (temp > 99));
  delay(2000);
}
