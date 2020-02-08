#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <conio.h>

#define CRED "\x1B[31m"
#define CGRN "\x1B[32m"
#define CYEL "\x1B[33m"
#define CBLU "\x1B[34m"
#define ANSI_RED "\x1b[31m"

//Global Variables
int gameState;

// Declaration of Functions
int setGameState(); //Complete For Now
int BasicMath(); //Completed For Now
int ColorRead(); //Completed For Now
void AudioQ(); //Waiting for GUI
void ImageQ(); //Waiting for GUI
void ReadingComp(); //Waiting for GUI
char ProfileQ(); //In progress by Dorian
int typing_challenge(); //In Progress by Mike





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
  printf("%s" "blue", ANSI_BLUE);
  char name[20], sq1c[1], sq1[30], bday[8];
  char initializedGameState[1];
  initializedGameState[0] = '1';
  printf("Hello and welcome to Detox.me! Please complete this quick first time setup.\n");
  printf("Please enter your name:\n");
  scanf("%s", &name);
  printf("\nPlease enter your birthdate (formatted MMDDYYYY):\n");
  scanf("%s", &bday);
  printf("\nHello %s, please choose a security question:\n", name);
  scanf("%s", &sq1);
  printf("\n");
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
    fputs(initializedGameState, fp);
    fputs("\n", fp);
    fclose(fp);
    printf("First time setup complete. Initializing Detox.me...\n");
    setGameState(1);
  }
}

void play(){

}

void setGameState(int n){
  if(n == 0) gameState = 0; //First time startup
  if(n == 1) gameState = 1; //Menu
  if(n == 2) gameState = 2; //Play
  if(n == 3) gameState = 3; //Exit
}

int BasicMath(int v1, int v2, int eq, int M_Score){
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
    return M_Score;
  }                //Value Checking
}

int typing_challenge(){


}

int ColorRead(){
//Initializing Values 0-3 for array values
  int score;
  srand(time(0));
  char colors[4] = {CRED,CGRN,CYEL,CBLU}; //Array storing labels of different color strings
  char colorWords[4] = {"Red","Green","Yellow","Blue"}
  int color = rand() % 4; //random values chosen for array
  int colorWord = rand() % 4; //Value for ColorWord Array
  // int color2 = rand() % 4;
  // int color3 = rand() % 4;
  // int color4 = rand() % 4;
//Declaring color variables
  colors[0] = CRED;
  colors[1] = CGRN;
  colors[2] = CBLU;
  colors[3] = CYEL;

/* Print and Scan statements for retrieving Inputs */

//First Test
  char ans[6];
  printf("What does this word say -> %s", colors[color]);
  printf("%s ?", colorWords[colorWord]);
  printf(colors[2]);

  scanf("%s", &ans);
  if(strcmp(ans, colorWords[colorWord]) == 0){
    score += 1;
  }
  else{
    score += 0;
  }

//Second Test
//   char Second;
//   printf("What is the color on this word -> %sGreen?\n",colors[color2]);
//   scanf("%s",&Second);
//   if(Second == colors[color2]){
//     score += 1;
//   }
//   else{
//     score += 0;
//   }
//
// //Third Test
//   char Third;
//   printf("What is the color on this word -> %sBlue?\n",colors[color3]);
//   scanf("%s",&Third);
//   if(Third == colors[color3]){
//     score += 1;
//   }
//   else{
//     score += 0;
//   }
//
// //Fourth Test
//   char Fourth;
//   printf("What is the color on this word -> %sYellow?\n",)colors[color4];
//   scanf("%s",&Fourth);
//   if(Fourth == color[color4]){
//     score += 1;
//   }
//   else{
//     score += 0;
//   }
//   return score;
}

/*typedef struct Color{
  uint8_t R;
  uint8_t G;
  uint8_t B;
}colortype;

colortype red;
red.R = 255U;
red.G = 0U;
red.B = 0U;

colortype green;
green.R = 0U;
green.G = 255U;
green.B = 0U;

colortype blue;
blue.R = 0U;
blue.G = 0U;
blue.B = 255U;

colortype yellow;
yellow.R = 244U;
yellow.G = 232U;
yellow.B = 104U;
*/
