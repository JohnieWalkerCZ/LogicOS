#include "Logic.hpp"
#include "Functions.hpp"
#include "MSplugin.hpp"
#include <iostream>
int bounces = 2;
int onScreen = 0;
bool inGame = false;

void showScreen0()
{
    onScreen = 0;
    display.drawCircleFilled(3, 6, 2, Rgb(255, 0, 0));
    display.drawSquare(0, 0, 10, Rgb(0, 255, 0));
    display.show();
}

void showScreen1()
{
    onScreen = 1;
    display.drawCircleFilled(6, 3, 1, Rgb(0, 0, 255));
    display.drawSquare(0, 0, 10, Rgb(255, 0, 0));
    display.show();
}

void showScreenM1()
{
    onScreen = -1;
    display.drawLine(1, 8, 8, 8, Rgb(0, 72, 0));
    display.drawLine(1, 7, 8, 7, Rgb(0, 0, 0));
    display.drawLine(3, 7, 6, 7, Rgb(150, 0, 0));
    display.drawLine(1, 1, 1, 5, Rgb(0, 255, 0));
    display.at(2, 1) = Rgb(0, 255, 0);
    display.at(3, 2) = Rgb(0, 255, 0);
    display.at(4, 1) = Rgb(0, 255,0);
    display.drawLine(5, 1, 5, 5, Rgb(0, 255, 0));
    display.drawLine(7, 1, 8, 1, Rgb(255, 255, 0));
    display.at(6, 2) = Rgb(255, 255, 0);
    display.at(7, 3) = Rgb(255, 255, 0);
    display.at(8, 4) = Rgb(255, 255, 0);
    display.drawLine(6, 5, 7, 5, Rgb(255, 255, 0));

    display.drawSquare(0, 0, 10, Rgb(0, 0, 255));
    display.show();
}

void logicMain()
{
    showScreen0();
    buttons.onPress([]()
                    {
                        display.clear();
                        if (onScreen == -1)
                        {
                            inGame = true;
                            minesweeper();
                            inGame = false;
                        }
                        else
                        {
                            inGame = true;
                            bouncingBall(bounces);
                            inGame = false;
                        }
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
    // showScreenSaver(inGame);
}