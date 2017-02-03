#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "calcul_triangle.h"
#include "boite_chiffre.h"
#include "affiche_triangle.h"
#include "lire_args.h"
#include "length.h"
#include <stdlib.h>



static char *sortie;

static char str_taille_police [MAX_INT_LENGTH];
static char str_x[MAX_INT_LENGTH];
static char str_y[MAX_INT_LENGTH];
static char str_delta_x[MAX_INT_LENGTH];
static char str_delta_y[MAX_INT_LENGTH];
static char str_valeur[MAX_INT_LENGTH];
static char str_nb_car[MAX_INT_LENGTH];

static char * liste [] = {"./creer_boite", str_taille_police, 
			    NULL, str_x, str_y, 
			    str_delta_x, str_delta_y, 
			    str_valeur, str_nb_car,NULL};


static char message_usage [] = "nombre d'arguments incorrect\nUsage : triangle taille_police nb_lignes";

/*********************************************************************/
/* Pour tracer les appels de boite_chiffre                          */
/*********************************************************************/

void trace_boite_chiffre (unsigned int taille_police, char *sortie,
		          unsigned int x, unsigned int y,
		          unsigned int delta_x, unsigned int delta_y,
		          unsigned int valeur, unsigned int nb_car)
{
	pid_t p;

  sprintf (str_taille_police,"%d",taille_police);
  liste[2] = sortie;
  sprintf (str_x,"%d",x); sprintf (str_y,"%d",y);
  sprintf (str_delta_y,"%d",delta_y); sprintf (str_delta_x,"%d",delta_x);
  sprintf (str_valeur,"%d",valeur); sprintf (str_nb_car,"%d",nb_car);
  
	p = fork();

	if (p < 0){
		fprintf(stderr, "bug");
		exit(1);
	}	
	if (p == 0){
		execve(liste[0], liste, NULL);
		/* On ne doit jamais arriver ici si execve reussit */
		#ifdef PRINTERROR
   	printf ("%s\n",strerror (errno)); 
		#endif
   	fprintf (stderr, "Je n'ai pas reussi a lancer l'execution du fichier %s",liste[0]);
	}
	wait(NULL);

}


/*********************************************************************/
/* La double boucle de parcours du triangle de Pascal                */
/* Tableau trait� comme un tableau � une seule dimension             */
/* pour que l'on puisse �ventuellement creer le tableau par malloc   */
/*********************************************************************/

void postscript_triangle (unsigned int taille_police)
{
  unsigned int nombre_lignes, ligne, colonne, nb_car;
  unsigned int x, y, valeur, delta_x, delta_y;
  char tampon [12];

  nombre_lignes=taille_triangle;
  triangle_pascal ();
  sprintf (tampon,"%d",maximum_pascal);
  nb_car = strlen (tampon);

  delta_x = (nb_car +1) * RATIO_DELTA_X * taille_police ;
  delta_y = RATIO_DELTA_Y * taille_police;

  for (ligne=0; ligne< nombre_lignes; ligne++)
    for (colonne=0; colonne<= ligne; colonne++)
      {
      valeur =pascal(ligne,colonne);
      if (valeur != 0)
        {
        y = ORIGINE_Y + delta_y * (nombre_lignes - (ligne+1));
        x = ORIGINE_X + delta_x * (colonne + 1);
#ifdef TRACE_BOITE
        trace_boite_chiffre (taille_police, sortie, x,y, delta_x, delta_y, 
               valeur, nb_car);
#endif
        boite_chiffre (taille_police, sortie, x,y, delta_x, delta_y, 
               valeur, nb_car);
        }
      }
}

/*********************************************************************/
/* Le main qui appelle tout le reste ...                             */
/*********************************************************************/

int main(int argc, char *argv[], char *envp[])
{

	char prog_suivant [] = "/usr/bin/gv";
	char *arguments [] = {"gv","-",NULL};
	unsigned int taille_police, nb_lignes;
  char nom_executable[200];
	
	pid_t pDroit, pGauche;  
	int statusGauche, statusDroit;

	int t[2];

  lire_args(argc,argv,3,message_usage, 
        "%s",nom_executable,"",
        "%d",&taille_police,"taille_de_police_incorrecte",
        "%d",&nb_lignes,"nombre de lignes incorrect");

	pipe(t);	
	
	pGauche = fork();
	if (pGauche < 0){
		fprintf(stderr, "fils non cr��");
		exit(1);
	}	
	if (pGauche == 0){
		close(t[0]); // fermeture de la sortie du tube
		dup2(t[1], 1); // association de l'entr�e du tube avec la sortie standard
		sortie = "stdout";
  	taille_triangle = nb_lignes;
  	postscript_triangle (taille_police);
		exit(0);
	}

	pDroit = fork();
	if (pDroit < 0){
		fprintf(stderr, "fils non cr��");
		exit(1);
	}	
	if (pDroit == 0){	
		close(t[1]); // fermeture de l'entr�e du tube
		dup2(t[0], 0); // association de la sortie du tube avec l'entr�e standard
		execve (prog_suivant, arguments, envp);
		/* On ne doit jamais arriver ici si execve reussit */
		#ifdef PRINTERROR
   	printf ("%s\n",strerror (errno)); 
		#endif
   	fprintf (stderr, "Je n'ai pas reussi a lancer l'execution du fichier %s",prog_suivant);
	}
	close(t[0]);
	close(t[1]);
	waitpid(pGauche, &statusGauche, 0);
	waitpid(pDroit, &statusDroit, 0);	

	if(statusDroit == 0 && statusGauche == 0){
		fprintf(stderr,"Generation et affichage du triangle de Pascal termine\n");
	}else{
		fprintf(stderr,"Generation et affichage du triangle de Pascal impossible\n");
	}
  return 0;
}
