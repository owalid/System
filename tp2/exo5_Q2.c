//EL AYADI OTHMANE
//exo5 question 2
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int main(){

//declarations des variables
	int pipe1[2], pipe2[2];
	int  octets = 2;
	float x, y,pi;
	float M, N;
	char c = '\0';

//initialisation des pipes
	pipe(pipe1);
	pipe(pipe2);

//verification lors de la creation du fils
	if(fork() == -1){
		perror("erreur lors de la creation du fils");
		exit(1);
	}

//si on est dans le fils
	else if(fork() == 0){

		while(1){
		//fermer le pipe1 en lecture et l'ouvrir en ecriture
		close(pipe1[0]);
		write(pipe1[1], &octets, 1);
		sleep(1);
		close(pipe2[1]);

		//lire x et y
		read(pipe2[0], &x, sizeof(float));
		read(pipe2[0], &y, sizeof(float));
		N++;
		printf("valeur de x = %f \n", x);
		printf("valeur de y = %f \n", y);

			if((x*x)+(y*y)<= 1){
					M++;
					pi = ((4*M)/N);
					printf("\n Approximation de pi = %f \n", pi);
			}	
		}
	}
	else{
		srandom(time(NULL));
		while(1){
			printf("Le pere attend \n");
			close(pipe1[1]);
//lecture d'un octet sur pipe1
			read(pipe1[0], &c, 1);
//calcul des random
			float random1 = (float)random() / RAND_MAX;
			float random2 = (float)random() / RAND_MAX;
//fermeture des tubes en ecriture
			write(pipe2[1], &random1, sizeof(float));
			write(pipe2[1], &random2, sizeof(float));

		}
	}
	return 0;
}
