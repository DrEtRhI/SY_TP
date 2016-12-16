#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[], char*envp[])
  {
  int i;
  int pid;
  int val_retour;

  pid = getpid();
  printf ("Je suis le processus %d executant echo_arg\n",pid);

  printf ("processus %d : nombre d'arguments argc = %d\n",pid,argc);
  for (i = 0; i <argc; i++)
     printf ("processus %d : argv[%d] : \"%s\"\n",pid,i,argv[i]);

  val_retour = 2*argc;
  printf ("Processus %d : code de retour = %d (deux fois le nombre d'arguments)\n",pid, val_retour);

  printf ("Execution de %d (echo_arg) terminee\n", getpid());
  return val_retour;
  }
