#include <Arduino.h>
#include <NeoPixelBus.h>

const uint16_t NUM_LED = 300;     // Number of LEDs for our strip
const uint8_t LED_PIN = 5;        // GPIO pin number for strip data

#ifdef LED_BUILTIN
   #define LED_BUILTIN 97                         // This seems to be true for my knock off esp32-s3 but I'm not 100% sure
#endif

float brightness = 0.01;  // 0.1 to 1.0 for brightness
uint8_t cometSize = 20;
float fadeFactor = 0.01; // I think the higher fade factor means less fade. While lower means more fade.
#include "wheel.h"
#include "rainbow.h"
#include "rainbowcomet.h"

RainbowLED myRainbowStrip(NUM_LED, LED_PIN, brightness);  // Adjust number of LEDs and pin as necessary

// number of leds, data pin, brightness, comet size, fade factor
//RainbowCometLED myRainbowComet(NUM_LED, LED_PIN, brightness, cometSize, fadeFactor);  

void setup() {
  delay(5000);             // wait for the terminal to catch up for debugging
  Serial.begin(115200);
  Serial.println("Started setup");

  myRainbowStrip.begin();
  // myRainbowComet.begin();
  
  Serial.println("Finished setup");
}

void loop()
{
  //Serial.println("Started loop");
  myRainbowStrip.showRainbow();
  // myRainbowComet.showRainbowComet();  // 
  //Serial.println("Finished loop");
}