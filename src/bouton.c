#include <SDL2/SDL.h>
#include "../lib/bouton.h"


/**
	* \file  bouton.c
	* \brief Programme pour les différents boutons
	* \author IC2-Fighter
	* \version 1.0
	*
	*  Programme avec les fonctions pour l'initialisation des boutons
	*
*/



/**
	* \fn bouton *creerBouton(SDL_Renderer *renderer, listeRect **listeRectangle, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, char *img, int anime, int nbEtat)
	* \brief  Cette fonction va initialisé le bouton et créer le bouton
	* \param *renderer Permet d'avoir le rendu de l'image
	* \param **listeRectangle 
	* \param *largeur Largeur du bouton
	* \param *hauteur Hauteur du bouton
	* \param rX Position du bouton sur l'axe X
	* \param rY Position du bouton sur l'axe Y
	* \param rW Ratio du bouton en fonction de la taille de l'ecran
	* \param rH Ratio du bouton en fonction de la taille de l'ecran
	* \param *img Adresse et nom de l'image utilisé
	* \param anime Définit si le bouton est animé ou pas
	* \param nbEtat Permet de changer le bouton quand on survole ou on clique dessus
	* \return Retourne le bouton une fois créé

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
	* \fn void DestroyBouton(bouton **b)
	* \brief  Cette fonction va supprimer le bouton 
	* \param **b Bouton que l'on veut supprimer
	* \return Ne Retourne rien

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
