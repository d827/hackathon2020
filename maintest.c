#include <stdio.h>

int gameState;

int main(){
  int i = 0;
  FILE *filep;
  char persistence[4][1000];
  filep = fopen("persistence.txt", "r");
  if(filep == NULL){
    gameState = 4;
  }
  while((fgets(persistence[i], 1000, filep)) != NULL){
    printf("%s", persistence[i]);
    i++;
  }
  fclose(filep);
}
