#pragma once

#include"Logic.hpp"

struct position {
    int x;
    int y;
    friend bool operator==(const position& a, const position& b) {
        return (a.x == b.x) && (a.y == b.y);
    }
};

position operator+(const position& a, const position& b) {
    return position{a.x + b.x, a.y + b.y};
}

struct area {
    int rectangles_number;
    position rectangle_starts[16];
    position rectangle_ends[16];
};

struct area_points {
    short int points_number;
    position positions[1024];
};

struct in_out {
    bool in;
    int number;
};

in_out int_in(int part, int list[1024], int lenght);
in_out position_in(position part, position list[1024], int lenght);
void reverse_display();
int periodic_plus(int min, int parts, int total);
void score_counter(int score);
position goDirection(position pos_before, short int direction, bool periodic, short int period_width, short int period_height);
void victory_screen();
void show_image(Rgb image[100]);
area_points generate_areaPoints(area input);
