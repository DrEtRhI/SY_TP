#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "display.h"

#define MAX_LIGNE 256
char format[MAX_LIGNE]="";

void display (void)
{
   printf ("\nJe suis le processus %d, mon pere est %d, et je vous dis ""%s""\n",
		getpid(), getppid(),message);
   sprintf(format,"ps -ef | grep  %d | grep -v grep",getppid());
   printf ("J'execute la commande ps -aF. Voici un extrait du resultat :\n\n");
   system("ps -aF | head -n 1");   /* Affichage des noms des colonnes */
   system(format);
}

