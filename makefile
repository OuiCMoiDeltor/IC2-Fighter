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
PROG=prog
LIB=lib/

FICHIERC=${SRC}bouton.c ${SRC}creation.c ${SRC}perso.c ${SRC}main.c

FICHIERH=${LIB}bouton.h ${LIB}creation.h ${LIB}perso.h

all: clean main

main: ${FICHIERC} ${FICHIERH}
	${CC} -o ${PROG} ${FICHIERC} ${FICHIERH} ${LIBS} ${INCLUDES}

PATH:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/SDL2/lib


    clean:
	rm -f ${SRC}*.o
	rm -f ${INCLUDE}*.o
	rm -f *.o
	rm -f ${prog}
