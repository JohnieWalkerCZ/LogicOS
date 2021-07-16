#include "Logic.hpp"

class GameState
{

public:
    bool restart;
    bool quit;

    GameState(bool restartIn, bool quitIn);

    GameState(bool restartIn);

    GameState();
};

class Game
{

public:
    GameState update();

protected:
    bool leftState = false;
    bool rightState = false;
    bool upState = false;
    bool downState = false;
    bool enterState = false;

    bool leftDown = false;
    bool rightDown = false;
    bool upDown = false;
    bool downDown = false;
    bool enterDown = false;
    bool leftUp = false;
    bool rightUp = false;
    bool upUp = false;
    bool downUp = false;
    bool enterUp = false;

    bool leftPressed = false;
    bool rightPressed = false;
    bool upPressed = false;
    bool downPressed = false;
    bool enterPressed = false;
    bool leftReleased = false;
    bool rightReleased = false;
    bool upReleased = false;
    bool downReleased = false;
    bool enterReleased = false;
};