#include "Logic.hpp"
#include "MSplugin.hpp"
#include "Games.hpp"
#include "ConvertImgs.hpp"
#include <iostream>

int increaseBrightness(int brightness)
{
    if (brightness >= 250)
    {
        return brightness;
    }
    brightness += 10;
    return brightness;
}

int decreaseBrightness(int brightness)
{
    if (brightness <= 10)
    {
        return brightness;
    }
    brightness -= 10;
    return brightness;
}

int switchScreens(int onScreen, int brightness, bool right)
{

    if (right)
    {
        std::cout << "right onScreen before: " << onScreen << std::endl;
        onScreen++;
        std::cout << "rigth onScreen after: " << onScreen << std::endl;
        switch (onScreen)
        {
        case -1:
            convertImgMineSweeper(brightness);
            return onScreen;
        case 0:
            convertImgFlappyBird(brightness);
            return onScreen;
        case 1:
            convertImgSnake(brightness);
            return onScreen;
        default:
            break;
        }
        std::cout << "rigth onScreen after: " << onScreen << std::endl;
    }
    else
    {
        std::cout << "left onScreen after: " << onScreen << std::endl;
        onScreen--;
        std::cout << "left onScreen after: " << onScreen << std::endl;
        switch (onScreen)
        {
        case -1:
            convertImgMineSweeper(brightness);
            return onScreen;
        case 0:
            convertImgFlappyBird(brightness);
            return onScreen;
        case 1:
            convertImgSnake(brightness);
            return onScreen;
        default:
            break;
        }
        std::cout << "left onScreen after: " << onScreen << std::endl;
    }
    return onScreen;
}

void showCurrentScreen(int brightness, int onScreen)
{
    switch (onScreen)
    {
    case -1:
        convertImgMineSweeper(brightness);
        break;
    case 0:
        convertImgFlappyBird(brightness);
        break;
    case 1:
        convertImgSnake(brightness);
        break;
    default:
        break;
    }
}

void clearButtonsCallbacks()
{
    Buttons::CallbackList &buttonCallbacks = buttons.callbackList();
    int index = 0;

    buttonCallbacks.forEach([&buttonCallbacks, &index](const Buttons::CallbackList::Handle &handle, const Buttons::CallbackList::Callback &callback)
                            {
                                std::cout << "forEach(Handle, Callback), invoked " << index << std::endl;
                                buttonCallbacks.remove(handle);
                                ++index;
                            });
    std::cout << "Cleared all callbacks" << std::endl;
}

void loadOSCallbacks(int &brightness, int &onScreen, int snakeSpeed)
{
    buttons.onPress([&onScreen, &brightness, snakeSpeed]()
                    {
                        display.clear();
                        playChosenGame(brightness, onScreen, snakeSpeed);
                        showCurrentScreen(brightness, onScreen);
                    },
                    Enter);
    buttons.onPress([&onScreen, &brightness]()
                    { onScreen = switchScreens(onScreen, brightness, true); },
                    Right);
    buttons.onPress([&onScreen, &brightness]()
                    { onScreen = switchScreens(onScreen, brightness, false); },
                    Left);
    buttons.onPress([&onScreen, &brightness]()
                    {
                        brightness = increaseBrightness(brightness);

                        showCurrentScreen(brightness, onScreen);
                    },
                    Up);
    buttons.onPress([&onScreen, &brightness]()
                    {
                        brightness = decreaseBrightness(brightness);

                        showCurrentScreen(brightness, onScreen);
                    },
                    Down);
    std::cout << "Loaded OS callbacks" << std::endl;
}
