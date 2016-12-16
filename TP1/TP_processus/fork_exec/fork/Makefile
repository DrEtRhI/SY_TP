SHELL=/bin/bash
CC = gcc
CFLAGS = -Wall

EXECUTABLES= coucou coucou2 descoucous


all:	${EXECUTABLES}

clean:	
	/bin/rm -f ${EXECUTABLES} A_LIRE.txt.ps /tmp/A_LIRE.txt

###########################################################################
# Fabrication des fichiers executables
	
coucou:	coucou_pere_fils.c
	${CC} ${CFLAGS} -o coucou coucou_pere_fils.c

coucou2: coucou2_pere_fils.c
	${CC} ${CFLAGS} -o coucou2 coucou2_pere_fils.c

descoucous: descoucous.c descoucous.h message.c
	${CC} ${CFLAGS} -o descoucous descoucous.c message.c
###########################################################################

###########################################################################
# Pour la fabrication de l'archive pour le placard
#
distrib:	A_LIRE.txt.pdf	clean

A_LIRE.txt.pdf:	A_LIRE.txt
	        cp A_LIRE.txt /tmp/A_LIRE.txt; recode utf8..latin1 /tmp/A_LIRE.txt; a2ps /tmp/A_LIRE.txt -o A_LIRE.txt.ps; ps2pdf A_LIRE.txt.ps
###########################################################################
