#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include <dlfcn.h>
#include <stdlib.h>

internal_exec() {
	char* path= (char*) running->syscall_args[0];
	char symbol= (char*) running->syscall_args[1];
	void* lib= dlopen(path, RTLD_LAZY);
	if(lib==NULL){
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return -1;
	}
	double (*cosine)(double);
    char *error;
    dlerror();    /* Clear any existing error */
	cosine = (double (*)(double)) dlsym(lib, symbol);
	error = dlerror();
           if (error != NULL) {
               fprintf(stderr, "%s\n", error);
               exit(EXIT_FAILURE);
           }

           printf("%f\n", (*cosine)(2.0));
           dlclose(lib);
           exit(EXIT_SUCCESS);
}
		
	

