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
}
