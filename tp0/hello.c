#include  <stdio.h>
int main(){
	double valeur = 10;
	double *pv = &valeur;
	int nombre, *pn;
	valeur = *pv +1;
	printf("valeur = %f\n",valeur);
	printf("&valeur = %p\n", &valeur);

	printf("taille valeur = %zu\n",sizeof(valeur));
	printf("taille pv = %zu\n",sizeof(pv));
	printf("taille pn = %zu\n",sizeof(pn));
	printf("taille nombre = %zu\n",sizeof(nombre));
	
	return(0);
}
