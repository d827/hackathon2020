#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

#define CRED "\x1B[31m"
#define CGRN "\x1B[32m"
#define CYEL "\x1B[33m"
#define CBLU "\x1B[34m"
#define ANSI_RED "\x1b[31m"

//Global Variables
int gameState;

// Declaration of Functions
void setGameState(); //Complete For Now
int basicMath(); //Completed For Now
int colorRead(); //Completed For Now
void audioQ(); //Waiting for GUI
void imageQ(); //Waiting for GUI
void readingComp(); //Waiting for GUI
char profileQ(); //In progress by Dorian
int typingChallenge(); //Completed for Now
void firstTime();





int main(int argc, char **argv){
  int totalScore = 0;
  int mathScore = 0;
  int typeScore = 0;
  int profScore = 0;
  int readingScore = 0;
  int imageScore = 0;
  int audioScore = 0;

  int i = 0;
  FILE *filep;
  char persistence[4][1000];
  filep = fopen("persistence.txt", "r");
  if(filep == NULL){
    gameState = 0;
  }
  while((fgets(persistence[i], 1000, filep)) != NULL){
    printf("%s", persistence[i]);
    i++;
  }
  fclose(filep);

  if(persistence[3][0] == '1') gameState == 1;

  while(gameState == 0){
    firstTime();
  }
  while(gameState == 1){

  }
  while(gameState == 2){
    for(int i = 0; i < 3; i++){
      int result = basicMath();
      if(result == 1) mathScore += 1;
    }
    totalScore += mathScore;
    for(int i = 0; i < 3; i++){
      int result = typingChallenge();
      if(result == 1) typeScore += 1;
    }
    totalScore += typeScore;
  }
  while(gameState == 3){

  }
  while(gameState == 4){

  }
}

void firstTime(){
  char name[20], animal[30], bday[9];
  char initializedGameState[2];
  initializedGameState[0] = '1';
  initializedGameState[1] = '\0';
  printf("Hello and welcome to Detox.me! Please complete this quick first time setup.\n");
  printf("Please enter your name:\n");
  scanf("%s", &name);
  printf("\nPlease enter your birthdate (formatted MMDDYYYY):\n");
  scanf("%s", &bday);
  printf("\nHello %s, please choose a favorite animal:\n", name);
  scanf("%s", &animal);
  printf("\n");

  FILE *fp;
  fp = fopen("persistence.txt", "w");
  if(fp == NULL) printf("persistence.txt has failed to open.");
  else{
    fputs(name, fp);
    fputs("\n", fp);
    fputs(bday, fp);
    fputs("\n", fp);
    fputs(animal, fp);
    fputs("\n", fp);
    fputs(initializedGameState, fp);
    fputs("\n", fp);
    fclose(fp);
    printf("First time setup complete. Initializing Detox.me...\n");
    setGameState(1);
  }
}

// void play(){
//
// }

void setGameState(int n){
  if(n == 0) gameState = 0; //First time startup
  if(n == 1) gameState = 1; //Menu
  if(n == 2) gameState = 2; //Play
  if(n == 3) gameState = 3; //Exit
  if(n == 4) gameState = 4; //Error screen
}

int basicMath(){
  int score;
  srand(time(0));
  int v1 = rand() % 100; //First Variable
  int v2 = rand() % 100; //Second Variable
  int eq = v1 + v2; //Eq value
  printf("What is the value of %d + %d? :> ",v1,v2);//Print Statement asking for values
  scanf("%d",&eq);   //Equation input
  if(eq==v1+v2){
    score = 1;
  }
  else{
    score = 0;
  }
  return score;
}

int typingChallenge(){

    srand(time(NULL));

    FILE *infile;
    infile = fopen("words.txt","r");

    char Lbuffer[133][1000];
    char user[1000];
    char n = '\n';

    int i = 0;
    int j = 0;

    int result;

    int score = 0;
    int fail = 0;

    while(fgets(Lbuffer[i],1000,infile) != NULL){

     i++;

    }

    while(score < 3 && fail < 3){

      j = rand() % 133;

      printf("\n---------");
      printf("\nPlease type the following word and press enter:\n\n%s\n",Lbuffer[j]);

      scanf("%s", user);
      strncat(user,&n,1);

      result = strcmp(Lbuffer[j],user);

      if (result == 0){
        printf("\nCorrect!\n");
        score = score + 1;
      }
      else  {
        printf("\nWrong!\n");
        fail = fail + 1;

      }
    fclose (infile);


    printf("\n---------");
    if (score == 3){
      printf("\nYou Passed!");
      return 1;
    }
    else{
      printf("\nYou Failed!");
      return 0;
    }
  }
}

// int colorRead(){
// //Initializing Values 0-3 for array values
//   int score;
//   srand(time(0));
//   char colors[4] = {CRED,CGRN,CYEL,CBLU}; //Array storing labels of different color strings
//   char colorWords[4] = {"Red","Green","Yellow","Blue"}
//   int color = rand() % 4; //random values chosen for array
//   int colorWord = rand() % 4; //Value for ColorWord Array
//   // int color2 = rand() % 4;
//   // int color3 = rand() % 4;
//   // int color4 = rand() % 4;
// //Declaring color variables
//   colors[0] = CRED;
//   colors[1] = CGRN;
//   colors[2] = CBLU;
//   colors[3] = CYEL;
//
// /* Print and Scan statements for retrieving Inputs */
//
// //First Test
//   char ans[6];
//   printf("What does this word say -> %s", colors[color]);
//   printf("%s ?", colorWords[colorWord]);
//   printf(colors[2]);
//
//   scanf("%s", &ans);
//   if(strcmp(ans, colorWords[colorWord]) == 0){
//     score += 1;
//   }
//   else{
//     score += 0;
//   }
//
// //Second Test
// //   char Second;
// //   printf("What is the color on this word -> %sGreen?\n",colors[color2]);
// //   scanf("%s",&Second);
// //   if(Second == colors[color2]){
// //     score += 1;
// //   }
// //   else{
// //     score += 0;
// //   }
// //
// // //Third Test
// //   char Third;
// //   printf("What is the color on this word -> %sBlue?\n",colors[color3]);
// //   scanf("%s",&Third);
// //   if(Third == colors[color3]){
// //     score += 1;
// //   }
// //   else{
// //     score += 0;
// //   }
// //
// // //Fourth Test
// //   char Fourth;
// //   printf("What is the color on this word -> %sYellow?\n",)colors[color4];
// //   scanf("%s",&Fourth);
// //   if(Fourth == color[color4]){
// //     score += 1;
// //   }
// //   else{
// //     score += 0;
// //   }
// //   return score;
// }
//
// /*typedef struct Color{
//   uint8_t R;
//   uint8_t G;
//   uint8_t B;
// }colortype;
//
// colortype red;
// red.R = 255U;
// red.G = 0U;
// red.B = 0U;
//
// colortype green;
// green.R = 0U;
// green.G = 255U;
// green.B = 0U;
//
// colortype blue;
// blue.R = 0U;
// blue.G = 0U;
// blue.B = 255U;
//
// colortype yellow;
// yellow.R = 244U;
// yellow.G = 232U;
// yellow.B = 104U;
// */
