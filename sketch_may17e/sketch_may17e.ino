#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <DHT.h>;

//Constants
#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302) !!!!
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//--------------------

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 4
#define CS_PIN 5

MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);


//void scrollText(String message, int delayTime) {
//  for (int i=0; i < lcdColumns; i++) {
//    message = " " + message;  
//  } 
//  message = message + " "; 
//  for (int pos = 0; pos < message.length(); pos++) {
//    lcd.setCursor(0, row);
//    lcd.print(message.substring(pos, pos + lcdColumns));
//    delay(delayTime);
//  }
//}

void setup() {
   Serial.begin(9600);
   Serial.println("DHTxx test!");
   dht.begin(); 
  Display.begin();
  Display.setIntensity(0);
  Display.displayClear();
}

void loop() {
  delay(2000);
    float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hi = dht.computeHeatIndex(f, h);

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C ");

  

  Display.setTextAlignment(PA_CENTER);
  Display.print(String(t) + "C");
  delay(4000);
  Display.print(String(h) + "%");
  Display.setInvert(false);
}
