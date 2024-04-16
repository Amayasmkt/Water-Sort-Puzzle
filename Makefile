#Cree une variable SRC qui regroupe tout oles fichier .c
SRC = $(wildcard *.c)

#liste de tout les fihcier .o
OBJ = $(SRC:.c=.o)
DEP = $(addprefix build/,$(SRC:.c=.d))

#Cree une variable qui stocke gcc 
CC = gcc

#Cree une variable qui a le nom de l'éxecutable 
EXE = jeu

#Cree une variable qui regroupe l'ensemble de la commande de compilation 
CFLAGS = -std=c99 -Wall -Wextra
LDFLAGS = #~lm

# regle principale: gener l'executable 
$(EXE):$(OBJ)
	@echo "Linking for exe"
	@$(CC) -o $(EXE) $(LDFLAGS) $(OBJ)


# regle generale pour cree un fichier .o a partir d'un fihchier .c
%.o : %.c
	$(CC) -c $< -o $@

#regle generique pour faire du nettoyage
clean:
	rm $(OBJ) $(EXE)

# inclusion automatique du fichier de dependances
-include $(DEP)

# regle generiqye pour gener un archive
#archive:
#	tar zeuf jeu jeu.tgz
#	cd jeu
