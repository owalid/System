#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char ** argv){
		
	int status;
	int found = 0;
	int N=0;
	int n=0;
	const int TABSIZE=100;
	unsigned char arr[TABSIZE];
	srandom(time(NULL));
//entasser le foin
	int i;
	for (i =0;i<TABSIZE;i++){
		arr[i] = (unsigned char) (random()%255)+1;
	}

//distribuer les travaux au fils
	if(argc>1)N=atoi(argv[1]);
	if(N<1 || N > 100) N = 1;

//cacher l'aiguille
	printf("%c \n",arr[0]);
	printf("Enter a number between 0 and %d: ", TABSIZE);
	scanf(" %d", &i);
	if(i >=0 && i < TABSIZE) arr[i] = 0;

	int id = fork();
	

	for(n=0;n<N;n++){
		if(id == -1){perror("fork error"); exit(1);}
		if(id == 0){
			for(i=n*TABSIZE/N; i<(n+1)*TABSIZE/2; i++){
				if(arr[i]==0)exit(1);
			}	
			exit(0);
		}
	}


//chercher dans l'autre moitie
	for (i=TABSIZE/2; i<TABSIZE; i++){
		if (arr[i] ==0){found =1;}
	}

//recup le result du fils
	for(n=0;n<N;n++){
		wait(&status);
	
	
		if(!WIFEXITED(status)){
		fprintf(stderr, "abnormal terminaison of the child process.\n");
		exit(1);
		}

		if(WEXITSTATUS(status==1)){found =1;}
	}
//afficher le resultat
	if(found)printf("Got a needle !\n");
	else printf("No needle. \n");
	return(0);
}

