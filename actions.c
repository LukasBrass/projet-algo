#include <stdio.h>
#include <stdlib.h>
#define CLEAR_BUFFER while (getchar() != '\n')

//OPEN = 2
//FLAG = 3
int openAndFlag(maillon* liste, int type, int maxLongueur, int maxLargeur)
{
	int a,b;
	printf("Choisissez une longueur, ou entrez 0 pour retourner en arriere : ");
        scanf("%d", & a);
        if (a <= 0)
          return 0;
        if (a > maxLongueur) {
          printf("La longueur choisie est au dessus de la limite, retour en arrière\n");
          return 0;
        }
        printf("Choisissez une largeur : ");
        scanf("%d", & b);
        if (b <= 0)
          return 0;
        if (b > maxLargeur) {
          printf("La largeur choisie est au dessus de la limite, retour en arrière\n");
          return 0;
        }
		if(type == 2)
			return open(liste,a,b);
		else
			return flag(liste,a,b);
}

int open(maillon* liste, int a, int b)
{
	maillon* maillon = find(liste,a,b);
	maillon->isOpened = 1;
	if(maillon->isMine == 1){
		return -1;
	}
	return 0;
}

int flag(maillon* liste, int a, int b)
{
	maillon* maillon = find(liste,a,b);
	maillon->isFlag = 1;
	return 0;
}

int undo(maillon* oldMaillon)
{
	if(oldMaillon == NULL)
		return 0;
	oldMaillon->droite->gauche != NULL ? oldMaillon : NULL;
	oldMaillon->gauche->droite != NULL ? oldMaillon : NULL;
	oldMaillon->bas->haut != NULL ? oldMaillon : NULL;
	oldMaillon->haut->bas != NULL ? oldMaillon : NULL;
	return 0;
}