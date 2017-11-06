/* CLIENT. Donner l'adresse IP et un pseudo en paramÃ¨tre */
/* exemple "client 127.0.0.1 dr.ced", lancer en dernier. */

#include <stdio.h>             /* fichiers d'en-tÃªte classiques */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#include <sys/socket.h>        /* fichiers d'en-tÃªte "rÃ©seau" */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_SERVEUR 5015      /* NumÃ©ro de port pour le serveur */
#define BUFFER_SIZE  1024      /* Taille maximum des messages */

int main(int argc, char *argv[]) {
	int sclient;
	struct sockaddr_in_in saddr = {0};

  /* 1. On crÃ©e la socket du client. */
	if((sclient = socket(AF_INET, SOCK_STREAM, 0)) == -1){
	perror("erreur soket");
	exit(1);}

  /* 2. On prÃ©pare l'adresse du serveur. */
	inet_addr("127.0.0.1");	


  /* 3. On demande une connexion au serveur, tant qu'on y arrive pas. */
	while(connect(sclient,(struct sockaddr *) &saddr, sizeof(saddr) ) == -1);


  /* 4. On communique. */
	
	if(fork()==-1){
		perror("erreur de la cration du process");
		exit(1);}

	if(fork()==0){
		char s[BUFFER_SIZE]={0};
		if(write(sclient, argv[1], sizeof(argv[1])) != 1){
			perror("erreur de communication");
			exit(1);}

		if(read(sclient, &s, sizeof(s)) == -1){
			perror("erreur de lecture");
			exit(1);}

		printf("%s",s);
	

  /* 5. On termine et libÃ¨re les ressources. */
	shutdown(sclient, SHUT_RDWR);
	close(sclient);}
  return 0;
}

