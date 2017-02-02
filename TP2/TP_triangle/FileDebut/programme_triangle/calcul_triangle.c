#include "calcul_triangle.h"

/* La mémoire pour le tableau devrait etre allouée dynamiquement   */
/* lors de l'appel de triangle_pacal, mais malloc n'est pas encore */
/* presentee dans le cadre du cours ISE ==> allocation statique    */

/* Le tableau est utilisé comme un tableau à 2 dimensions     */
/* Mais il est déclaré comme un tableau à une seule dimension */
/* pour que l'on puisse facilement remplacer la déclaration   */
/* statique par un malloc                                     */

unsigned maximum_pascal = 0;
unsigned int taille_triangle = 0;

static unsigned int triangle [MAX_LIGNES* MAX_LIGNES];

/**********************************************************************/
/* Convertit accès en ligne/colonne en accès au tableau à 1 dimension */
/**********************************************************************/

unsigned int pascal (unsigned int l, unsigned int c)
{
  return triangle [l * taille_triangle + c];
}

void setpascal (unsigned int l, unsigned int c, unsigned int valeur)
{
  triangle [l * taille_triangle + c] = valeur;
}

/**********************************************************************/
/* Initialise le triangle des Cnp de PASCAL                           */
/**********************************************************************/

void triangle_pascal (void)
{
  unsigned int l, c, cumul;
  setpascal (0,0,1);          
  setpascal (0,1,0);    

  l = 1;
  while (l < taille_triangle)
    {
      setpascal(l,0,1);        /* t[l][0] = 1 */
      setpascal(l,l+1,0);      /* t[l][l+1] = 0 */
      c = 1;
      while (c <= l)
	    {
	    cumul =  pascal(l-1,c-1) +  pascal(l-1,c); 
	    setpascal (l,c,cumul);  
	    if (cumul > maximum_pascal) maximum_pascal = cumul;
	    c ++;
	    }
      l ++;
    }
  return;
}

//  triangle [0+0] = 1;                   /* t[0][0] */
//  triangle [0+1] = 0;                   /* t[0][1] */
//
//      triangle [l * t +   0] = 1;  /* t[l][0] */
//      triangle [l * t + l+1] = 0;  /* t[l][l+1] */
//      c = 1;
//      while (c <= l)
//	    {
//	    cumul =  triangle [(l-1)*t + c-1] +  /* t[l-1][c-1] */
//	             triangle [(l-1)*t + c];     /* t[l-1][c] */
//	    triangle [l*t + c] = cumul;          /* t[l][c] */
//	    if (cumul > maximum_pascal) maximum_pascal = cumul;
