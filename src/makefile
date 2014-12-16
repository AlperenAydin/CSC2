CC     = gcc
CFLAGS = -Wall -Wextra -g -Wno-unused-parameter
LDLIBS = -lm


OBJECT_LOW = coordonnees_plateau.o  orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o poussee.o

OBJECT_HIGH = api_siam.o condition_victoire_partie.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o mode_interactif.o 

OBJECTS  = $(OBJECT_LOW) $(OBJECT_HIGH)

EXEC   = main


all     : $(EXEC)


$(EXEC) : % : %.o $(OBJECTS)
	$(CC)  $^  -o ../bin/jeu_siam


%.o : %.c 
	$(CC) -o $@ -c $< $(CFLAGS)



clean   : 
	rm *.o $(exec)

