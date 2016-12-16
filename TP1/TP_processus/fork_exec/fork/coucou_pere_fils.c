#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_TAMPON 200
char tampon [MAX_TAMPON];

void suite_pere (pid_t pid)
{
  sprintf (tampon,"Je suis le pere numero %d ",getpid());
  write (fileno(stdout),tampon,strlen(tampon));
  sprintf (tampon,"et mon fils est %d\n",pid);
  write (fileno(stdout),tampon,strlen(tampon));
}


void suite_fils ()
{
   sprintf (tampon,"Je suis le fils");
   write (fileno(stdout),tampon,strlen(tampon));
   sprintf (tampon," numero %d et mon pere est %d\n",getpid(), getppid());
   write (fileno(stdout),tampon,strlen(tampon));
}

int main (int argc, char *argv[], char *envp[])
   {
   pid_t p, fini;
   int status_fils;

   fprintf (stdout,"Je suis le pere numero %d et j appelle fork\n", 
                    getpid());
   p = fork ();
   if (p <0)
     {
     fprintf (stderr, "Je n ai pas pu creer de fils par fork\n");
     exit (1);
     }
   if (p != 0)
       {
       /* Non nul : pid du fils cree et je suis le pere */
       suite_pere (p);
       /* Attendre la terminaison du fils */
       fini = wait (&status_fils);
       fprintf (stdout,"Je suis le pere numero %d et le fils %d s'est termine\n",getpid(),fini);
       }
   else
       /* Nul : je suis donc le fils */
       suite_fils ();
   /* Cet appel a exit est eexecute par le pere et par le fils */
   exit (3);  
}
