SHELL=/bin/bash
CC = gcc
CFLAGS = -Wall


all:	echo_arg forker

clean:
		/bin/rm -f echo_arg forker A_LIRE.txt.ps /tmp/A_LIRE.txt

##############################################################################
# Fabrication des executables 
##############################################################################

echo_arg:	echo_arg.c

forker:		forker.c

################################################################################
# Pour la fabrication du tar a mettre dans le placard

distrib:        A_LIRE.txt.pdf  clean

A_LIRE.txt.pdf: A_LIRE.txt
	cp A_LIRE.txt /tmp/A_LIRE.txt; recode utf8..latin1 /tmp/A_LIRE.txt; a2ps /tmp/A_LIRE.txt -o A_LIRE.txt.ps; ps2pdf A_LIRE.txt.ps

################################################################################

