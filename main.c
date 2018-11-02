#include <stdio.h>
#include <stdlib.h>
#define CLEAR_BUFFER while(getchar() != '\n')

int main(void)
{
  printf("Choisissez une taille de grile : \n");
  int a,b,boucle1,boucle2,j;
  int i = 1000;
  int chainlength;
  int num = 1;
  short success = 0;
  printf("longueur : ");
  scanf("%d",&a);
  printf("largeur : ");
  scanf("%d",&b);
  int max = a*b;
  while(i >= max)
    i /=10;
  for( boucle1 = 1; boucle1 <= a;boucle1++){
    for(boucle2 = 1;boucle2 <= b;boucle2++){
      printf("[");
      j = i;
      while(num < j){
	j /= 10;
	printf("0");
      }
      printf("%d] ",num);
      num++;
    }
    printf("\n");
  }
  CLEAR_BUFFER;
	 while(success == 0){
	   chainlength = 0;
	   char actionchaine[5], casechaine[4] ;
	   printf("Choisissez une action ('undo', 'redo', 'open' or 'flag) : ");
	   fgets(actionchaine,5,stdin);
	   if( strcmp(actionchaine, "undo") != 0 && strcmp(actionchaine, "redo") != 0 && strcmp(actionchaine, "open") != 0 && strcmp(actionchaine, "flag") != 0 ){
	   	printf("Vous ne pouvez utiliser que les commandes undo, redo, open ou flag\n");
		CLEAR_BUFFER;
		continue;
	   }
	   while(actionchaine[chainlength] != 0)
	     chainlength++;
	   if (chainlength > 0 && actionchaine[chainlength-1] != '\n')
	       CLEAR_BUFFER;
	   //UNDO
	   if(strcmp(actionchaine, "undo") == 0){
	   	printf("this is an undo");
		continue;
	   }
	   //REDO
	   if(strcmp(actionchaine, "redo") == 0){
	   	printf("this is a redo");
		continue;
	   }
	   //OPEN
	   if(strcmp(actionchaine,"open") == 0){
	   printf("Choisissez une case, ou entrez un non-digit pour revenir en arrière : ");
	   fgets(casechaine,4,stdin);
		continue;
	   }
	   //FLAG
	   if(strcmp(actionchaine,"flag") == 0){
	   	printf("this is an flag");
		continue;
	   }
	 }
  return EXIT_SUCCESS;
}