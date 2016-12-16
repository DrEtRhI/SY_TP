#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "display.h"


char * arguments [] = {NULL};

char message [] = "Au revoir";

int main (int argc, char *argv[], char *envp[])
   {
   display ();
   printf ("\nFin du programme aurevoir\net fin de la demonstration\n");
   return 0;
   }

