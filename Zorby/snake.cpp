#include "snake.hpp"

GameSnake::GameSnake()
{
    snake.push_front(Body(0, 0));
    snake.push_front(Body(0, 1));
    snake.push_front(Body(0, 2));

    appleX = random(1, 9);
    appleY = random(3, 9);
}

GameState GameSnake::update()
{
    Game::update();

    display.at(appleX, appleY) = Rgb(200, 20, 10);

    if (!isDead)
    {
        if (upReleased && direction != 2)
            direction = 0;
        else if (rightReleased && direction != 3)
            direction = 1;
        else if (downReleased && direction != 0)
            direction = 2;
        else if (leftReleased && direction != 1)
            direction = 3;

        drawSnake();

        loop++;
        if (loop == 4)
        {
            int x = snake.front().x;
            int y = snake.front().y;

            if (direction == 0)
            {
                snake.push_front(Body(x, y - 1));
            }
            else if (direction == 1)
            {
                snake.push_front(Body(x + 1, y));
            }
            else if (direction == 2)
            {
                snake.push_front(Body(x, y + 1));
            }
            else if (direction == 3)
            {
                snake.push_front(Body(x - 1, y));
            }
            loop = 0;
            if (snake.front().x == appleX && snake.front().y == appleY)
            {
                placeApple();
            }
            else
            {
                snake.pop_back();
            }
            int idx = 0;
            for (Body body : snake)
            {
                if (snake.front().x == body.x && snake.front().y == body.y && idx != 0)
                {
                    die();
                    return GameState();
                }

                idx++;
            }

            if (snake.front().x < 0 || snake.front().x > 9 || snake.front().y < 0 || snake.front().y > 9)
            {
                snake.pop_front();
                die();
                return GameState();
            }
        }
    }
    else
    {
        if (deadTicks == 25)
        {
            return GameState(true);
        }

        if (((int)deadTicks / 5) % 2 == 0)
        {
            drawSnake();
        }

        deadTicks++;
    }
    return GameState();
}

void GameSnake::drawSnake()
{
    int idx = 0;
    Rgb color;
    for (Body body : snake)
    {
        if (idx == 0)
        {
            color = Rgb(70, 255, 70);
        }
        else if (idx % 2 == 1)
            color = Rgb(0, 50, 10);
        else
            color = Rgb(0, 200, 30);
        display.at(body.x, body.y) = color;
        idx++;
    }
}

void GameSnake::die()
{
    isDead = true;
}

void GameSnake::placeApple()
{
    appleX = random(9);
    appleY = random(9);

    for (Body body : snake)
    {
        if (body.x == appleX && body.y == appleY)
        {
            placeApple();
            return;
        }
    }
}

GameSnake::Body::Body(int xIn, int yIn)
{
    x = xIn;
    y = yIn;
}