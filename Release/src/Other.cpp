#include "Logic.hpp"
#include <iostream>

int increaseBrightness (int brightness) {
    if (brightness >= 250) {
        return brightness;
    }
    brightness += 10;
    return brightness;
}

int decreaseBrightness (int brightness) {
    if (brightness <= 10) {
        return brightness;
    }
    brightness -= 10;
    return brightness;
}