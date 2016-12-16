SHELL=/bin/bash
all:	monps

monps:	monps.c
	gcc -Wall -o monps monps.c

clean:	
	/bin/rm -f monps A_LIRE.txt.ps /tmp/A_LIRE.txt

###########################################################################
# Pour la fabrication de l'archive pour le placard

distrib:        A_LIRE.txt.pdf  clean

A_LIRE.txt.pdf: A_LIRE.txt
	cp A_LIRE.txt /tmp/A_LIRE.txt; recode utf8..latin1 /tmp/A_LIRE.txt; a2ps /tmp/A_LIRE.txt -o A_LIRE.txt.ps; ps2pdf A_LIRE.txt.ps
###########################################################################
