#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include <dlfcn.h>
#include <stdlib.h>

internal_exec() {
	printf("qui si!1\n");
	char* path= (char*) running->syscall_args[0];
	char symbol= (char*) running->syscall_args[1];
	void* lib= dlopen(path, RTLD_LAZY);
	if(lib==NULL){
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return -1;
	}
	printf("qui pure\n");
	
    
    dlerror();    /* Clear any existing error */
    printf("qui?!1\n");
	void (*start_function)(void*) = (void (*)(void*)) dlsym(lib, symbol);
  char* error = dlerror();
  if (error != NULL) {
    fprintf(stderr, "dlsym error: %s\n", error);
    dlclose(lib);
    running->syscall_retvalue = -1;  // Errore di simbolo
    return;
  }
printf("qui?!2\n");
  // Esegui la funzione caricata
  (*start_function)(NULL);  // Puoi passare argomenti se necessario

  // Chiudi la libreria (se non necessario lascia aperta per chiamate future)
  dlclose(lib);

  running->syscall_retvalue = 0;  // Successo
}

		
	

