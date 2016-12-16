SHELL=/bin/bash

EXECUTABLES = echoenv exporter

CC = gcc
CFLAGS = -Wall

all:		${EXECUTABLES}

clean:
		/bin/rm -f ${EXECUTABLES} A_LIRE.txt.ps /tmp/A_LIRE.txt


echoenv:	echoenv.c

exporter:	exporter.c

##########################################################################
# Pour la fabrication de l'archive pour le placard

distrib:        A_LIRE.txt.pdf  clean

A_LIRE.txt.pdf: A_LIRE.txt
	cp A_LIRE.txt /tmp/A_LIRE.txt; recode utf8..latin1 /tmp/A_LIRE.txt; a2ps /tmp/A_LIRE.txt -o A_LIRE.txt.ps; ps2pdf A_LIRE.txt.ps
###########################################################################
