#include "MSplugin.hpp"
#include "Logic.hpp"

int pole [10][10];
bool MSgenRIP;
int MSpocetmin = 15;
bool zakryte[10][10];

//generace mapy
void MSgenerace(){
    // smazání toho, aby nenastal problém
   MSgenRIP = false;
   for(int i = 0;i<10;i++){
      for(int j = 0;j<10;j++){
         pole[i][j] = 0;
      }
   }

   //rozházení min
   for(int i = 0;i<MSpocetmin;i++){
      while (true)
      {
         int minaX = random(0,10);
         int minaY = random(0,10);

         if(pole[minaX][minaY] == 6 ){
            continue;
         }
         else
         {
            pole[minaX][minaY] = 6;
            break;
         }

      }
    // doplnění čísel
   }
   for(int i = 0;i<10;i++){
      for(int j = 0;j<10;j++){
         if(pole[i][j] == 6){
            continue;
         }
         int okolni = 0;
         for(int a = -1;a<2;a++){
            for(int b = -1;b<2;b++){
                if(i == 0&& a == -1) a = 0;
                if(j == 0&&  b== -1) b = 0;
                if(i == 9 && a == 1) continue;
                if(j == 9 && b == 1) continue;

               if (pole[i+a][j+b] == 6)
               {
                  okolni++;
               }
            }
         }

         //jsem líný dodělat 6
         if(okolni>5){
            MSgenRIP = true;
         }
         pole[i][j] = okolni;
      }
   }
}

//boom AKA prohra
void BOOM (int x, int y){

    //jen malá animace
   for(int i = 0;i<20;i++){
      display.clear();
      display.drawCircle(x,y,i,Rgb(255,255,0));
      display.drawCircle(x,y,i+1,Rgb(255,0,0));
      display.show();
      delay(100);
   }
   display.clear();
}

// výhra
void WIN (){

    //jen animace nic víc
   for(int a = 0;a<3;a++){
       display.fill(Rgb(100,100,0));

        for(int i = 0;i<10;i++){
         for(int j = 0;j<10;j++){
            if(zakryte[i][j] == true){
               display.setColor(i,j,Rgb(0,0,0));
            }
         }
      }
      display.show();
      delay(500);
      display.clear();
      display.show();
      delay(500);
   }
}


//hlavní program tohle callujte
void minesweeper(){
   int VyberX = 4;
   int VyberY = 4;
   bool waiter = true;
   int odkryte = 0;
   
  //nastavení obtížnosti
   int obtiznost = 1;
         display.fill(Rgb(255,255,0));
   while(true){
      if(buttons.read(RightDown)){
         MSpocetmin = 10+(obtiznost*5);
         break;
      }
      if(buttons.read(Left)){
         obtiznost = 0;
         display.fill(Rgb(0,255,0));
      }
       if(buttons.read(Enter)){
         obtiznost = 1;
         display.fill(Rgb(255,255,0));
      }
       if(buttons.read(Right)){
         obtiznost = 2;
         display.fill(Rgb(255,0,0));
      }
        // šipka ._.
      display.setColor(9,9,Rgb(0,0,255));
      display.setColor(8,9,Rgb(0,0,255));
      display.setColor(7,9,Rgb(0,0,255));
      display.setColor(6,9,Rgb(0,0,255));
      display.setColor(9,8,Rgb(0,0,255));
      display.setColor(9,7,Rgb(0,0,255));
      display.setColor(9,6,Rgb(0,0,255));
      display.setColor(8,8,Rgb(0,0,255));
      display.setColor(7,7,Rgb(0,0,255));
      display.setColor(6,6,Rgb(0,0,255));

      display.show(30);

   }

    //generace mapy
    while(true){
      MSgenerace();
      if(MSgenRIP == false){
         break;
      }
   }

   
    //fillnutí překrývacího layeru
   for(int i = 0;i<10;i++){
      for(int j = 0;j<10;j++){
         zakryte[i][j] = true;
      }
   }

   while (true)
   {

      //jen pohyb s ukazovátkem (waiter je aby se oddělily inputy)
      if (buttons.read(Left) && VyberX != 0 && waiter == true)
      {
         waiter = false;
         VyberX--;
      }
      if (buttons.read(Right) && VyberX != 9 && waiter == true)
      {
         waiter = false;
         VyberX++;
      }
      if (buttons.read(Up) && VyberY != 0 && waiter == true)
      {
         waiter = false;
         VyberY--;
      }
      if (buttons.read(Down) && VyberY != 9 && waiter == true)
      {
         waiter = false;
         VyberY++;
      }
      if (!(buttons.read(Down) || buttons.read(Up) || buttons.read(Left) || buttons.read(Right)||buttons.read(LeftUp)))
      {
         buzzer.off();
         waiter = true;
      }
      else{
         buzzer.on();
      }

        //odkrývání
      if(buttons.read(Enter)){
         if(pole[VyberX][VyberY] == 6){
            BOOM(VyberX,VyberY);
            break;
         }
          if(zakryte[VyberX][VyberY] == true){
            odkryte++;
         }
         zakryte[VyberX][VyberY] = false;

         if(odkryte == 100-MSpocetmin){
            WIN();
         }
      }


      //displej
      display.clear();
      //pozadi AKA hraci pole
       for(int i = 0;i<10;i++){
         for(int j = 0;j<10;j++){
           switch (pole[i][j])
           {
               case 0:
              display.setColor(i,j,Rgb(100,100,100));
              break;
           case 1:
              display.setColor(i,j,Rgb(0,0,255));
              break;

            case 2:
               display.setColor(i,j,Rgb(0,255,0));
               break;
               case 3:
               display.setColor(i,j,Rgb(255,0,0));
               break;
               case 4:
               display.setColor(i,j,Rgb(255,0,255));
               break;
               case 5:
               display.setColor(i,j,Rgb(255,255,0));
               break;
               case 6:
               display.setColor(i,j,Rgb(0,0,0));
               break;
           }
         }
      }
      //neodhalene policka
      for(int i = 0;i<10;i++){
         for(int j = 0;j<10;j++){
            if(zakryte[i][j] == true){
               display.setColor(i,j,Rgb(0,0,0));
            }
         }
      }
      //blikání ukazovátka
      if ((millis() / 1000) % 2 == 0)
      {
         display.setColor(VyberX, VyberY, Rgb(0, 255, 255));
      }
      display.show(30);

      //break pokud chceš leavnout
      if(buttons.read(LeftDown)){
         display.clear();
         display.show();
         break;
      }
   }

   //pro dobrou míru
   display.clear();
   display.show();
}