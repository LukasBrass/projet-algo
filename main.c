#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.c"
#include "actions.c"
#define CLEAR_BUFFER while (getchar() != '\n')

  int main(void) {
    int maxlongueur, maxlargeur, i, j, chainlength,type;
	short oldIsOpened,oldIsFlag;
    short success = 0;
	printf("Choisissez une taille de grille : \nlongueur : ");
    scanf("%d", & i);
    printf("largeur : ");
    scanf("%d", & j);
    maxlongueur = i;
    maxlargeur = j;
	maillon* liste = initiate(maxlongueur,maxlargeur);
	//Variables for undo redo
	maillon* oldmaillon;
    CLEAR_BUFFER;
    while (success == 0) {
	printf("   ");
		i = 1;
		while (i <= maxlongueur)
      		printf(" %d ", i++);
    		printf("\n");
    		for (i = 1; i <= maxlongueur; i++) {
      		printf(" %d ", i);
      		for (j = 1; j <= maxlargeur; j++){
				maillon* maillon = find(liste,i,j);
				if(maillon->isFlag == 1)
        				printf(" F ");
				else {
					if(maillon->isOpened == 0)
						printf(" x ");
					else {
						printf(" %d ",minesNumber(maillon));
						}
				}
			}
      		printf("\n");
	  	}
      chainlength = 0;
      char actionchaine[5];
      printf("Choisissez une action ('undo', 'redo', 'open' or 'flag) : ");
      fgets(actionchaine, 5, stdin);
      if (strcmp(actionchaine, "undo") != 0 && strcmp(actionchaine, "redo") != 0 && strcmp(actionchaine, "open") != 0 && strcmp(actionchaine, "flag") != 0) {
        printf("Vous ne pouvez utiliser que les commandes undo, redo, open ou flag\n");
        CLEAR_BUFFER;
        continue;
      }
      while (actionchaine[chainlength] != 0)
        chainlength++;
      if (chainlength > 0 && actionchaine[chainlength - 1] != '\n')
        CLEAR_BUFFER;
      //UNDO
      if (strcmp(actionchaine, "undo") == 0) {
	  if(!oldIsOpened || !oldIsFlag){
	  	printf("Pas d'anciens coups\n");
		continue;
	  }
	  	short tmpIsOpened = oldmaillon->isOpened;
		short tmpIsFlag = oldmaillon->isFlag;
		oldmaillon->isOpened = oldIsOpened;
		oldmaillon->isFlag = oldIsFlag;
		oldIsOpened = tmpIsOpened;
		oldIsFlag = tmpIsFlag;
        continue;
      }
      //REDO
      if (strcmp(actionchaine, "redo") == 0) {
        printf("this is a redo");
        continue;
      }
	  if(strcmp(actionchaine, "open") == 0) //OPEN
	 	type = 2;
	 if(strcmp(actionchaine, "flag") == 0) //FLAG
	 	type = 3;
	  success = openAndFlag(liste,type,maxlongueur,maxlargeur);
	  if(success != -1)
	  	success = winChecker(liste,maxlongueur,maxlargeur);
    }
    if (success == 1)
      printf("Félicitations, vous avez gagné !\n");
    else
      printf("Aie, vous avez perdu :( \n");
    return EXIT_SUCCESS;
  }