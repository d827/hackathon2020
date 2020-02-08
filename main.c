#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Color{
  int WordColor[100];
  char Word[100;
}



// Declaration of Functions
int GameState();
int BasicMath(int v1, int v2, int eq, int score);
int ColorRead();
void AudioQ();
void ImageQ();
void ReadingComp();
char ProfileQ();
int typing_challenge();





int main(int argc, char **argv){
  // while(gameState == 0){
  //
  // }
  // while(gameState == 1){
  //
  // }
  // while(gameState == 2){
  //
  // }
  // while(gameState == 3){
  //
  // }
}

void firstTime(){
  char name[20], sq1[30], sq2[30];
  int bday[10];
  int initializedGameState = 1;
  printf("Hello and welcome to Detox.me! Please complete this quick first time setup.\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("\nHello %s, please choose a security question: ", name);
  scanf("%s", sq1);
  printf("\nChoose a second security question: ");
  scanf("%s", sq2);
  FILE *fp;
  fp = fopen("persistence.txt", "w");
  if(fp == NULL) printf("persistence.txt has failed to open.");
  else{
    fputs(name, fp);
    fputs(bday, fp);
    fputs(sq1, fp);
    fputs(sq2, fp);
    fputs(initializedGameState, fp);
    fclose(fp);
    printf("First time setup complete. Initializing Detox.me");
    setGameState(1);
  }
}

void setGameState(int n){
  if(n == 0) gameState = 0; //First time startup
  if(n == 1) gameState = 1; //Menu
  if(n == 2) gameState = 2; //Play
  if(n == 3) gameState = 3; //Exit
}

int BasicMath(int v1, int v2, int eq, int score){
  srand(time(0));
  v1 = rand() % 100; //First Variable
  v2 = rand() % 100; //Second Variable
  eq = v1 + v2; //Eq value
  print("What is the value of %d + %d? :> ",v1,v2);//Print Statement asking for values
  scanf("%d",&eq);   //Equation input
  if(eq==v1+v2){
    score = 1;
    return score;
  }
  else{
    score = 0;
    return score;
  }                //Value Checking
}

int typing_challenge(){


}

int ColorRead(){
  struct Colors Word1;
  struct Colors Word2;
  struct Colors Word3;
  struct Colors Word4;
}
