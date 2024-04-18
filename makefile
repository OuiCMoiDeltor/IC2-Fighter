CC=gcc
CCO=gcc
FLAGS=-Wall -g
SDL_DIR=lib/SDL2
EXECU_DIR=bin
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include
SDL_DIR=${HOME}/SDL2
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm
INCLUDES=-I${SDLINC_DIR}

INCLUDE=include/
SRC=src/
PROG=IC2Fighter
LIB=lib/

FICHIERC=${SRC}bouton.c ${SRC}creation.c ${SRC}perso.c ${SRC}combat.c ${SRC}touches.c ${SRC}controle.c ${SRC}options.c ${SRC}menu_principal.c ${SRC}gamemode_selection.c ${SRC}champ_select.c ${SRC}main.c

FICHIERH=${LIB}bouton.h ${LIB}creation.h ${LIB}perso.h ${LIB}combat.h ${LIB}touches.h ${LIB}controle.h ${LIB}options.h ${LIB}menu_principal.h ${LIB}gamemode_selection.h ${LIB}champ_select.h

all: main

main: ${FICHIERC} ${FICHIERH}
	${CC} -o ${PROG} ${FICHIERC} ${FICHIERH} ${LIBS} ${INCLUDES}

PATH:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/SDL2/lib


clean:
	rm -f ${SRC}*.o
	rm -f ${INCLUDE}*.o
	rm -f *.o
	rm -f ${PROG}

exe: clean all
	./${PROG}
