#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lire_args.h"


void erreur(char *message)
{
  fprintf (stderr,"Erreur : %s\n",message);
  exit (1);
}

void afficher_args (int argc, char *liste[])
{
  char **p=liste;
  if (argc == AFFICHER_ARGS_NO_ARGC) 
     while (*p != NULL)         {fprintf (stderr,"%s ", *p); p++;}
  else
     {
     fprintf (stderr,"argc = %d\n", argc);
      while ((p-liste) < argc )  {fprintf (stderr,"%s ", *p); p++;}
     }
  fprintf (stderr,"\n");
}


int lire_args (int argc, char **argv, int val_argc, char *musage, ...)
{
  va_list liste;

  char *format;
  char *message;
  void *variable;

  int arg;

  va_start(liste,musage);
  
  /* Verifier le nombre de paramètres passés */

  if (argc != val_argc) erreur (musage); 

  /* Parcourir et verifier les paramètres */

  for (arg=0; arg < argc; arg++)
    {
    format = va_arg(liste, char *);
    variable = (void *) va_arg(liste, void *);
    message = va_arg(liste, char *);
    if (sscanf (argv[arg], format, variable) != 1) erreur (message);
    }
  va_end(liste);
  return arg;
}

