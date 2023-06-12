# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Répertoire des sources
SRC_DIR = src

# Noms des fichiers source (tous les fichiers .c dans le répertoire src)
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Noms des fichiers objets générés
OBJECTS = $(SOURCES:.c=.o)

# Nom de l'exécutable
EXECUTABLE = woody_woodpacker

# Règle par défaut
all: $(EXECUTABLE)
	@rm -f $(SOURCES:.c=.o)

# Règle de compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de construction de l'exécutable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

re : clean all

# Règle de nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(EXECUTABLE)

push:
	git add .
	git commit -m "update"
	git push origin master
