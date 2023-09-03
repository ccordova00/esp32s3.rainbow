#include <Arduino.h>
#include <NeoPixelBus.h>


class RainbowCometLED {
private:
    NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip;
    const uint8_t pixelPin;
    const uint16_t pixelCount;
    float brightness;
    uint16_t cometSize;
    float fadeFactor;

    ColorWheel wheel;

public:
    RainbowCometLED(uint16_t count, uint8_t pin, float brightness = 1.0, uint16_t cometSize = 5, float fadeFactor = 0.85) 
        : pixelCount(count), pixelPin(pin), strip(count, pin), brightness(brightness), cometSize(cometSize), fadeFactor(fadeFactor) {}

    void begin() {
        strip.Begin();
        strip.Show();
    }

    void showRainbowComet() {
        for(uint16_t stripPos = 0; stripPos < pixelCount + cometSize; stripPos++) { // for loop runs for strip size plus comet size to ensure a complete effect
            strip.ClearTo(0); // clear strip

            // Draw the comet
            for(uint16_t cometPos = 0; cometPos < cometSize; cometPos++) { 
                if ((stripPos - cometPos < pixelCount) && (stripPos - cometPos >= 0)) {
                    // Adjusted the Dim method argument to take values from 0 to 255
                    strip.SetPixelColor(stripPos - cometPos, wheel.getColor(((stripPos - cometPos) * 256 / pixelCount) & 255).Dim((uint8_t)(brightness * 255 * (1.0 - (float)cometPos / cometSize))));
                }
            }

            strip.Show();
            delay(20);
        
            // Fade the LEDs by the fade factor
            for(uint16_t j = 0; j < pixelCount; j++) {
            // Adjusted the Dim method argument to take values from 0 to 255
            strip.SetPixelColor(j, strip.GetPixelColor(j).Dim((uint8_t)(brightness * 255 * fadeFactor)));
            }
        }
    }
 
};

