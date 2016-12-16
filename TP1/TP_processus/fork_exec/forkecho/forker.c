#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* stockage de la representation textuelle d'un uid */
char utilisateur [10];

/* La ligne de commande pour lancer echo_arg */
/* NULL est le marqueur de fin pour les arguments et l'environnement */

char nom [] = "/bin/ls";
char *arguments [] = {"./echo_arg","-ai", NULL};

int main (int argc, char *argv[],char *envp[])
  {
  pid_t p, fils;
  int code_retour;

  fprintf (stdout,"Je suis le pere numero %d\n", getpid());

  /* appel de fork et elimination du cas d'erreur */
  p = fork ();
  if (p <0) {
    fprintf (stderr, "Je n ai pas pu creer de fils par fork\n");
    exit (1);
    }

  if (p != 0) {
      /* code du pere */

      fprintf (stdout, "Je suis le pere numero %d et j'attends la fin du fils %d\n", getpid(), p);
      /* Attendre la terminaison du fils */
      fils = wait (&code_retour);
      if (WIFEXITED(code_retour)) {
         fprintf (stdout, "Processus %d : fin du fils %d avec le code %d\n", getpid(), fils, WEXITSTATUS(code_retour));
      } else {
         fprintf (stdout, "Processus %d : fin anormale du fils %dn", getpid(), fils);
      } 

  } else {

      /* code du fils */

     /* Nul : je suis donc le fils */
      fprintf (stdout, "Je suis le fils numero %d et je me transforme en echo_arg par exec\n", getpid());
      execve (nom, arguments, envp);
      fprintf (stderr, "Ce message ne devrait pas etre affiche : \nFils : je n'ai pas reussi a lancer l'execution du fichier %s\n",arguments[0]);
      }

  return 0;
  }
