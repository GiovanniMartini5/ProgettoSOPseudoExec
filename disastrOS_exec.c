#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include <dlfcn.h>

int internal_exec() {
	char* path= (char*) running->syscall_args[0];
	char symbol= (char) running->syscall_args[1];
	void* lib= dlopen(path, RTLD_LAZY);
	if(lib==NULL){
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return -1;
	}
	return 0;
}
