#include <stdio.h>
#include <unistd.h>
#include <poll.h>

#include "disastrOS.h"
// Funzioni di esempio da eseguire tramite exec

//Stampa una semplice scritta
void example_function() {
	
	printf("Eseguita example_function!\n");
	
}

//Calcola la somma di due interi
void calculate(void** params){
	int i= *(int*) params[0];
	int j= *(int*) params[1];
	int n=i+j;
	printf("il numero è %d\n", n);
	
}

//Descrive i dettagli riguardanti uno studente
void identity(void** params){
	char* nome= (char*) params[0];
	char* cognome= (char*)params[1];
	int matricola= *(int*) params[2];
	printf("io sono %s %s matricola numero: %d\n", nome, cognome, matricola);
	
}
