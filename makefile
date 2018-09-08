CC=gcc
CFLAGS=-pipe -ansi -W -Wall -Wextra -Wpadded -pedantic -fmessage-length=0 -fstack-protector-strong
LDFLAGS=-pipe
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
DEP=$(wildcard *.h)
DEBUG=
EXEC=graphe

ifeq ($(DEBUG), yes)
	CFLAGS += -g3
else
	CFLAGS += -O2 -ftree-vectorize
endif

all: clean depend $(EXEC)

$(EXEC):	$(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

depend:
	@makedepend -- $(CXXFLAGS) -- -Y $(SRC) 2> /dev/null

.PHONY: clean mrproper
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
# DO NOT DELETE

algo_parcours.o: algo_parcours.h graphe.h liste_adjacence.h
algo_parcours.o: cellule_adjacence.h listeIncidence.h celluleIncidence.h
algo_parcours.o: arete.h cellEnsemble.h ensemble.h file.h filePrioriteMin.h
algo_parcours.o: outilsGraphe.h tas.h tri.h
arete.o: arete.h
outilsListe.o: outilsListe.h liste_adjacence.h cellule_adjacence.h
outilsListe.o: listeIncidence.h celluleIncidence.h arete.h
ensemble.o: ensemble.h cellEnsemble.h
file.o: file.h
outilsGraphe.o: outilsGraphe.h algo_parcours.h graphe.h liste_adjacence.h
outilsGraphe.o: cellule_adjacence.h listeIncidence.h celluleIncidence.h
outilsGraphe.o: arete.h
tas.o: tas.h arete.h util.h algo_parcours.h graphe.h liste_adjacence.h
tas.o: cellule_adjacence.h listeIncidence.h celluleIncidence.h
util.o: util.h algo_parcours.h graphe.h liste_adjacence.h cellule_adjacence.h
util.o: listeIncidence.h celluleIncidence.h arete.h
cellEnsemble.o: cellEnsemble.h ensemble.h
graphe.o: graphe.h liste_adjacence.h cellule_adjacence.h listeIncidence.h
graphe.o: celluleIncidence.h arete.h outilsListe.h
main.o: algo_parcours.h graphe.h liste_adjacence.h cellule_adjacence.h
main.o: listeIncidence.h celluleIncidence.h arete.h
filePrioriteMin.o: filePrioriteMin.h algo_parcours.h graphe.h
filePrioriteMin.o: liste_adjacence.h cellule_adjacence.h listeIncidence.h
filePrioriteMin.o: celluleIncidence.h arete.h util.h
liste_adjacence.o: liste_adjacence.h cellule_adjacence.h
tri.o: tri.h tas.h arete.h util.h algo_parcours.h graphe.h liste_adjacence.h
tri.o: cellule_adjacence.h listeIncidence.h celluleIncidence.h
listeIncidence.o: listeIncidence.h celluleIncidence.h arete.h
cellule_adjacence.o: cellule_adjacence.h
celluleIncidence.o: celluleIncidence.h arete.h
