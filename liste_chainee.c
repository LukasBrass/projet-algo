#include <stdio.h>
#include <stdlib.h>

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
	while(element->abscisse != abscisse)
		element = element->droite;
	while(element->ordonnee != ordonnee)
		element = element->bas;
	return element;
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
    return first;
}








