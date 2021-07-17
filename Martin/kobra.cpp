#include"kobra.hpp"
#include"Logic.hpp"
#include"basic_gameLib.hpp"

void basic_kobra() {
    int slowness = 100;
    position nextHeadPosition;
    position apple = {.x = random(0, 9), .y = random(0, 9)};
    position body[100]; body[0] = position{2, 2};
    int kobra_lenght = 1;
    short int direction = 7; // 0 up | 1 left-up | 2 left | 3 left-down | 4 down | 5 right-down | 6 right | 7 right-up
    bool fail = false;
    while(!(fail)) {
        for(int i = 0; i < slowness; i++) {
            if(buttons.read(Up) && (!(direction == 4))) direction = 0;
            if(buttons.read(LeftUp) && (!(direction == 5))) direction = 1;
            if(buttons.read(Left) && (!(direction == 6))) direction = 2;
            if(buttons.read(LeftDown) && (!(direction == 7))) direction = 3;
            if(buttons.read(Down) && (!(direction == 0))) direction = 4;
            if(buttons.read(RightDown) && (!(direction == 1))) direction = 5;
            if(buttons.read(Right) && (!(direction == 2))) direction = 6;
            if(buttons.read(RightUp) && (!(direction == 3))) direction = 7;
            delay(10);
        }
        // Apple detection
        nextHeadPosition = goDirection(body[0], direction, true, 10, 10);
        if((nextHeadPosition.x == apple.x) && (nextHeadPosition.y == apple.y)) {
            body[kobra_lenght] = position{0, 0};
            kobra_lenght++;
            slowness = slowness - 1;
            while(position_in(apple, body, kobra_lenght-1).in || ((apple.x == nextHeadPosition.x) && (apple.y == nextHeadPosition.y)))
                apple = position{random(0, 9), random(0, 9)};
        }
        // Impact detection
        if(position_in(nextHeadPosition, body, kobra_lenght - 1).in) fail = true;
        else
        {
            // Kobra shift
            for(int i = kobra_lenght - 1; i > 0; i = i - 1) {
                body[i] = body[i - 1];
            }
            body[0] = nextHeadPosition;
        }
        // Refreshing screen
        display.clear();
        for(int i = 1; i < kobra_lenght; i++) {
            display.setColor(body[i].x, body[i].y, Rgb(0, 255, 0));
        }
        display.setColor(body[0].x, body[0].y, Rgb(0, 0, 255));
        display.setColor(apple.x, apple.y, Rgb(255, 0, 0));
        display.show();
    }
    buzzer.on();
    for(int i = 0; i < 10; i++) {
        delay(100);
        reverse_display();
    }
    buzzer.off();
    display.clear(); 
    display.show();
}

/*
Rgb ani1[100] = {
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
};
Rgb ani2[100] = {
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
};
Rgb ani3[100] = {
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
};
Rgb ani4[100] = {
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0),
    (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0),
    (0, 255, 0), (0, 255, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 255, 0), (0, 255, 0), (0, 255, 0), (255, 255, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
    (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0), (0, 0, 0),
};
*/

