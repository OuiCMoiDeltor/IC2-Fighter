/**
 * @file bouton.h
 * @brief En-tête pour la gestion des boutons avec SDL.
 *
 * Ce fichier d'en-tête définit les structures et les fonctions nécessaires pour créer et gérer des boutons interactifs
 * dans une application utilisant la SDL. Les boutons peuvent avoir différents états visuels (relâché, appuyé, survolé)
 * et sont utilisés pour gérer les interactions utilisateur dans l'interface graphique.
 */

#ifndef _BOUTON_H_
#define _BOUTON_H_

#include <SDL2/SDL.h>
#include "creation.h"

#define BOUTON_RELACHE 0
#define BOUTON_APPUYE 1
#define BOUTON_OVER 2
#define NB_ETAT 3
 
/**
 * @struct bouton
 * @brief Structure représentant un bouton interactif.
 *
 * Cette structure contient toutes les informations nécessaires pour afficher et interagir avec un bouton.
 * Elle stocke les textures pour les différents états visuels et la position du bouton à l'écran.
 */

typedef struct bouton_s
{
    SDL_Texture *texture; /** contient la texture des différents aspects du bouton */
    rectangle *position; /** contient la position (.x et .y) et les dimensions (.w et .h) du bouton */
    int etat; /** contient l'état du bouton (BOUTON_RELACHE / BOUTON_APPUYE / BOUTON_OVER) */
    int nbEtat;
    SDL_Rect *relache; /** image du bouton lorsqu'il est relaché */
    SDL_Rect *appuye; /** image du bouton lorsqu'il est appuyé */
    SDL_Rect *over; /** image du bouton lorsqu'il est survolé */
    SDL_Rect **frames;
}bouton;

extern bouton *creerBouton(SDL_Renderer*,listeRect **,int *,int *,float,float,float,float,char*,int,int);
extern void DestroyBouton(bouton**);

/**
 * @struct listeBouton
 * @brief Structure pour une liste de boutons.
 *
 * Cette structure est utilisée pour gérer une liste chaînée de boutons,
 * permettant de stocker et de manipuler plusieurs boutons dans une interface.
 */

typedef struct listeB_s {
    bouton **pBouton;
    struct listeB_s *suivant;
}listeBouton;

extern listeBouton *creerListeBouton();
extern void ajoutListeBouton(listeBouton **liste, bouton **Bouton);
extern void detruireListeBouton(listeBouton **liste);


#endif
