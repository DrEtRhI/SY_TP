#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "boite_chiffre.h"
#include "lire_args.h"
#include "length.h"

char message_usage [] = "Nombre d'arguments incorrects\nUsage : creer_boite taille_police fichier_sortie position_x position_y intervalle_x intervalle_y valeur nb_caracteres";

/**************************************************************************/
/* Creer_boite :                                                          */
/*  + call = 0  : affiche resultat de trace_boite_chiffre                 */
/*                                        (programme executable triangle) */
/*  + call = 1  : appeler boite_chiffre, paramètres en ligne de commande  */
/*                                   (programme executable boite_chiffre) */
/**************************************************************************/

int creer_boite(int argc, char *argv[], int call)
{
   char nom_executable[MAX_FILE_NAME_LENGTH];
   char nom_sortie[MAX_FILE_NAME_LENGTH];
   unsigned int taille_police, x, y, delta_x, delta_y, valeur, nb_car;

  lire_args(argc,argv,9,message_usage, 
        "%s",nom_executable,"",
        "%d",&taille_police,"taille_de_police_incorrecte",
	"%s",nom_sortie,"nom du fichier de sortie incorrect",
        "%d",&x,"parametre entier x incorrect",
        "%d",&y,"parametre entier y incorrect",
        "%d",&delta_x,"parametre entier delta_x incorrect",
        "%d",&delta_y,"parametre entier delta_y incorrect",
        "%d",&valeur,"parametre entier valeur incorrect",
        "%d",&nb_car,"parametre entier nb_car incorrect"
	);
   if (call) fprintf (stderr, "Processus %d (pere %d) : ",getpid(), getppid());
   fprintf (stderr, "%s %u %s %u %u %u %u %u %u",
                    nom_executable, taille_police, nom_sortie, x,y,
		    delta_x, delta_y, valeur, nb_car);
   if (!call) fprintf (stderr, " >> triangle.ps");
   fprintf (stderr,"\n");
   if (call) 
       boite_chiffre(taille_police, nom_sortie, x,y, delta_x, delta_y, 
                     valeur, nb_car);
  return 0;
}

/***************************************************************************/
/* Boite_chiffre : generation du Postscript d'une case du triangle         */
/*                 taille_police et sortie : taille et fichier de sortie   */
/*                 x,y : coordonnées de la case                            */
/*                 delta_x, delta_y : espacement entre boîtes              */
/*                 valeur et nb_case : contenu et format                   */
/***************************************************************************/
 
void boite_chiffre (unsigned int taille_police, char *sortie,
		    unsigned int x, unsigned int y,
		    unsigned int delta_x, unsigned int delta_y, 
		    unsigned int valeur, unsigned int nb_car)
{
  char format [80];
  FILE *fsortie;

  if (strcmp (sortie, "stdout") == 0) 
    fsortie = stdout;
  else {
    fsortie = fopen (sortie, "w");
    if (fsortie == NULL)
      erreur ("Impossible d'ouvrir le fichier en ecriture\n");
  }
  fprintf (fsortie,"newpath %u %u moveto ",x,y);
  fprintf (fsortie,"%u %u lineto ",x+delta_x,y);
  fprintf (fsortie,"%u %u lineto ",x+delta_x,y+delta_y);
  fprintf (fsortie,"stroke ");
  fprintf (fsortie,"newpath %u %u moveto ",x,y);
  fprintf (fsortie,"%u %u lineto ",x,y+delta_y);
  fprintf (fsortie,"%u %u lineto ",x+delta_x,y+delta_y);
  fprintf (fsortie,"stroke ");
  fprintf (fsortie,"/Courier findfont %u scalefont setfont ", taille_police);
  fprintf (fsortie,"newpath %u %u moveto ",x + (int) ((float) delta_x/12.0), 
	   y + (int) ((float) delta_y/4.0));
  sprintf (format,"(%%%uu) show \n",nb_car);
  fprintf (fsortie,format,valeur);
  fflush (fsortie);
  if (strcmp (sortie, "stdout") != 0) fclose (fsortie);
}
