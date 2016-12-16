SHELL=/bin/bash
CC = gcc
CFLAGS = -Wall

SOURCES=bonjour.c coucou.c beau.c
EXECUTABLES=bonjour coucou beau aurevoir

all:		${SOURCES} ${EXECUTABLES}

clean:		
		/bin/rm -fr ${SOURCES} ${EXECUTABLES} display.o A_LIRE.txt.ps /tmp/A_LIRE.txt

################################################################################
# Construction des sources par susbstitution textuelle

bonjour.c:	modele.c
	cat modele.c | sed -e "s/MESSAGE/Bonjour !/" | sed -e "s/SUIVANT/coucou/" > bonjour.c

coucou.c:	modele.c
	cat modele.c | sed -e "s/MESSAGE/Coucou !/" | sed -e "s/SUIVANT/beau/" > coucou.c

beau.c:	modele.c
		cat modele.c | sed -e "s/MESSAGE/Fait-il beau ?/" | sed -e "s/SUIVANT/aurevoir/" > beau.c
################################################################################


################################################################################
# Construction des executables

bonjour:	bonjour.c display.o

coucou:		coucou.c display.o

beau:		beau.c display.o

aurevoir:	aurevoir.c display.o

################################################################################

################################################################################
# Pour la fabrication du tar a mettre dans le placard
#

distrib:        A_LIRE.txt.pdf  clean

A_LIRE.txt.pdf: A_LIRE.txt
	cp A_LIRE.txt /tmp/A_LIRE.txt; recode utf8..latin1 /tmp/A_LIRE.txt; a2ps /tmp/A_LIRE.txt -o A_LIRE.txt.ps; ps2pdf A_LIRE.txt.ps
################################################################################
