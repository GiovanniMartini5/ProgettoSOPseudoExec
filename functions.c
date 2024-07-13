#include <stdio.h>
#include <unistd.h>
#include <poll.h>

#include "disastrOS.h"
// Funzione di esempio da eseguire tramite exec
void example_function(void* args) {
  printf("Eseguita example_function!\n");
}

void initFunction(void* args) {
 
  disastrOS_printStatus();
  disastrOS_exec("/home/giovanni/Desktop/ProgettoSoPseudoExec", "example functions");
  

  return;
}
// Avvio del sistema
int main(int argc, char** argv){
  char* logfilename=0;
  if (argc>1) {
    logfilename=argv[1];
  }
  // we create the init process processes
  // the first is in the running variable
  // the others are in the ready queue
  // spawn an init process
  printf("start\n");
  disastrOS_start(initFunction, 0, logfilename);
  return 0;
}


