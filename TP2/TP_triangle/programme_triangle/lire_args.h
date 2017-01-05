#include <stdarg.h>

extern void erreur(char *);

/************************************************************************/
/* Afficher args : affiche les chaïnes de carcatères de liste           */
/*                                                                      */
/* argc >= 0  : nombre d'éléments de la liste  (type argc+argv)         */ 
/* argc <0    : liste terminée par NULL        (type envp)              */ 
/************************************************************************/

#define AFFICHER_ARGS_NO_ARGC -1
extern void afficher_args (int argc,char *liste[]);

/************************************************************************/
/* Lire_args : verifie les parametres de la ligne de commande           */
/*                                                                      */
/* erreur        : fonction a fournir, qui affiche un message d'erreur  */
/*                 ==> sur argument errone                              */
/*                                                                      */
/* Utilisation :                                                        */
/*                                                                      */
/* lire_args (argc, argv, ARGC_VAL, mu,                                 */
/*               f1, &var1, m1, f2, &var2, m2, ..., fn,&varn,mn)        */   
/*                                                                      */
/*            argc : le nombre d'arguments de la ligne de commande      */
/*            argv : le tableau d'arguments de la ligne de commande     */
/*        ARGC_VAL : le nombre d'arguments attendus                     */
/*              mu : message d'erreur si argc != ARGC_VAL               */
/*              fi : le format attendu ("%s", "%d", "%c") de argv[i]    */
/*           &vari : adresse de stockage de argv[i],                    */
/*              mi : message d'erreur si var[i] de format errone        */
/*                                                                      */
/*                                                                      */
/* Exemple :  tail affiche les n dernieres lignes d'un fichier          */
/*                                                                      */
/* Utilisation  : tail    nom_fichier nombre_lignes                     */
/*                tail    /etc/passwd  10                               */
/*               argv[0]  argv[1]     argv[2]                           */
/*               chaine   chaine      entier                            */
/*                                                                      */
/*     argc doit valoir 3                                               */
/*                                                                      */
/* const char message_usage [] = "Usage : tail fichier nombre_lignes\n" */
/* char nom_executable[TAILLE_NOM];                                     */
/* char nom_fichier [TAILLE_NOM];                                       */
/* unsigned int nb_lignes;                                              */
/*                                                                      */
/*  lire_args (argc, 3, message_usage, argv,                            */
/*             "%s", &nom_executable, "",                               */
/*             "%s", &nom_fichier, "nom de fichier incorrect\n",        */
/*             "%d", &nb_lignes, "nombre de lignes incorrect\n");       */
/*                                                                      */
/************************************************************************/

int lire_args (int argc, char **argv, int val_argc, char *musage,  ...);
