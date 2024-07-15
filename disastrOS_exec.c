#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include <dlfcn.h>
#include <stdlib.h>

void internal_exec() {
	printf("qui si!1\n");
	char* path= "./functions.so";
	char* symbol= "example_function";
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
    
  }
printf("qui?!2\n");
  
  (*start_function)(NULL);  
printf("qui?!3\n");
  
  dlclose(lib);

  
}
