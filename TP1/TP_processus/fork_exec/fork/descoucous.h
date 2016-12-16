#include <unistd.h>
#include <stdlib.h>

extern pid_t p1,p2,p3, createur;
extern char *ch1, *ch2, *ch3;
extern char tampon [];


void message(void);
void prologue(char *m);
void afficher (void);
void montrer_arbre (void);
void finir (void);
