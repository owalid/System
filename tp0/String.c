#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 100

int main(){
	char chaine1[TAILLE_MAX]="bonjour,",chaine2[TAILLE_MAX];
	printf("%s(taille chaine = %lu)\n",chaine1,strlen(chaine1));
	strcpy(chaine2,chaine1);
	strcpy(chaine2," monde");
	printf("%s(taille chaine = %lu\n",chaine2,strlen(chaine2));
	sprintf(chaine1,"%s mond%d",chaine1,3);
	printf("%s(taille chaine = %lu)\n",chaine1,strlen(chaine1));
	return 0;
}