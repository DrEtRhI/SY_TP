#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "descoucous.h"

char arbre [][100] = {
"      Createur   \n",
"          |      \n",
"        fork1    \n",
"          |  |   \n",
"          |  ----------------------------------------------\n",
"          |                                               |\n",
"     Createur                                            fils1 \n",
"       p1 !=0                                            p1==0 \n",
"          |                                               |    \n",
"        fork2                                            fork2 \n",
"          |  |                                            |  | \n",
"          |  --------------------                         |  -----------------\n",
"          |                     |                         |                  | \n",
"     Createur                  fils2                     fils1             pfils\n",
"        p1 != 0               p1 !=0                    p1 == 0           p1==0\n",
"        p2 != 0               p2 == 0                   p2 != 0           p2==0\n",
"          |                     |                         |                  |\n",
"        fork3                  fork3                     fork3              fork3\n",
"          |  |                  |  |                      |  |               | |\n",
"          |  ---------          |  ----------             |  ----------      | ---------\n",
"          |          |          |           |             |            |     |         |\n",
"      Createur     fils3      fils2      pfils           fils1       pfils   pfils    apfils\n",
"        p1 != 0    p1 != 0    p1 !=0     p1 != 0        p1 == 0     p1==0   p1==0     p1 == 0\n",
"        p2 != 0    p2 != 0    p2 == 0    p2 == 0        p2 != 0     p2!=0   p2==0     p2 == 0\n",
"        p3 != 0    p3 == 0    p3 !=0     p3 == 0        p3 != 0     p3==0   p3!=0     p3 == 0\n",
"\n",
"\0"
                    };

void montrer_arbre (void)
  {
  int ligne;
  ligne = 0;
  fprintf (stderr, "\n\n");
  while (arbre[ligne][0] != 0) 
    {
    fprintf (stderr,"%s",arbre[ligne]);
    ligne ++;
    }
  fflush (stderr);
  }

void prologue (char *m)
  {
  fprintf (stderr,"\nPfils signifie petit-fils (fils d'un fils)\n");
  fprintf (stderr,"Apfils signifie arriere-petit-fils (fils d'un petit-fils)\n");
  fprintf (stderr,"\nElargissez votre fenetre si les lignes longues sont repliees\n\n");
  fprintf (stderr,"Je suis le createur %d (%s) fils de %d (shell)\n\n", getpid(),m, getppid());
  fflush (stderr);
  }


void message(void)
  {
  if (p1 == 0) 
    {
    ch1 =        "--> fils1 ";
    if (p2 == 0)
      {
      ch2 =      "--> pfils1 ";
      if (p3 == 0)
	ch3 =    "--> apfils ";
      else
        ch3 = "";
      }
    else
      {
      ch2 = "";
      if (p3 == 0)
        ch3 =    "--> pfils3 ";
      else
        ch3 = "";
      }
    }
  else
    {
    ch1 = "";
    if (p2 == 0)
      {
      ch2 =      "--> fils2 ";
      if (p3 == 0)
	ch3 =    "--> pfils2 ";
      else
        ch3 = "";
      }
    else
      {
      ch2 = "";
      if (p3 == 0)
        ch3 =    "--> fils3 ";
      else
        ch3 = "";
      }
     }
   }

void afficher (void)
  {
  pid_t moi = getpid();
  pid_t pere = getppid();
  sprintf (tampon, "(%d) fils de %d  p1 = %5d p2= %5d p3 = %5d : Createur %s%s%s\n", 
           moi, pere, p1, p2, p3, ch1, ch2, ch3);
  write (fileno(stdout), tampon, strlen(tampon));
  }


void finir (void)
  {
  int dummy;
  message();
  afficher ();
  if (p3 != 0) wait (&dummy);
  if (p2 != 0) wait (&dummy);
  if(p1 != 0) wait (&dummy);
  }

