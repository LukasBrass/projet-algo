#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  printf("Choisissez une taille de grile : \n");
  int a,b,boucle1,boucle2,j;
  int i = 1000;
  int num = 1;
  scanf("%d",&a);
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
  return EXIT_SUCCESS;
}
