//EL AYADI OTHMANE
//exo5 question 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){ 
	int ppe[2];
	char car = '\0';
//on creer le tube
	pipe(ppe);

//verification lors de la creation du fils
	if(fork() == -1){
		perror("erreur lors de la creation du fils");
		exit(1);
	}

//code du pere
	if (fork() != 0) { 
		float rand;
		close(ppe[1]);
		srandom(time(NULL));

		while (1){ 
			printf("Le pere en attente.\n");
			read(ppe[0], &car, 1);
			rand= ((float)random()/RAND_MAX); 
			printf("Envoi de : %f \n", rand);
	}
		close(ppe[0]);
		return 0;
	}
//code du fils
	else{
		close(ppe[0]);
		while (1){ 
			write(ppe[1], &car, 1);
			sleep(1);
		}
	}
	close(ppe[1]);
	return 0;
}
