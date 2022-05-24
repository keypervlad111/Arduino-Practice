#include <MD_Parola.h>
#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 5

MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
//int Buzzer = 6;        // used for Arduino
//int Gas_analog = A0;    // used for Arduino
//int Gas_digital = 7;   // used for Arduino

//int Buzzer = D2;        // used for ESP8266
//int Gas_analog = A0;    // used for ESP8266
//int Gas_digital = D1;   // used for ESP8266

int Buzzer = 32;        // used for ESP32
int Gas_analog = 4;    // used for ESP32
int Gas_digital = 2;   // used for ESP32


void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);      
  pinMode(Gas_digital, INPUT);
  Display.begin();
  Display.setIntensity(0);
  Display.displayClear();
}

void loop() {
  int gassensorAnalog = analogRead(Gas_analog);
  int gassensorDigital = digitalRead(Gas_digital);

  Serial.print("Gas Sensor: ");
  Serial.print(gassensorAnalog);
  Serial.print("\t");
  Serial.print("Gas Class: ");
  Serial.print(gassensorDigital);
  Serial.print("\t");
  Serial.print("\t");

  Display.setTextAlignment(PA_CENTER);
  Display.print(String(gassensorAnalog));
  Display.setInvert(false);
  
  if (gassensorAnalog > 1000) {
    Serial.println("Gas");
    digitalWrite (Buzzer, HIGH) ; //send tone
    delay(1000);
    digitalWrite (Buzzer, LOW) ;  //no tone
  }
  else {
    Serial.println("No Gas");
  }
  delay(100);
}
