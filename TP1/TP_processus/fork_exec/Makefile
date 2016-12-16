SHELL=/bin/bash

#	tar cvf ../Placard/TP_processus/tp.tar A_LIRE.* exec fork forkecho forkps env; cp A_LIRE.txt.pdf ../Placard/TP_processus

all:	local gen_exec gen_fork gen_forkecho gen_forkps gen_env	
	pushd ..; tar cvf Placard/TP_processus/tp.tar fork_exec; popd; cp A_LIRE.txt.pdf ../Placard/TP_processus

local:	A_LIRE.txt.pdf
	/bin/rm -rf A_LIRE.txt.ps /tmp/A_LIRE.txt

A_LIRE.txt.pdf:	A_LIRE.txt
	cp A_LIRE.txt /tmp/A_LIRE.txt; recode utf8..latin1 /tmp/A_LIRE.txt; a2ps /tmp/A_LIRE.txt -o A_LIRE.txt.ps; ps2pdf A_LIRE.txt.ps
	
gen_exec:	
	pushd exec; make distrib; popd

gen_fork:	
	pushd fork; make distrib; popd

gen_forkecho:	
	pushd forkecho; make distrib; popd

gen_forkps:	
	pushd forkps; make distrib; popd

gen_env:	
	pushd env; make distrib; popd

