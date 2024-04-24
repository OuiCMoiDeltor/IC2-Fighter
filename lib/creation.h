/**
 * @file creation.h
 * @brief Fichier d'en-tête pour la gestion des créations graphiques dans le jeu.
 *
 * Ce fichier contient les définitions des structures et des fonctions nécessaires pour la gestion
 * des textures et des rectangles utilisés dans le jeu. Il fournit des méthodes pour créer, manipuler
 * et détruire des listes de textures et de rectangles, facilitant ainsi la gestion de la mémoire
 * et l'organisation du rendu graphique dans le jeu.
 */

#ifndef _CREATION_H_
#define _CREATION_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 * @struct listeT_t
 * @brief Structure pour la liste de textures.
 *
 * Cette structure permet de gérer une liste de textures SDL pour faciliter leur utilisation
 * et gestion à travers le jeu.
 */

typedef struct listeT_s {
    SDL_Texture **pTexture;
    struct listeT_s *suivant;
}listeT_t;

/**
 * @struct rectangle
 * @brief Structure représentant un rectangle avec des proportions adaptatives par rapport à la taille de la fenêtre.
 *
 * Cette structure stocke les proportions et les dimensions calculées d'un rectangle,
 * qui peut être utilisé pour positionner et redimensionner les éléments graphiques de manière responsive.
 */

typedef struct rectangle_s {
    int *largeur; // Largeur de la fenêtre
    int *hauteur; // Hauteur de la fenêtre
    float ratioX;
    float ratioY;
    float ratioW;
    float ratioH;
    SDL_Rect *rect;
}rectangle;

/**
 * @struct listeRect_s
 * @brief Structure pour la liste de rectangles.
 *
 * Cette structure permet de gérer une liste de rectangles pour organiser et manipuler
 * les positions et tailles des éléments graphiques dans le jeu.
 */

typedef struct listeRect_s {
    rectangle **pRect;
    struct listeRect_s *suivant;
}listeRect;

extern listeT_t *creerListeT(void);
extern void ajoutListeT(listeT_t **,SDL_Texture **);
extern void detruireListeT(listeT_t **);
extern SDL_Texture *creerImage(SDL_Renderer *,char *);
extern SDL_Texture *creerTexte(SDL_Renderer *,TTF_Font *,char *,SDL_Color);
extern listeRect *creerListeRect(void);
extern void ajoutListeRect(listeRect **,rectangle **);
extern void detruireListeRect(listeRect **);
extern void updateRectangles(listeRect *);
extern rectangle *creerRectangle(int *,int *,float,float,float,float);

#endif
