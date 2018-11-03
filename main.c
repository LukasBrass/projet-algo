#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.c"
#define CLEAR_BUFFER while (getchar() != '\n')

  int main(void) {
    printf("Choisissez une taille de grile : \n");
    int a, b, maxlongueur, maxlargeur, i, j, chainlength;
    short success = 0;
    printf("longueur : ");
    scanf("%d", & a);
    printf("largeur : ");
    scanf("%d", & b);
    maxlongueur = a;
    maxlargeur = b;
	maillon* liste = initiate(maxlongueur,maxlargeur);
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
        printf("this is an undo");
        continue;
      }
      //REDO
      if (strcmp(actionchaine, "redo") == 0) {
        printf("this is a redo");
        continue;
      }
      //OPEN
      if (strcmp(actionchaine, "open") == 0) {
        printf("Choisissez une longueur, ou entrez 0 pour retourner en arriere : ");
        scanf("%d", & a);
        if (a <= 0) {
          CLEAR_BUFFER;
          continue;
        }
        if (a > maxlongueur) {
          printf("La longueur choisie est au dessus de la limite, retour en arrière\n");
          CLEAR_BUFFER;
          continue;
        }
        printf("Choisissez une largeur : ");
        scanf("%d", & b);
        if (b <= 0) {
          CLEAR_BUFFER;
          continue;
        }
        if (b > maxlargeur) {
          printf("La largeur choisie est au dessus de la limite, retour en arrière\n");
          CLEAR_BUFFER;
          continue;
        }
		maillon* maillon = find(liste,a,b);
		maillon->isOpened = 1;
		if(maillon->isMine == 1){
			success = -1;
			break;
		}
      }
      //FLAG
      if (strcmp(actionchaine, "flag") == 0) {
        printf("this is an flag");
        continue;
      }
	  success = winChecker(liste,maxlongueur,maxlargeur);
    }
    if (success == 1)
      printf("Félicitations, vous avez gagné !\n");
    else
      printf("Aie, vous avez perdu :( \n");
    return EXIT_SUCCESS;
  }