#include "shared.hpp"

GameState::GameState(bool restartIn, bool quitIn)
{
    restart = restartIn;
    quit = quitIn;
}

GameState::GameState(bool restartIn)
{
    restart = restartIn;
}

GameState::GameState() {}

GameState Game::update()
{
    leftPressed = false;
    rightPressed = false;
    upPressed = false;
    downPressed = false;
    enterPressed = false;
    leftReleased = false;
    rightReleased = false;
    upReleased = false;
    downReleased = false;
    enterReleased = false;

    bool prevLeftState = leftState;
    bool prevRightState = rightState;
    bool prevUpState = upState;
    bool prevDownState = downState;
    bool prevEnterState = enterState;

    leftState = buttons.read(Left);
    rightState = buttons.read(Right);
    upState = buttons.read(Up);
    downState = buttons.read(Down);
    enterState = buttons.read(Enter);

    if ((!prevLeftState) && leftState)
        leftPressed = true;
    if ((!prevRightState) && rightState)
        rightPressed = true;
    if ((!prevUpState) && upState)
        upPressed = true;
    if ((!prevDownState) && downState)
        downPressed = true;
    if ((!prevEnterState) && enterState)
        enterPressed = true;

    if (prevLeftState && !leftState)
        leftReleased = true;
    if (prevRightState && !rightState)
        rightReleased = true;
    if (prevUpState && !upState)
        upReleased = true;
    if (prevDownState && !downState)
        downReleased = true;
    if (prevEnterState && !enterState)
        enterReleased = true;

    return GameState();
}