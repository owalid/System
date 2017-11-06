/* SERVEUR. Lancer ce programme en premier (pas d'arguments). */

#include <stdio.h>                  /* fichiers d'en-tÃªte classiques */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/socket.h>             /* fichiers d'en-tÃªte "rÃ©seau" */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_SERVEUR 5015           /* NumÃ©ro de port pour le serveur */
#define MAX_CLIENTS   128           /* Nombre maximum de clients */
#define BUFFER_SIZE  1024           /* Taille maximum des messages */	

int main(int argc, char *argv[]) {

	int secoute;
	char message[BUFFER_SIZE] = {0};
	struct sockaddr_in cadresse={0};
	sok_len caddrlen = sizeof(cadresse);
	

  /* 1. On dÃ©route les signaux */
	
	signal(SIGCHLD,handler);
  /* 2. On crÃ©e la socket d'Ã©coute. */
	if(secoute = soket(AF_INET, SOCK_STREAM,0) == -1){
	perror("Erreur ouverture des sokets");
	exit(1);}


  /* 3. On prÃ©pare l'adresse du serveur. */
	struct sockaddr_in adresse = {0};
	adresse.sin_family = AF_INET;
	adresse.sin_addr.s_addr = htonl(INADDR_ANY);
	adresse.sin_port = htons(atoi(argv[1]));	


  /* 4. On attache la socket a l'adresse du serveur. */
	if(bind(secout,(struct sockaddr *) &adresse, sizeof(adresse))==-1){
	perror("erreur attachement");
	exit(0);
	}	
	
  /* 5. Enregistrement auprÃ¨s du systÃ¨me. */
	if((listen(secoute,128))==-1){perror("erreur de demande de connexion");exit(1);}
	 
	fd_set fds, fds_tmp;
	FD_ZERO(&fds_master);
	FD_SET(secoute, &fds_master);
	max_fd = secoute;

	while (1) {
		fds_tmp =fds_master;
	    printf("Serveur en attente de nouveaux clients ou messages.\n");
		select(max_fd -1, &fds, NULL, NULL);
		if((sservice = accept(secoute,(struct sock_addr *) &cadresse, &caddrlen))==-1)

    /* 6. Si on a reÃ§u une demande sur la socket d'Ã©coute... */
	if(FD_ISSET(secoute, &fds_tmp)){
		(sservice = accept(secoute,NULL,NULL))==-1){}
	}
	FD_SET(sservice, &fds_master);
	if(sservice > max_fd) max_fd = sservice;

    /* 7. Si on a reÃ§u des donnÃ©es sur une socket de service... */

  }

  /* 8. On termine et libÃ¨re les ressources. */

  return 0;
}

