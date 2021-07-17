#include"basic_gameLib.hpp"
#include"Logic.hpp"

in_out int_in(int part, int list[1024], int lenght) {
    bool in = false;
    int number = -1;
    for(int i = 0; i < lenght; i++)
        if(list[i] == part) {in = true; number = i;}
    return in_out{in, number};
}

in_out position_in(position part, position list[1024], int lenght) {
    bool in = false;
    int number = -1;
    for(int i = 0; i < lenght; i++)
        if((list[i].x == part.x) && (list[i].y == part.y)) {in = true; number = i;}
    return in_out{in, number};
}

void reverse_display() {
    for(int x = 0; x < 10; x++)
        for(int y = 0; y < 10; y++) 
            display.setColor(x, y, Rgb(255 - display.at(x, y).r, 255 - display.at(x, y).g, 255 - display.at(x, y).b));
    display.show();
    return;
}

int periodic_plus(int min, int parts, int total) {
    return (total%(parts))+min;
}

position goDirection(position pos_before, short int direction, bool periodic, short int period_width, short int period_height) {
    position out = pos_before;
    if(direction == 0) {out.y = out.y - 1;}
    if(direction == 1) {out.x = out.x - 1; out.y = out.y - 1;}
    if(direction == 2) {out.x = out.x - 1;}
    if(direction == 3) {out.x = out.x - 1; out.y = out.y + 1;}
    if(direction == 4) {out.y = out.y + 1;}
    if(direction == 5) {out.x = out.x + 1; out.y = out.y + 1;}
    if(direction == 6) {out.x = out.x + 1;}
    if(direction == 7) {out.x = out.x + 1; out.y = out.y - 1;}
    if(periodic){
        if(out.x == -1) out.x = 9;
        if(out.x == period_width) out.x = 0;
        if(out.y == -1) out.y = 9;
        if(out.y == period_width) out.y = 0;
    }
    return out;
}

void score_counter(int score) {
    statusBar.clear();
    if(score < 32) {
        int score2 = score;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(255, 0, 0);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(255, 0, 0);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(255, 0, 0);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(255, 0, 0);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(255, 0, 0);
    }
    else if(score < 64) {
        int score2 = score - 32;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(255, 127, 0);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(255, 127, 0);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(255, 127, 0);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(255, 127, 0);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(255, 127, 0);
    }
    else if(score < 96) {
        int score2 = score - 64;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(255, 255, 0);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(255, 255, 0);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(255, 255, 0);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(255, 255, 0);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(255, 255, 0);
    }
    else if(score < 128) {
        int score2 = score - 96;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(127, 255, 0);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(127, 255, 0);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(127, 255, 0);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(127, 255, 0);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(127, 255, 0);
    }
    else if(score < 160) {
        int score2 = score - 128;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(0, 255, 0);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(0, 255, 0);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(0, 255, 0);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(0, 255, 0);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(0, 255, 0);
    }
    else if(score < 192) {
        int score2 = score - 160;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(0, 255, 127);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(0, 255, 127);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(0, 255, 127);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(0, 255, 127);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(0, 255, 127);
    }
    else if(score < 224) {
        int score2 = score - 192;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(0, 255, 255);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(0, 255, 255);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(0, 255, 255);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(0, 255, 255);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(0, 255, 255);
    }
    else if(score < 256) {
        int score2 = score - 224;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(0, 127, 255);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(0, 127, 255);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(0, 127, 255);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(0, 127, 255);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(0, 127, 255);
    }
    else if(score < 288) {
        int score2 = score - 256;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(0, 0, 255);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(0, 0, 255);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(0, 0, 255);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(0, 0, 255);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(0, 0, 255);
    }
    else if(score < 320) {
        int score2 = score - 288;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(127, 0, 255);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(127, 0, 255);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(127, 0, 255);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(127, 0, 255);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(127, 0, 255);
    }
    else if(score < 352) {
        int score2 = score - 320;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(255, 0, 255);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(255, 0, 255);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(255, 0, 255);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(255, 0, 255);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(255, 0, 255);
    }
    else if(score < 384) {
        int score2 = score - 352;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(255, 0, 127);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(255, 0, 127);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(255, 0, 127);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(255, 0, 127);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(255, 0, 127);
    }
    else if(score < 416) {
        int score2 = score - 384;
        if((score2 >> 0) & 1) statusBar.at(A) = Rgb(255, 255, 255);
        if((score2 >> 1) & 1) statusBar.at(B) = Rgb(255, 255, 255);
        if((score2 >> 2) & 1) statusBar.at(C) = Rgb(255, 255, 255);
        if((score2 >> 3) & 1) statusBar.at(D) = Rgb(255, 255, 255);
        if((score2 >> 4) & 1) statusBar.at(E) = Rgb(255, 255, 255);
    }
}

void victory_screen() {
    display.clear();
    display.drawRectangleFilled(Rectangle(3, 2, 4, 5), Rgb(255, 255, 0));
    display.setColor(2, 2, Rgb(255, 255, 0));
    display.setColor(2, 3, Rgb(255, 255, 0));
    display.setColor(1, 3, Rgb(255, 255, 0));
    display.setColor(1, 4, Rgb(255, 255, 0));
    display.setColor(2, 5, Rgb(255, 255, 0));
    display.setColor(7, 2, Rgb(255, 255, 0));
    display.setColor(7, 3, Rgb(255, 255, 0));
    display.setColor(8, 3, Rgb(255, 255, 0));
    display.setColor(8, 4, Rgb(255, 255, 0));
    display.setColor(7, 5, Rgb(255, 255, 0));
    display.drawRectangleFilled(Rectangle(4, 7, 2, 3), Rgb(255, 255, 0));
    display.setColor(3, 9, Rgb(255, 255, 0));
    display.setColor(6, 9, Rgb(255, 255, 0));
    display.show();
}

void show_image(Rgb image[100]) {
    for(int x = 0; x < 10; x++)
        for(int y = 0; y < 10; y++)
            display.setColor(x, y, image[(x * 10) + y]);
    display.show();
}

area_points generate_areaPoints(area input) {
    area_points out; out.points_number = 0;
    for(int rect_number = 0; rect_number < input.rectangles_number; rect_number++)
        for(int rect_x = input.rectangle_starts[rect_number].x; rect_x < (input.rectangle_ends[rect_number].x + 1); rect_x++)
            for(int rect_y = input.rectangle_starts[rect_number].y; rect_y < (input.rectangle_ends[rect_number].y + 1); rect_y++)
                if(!(position_in(position{rect_x, rect_y}, out.positions, out.points_number).in)) {
                    out.positions[out.points_number] = position{rect_x, rect_y};
                    out.points_number++;
                }
    return out;
}
