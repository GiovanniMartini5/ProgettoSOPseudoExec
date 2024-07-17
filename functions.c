#include <stdio.h>
#include <unistd.h>
#include <poll.h>

#include "disastrOS.h"
// Funzione di esempio da eseguire tramite exec
void example_function() {
	
	printf("Eseguita example_function!\n");
	
}

void calculate(void** params){
	int i= *(int*) params[0];
	int j= *(int*) params[1];
	int n=i+j;
	printf("il numero è %d\n", n);
	
}
void identity(void** params){
	char* nome= (char*) params[0];
	char* cognome= (char*)params[1];
	int matricola= *(int*) params[2];
	printf("io sono %s %s matricola numero: %d\n", nome, cognome, matricola);
	
}
