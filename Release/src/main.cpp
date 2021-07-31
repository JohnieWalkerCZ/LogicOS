#include "Logic.hpp"
#include "Games.hpp"
#include "MSplugin.hpp"
#include "ConvertImgs.hpp"
#include "Other.hpp"
#include <iostream>
int bounces = 2;
int onScreen = 0;
int snakeSpeed = 100;
int speed = 100;
int brightness = 20;
bool right = NULL;

void logicMain()
{
    display.clear();
    convertImgPre();
    convertImgFlappyBird(brightness);
    
    loadOSCallbacks(brightness, onScreen, snakeSpeed);

}