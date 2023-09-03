#include <Arduino.h>
#include <NeoPixelBus.h>

class ColorWheel {
public:
    ColorWheel() {}

    // Method to get a color from a wheel position
    RgbColor getColor(byte wheelPos) const {
        return getColor(wheelPos, 1.0f); // default brightness is 1 (full brightness)
    }

    // Overloaded method to get a color from a wheel position with brightness adjustment
    RgbColor getColor(byte wheelPos, float brightness) const {
        wheelPos = 255 - wheelPos;
        if (brightness < 0.0f) brightness = 0.0f;
        if (brightness > 1.0f) brightness = 1.0f;
        // first third
        if (wheelPos < 85) {
            return RgbColor((255 - wheelPos * 3) * brightness, 0, (wheelPos * 3) * brightness);
        } 
        // second third
        else if (wheelPos < 170) {
            wheelPos -= 85;
            return RgbColor(0, (wheelPos * 3) * brightness, (255 - wheelPos * 3) * brightness);
        } 
        // final third
        else {
            wheelPos -= 170;
            return RgbColor((wheelPos * 3) * brightness, (255 - wheelPos * 3) * brightness, 0);
        }
    }
};