#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 20
int tab[SIZE];


void * bulle(void * arg) {
//tri a bulle
	bool tab_ordre = false;
	int temp;
	int i;
	while(!tab_ordre){
		tab_ordre = true;
		for (i = 0; i<= SIZE-1; i++){
			if(tab[i+1] < tab[i]){	
				temp = tab[i+1];
				tab[i+1] = tab[i];
				tab[i] = temp;
				tab_ordre = false;
			}
		}
	}
	return NULL;
}
void * plomb(void * arg) {
//tri a bulle
	bool tab_ordre = false; 
	int temp;
	int j;
	while(!tab_ordre){
		tab_ordre = true;
		for (j =  SIZE-1; j>= SIZE; j--){
			if(tab[j-1]> tab[j]){	
				temp = tab[j-1];
				tab[j-1] = tab[j];
				tab[j] = temp;
				tab_ordre = false;
				}
			}
		}
	return NULL;
}

void shuffle() {
  int i, j, temp;
  for (i = SIZE - 1; i >= 0; i--) {
    j = random() % (i + 1);
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
  }
}

int main() {
  int i;
  pthread_t bulle_id, plomb_id;
  srandom(time(NULL));

  for (i = 0; i < SIZE; i++) tab[i] = i + 1;

  for (i = 0; i < 3000; i++) {
    shuffle();
    if (pthread_create(&bulle_id, NULL, bulle, NULL) != 0) exit(1);
    if (pthread_create(&plomb_id, NULL, plomb, NULL) != 0) exit(1);
    pthread_join(bulle_id, NULL);
    pthread_join(plomb_id, NULL);
  }

  for (i = 0; i < SIZE; i++) printf("%d ", tab[i]);
  putchar('\n');
  return 0;
}


