#include "Logic.hpp"
#include "Games.hpp"
#include "snake.hpp"
#include "esp_spiffs.h"
#include <iostream>
#include <vector>
#include <cstdio>

//Snake

void snakeMain(int speed, int brightness)
{
    GameSnake game;

    while (true)
    {
        display.clear();

        GameState gamestate = game.update();

        if (gamestate.restart)
        {
            game = GameSnake();
        }
        else if (gamestate.quit)
        {
            return;
        }

        display.show(brightness);
        delay(speed);
    }
}

//Flappy Bird
const int numberOfPipes = 10;
int birdY = 4;

void BOOM(int brightness)
{

    for (int i = 0; i < 20; i++)
    {
        display.clear();
        display.drawCircle(2, birdY, i, Rgb(255, 255, 0));
        display.drawCircle(2, birdY, i + 1, Rgb(255, 0, 0));
        display.show(brightness);
        delay(100);
    }
    display.clear();
}

void bird()
{
    display.at(1, birdY) = Rgb(255, 255, 0);
    display.at(2, birdY) = Rgb(255, 255, 0);
}

void destroyBird()
{
    display.at(1, birdY) = Rgb(0, 0, 0);
    display.at(2, birdY) = Rgb(0, 0, 0);
}

void pipes(int brightness)
{
    int pipeX = 9;
    for (int i = 0; i <= numberOfPipes; i++)
    {
        int cutoutY = random(1, 8);
        int cutoutYOffset = random(2, 3);
        int cutoutY2nd = cutoutY + cutoutYOffset;

        for (int i = 0; i <= 9; i++)
        {
            destroyBird();
            birdY++;
            if (buttons.read(Enter))
            {
                // std::cout << "Enter was pressed" << std::endl;
                display.at(1, birdY) = Rgb(0, 0, 0);
                display.at(2, birdY) = Rgb(0, 0, 0);
                birdY -= 3;
                display.at(1, birdY) = Rgb(255, 255, 0);
                display.at(2, birdY) = Rgb(255, 255, 0);
            }
            if (birdY <= 0)
            {
                birdY = 0;
            }
            if (birdY >= 10)
            {
                birdY = 4;
                break;
            }
            if (buttons.read(LeftUp) && buttons.read(RightUp))
            {
                //return back to OS
                return;
            }
            if (pipeX <= 1 && !(birdY >= cutoutY && birdY <= cutoutY + cutoutYOffset))
            {
                BOOM(brightness);
                return;
            }
            display.drawLine(pipeX, 0, pipeX, 9, Rgb(0, 255, 0));
            display.drawLine(pipeX, cutoutY, pipeX, cutoutY2nd, Rgb(0, 0, 0));
            bird();
            display.show(brightness);
            display.drawLine(pipeX, 0, pipeX, 9, Rgb(0, 0, 0));
            delay(200);
            pipeX--;
        }
        pipeX = 9;
    }
}

void flappyBird(int brightness)
{
//     buttons.onPress([]()
//                     {
//                         // std::cout << "Enter was pressed" << std::endl;
//                         display.at(1, birdY) = Rgb(0, 0, 0);
//                         //Toto NIKDY nepridavat do kodu.
// //---------------------------------------------------------------------
//                         // birdY -= 3;
// //---------------------------------------------------------------------
//                         display.at(2, birdY) = Rgb(0, 0, 0);
//                         display.at(1, birdY) = Rgb(255, 255, 0);
//                         display.at(2, birdY) = Rgb(255, 255, 0);
//                     },
//                     Enter);
    bird();
    pipes(brightness);
}