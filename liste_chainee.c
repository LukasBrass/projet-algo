#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct maillon
{
    short isFlag;
	short isMine;
	short isOpened;
	short abscisse;
	short ordonnee;
	struct maillon* droite;
	struct maillon* gauche;
	struct maillon* haut;
	struct maillon* bas;
}maillon;

maillon* find(maillon* element, int abscisse, int ordonnee){
	while(element->abscisse < abscisse)
		element = element->droite;
	while(element->ordonnee < ordonnee)
		element = element->bas;
	return element;
}

void randomMines(maillon* liste, int longueur, int largeur)
{
	int nbmines = (longueur*largeur) / 10;
	int i = 0;
	int rand_x, rand_y;
	srand(time(NULL));
	while(i <= nbmines){
		rand_x = rand()%longueur + 1;
		rand_y = rand()%largeur + 1;
		maillon* maillon = find(liste,rand_x,rand_y);
		if(maillon->isMine == 1)
			continue;
		maillon->isMine = 1;
		i++;
	}
}

maillon* initiate(int longueur, int largeur)
{
	int i,j;
	maillon* elementgauche;
	maillon* elementhaut;
	maillon* first;
	maillon* element;
	for(i = 1; i <= largeur; i++){
		for(j=1; j <= longueur;j++){
			element = (maillon*)malloc(sizeof(maillon));
			element->abscisse = j;
			element->ordonnee = i;
			element->isFlag = 0;
			element->isOpened = 0;
			element->isMine = 0; //will change to isMine = function mine;
			element->droite = NULL;
			element->gauche = NULL;
			element->haut = NULL;
			element->bas = NULL;
			if(j > 1){
			elementgauche = find(first,j-1,i);
			element->gauche = elementgauche;
			elementgauche->droite = element;
			}
			if(i > 1){
			elementhaut = find(first,j,i-1);
			element->haut = elementhaut;
			elementhaut->bas = element;
			}
			if(i == 1 && j == 1){
				first = element;
			}
		}
	}
    if (first == NULL)
    {
        exit(EXIT_FAILURE);
    }
	randomMines(first, longueur, largeur);
    return first;
}

int winChecker(maillon* liste, int abscisse, int ordonnee)
{
	int i,j;
	for(i = 1; i <= abscisse;i++){
			for(j = 1; j <= ordonnee;j++){
					maillon* maillon = find(liste,i,j);
					if(maillon->isMine == 1 && maillon->isFlag == 0)
						return 0;
			}
	}
	return 1;
}

int minesNumber(maillon* maillon)
{
	int number = 0;
	if(maillon->haut != NULL && maillon->haut->isMine == 1)
		number++;
	if(maillon->bas != NULL && maillon->bas->isMine == 1)
		number++;
	if(maillon->droite != NULL){
		if( maillon->droite->isMine == 1)
			number++;
		if(maillon->droite->haut != NULL && maillon->droite->haut->isMine == 1)
			number++;
		if(maillon->droite->bas != NULL && maillon->droite->bas->isMine == 1)
			number++;
	}
	if(maillon->gauche != NULL) {
		if( maillon->gauche->isMine == 1)
			number++;
		if(maillon->gauche->haut != NULL && maillon->gauche->haut->isMine == 1)
			number++;
		if(maillon->gauche->bas != NULL && maillon->gauche->bas->isMine == 1)
			number++;
	}
	return number;
}








