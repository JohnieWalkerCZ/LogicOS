#pragma once

#include "Logic.hpp"
#include "basic_gameLib.hpp"

struct singleKobra_in {
    /*singleKobra_in(){
    }*/
    position starting_body[16]/* = {(0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0)}*/;
    short int starting_lenght = 0;
    short int starting_direction = 5;
    area apples_spawnArea/* = area{.rectangles_number = 1, .rectangle_starts = {(0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0)}, .rectangle_ends = {(9, 9), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0)}}*/;
    short int applesAtOnce = 1; // max is 16
    short int applesEverSpawned = -1; // -1 = infinity
    short int victory_score = -1; // -1 = no victory
    bool scoreCounter_on = true;
    bool periodic_area = true;
    short int area_height = 10;
    short int area_width = 10;
    position borders[1024];
    short int used_borders = 0;
    short int starting_slowness = 100; // 1 slowness point = 10 delay per time step
    short int timeStep_acceleration = 0;
    short int score_acceleration = 1;
    short int min_slowness = 10;
    bool allowed_keys[8] = {true, false, true, false, true, false, true, false};
};
struct kobra_record {
    unsigned short int timeSteps;
    short int directions[4096];
    short int apples_spawnTimes[256];
    position apples_spawnPositions[256];
    short int apples_spawns;
};
struct kobra_out {
    int score;
    kobra_record record;
};

void basic_kobra();
void setable_kobra(int default_slowness, int timeStep_acceleration, int score_acceleration, bool allowed_keys[8] /* 0 Up | 1 LeftUp | 2 Left | ... | 7 RightUp */, int maxScore, bool score_counter_on, position borders[100]);
