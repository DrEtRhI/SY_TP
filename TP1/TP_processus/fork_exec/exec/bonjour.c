#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "display.h"

char * arguments [] = {NULL};

char message [] = "Bonjour !";
char prog_suivant [] = "./coucou";
char lu[10];

int main (int argc, char *argv[], char *envp[])
   {
   display ();
   fprintf (stderr,"\ntaper ensuite un retour a la ligne pour continuer\n");
   scanf ("%c",lu);
   printf ("\nJe me transforme en %s en utilisant exec\n\n",prog_suivant);
   execve (prog_suivant, arguments, envp);
   /* On ne doit jamais arriver ici si execeve reussit */
#ifdef PRINTERROR
   printf ("%s\n",strerror (errno)); 
#endif
   fprintf (stderr, "Je n'ai pas reussi a lancer l'execution du fichier %s",prog_suivant);
   return 0;
   }

