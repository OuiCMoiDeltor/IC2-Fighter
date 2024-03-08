#include <SDL2/SDL.h>
#include "creation.h"

#define BOUTON_RELACHE 0
#define BOUTON_APPUYE 1
#define BOUTON_OVER 2
#define NB_ETAT 3
 
// Structure contenant les informations sur le bouton
typedef struct bouton_s
{
    SDL_Texture *texture; // contient la texture des différents aspects du bouton
    rectangle *position; // contient la position (.x et .y) et les dimensions (.w et .h) du bouton
    int etat; // contient l'état du bouton (BOUTON_RELACHE / BOUTON_APPUYE / BOUTON_OVER)
    int nbEtat;
    SDL_Rect *relache; // image du bouton lorsqu'il est relaché
    SDL_Rect *appuye; // image du bouton lorsqu'il est appuyé
    SDL_Rect *over; // image du bouton lorsqu'il est survolé
    SDL_Rect **frames;
}bouton;

extern bouton *creerBouton(SDL_Renderer*,listeRect **,int *,int *,float,float,float,float,char*,int,int);
extern void DestroyBouton(bouton**);