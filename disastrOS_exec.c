#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include <dlfcn.h>
#include <stdlib.h>

void internal_exec() {
	printf("qui si!1\n");
	char* path = (char*) running->syscall_args[0];
    char* symbol = (char*) running->syscall_args[1];
	void* lib= dlopen(path, RTLD_LAZY);
	if(lib==NULL){
		printf(stderr, "dlopen error: %s\n", dlerror());
		return -1;
	}
	printf("qui pure\n");
	
    
    dlerror();    /* Clear any existing error */
   	void (*start_function)(void*) = (void (*)(void*)) dlsym(lib, symbol);
  char* error = dlerror();
  if (error != NULL) {
    fprintf(stderr, "dlsym error: %s\n", error);
    dlclose(lib);
    
  }
  
  (*start_function)(NULL);  

  
  dlclose(lib);

  
}
