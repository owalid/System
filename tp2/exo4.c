#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	int fd;
	if(argc <=1){
	perror("Pas de fichier passer en parametre");
	exit(0);
	}

	close(1);
	fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC,0644);	
	execlp("wc","wc", "-l",argv[1],NULL);

	if(fd != 1){perror("error open()"); return 1;}

	perror("error exec()");

return 1;
}
