#include <Arduino.h>
#include <NeoPixelBus.h>

const uint16_t NUM_LED = 300;     // Number of LEDs for our strip
const uint8_t LED_PIN = 5;        // GPIO pin number for strip data

#ifdef LED_BUILTIN
   #define LED_BUILTIN 97                         // This seems to be true for my knock off esp32-s3 but I'm not 100% sure
#endif

float brightness = 0.2;  // 0.1 to 1 for brightness

#include "rainbow.h"

RainbowLED myRainbowStrip(NUM_LED, LED_PIN, brightness);  // Adjust number of LEDs and pin as necessary

void setup() {
  delay(10000);             // wait for the terminal to catch up for debugging
  Serial.begin(115200);
  Serial.println("Started setup");

  myRainbowStrip.begin();
  
  Serial.println("Finished setup");
}

void loop()
{
  //Serial.println("Started loop");
  myRainbowStrip.showRainbow();  // 
  //Serial.println("Finished loop");
}