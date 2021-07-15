#include "Logic.hpp"
#include "Functions.hpp"
#include <iostream>
#include <vector>

void bouncingBall(int bounces)
{
    int pos[] = {0, 9};
    int color[] = {0, 0, 0};
    int ballRadius = 1;
    for (int i = 0; i < bounces; i++)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (buttons.read(RightUp) && buttons.read(LeftUp))
            {
                i = 0;
                return;
            }

            display.drawCircleFilled(pos[0], pos[1], ballRadius, Rgb(color[0], color[1], color[2]));
            display.show();
            delay(100);
            display.drawCircleFilled(pos[0], pos[1], ballRadius, Rgb(0, 0, 0));
            color[0] += 10;
            color[1] += 10;
            color[2] += 10;
            if (buttons.read(Up))
            {
                ballRadius++;
            }
            if (buttons.read(Down))
            {
                ballRadius--;
            }

            pos[0] += 1;
            pos[1] -= 1;
            if (pos[0] >= 9 && pos[1] <= 0)
            {
                break;
            }
        }
        color[0] = random(255);
        color[1] = random(255);
        color[2] = random(255);
        if (pos[0] == 9)
        {
            pos[0] = 9;
            pos[1] = 0;
            for (int j = 0; j <= 9; j++)
            {
                if (buttons.read(RightUp) && buttons.read(LeftUp))
                {
                    j = 0;
                    return;
                }
                display.drawCircleFilled(pos[0], pos[1], ballRadius, Rgb(color[0], color[1], color[2]));
                display.show();
                delay(100);
                display.drawCircleFilled(pos[0], pos[1], ballRadius, Rgb(0, 0, 0));
                if (buttons.read(Up))
                {
                    ballRadius++;
                }
                if (buttons.read(Down))
                {
                    ballRadius--;
                }
                pos[0] -= 1;
                pos[1] += 1;
            }
        }
    }
}

int choice(std::vector<int> list)
{
    int idx = random(list.size());
    return list[idx];
}

std::vector<Rgb> redPalette = {Rgb(0, 0, 0),
                               Rgb(100, 0, 0),
                               Rgb(200, 0, 0),
                               Rgb(255, 50, 0),
                               Rgb(255, 100, 0)};

std::vector<Rgb> bluePalette = {Rgb(0, 0, 0),
                                Rgb(0, 0, 100),
                                Rgb(50, 50, 200),
                                Rgb(150, 150, 255),
                                Rgb(255, 255, 255)};

std::vector<Rgb> rainbowPalette = {Rgb(0, 0, 0),
                                   Rgb(255, 0, 255),
                                   Rgb(0, 0, 255),
                                   Rgb(0, 255, 255),
                                   Rgb(0, 255, 0),
                                   Rgb(255, 255, 0),
                                   Rgb(255, 0, 0)};

std::array<std::vector<Rgb>, 3> palettes = {redPalette, bluePalette, rainbowPalette};
int paletteIdx = 0;

bool produceMore = true;
bool randomWindChange = true;
int windDirection = -1;
int brightness = 10;

class Particle
{

public:
    Particle(int xIn, int yIn)
    {
        x = xIn;
        y = yIn;
        ownPaletteIdx = paletteIdx;
        temperature = palettes[ownPaletteIdx].size() - 1;
    }

    void spread()
    {
        y -= choice(std::vector({1, 1, 1, 1, 1, 1, 0}));
        std::vector<int> list({0, 0, 0, 0, 0, 0, 0});

        for (int i = 9; i > y; i--)
        {
            list.push_back(1);
        }

        x += choice(list) * windDirection;
        std::vector<int> list1({0, 0, 1});
        for (int i = 9; i > y; i -= 2)
        {
            list1.push_back(1);
        }

        temperature -= choice(list1);
    }

    void draw()
    {
        display.at(x, y) = palettes[ownPaletteIdx][temperature];
    }

    int x;
    int y;
    int temperature;
    int ownPaletteIdx;
};

std::vector<Particle> particles;

void screenSaverFire()
{


    // buttons.onRelease([]()
    //                   {
    //                       windDirection = -1;
    //                       randomWindChange = false;
    //                       produceMore = true;
    //                   },
    //                   Left);

    // buttons.onRelease([]()
    //                   {
    //                       windDirection = 1;
    //                       randomWindChange = false;
    //                       produceMore = true;
    //                   },
    //                   Right);

    // buttons.onRelease([]()
    //                   {
    //                       windDirection = 0;
    //                       randomWindChange = false;
    //                       produceMore = true;
    //                   },
    //                   Up);

    // buttons.onRelease([]()
    //                   {
    //                       randomWindChange = true;
    //                       produceMore = true;
    //                       windDirection = choice(std::vector({-1, 1}));
    //                   },
    //                   Enter);

    // buttons.onRelease([]()
    //                   {
    //                       paletteIdx--;
    //                       if (paletteIdx < 0)
    //                       {
    //                           paletteIdx = palettes.size() - 1;
    //                       }
    //                   },
    //                   LeftDown);

    // buttons.onRelease([]()
    //                   {
    //                       paletteIdx++;
    //                       if (paletteIdx >= palettes.size())
    //                       {
    //                           paletteIdx = 0;
    //                       }
    //                   },
    //                   RightDown);

    // buttons.onRelease([]()
    //                   {
    //                       if (brightness > 1)
    //                       {
    //                           brightness--;
    //                       }
    //                   },
    //                   LeftUp);

    // buttons.onRelease([]()
    //                   {
    //                       if (brightness < 10)
    //                       {
    //                           brightness++;
    //                       }
    //                   },
    //                   RightUp);

    // buttons.onRelease([]()
    //                   { produceMore = !produceMore; },
    //                   Down);

    statusBar.setColor(Rgb(255, 255, 255));

    while (true)
    {
        buttons.onPress([]()
                        {

                        return; 
                        
                        });
            statusBar.clear();
        statusBar.setState(((int)((brightness + 1) / 2)));
        statusBar.show(brightness * 10);

        display.clear();

        if (randomWindChange)
        {
            bool change = (bool)choice(std::vector({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}));
            if (change)
                windDirection *= -1;
        }

        if (produceMore)
        {
            for (int i = 0; i < 10; i++)
            {
                particles.push_back(Particle(i, 9));
            }
            for (int i = 2; i < 7; i++)
            {
                particles.push_back(Particle(i, 8));
            }
        }

        int idx = 0;
        for (Particle &particle : particles)
        {
            particle.draw();
            particle.spread();
            if (particle.y < 0 || particle.temperature == 0 || particle.x < 0 || particle.x > 9)
            {
                particles.erase(particles.begin() + idx);
            }
            idx++;
        }

        display.show(brightness * 10);
        delay(100);
    }
}

void showScreenSaver (bool inGame) {
    buttons.onPress([=](){
        if (inGame) {
            return;
        }
        delay(5000);
        screenSaverFire();
    });
}