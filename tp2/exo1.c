#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

int main (int argc, char ** argv) {
	int fd, nbLus;
	char c;
	if (argc <= 1) { write(2, "missing argument\n", 17); return 1; }
	fd = open(argv[1], O_RDWR);
	if (fd == -1) { perror("open() error"); return 1;}
	while (1){
		nbLus = read(fd, &c, 1);
		if (nbLus == 0) break;
		if (islower(c)) c = toupper(c);
		else if (isupper(c)) c = tolower(c);
		printf("%c", c);
	}
	return 0;
}
