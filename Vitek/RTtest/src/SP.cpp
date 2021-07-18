#include "SP.hpp"

   bool blocky [10][10];
   bool padajici [10][10];
   int body = 0;
   int Hx = 4;
   int Hy = 9;
   int padajiciLimit [10];
   int AirFrames = 0;
   bool jumpAvalible = true;
   bool ded = false;

void FallFrame (){
    for(int x = 0;x<10;x++){
        for(int y = 9;y>=0;y--){
            if(padajici[x][y]){
                if(Hx == x && Hy == y+1){
                    /*ded*/
                    ded = true;
                }
                if(y == 8){
                     padajici[x][8] = false;
                    blocky[x][9] = true;
                    padajiciLimit[x] --;
                    continue;
                }
                if(blocky[x][y+2]){
                    padajici[x][y] = false;
                    blocky[x][y+1] = true;
                    padajiciLimit[x] --;
                    continue;
                }

                     padajici[x][y] = false;
                    padajici[x][y+1] = true;
                
            }
        }
    }
}

void playerFall(){
    if(Hy == 9){
        AirFrames = 0;
        jumpAvalible = true;
        return;
    }
    if(blocky[Hx][Hy+1] == false && AirFrames >= 1){
        Hy++;
        return;
    }
    if(blocky[Hx][Hy+1]){
        AirFrames = 0;
        jumpAvalible = true;
    }
    else{
        AirFrames++;
    }
}

void PointCheck(){
    while(true){
        for(int i = 0;i<10;i++){
            if(blocky[i][9] == false){
                return;
            }
        }
        body ++;
        for(int x = 0;x<10;x++){
             for(int y = 9;y>=0;y--){
                if(y == 0){
                    blocky[x][0] = false;
                }
                else{
                    blocky[x][y] = blocky[x][y-1];
                }
             }
        }
        FallFrame();
    }
}

void Spawn (){
    int pocet = random(1,(body+4)*0.5);
    for(int i = 0;i<pocet;i++){
        int misto = random(0,10);
        for(int df = 0;df<10;df++)
        {
            if(blocky[misto][8] == false && padajiciLimit[misto]<4){
                break;
            }
            if(misto == 9){
                misto = -1;
            }
            misto++;
            if(df == 10){
                return;
            }
        }
        padajici[misto][0] = true;
        padajiciLimit[misto]++;
    }
}

void SurvTetris(){

buttons.onPress([]() {
        if(blocky[Hx-1][Hy] == false){
            Hx--;
        }
    }, Left);

     buttons.onPress([]() {
        if(blocky[Hx+1][Hy] == false){
            Hx++;
        }
    }, Right);

     buttons.onPress([]() {
        if(jumpAvalible){
            Hy--;
            jumpAvalible = false;
        }
    }, Up);

    while(true){
        display.clear();

        for(int x = 0;x<10;x++){
        for(int y = 0;y<10;y++){
            if(blocky[x][y]){
                display.setColor(x,y,Rgb(0,0,255));
            }
             if(padajici[x][y]){
                display.setColor(x,y,Rgb(255,0,0));
            }
        }
        }
        display.setColor(Hx,Hy,Rgb(0,255,0));
        display.show(30);
        delay(1000);
        PointCheck();
        FallFrame();
        playerFall();
        Spawn();
        if(ded){
            display.clear();
            display.show();
            return;
        }

    }
    

    
}