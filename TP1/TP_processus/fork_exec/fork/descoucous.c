#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "descoucous.h"

#define MAX_TAMPON 200
char tampon [MAX_TAMPON];

pid_t p1,p2,p3, createur;
char *ch1, *ch2, *ch3;

int main (int argc, char *argv[], char *envp[])
   {
   prologue (argv[0]);
   createur = getpid ();

   p1 = fork ();           /* fork1 */
   p2 = fork ();           /* fork2 */
   p3 = fork ();           /* fork3 */

   if ((p1 <0) || (p2 <0)|| (p3 <0))
     {
     fprintf (stderr, "Je n ai pas pu creer tous les fils par fork\n");
     exit (1);
     }

   finir ();
   if (getpid() == createur) montrer_arbre ();
   return 0;
   }
