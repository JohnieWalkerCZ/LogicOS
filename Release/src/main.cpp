#include "Logic.hpp"
#include "Games.hpp"
#include "MSplugin.hpp"
#include "ConvertImgs.hpp"
#include <iostream>
int bounces = 2;
int onScreen = 0;
bool inGame = false;
const int speed = 100;

void showScreen0()
{
    onScreen = 0;
    convertImgFlappyBird();
}

void showScreen1()
{
    onScreen = 1;
    convertImgSnake();
}

void showScreenM1()
{
    onScreen = -1;
    convertImgMineSweeper();
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
                            minesweeper();
                            break;
                        case 0:
                            flappyBird();
                            break;

                        case 1:
                            snakeMain(speed);
                            break;

                        default:
                            break;
                        }
                        switch (onScreen)
                        {
                        case -1:
                            showScreenM1();
                            // std::cout << "Screen: " << onScreen << "\n";
                            break;
                        case 0:
                            showScreen0();
                            // std::cout << "Screen: " << onScreen << "\n";
                            break;
                        case 1:
                            showScreen1();
                            // std::cout << "Screen: " << onScreen << "\n";
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
                            // std::cout << "Screen: " << onScreen << "\n";
                            break;

                        case 0:
                            onScreen += 1;
                            display.clear();
                            showScreen1();
                            // std::cout << "Screen: " << onScreen << "\n";
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
                            // std::cout << "Screen: " << onScreen << "\n";
                            break;

                        case 1:
                            onScreen -= 1;
                            display.clear();
                            showScreen0();
                            // std::cout << "Screen " << onScreen << "\n";
                        default:
                            break;
                        }
                    },
                    Left);
}