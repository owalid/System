#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char ** argvv){
	const int TABSIZE=100000;
	unsigned char arr[TABSIZE];
	srandom(time(NULL));

//entasser le foin
	int i;
	for (i =0;i<TABSIZE;i++){
		arr[i] = (unsigned char) (random()%255)+1;
	}

//cacher l'aiguille
	printf("%c \n",arr[0]);
	printf("Enter a number between 0 and %d: ", TABSIZE);
	scanf(" %d", &i);
	if(i >=0 && i < TABSIZE) arr[i] = 0;
	
	int status;
	int found = 0;
	int id = fork();
	if(id == -1){perror("fork error"); exit(1);}
	if(id == 0){

		for(i=0; i<TABSIZE /2; i++){
			if(arr[i]==0)exit(1);
		}	
		exit(0);
	}

//chercher dans l'autre moitie
	for (i=TABSIZE/2; i<TABSIZE; i++){
		if (arr[i] ==0){found =1;}
	}

//recup le result du fils
	wait(&status);
	if(!WIFEXITED(status)){
	fprintf(stderr, "abnormal terminaison of the child process.\n");
	exit(1);
	}

	if(WEXITSTATUS(status==1)){found =1;}

//afficher le resultat
	if(found)printf("Got a needle !\n");
	else printf("No needle. \n");
	return(0);
}
