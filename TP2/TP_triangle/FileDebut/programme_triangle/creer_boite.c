#include <stdio.h>
#include "boite_chiffre.h"

/********************************************************************/
/* Executable creer_boite                                           */
/* Genere le postscript d'une case du triangle de Pascal            */
/* Convertit les chaînes de la ligne de commande en paramètres      */
/* entiers de boite_chiffre                                         */
/********************************************************************/

int  main (int argc, char *argv[])
  {
  int i;
  creer_boite(argc, argv,1);
  return 0;
  }
