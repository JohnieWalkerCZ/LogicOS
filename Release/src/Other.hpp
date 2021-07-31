#pragma once

#include "Logic.hpp"
#include <iostream>

int increaseBrightness(int brightness);
int decreaseBrightness(int brightness);
int switchScreens(int onScreen, int brightness, bool right);
void showCurrentScreen(int brighness, int onScreen);
void clearButtonsCallbacks();
void loadOSCallbacks(int & brightness, int & onScreen, int snakeSpeed);