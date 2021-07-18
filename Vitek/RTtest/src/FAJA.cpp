#include "FAJA.HPP"
#include "Logic.hpp"

int particly[1000][3];
int RANstrany = 10;
int RANteplota = 25;



void newparticle(int x,int y,int t){
   for(int i = 0;i<1000;i++){
      if(particly[i][2] == -1){
         particly[i][0] = x;
         particly[i][1] = y;
         particly[i][2] = t;
         break;
      }
   }
}

void delparticle(int num){
   for(int i = num;i<1000;i++){
      if(particly[i][2] == -1){
         break;
      }
      particly[i][0] = particly[i+1][0];
      particly[i][1] = particly[i+1][1];
      particly[i][2] = particly[i+1][2];
   }
}

void fireA (){

   display.clear();

   if(!(buttons.read(Enter))){
       for(int x = 0;x<20;x++){
      newparticle(x%10,11,5);
   }
   }
  

   for(int i = 0;i<1000;i++){
       if(particly[i][2] == -1){
         break;
      }
      particly[i][1]--;
      
      if(random(1,100)<= RANstrany){
         if(random(1,2) == 1){
            particly[i][0]++;
         }
         else{
            particly[i][0]--;
         }
      }
      
      
      if(random(1,100)> RANteplota){
         particly[i][2]--;
      }

      if(particly[i][2] == 0||particly[i][0] == -1||particly[i][0] == 10||particly[i][1] == -1){
         delparticle(i);
      }
      
      display.setColor(particly[i][0],particly[i][1],Rgb(150,(15*particly[i][2])+10,0));
   }
   display.setColor(0,0,Rgb(0,0,0));
   display.show();
   delay(100);

}

void fire(){
   for(int i = 0;i<1000;i++){
      particly[i][2] = -1;
   }
   while(true){
      fireA();
   }

}
