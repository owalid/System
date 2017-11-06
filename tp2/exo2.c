#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
	int fd;
	int size =0;
	int pos=0;
	char car;

	if(argc <=1){write(2,"missing argument\\n",17); return 1;}
	fd= open(argv[1], O_RDWR);
	if(fd == -1 ) {perror("open() error"); return 1;}
	size = lseek(fd, 0, SEEK_END);
	

	for(pos = 0; pos < size; pos++){
		lseek(fd,pos,SEEK_SET);
		read(fd,&car,1);

		if(islower(car)){
		 car = toupper(car);
		}

		else if (isupper(car)){
		 car = tolower(car);
		}
	write(1, &car,1);
	}
	close(fd);
	return 0;
	
}
