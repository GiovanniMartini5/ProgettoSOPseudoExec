#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include <dlfcn.h>
#include <stdlib.h>

void internal_exec() {
	
	//carico il percorso, la funzione da utilizzare e i parametri da passare alla funzione
	char* path = (char*) running->syscall_args[0];
    char* symbol = (char*) running->syscall_args[1];
    void** parameters=(void**) running->syscall_args[2];
    
    //carica la libreria dinamica
	void* lib= dlopen(path, RTLD_LAZY);
	if(lib==NULL){
		printf("dlopen error: %s\n", dlerror()); //errore
		running->syscall_retvalue = DSOS_EEXEC;
		return;
	}
    
    dlerror();    /* Clear any existing error */
    
    //carica la funzione della libreria dinamica
	void (*start_function)(void*) = (void (*)(void*)) dlsym(lib, symbol);
	char* error = dlerror();
	if (error != NULL) {
		printf("dlsym error: %s\n", error); //errore
		dlclose(lib);
		running->syscall_retvalue = DSOS_EEXEC;
		return;
    
	}
  
	(*start_function)(parameters); //invoco la funzione passando i parametri

  
	dlclose(lib); //chiudo la libreria

  
}
