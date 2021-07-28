#include "Logic.hpp"
#include "Games.hpp"
#include "MSplugin.hpp"
#include "ConvertImgs.hpp"
#include "Other.hpp"
#include <iostream>
int bounces = 2;
int onScreen = 0;
bool inGame = false;
const int speed = 100;
int brightness = 20;

void showScreen0()
{
    onScreen = 0;
    convertImgFlappyBird(brightness);
}

void showScreen1()
{
    onScreen = 1;
    convertImgSnake(brightness);
}

void showScreenM1()
{
    onScreen = -1;
    convertImgMineSweeper(brightness);
}

void logicMain()
{
    delay(200);
    display.clear();
    convertImgPre();
    showScreen0();
    buttons.onPress([]()
                    {
                        display.clear();
                        switch (onScreen)
                        {
                        case -1:
                            minesweeper(brightness);
                            showScreenM1();
                            break;
                        case 0:
                            flappyBird(brightness);
                            showScreen0();
                            break;
                        case 1:
                            snakeMain(speed, brightness);
                            showScreen1();
                            break;
                        default:
                            break;
                        }
                    },
                    Enter);
    buttons.onPress([]()
                    {
                        switch (onScreen)
                        {
                        case -1:
                            onScreen += 1;
                            display.clear();
                            showScreen0();
                            break;

                        case 0:
                            onScreen += 1;
                            display.clear();
                            showScreen1();
                            break;

                        default:
                            break;
                        }
                    },
                    Right);
    buttons.onPress([]()
                    {
                        switch (onScreen)
                        {
                        case 0:
                            onScreen -= 1;
                            display.clear();
                            showScreenM1();
                            break;

                        case 1:
                            onScreen -= 1;
                            display.clear();
                            showScreen0();
                        default:
                            break;
                        }
                    },
                    Left);
    buttons.onPress([]()
                    {
                        brightness = increaseBrightness(brightness);
                        switch (onScreen)
                        {
                        case -1:
                            showScreenM1();
                            break;
                        case 0:
                            showScreen0();
                            break;
                        case 1:
                            showScreen1();
                            break;
                        default:
                            break;
                        }
                    },
                    Up);
    buttons.onPress([]()
                    {
                        brightness = decreaseBrightness(brightness);
                        switch (onScreen)
                        {
                        case -1:
                            showScreenM1();
                            break;
                        case 0:
                            showScreen0();
                            break;
                        case 1:
                            showScreen1();
                            break;
                        default:
                            break;
                        }
                    },
                    Down);
}