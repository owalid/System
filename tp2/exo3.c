#include <unistd.h>


int main(int argc, char **argv){
	if(argc <1){perror("Pas de fichier passer en parametre"), exit(0)}
	execlp("wc","wc", "-l",argv[1],NULL);
return 1;
}
