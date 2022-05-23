#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 5
MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  Display.begin();
  Display.setIntensity(0);
  Display.displayClear();
}

void loop() {  
  int touch = touchRead(T0);
  Display.setTextAlignment(PA_CENTER);

  if (touch == 0){
     Display.print("NoTouch");
  }
  else { 
     Display.print("Touch");
  }

  Display.setInvert(false);
  delay(1000);
}
