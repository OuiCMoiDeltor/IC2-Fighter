/**
 * \file   bouton.c
 * \brief  Gestion des boutons dans l'interface utilisateur
 *
 * Ce fichier contient toutes les fonctions nécessaires pour la création, la gestion et la destruction
 * des boutons utilisés dans l'interface utilisateur du jeu. Il permet de définir les propriétés des
 * boutons tels que leur texture, leur position, leurs états visuels (relâché, appuyé, survolé), ainsi
 * que leur comportement interactif. Les fonctions supportent également la gestion dynamique de plusieurs
 * états pour les boutons animés.
 *
 * \author IC2-Fighter
 * \version 1.0
 * \date 2024
 */

#include <SDL2/SDL.h>
#include "../lib/bouton.h"

/**
 * \brief Crée un bouton avec des propriétés spécifiques.
 *
 * Cette fonction alloue la mémoire pour un nouveau bouton, initialise sa texture à partir d'une image, 
 * et définit ses dimensions et états selon qu'il soit animé ou non. La position et la taille du bouton
 * sont spécifiées par les paramètres de rectangle, et les états du bouton sont gérés en fonction du
 * paramètre 'anime'.
 *
 * \param renderer Pointeur vers le rendu SDL.
 * \param listeRectangle Pointeur vers la liste des rectangles à mettre à jour avec la position du bouton.
 * \param largeur Largeur du bouton (modifiable).
 * \param hauteur Hauteur du bouton (modifiable).
 * \param rX Position X du rectangle du bouton.
 * \param rY Position Y du rectangle du bouton.
 * \param rW Largeur du rectangle du bouton.
 * \param rH Hauteur du rectangle du bouton.
 * \param img Chemin vers l'image à utiliser pour la texture du bouton.
 * \param anime Indique si le bouton doit être animé.
 * \param nbEtat Nombre d'états graphiques du bouton (utilisé pour l'animation).
 * \return Pointeur vers le bouton nouvellement créé ou NULL en cas d'échec.
 */

extern
bouton *creerBouton(SDL_Renderer *renderer, listeRect **listeRectangle, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, char *img, int anime, int nbEtat)
{
    bouton *b = malloc(sizeof(bouton));
    b->texture = creerImage(renderer, img);
    if(b->texture == NULL) {
        free(b);
        b = NULL;
        return (bouton *)NULL;
    }
    b->position = creerRectangle(largeur, hauteur, rX, rY, rW, rH); // affectation de la position (.x et .y) et des dimensions (.w et .h) du bouton
    ajoutListeRect(listeRectangle, &(b->position));

    int image_w, image_h;
    SDL_QueryTexture(b->texture, NULL, NULL, &image_w, &image_h);

    if(anime) {
        b->relache = NULL;
        b->appuye = NULL;
        b->over = NULL;
        
        b->etat = 0;
        b->nbEtat = nbEtat;

        b->frames = malloc(sizeof(SDL_Rect*)*nbEtat);
        for(int i=0; i<nbEtat; i++) {
            b->frames[i] = malloc(sizeof(SDL_Rect));
            b->frames[i]->x = image_w/nbEtat * i;
            b->frames[i]->y = 0;
            b->frames[i]->w = image_w/nbEtat;
            b->frames[i]->h = image_h;
        }
    }else {
        b->relache = malloc(sizeof(SDL_Rect));
        b->appuye = malloc(sizeof(SDL_Rect));
        b->over = malloc(sizeof(SDL_Rect));

        b->nbEtat = NB_ETAT;
        b->etat = BOUTON_RELACHE;

        b->relache->x = 0;
        b->relache->y = 0;
        b->relache->w = image_w/NB_ETAT;
        b->relache->h = image_h;

        b->appuye->x = image_w/NB_ETAT;
        b->appuye->y = 0;
        b->appuye->w = image_w/NB_ETAT;
        b->appuye->h = image_h;

        b->over->x = image_w/NB_ETAT*2;
        b->over->y = 0;
        b->over->w = image_w/NB_ETAT;
        b->over->h = image_h;

        b->frames = NULL;
    }

    return b;
}

/**
 * \brief Détruit un bouton et libère toutes les ressources associées.
 *
 * Cette fonction détruit la texture du bouton, libère les rectangles des états si nécessaire,
 * et libère la structure du bouton elle-même.
 *
 * \param b Pointeur double vers le bouton à détruire.
 */

extern
void DestroyBouton(bouton **b)
{
    SDL_DestroyTexture((*b)->texture); (*b)->texture = NULL;
    if((*b)->frames == NULL) {
        free((*b)->relache); (*b)->relache = NULL;
        free((*b)->appuye); (*b)->appuye = NULL;
        free((*b)->over); (*b)->over = NULL;
    }else {
        for(int i=0; i<((*b)->nbEtat); i++) {
            free((*b)->frames[i]); (*b)->frames[i] = NULL;
        }
        free((*b)->frames); (*b)->frames = NULL;
    }
    free(*b); *b = NULL;
}

/**
 * \brief Crée une liste pour gérer les boutons.
 *
 * Cette fonction alloue et initialise une nouvelle liste de boutons vide.
 *
 * \return Pointeur vers la nouvelle liste de boutons.
 */

extern
listeBouton *creerListeBouton() {
    listeBouton *liste = malloc(sizeof(listeBouton));
    liste->pBouton = NULL;
    liste->suivant = NULL;
    return liste;
}

/**
 * \brief Ajoute un bouton à une liste de boutons.
 *
 * Cette fonction ajoute un bouton à la fin d'une liste circulaire de boutons. 
 * Elle ajuste les pointeurs pour maintenir la structure de la liste.
 *
 * \param liste Double pointeur vers la liste de boutons où ajouter le nouveau bouton.
 * \param Bouton Double pointeur vers le bouton à ajouter à la liste.
 */

extern
void ajoutListeBouton(listeBouton **liste, bouton **Bouton)
{
  if((*liste)->suivant == NULL) {
    (*liste)->pBouton = Bouton;
    (*liste)->suivant = (*liste);
  }
  else {
    listeBouton *new = malloc(sizeof(listeBouton));
    listeBouton *temp = (*liste)->suivant;
    (*liste)->suivant = new;
    (*liste)->suivant->suivant = temp;
    temp = NULL;
    new = NULL;
    (*liste) = (*liste)->suivant;
    (*liste)->pBouton = Bouton;
  }
}

/**
* \brief Détruit une liste de boutons et libère toutes les ressources associées.
*
* Cette fonction parcourt une liste de boutons, détruit chaque bouton et libère la mémoire de la liste.
*
* \param liste Double pointeur vers la liste de boutons à détruire.
*/

extern
void detruireListeBouton(listeBouton **liste)
{
    if(*liste!=NULL) {
        listeBouton *dernier = (*liste);
        (*liste) = (*liste)->suivant;
        listeBouton *temp = (*liste)->suivant;
        while((*liste) != dernier) {
            DestroyBouton((*liste)->pBouton);
            free((*liste));
            (*liste) = temp;
            temp = (*liste)->suivant;
        }
        dernier = NULL;
        temp = NULL;
        DestroyBouton((*liste)->pBouton);
        free((*liste));
        (*liste) = NULL;
    }
}
