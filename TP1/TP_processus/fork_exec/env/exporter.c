#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define NB_ENV 10
#define NB_ARG 10

char *envpasse [NB_ENV] = {NULL};
char *argvpasse [NB_ARG] = {NULL, NULL};

void erreur_usage ()
   {
   fprintf (stderr, "Mauvais nombre d'arguments.Usage :");
   fprintf (stderr, "exporter executable\n\n");
   exit (1);
   }

/* Recherche la sous-chaine cherche au debut de la chaine source */
char *chercher (char *source, const char *cherche)
   {
   char *trouve = NULL;
   if (!strncmp (source,cherche,strlen(cherche))) 
     {
     trouve = source;
     }
   return trouve;
   }

int main (int argc, char *argv[], char *envp[])
   {
   int envlu = 0;
   int envecrit=0;
   
   if (argc != 2) erreur_usage ();

   fprintf (stderr, "Je suis le programme exporter\n");
   fprintf (stderr, "Voici l'environnement que j'ai recu : \n\n");
   fprintf (stderr, "Et dont je ne vais transmettre que PATH et USER\n");

   while (envp[envlu] != NULL)
     {
     fprintf (stdout, "%3d :-------> %s\n", envlu, envp[envlu]);
     if (chercher(envp[envlu],"PATH=") != NULL)  envpasse [envecrit++] = envp[envlu];
     if (chercher(envp[envlu],"USER=") != NULL)  envpasse [envecrit++] = envp[envlu];
     envlu++;
     }
   fprintf (stdout, "\n\n");

   envpasse[envecrit] = NULL;
   argvpasse[0] = argv[1];

   execve (argv[1],argvpasse,envpasse); 
   fprintf (stderr,"Erreur : je n ai pas pu executer %s\n\n",argv[1]);

   return 0;        /* normalement jamais execute */
   }
