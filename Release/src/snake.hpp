#include "shared.hpp"

#include <list>

class GameSnake : public Game
{

public:
    GameSnake();

    GameState update();

private:
    int direction = 2;
    int loop = 0;
    int appleX;
    int appleY;
    bool isDead = false;
    int deadTicks = 0;

    void drawSnake();

    void die();

    void placeApple();

    class Body
    {

    public:
        Body(int xIn, int yIn);

        int x;
        int y;
    };

    std::list<Body> snake = {};
};