#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>



/* stockage de la representation textuelle d'un uid */
char utilisateur [10];

/* La ligne de commande pour lancer ps */
/* NULL est le marqueur de fin pour les arguments et l'environnement */

char nom [] = "/bin/ps";
char *arguments [] = {"ps","-u", utilisateur, "-w", "-l",NULL};


int main (int argc, char *argv[], char *envp[])
{
   pid_t p, pere, grand_pere;
   uid_t u;
   gid_t g;
   int status;  /* pour le code de retour recupere par wait */ 

   /* Affichage des PID, PPID, UID, GID */
   pere = getpid();
   grand_pere = getppid();

   fprintf (stdout,"Je suis le processus numero %d ", pere);
   fprintf (stdout,"et mon pere est le processus %d\n", grand_pere);
   
   u = getuid ();
   g = getgid ();
   
   fprintf (stdout,"J'appartiens a l'utilisateur %d, groupe %d\n\n",u,g);
   sprintf (utilisateur,"%d",u);
  
   /* Appel de fork et traitement du cas d'erreur */
   p = fork ();
   if (p <0)
     {
     fprintf (stderr, "Je n ai pas pu creer de fils par fork\n");
     exit (1);
     }
   if (p != 0)
       {
       /* p non nul = pid du fils cree et je suis le pere */

       fprintf (stdout,"\nJe suis le pere et je viens de creer le processus fils numero %d\n\n",p);

       /* Attendre la terminaison du fils */
       wait (&status);
       fprintf (stdout,"\nIci le pere %d : quel programme est execute par mon pere %d ?\n", pere,getppid());
       fprintf (stdout,"\nIci le pere %d : je termine mon execution \n", pere);
       }
   else
      {
      /* p nul : je suis donc le fils */

      fprintf (stdout,"Je suis le fils numero %d de mon pere %d et je vais lancer par exec la commande ps\n\n", getpid(), getppid());
   
       execve (nom, arguments, envp);

       /* on ne doit pas arriver ici si execve fonctionne */
       fprintf (stderr, "Je n'ai pas reussi a lancer l'execution du fichier %s\n",arguments[0]);
       }

    /* Code commun au pere et au fils */
    return 0;
}
