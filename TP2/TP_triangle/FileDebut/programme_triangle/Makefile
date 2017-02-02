#  Ceci est un commentaire
#  Les espaces en debut de ligne avant les commandes de generation
#  sont des tabulations, pas des espaces ordinaires

# Les variables speciales
#  $@ est le nom de la cible (fichier a generer)
#  $< nom de la premiere dependance
#  $^ liste des dependances

# Les commandes pour la compilation et l'edition de liens
CC = gcc   
LD = gcc

CCOPTS = -c -g3 -Wall ${DEFS}

# Pour definir une autre origine de la position du triangle: decommenter
#DEFS= -DORIGINE_Y=300

# La liste des binaires a generer
BINAIRES = triangle creer_boite

# La liste des fichiers objets a generer
#
OBJETS_TRIANGLE = affiche_triangle.o boite_chiffre.o calcul_triangle.o lire_args.o 

OBJETS_BOITE = creer_boite.o boite_chiffre.o lire_args.o


# regle par defaut : un fichiers f.o depend de f.c et f.h plus Makefile (DEFS)
%.o: %.c %.h  Makefile
	${CC} ${CCOPTS} $<



all:		${BINAIRES}

clean:
		/bin/rm -rf  ${OBJETS_TRIANGLE} ${OBJETS_BOITE} ${BINAIRES} triangle_pascal.ps boite.ps



# Les demonstrations

GS = /usr/bin/gs
GV = /usr/bin/gv

demo_gs:	triangle
		echo "demo_gs : "; sleep 2;  ./triangle 10 6 | ${GS} -sDEVICE=x11 -q

demo_gv:	triangle_pascal.ps
		echo "demo_gv : taper q dans gv pour sortir"; 
		${GV} triangle_pascal.ps

triangle_pascal.ps:	triangle
		./triangle 10 6 > triangle_pascal.ps

demo_creer:	creer_boite
		./creer_boite 12 stdout 24 110 14 15 1 1 > boite.ps; ${GV} boite.ps



# Les dependances aux .h specifiques

triangle:	${OBJETS_TRIANGLE} 
		${LD} -o $@ $^ ${LDOPTS}

creer_boite:	${OBJETS_BOITE} 
		${LD} -o $@ $^ ${LDOPTS}


affiche_triangle.o:	boite_chiffre.h calcul_triangle.h lire_args.h length.h

boite_chiffre.o:	lire_args.h length.h

creer_boite.o:		boite_chiffre.h
