#include <stdio.h>
#include <stdlib.h>

int gameState;

void setGameState(int n){
  if(n == 0) gameState = 0; //First time startup
  if(n == 1) gameState = 1; //Menu
  if(n == 2) gameState = 2; //Play
  if(n == 3) gameState = 3; //Exit
}

void firstTime(){
  char name[10], sq1[30], sq2[30], bday[10];
  char initializedGameState[1];
  initializedGameState[0] = '1';
  printf("Hello and welcome to Detox.me! Please complete this quick first time setup.\n");
  printf("Please enter your name: \n");
  scanf("%s\n", &name);
  printf("Please enter your birthdate (formatted MMDDYYYY): \n");
  scanf("%s\n", &bday);
  printf("Hello %s, please choose a security question: \n", name);
  scanf("%s\n", &sq1);
  printf("Choose a second security question: \n");
  scanf("%s\n", &sq2);
  FILE *fp;
  fp = fopen("persistence.txt", "w");
  if(fp == NULL) printf("persistence.txt has failed to open.");
  else{
    fputs(name, fp);
    fputs("\n", fp);
    fputs(bday, fp);
    fputs("\n", fp);
    fputs(sq1, fp);
    fputs("\n", fp);
    fputs(sq2, fp);
    fputs("\n", fp);
    fputs(initializedGameState, fp);
    fclose(fp);
    printf("First time setup complete. Initializing Detox.me");
    setGameState(1);
  }
}



int main(){
  printf("%sred\n", "\x1B[32m");
  firstTime();
}
