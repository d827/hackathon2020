#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

//Global Variables
int gameState = 0;
char persistence[4][1000];
int totalScore = 0;
int mathScore = 0;
int typeScore = 0;
int profScore = 0;
int readingScore = 0;
int imageScore = 0;
int audioScore = 0;

// Declaration of Functions
void setGameState();
int basicMath();
int readingComp();
int profileQ();
int typingChallenge();
void firstTime();


int main(){
  int i = 0;
  FILE *filep;
  //char persistence[4][1000];
  filep = fopen("persistence6.txt", "r");
  if(filep == NULL){
    firstTime();
  }
  while((fgets(persistence[i], 1000, filep)) != NULL){
    i++;
  }
  fclose(filep);

  if(persistence[3][0] == '1') setGameState(1);

  while(gameState == 0){
    firstTime();
  }
  while(gameState == 1){
    printf("This is the menu. ");
    int choice;
    printf("Want to start? Press 1 to continue. Press any other key to exit.");
    scanf("%d", &choice);
    if(choice == 1) setGameState(2);
    else{
      setGameState(4);
    }

  }
  while(gameState == 2){
    for(int i = 0; i < 3; i++){
      int result1 = basicMath();
      if(result1 == 1) mathScore += 1;
    }
    totalScore += mathScore;
    int result2 = typingChallenge();
    if(result2 == 1) typeScore += 1;
    totalScore += typeScore;
    int result4 = profileQ();
    if(result4 == 1) profScore += 1;
    totalScore += profScore;
    int result3 = readingComp();
    if(result3 == 1) readingScore += 1;
    totalScore += readingScore;
    setGameState(3);
  }
  while(gameState == 3){
    printf("\nTOTAL SCORE: %d out of 9 possible points\n", totalScore);
    printf("\nPercentage: %f%\n", (totalScore/9.0)*100);
    printf("--------Score Breakdown--------\n");
    printf("Math Score: %d\n", mathScore);
    printf("Typing Score: %d\n", typeScore);
    printf("Profiling score: %d\n", profScore);
    printf("Reading Score: %d\n", readingScore);
    if(totalScore==9){
      printf("Status:Basically Sober\n");
      printf("--------Advice--------\n");
      printf("Do not Operate Vechicles even though you are 'Sober'.\n");
      printf("Continue drinking if wanted.\n");
      printf("Maybe help out some friends that inebriated.\n");
      printf("Get CRUNK'd next time.\n");
      setGameState(4);
    }
    if(totalScore<9 && totalScore>=6){
      printf("Status:Tipsy\n");
      printf("--------Advice--------\n");
      printf("Do not Operate Vechicles when you are not Sober.\n");
      printf("Continue drinking if wanted, but pace yourself.\n");
      printf("Maybe help out some friends that is more inebriated than you.\n");
      printf("Get more CRUNK next time.\n");
      setGameState(4);
    }
    if(totalScore<6 && totalScore<=4){
      printf("Status:Drunk\n");
      printf("--------Advice--------\n");
      printf("Do not Operate Vechicles under the influence.\n");
      printf("Try to lay off the drinks and start hydrating.\n");
      printf("Maybe get help to find your way home or grab an uber.\n");
      printf("You are near a good level of drinking.\n");
      printf("Don't embarass yourself or hit anyone.");
      setGameState(4);
    }
    if(totalScore<4 && totalScore>0){
      printf("Status:Approaching Unbeknownst Levels Intoxication\n");
      printf("--------Advice--------\n");
      printf("Do not drinking besides water and relax.\n");
      printf("Maybe don't drink for the rest of the week.\n");
      printf("Get help from someone or some friends to detox.\n");
      printf("Drink some gatorate for that hangover chief.\n");
      setGameState(4);
    }
    if(totalScore==0){
      printf("Status:How?\n");
      printf("--------Advice--------\n");
      printf("Do not anything. Not even your legs.\n");
      printf("Wait how are you even taking this test?\n");
      printf("Hold up, how did you make it to the scoring screen?\n");
      printf("Kinda impressed, but next time do not get this CRUNK'd.\n");
      setGameState(4);
    }
    break;
  }
  while(gameState == 4){
    printf("\nExiting...\n");
    break;
  }
}

