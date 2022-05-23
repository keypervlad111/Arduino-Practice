#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

int ledPin = 13;                // LED
int pirPin = 27;                 // PIR Out pin
int pirStat = 0;   

//--------------------

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 4
#define CS_PIN 5

MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  Display.begin();
  Display.setIntensity(0);
  Display.displayClear();
}

void loop() {
 pirStat = digitalRead(pirPin);
  if (pirStat == HIGH) {
    Display.setTextAlignment(PA_CENTER);
    Display.print("Hey i see you");
    Display.setInvert(false);
  }
  else {
    Display.setTextAlignment(PA_CENTER);
    Display.print("I'll catch you ");
    Display.setInvert(false);
  }
}