void setable_kobra(singleKobra_in data) {
    /*################*/
    //show_image(ani1);
    statusBar.setColor(Rgb(255, 0, 0)); statusBar.at(A) = Rgb(0, 0, 255); statusBar.show();
    /*-----APPLES-----*/
    position apples[1024];
    area_points apples_allowedPositions = generate_areaPoints(data.apples_spawnArea);
    // Random apples generation
    for(int i = 0; i < data.applesAtOnce; i++) {
        apples[i] = apples_allowedPositions.positions[random(apples_allowedPositions.points_number - 1)];
        while(position_in(apples[i], apples, i).in)
            apples[i] = apples_allowedPositions.positions[random(apples_allowedPositions.points_number - 1)];
    }
    /*################*/
    //show_image(ani2);
    statusBar.at(A) = Rgb(0, 255, 0); statusBar.at(B) = Rgb(0, 0, 255); statusBar.show();
    /*------BODY------*/
    short int slowness = data.starting_slowness;
    position body[1024]; for(int i = 0; i < data.starting_lenght; i++) body[i] = data.starting_body[i];
    short int kobra_lenght = data.starting_lenght;
    short int direction = data.starting_direction; // 0 up | 1 left-up | 2 left | 3 left-down | 4 down | 5 right-down | 6 right | 7 right-up
    /*################*/
    //show_image(ani3);
    statusBar.at(B) = Rgb(0, 255, 0); statusBar.at(C) = Rgb(0, 0, 255); statusBar.show();
    /*--HELPING VARS--*/
    position nextHeadPosition;
    int eated_apple;
    bool noEnd = true;
    bool victory;
    position displaying_move;
    /*################*/
    //show_image(ani4);
    statusBar.at(C) = Rgb(0, 255, 0); statusBar.at(D) = Rgb(0, 0, 255); statusBar.show();
    delay(500);
    statusBar.setColor(Rgb(0, 0, 0)); statusBar.show();
    /*################*/
    // One cycle = time step
    while(noEnd) {
        // Buttons detection
        for(int i = 0; i < slowness; i++) {
            if(buttons.read(Up) && (!(direction == 4)) && data.allowed_keys[0]) direction = 0;
            if(buttons.read(LeftUp) && (!(direction == 5)) && data.allowed_keys[1]) direction = 1;
            if(buttons.read(Left) && (!(direction == 6)) && data.allowed_keys[2]) direction = 2;
            if(buttons.read(LeftDown) && (!(direction == 7)) && data.allowed_keys[3]) direction = 3;
            if(buttons.read(Down) && (!(direction == 0)) && data.allowed_keys[4]) direction = 4;
            if(buttons.read(RightDown) && (!(direction == 1)) && data.allowed_keys[5]) direction = 5;
            if(buttons.read(Right) && (!(direction == 2)) && data.allowed_keys[6]) direction = 6;
            if(buttons.read(RightUp) && (!(direction == 3)) && data.allowed_keys[7]) direction = 7;
            delay(10);
        }
        nextHeadPosition = goDirection(body[0], direction, data.periodic_area, data.area_width, data.area_height);
        // Eating detection
        if(position_in(nextHeadPosition, apples, data.applesAtOnce).in) {
            eated_apple = position_in(nextHeadPosition, apples, data.applesAtOnce).number;
            body[kobra_lenght] = position{0, 0};
            kobra_lenght++;
            slowness = slowness - data.score_acceleration;
            while(position_in(apples[eated_apple], body, kobra_lenght-1).in || position_in(apples[eated_apple], data.borders, int(data.used_borders)).in || (apples[eated_apple] == nextHeadPosition) || position_in(apples[eated_apple], apples, data.applesAtOnce).in)
                apples[eated_apple] = position{random(0, data.area_width - 1), random(0, data.area_height - 1)};
            if(data.scoreCounter_on) score_counter(kobra_lenght - 1);
        }
        // Impact and victory detection
        if(position_in(nextHeadPosition, body, kobra_lenght - 1).in || position_in(nextHeadPosition, data.borders, data.used_borders - 1).in) // When is the next position of snake's head body or border, end Kobra with lose
            {noEnd = false; victory = false;}
        else if((kobra_lenght - 1) == data.victory_score) // When is your score victory score, end with victory
            {noEnd = false; victory = true;}
        else // When there isn't action like that, shift all the cobra by 1
        {
            for(int i = kobra_lenght - 1; i > 0; i = i - 1)
                body[i] = body[i - 1];
            body[0] = nextHeadPosition; // body[0] is head
        }
        // Refreshing screen
        {
            display.clear();
            if((data.area_height < 11) && (data.area_width < 11)) { // When classic display (not moving camera)
                for(int i = 0; i < data.used_borders; i++) // Drawing borders
                    display.setColor(data.borders[i].x, data.borders[i].y, Rgb(255, 255, 255));
                for(int i = 0; i < data.applesAtOnce; i++) // Drawing apples
                    display.setColor(apples[i].x, apples[i].y, Rgb(255, 0, 0));
                for(int i = 1; i < kobra_lenght; i++) // Drawing kobra's body
                    display.setColor(body[i].x, body[i].y, Rgb(0, 255, 0));
                display.setColor(body[0].x, body[0].y, Rgb(0, 0, 255)); // Drawing kobra's head
            }
            else { // Moving camera
                if(body[0].x < 5) { // When close to left border
                    displaying_move.x = 0;
                }
                else if(body[0].x > (data.area_width - 6)) { // When close to right border
                    displaying_move.x = data.area_width - 10;
                }
                else { // When not close to one of this borders
                    displaying_move.x = body[0].x - 4;
                }
                if(body[0].y < 5) { //When close to top border
                    displaying_move.y = 0;
                }
                else if(body[0].y > (data.area_height - 6)) { // When close to down border
                    displaying_move.y = data.area_height - 4;
                }
                else {
                    displaying_move.y = body[0].y - 4;
                }
                for(int i = 0; i < data.used_borders; i++) // Drawing borders
                    display.setColor(data.borders[i].x + displaying_move.x, data.borders[i].y + displaying_move.y, Rgb(255, 255, 255));
                for(int i = 0; i < data.applesAtOnce; i++) // Drawing apples
                    display.setColor(apples[i].x + displaying_move.x, apples[i].y + displaying_move.y, Rgb(255, 0, 0));
                for(int i = 1; i < kobra_lenght; i++) // Drawing kobra's body
                    display.setColor(body[i].x + displaying_move.x, body[i].y + displaying_move.y, Rgb(0, 255, 0));
                display.setColor(body[0].x, body[0].y, Rgb(0, 0, 255)); // Drawing kobra's head
            }
            display.show();
        }
    }
    if(victory) {
        victory_screen();
        buzzer.on(); delay(250); buzzer.off(); delay(250); buzzer.on(); delay(500); buzzer.off();
    }
    else {
        buzzer.on();
        for(int i = 0; i < 10; i++) {
            delay(100);
            reverse_display();
        }
        delay(100);
        buzzer.off();
    }
    display.clear(); 
    display.show();
}