void firstTime(){
  char name[20], animal[30], bday[9];
  char initializedGameState[2];
  initializedGameState[0] = '1';
  initializedGameState[1] = '\0';
  printf("Hello and welcome to Detox.me! Please complete this quick first time setup.\n");
  printf("Please enter your first name:\n");
  scanf("%s", &name);
  printf("\nPlease enter your birthdate (formatted MMDDYYYY):\n");
  scanf("%s", &bday);
  printf("\nHello %s, please choose a favorite animal:\n", name);
  scanf("%s", &animal);
  printf("\n");

  FILE *fp;
  fp = fopen("persistence6.txt", "w");
  if(fp == NULL) printf("persistence6.txt has failed to open.");
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
  if(n == 3) gameState = 3; //Score Breakdown
  if(n == 4) gameState = 4; //Exit
}

int profileQ(){
  srand(time(0));
  char ans[10];
  int v1 = rand() % 3;
  if(v1 == 0){
    printf("Do you remember your first name?: \n");
    scanf(" %s\n", &ans);
    if((strcmp(ans, persistence[0])) == 0){
      printf("Correct!\n");
      return 1;
    }
    printf(" %s\n", persistence[0]);
    printf("Incorrect!\n");
    return 0;
  }
  if(v1 == 1){
    printf("Do you remember your birthday? (Formatted MMDDYYYY): \n");
    scanf(" %s\n", &ans);
    if((strcmp(ans, persistence[1])) == 0) {
      printf("Correct!\n");
      return 1;
    }
    printf("%s\n", persistence[1]);
    printf("Incorrect!\n");
    return 0;
  }
  if(v1 == 2){
    printf("Do you remember your favorite animal?: \n");
    scanf(" %s\n", &ans);
    if((strcmp(ans, persistence[2])) == 0){
      printf("Correct!\n");
      return 1;
    }
    printf("%s\n", persistence[2]);
    printf("Incorrect!\n");
    return 0;
  }
}

int basicMath(){
  int score;
  srand(time(0));
  int v1 = rand() % 50; //First Variable
  int v2 = rand() % 50; //Second Variable
  int eq = v1 + v2; //Eq value
  printf("What is the value of %d + %d? :> ", v1, v2);//Print Statement asking for values
  scanf("%d",&eq);   //Equation input
  if(eq == v1 + v2){
    printf("\nCorrect!\n");
    score = 1;
    return score;
  }
  else{
    printf("\nWrong!\n");
    score = 0;
    return score;
  }
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
  }
  fclose (infile);


  printf("\n---------");
  if (score == 3){
    printf("\nYou Passed!\n");
    return 1;
  }
  else{
    printf("\nYou Failed!\n");
    return 0;
  }
}

int readingComp() {

  srand(time(NULL));

  int n,c,d,q;
  char u_name[20],u_dog[20],u_color[20];
  int result;
  int choice;
  int score = 0;
  int fail = 0;


  while(score < 2 && fail < 3){

    n = rand() % 3;
    c = rand() % 3;
    d = rand() % 3;
    q = rand() % 3;

    char color[3][20] = {"red","blue","yellow"};
    char name[3][20] = {"Fred","John", "Billy"};
    char dog[3][20] = {"Max","Spot","Rex"};

    printf("\n\n%s was wearing a %s shirt and walking his dog %s down the street.\n",name[n],color[c],dog[d]);

    if (q == 0){
      printf("\nWhat was the man's name?\n");
      scanf("%s",u_name);
      result = strcmp(u_name,name[n]);
    }
    else if (q == 1){
      printf("\nWhat was the dog's name?\n");
      scanf("%s",u_dog);
      result = strcmp(u_dog,dog[d]);
    }
    else{
      printf("\nWhat color was the man's shirt?\n");
      scanf("%s",u_color);
      result = strcmp(u_color,color[c]);
    }

    if (result == 0){
        printf("\nCorrect!\n");
        score = score + 1;
    }
    else  {
      printf("\nWrong!\n");
      fail = fail + 1;

    }
  }
    printf("\n---------");
  if (score == 2){
    printf("\nYou Passed!\n");
    return 1;
  }
  else{
    printf("\nYou Failed!\n");
    return 0;
  }
  return 0;
}
