#include <stdio.h>

int main (int argc, char *argv[], char *envp[])
   {
   int envlu;
   envlu = 0;
   fprintf (stderr, "Je suis le programme echoenv\n");
   fprintf (stderr, "Voici l'environnement que j'ai recu : \n\n");
   while (envp[envlu] != NULL) 
      {
      fprintf (stdout, "%3d :--> %s\n", envlu, envp[envlu]);
      envlu++;
      }
   return 0;
   }
