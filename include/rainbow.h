#include <Arduino.h>
#include <NeoPixelBus.h>


class RainbowLED {
private:
    NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip;
    const uint8_t pixelPin;
    const uint16_t pixelCount;
    const float brightness;

    ColorWheel wheel;

public:
    RainbowLED(uint16_t count, uint8_t pin, float brightness = 1.0) : pixelCount(count), pixelPin(pin), strip(count, pin), brightness(brightness) {}

    void begin() {
        strip.Begin();
        strip.Show();
    }

    void showRainbow() {
    for(int j = 0; j < 256; j++) { 
        for(uint16_t i = 0; i < pixelCount; i++) {
            RgbColor color = wheel.getColor(((i * 256 / pixelCount) + j) & 255, brightness);
            strip.SetPixelColor(i, color);
        }
        strip.Show();
        delay(20);  // Adjust this delay to speed up/slow down the rainbow animation
    }
}
};