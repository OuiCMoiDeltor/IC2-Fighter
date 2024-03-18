#include <SDL2/SDL.h>
#include "../lib/creation.h"
#include "../lib/perso.h"

/**
	* \file  perso.c
	* \brief Programme personnages
	* \author IC2-Fighter
	* \version 1.0
	*
	*  Programme avec les fonctions pour les personnages
	*
*/



/**
	* \fn personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle)
	* \brief  Cette fonction va initialisé le personnage et le créer
	* \param *renderer Permet d'avoir le rendu de l'image
	* \param **listeRectangle 
	* \param *largeur Largeur du personnage
	* \param *hauteur Hauteur du personnage
	* \param rX Position du bouton sur l'axe X
	* \param rY Position du bouton sur l'axe Y
	* \param rW Ratio du bouton en fonction de la taille de l'ecran
	* \param rH Ratio du bouton en fonction de la taille de l'ecran
	* \param *image Adresse et nom de l'image utilisé
	* \return Retourne le perso une fois créé

*/



extern
personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle)
{
    personnage *perso = malloc(sizeof(personnage));
    perso->pos = creerRectangle(largeur, hauteur, rX, rY, rW, rH);
    ajoutListeRect(listeRectangle, &perso->pos);
    perso->texture = creerImage(renderer, image);
    if(perso->texture == NULL) return NULL;
    perso->etatIdle = perso->etatWalk = 0;

    int i;

    perso->idle = malloc(sizeof(SDL_Rect*)*5);
    for( i = 0 ; i < 5 ; i++) {
        perso->idle[i] = malloc(sizeof(SDL_Rect));
        perso->idle[i]->x = 87*i;
        perso->idle[i]->y = 0;
        perso->idle[i]->w = 87;
        perso->idle[i]->h = 104;
    }

    perso->walk = malloc(sizeof(SDL_Rect*)*6);
    for( i = 0 ; i < 6 ; i++) {
        perso->walk[i] = malloc(sizeof(SDL_Rect));
        perso->walk[i]->x = 81*i;
        perso->walk[i]->y = 117;
        perso->walk[i]->w = 81;
        perso->walk[i]->h = 104;
    }

    perso->speed = 1;

    return perso;
}


/**
	* \fn void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso, const Uint8 *keyboardState, int largeur, int hauteur)
	* \brief  Cette fonction va initialisé le personnage et le créer
	* \param *renderer Permet d'avoir le rendu de l'image
	* \param *perso utilise la structure du personnage
	* \param largeur Largeur du personnage
	* \param hauteur Hauteur du personnage
	* \param *keyboardState pour connaitre le statut du bouton appuyer
	* \return Ne retourne rien
*/

extern
void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso, const Uint8 *keyboardState, int largeur, int hauteur) {
    if(!(keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_DOWN])) {
        SDL_RenderCopy(renderer, perso->texture, perso->idle[perso->etatIdle], perso->pos->rect);
    }else {
        perso->etatIdle = 0;
        if (keyboardState[SDL_SCANCODE_LEFT]) {
            if ((perso->pos->rect->x - perso->speed) > 0)
                perso->pos->rect->x -= perso->speed;
            SDL_RenderCopy(renderer, perso->texture, perso->walk[perso->etatWalk], perso->pos->rect);
        }
        if (keyboardState[SDL_SCANCODE_RIGHT]) {
            if ((perso->pos->rect->x + perso->speed + 50) <= largeur)
                perso->pos->rect->x += perso->speed;
            SDL_RenderCopy(renderer, perso->texture, perso->walk[perso->etatWalk], perso->pos->rect);
        }
        if (!(keyboardState[SDL_SCANCODE_LEFT]) && !keyboardState[SDL_SCANCODE_RIGHT]) perso->etatWalk = 0;
        
        if (keyboardState[SDL_SCANCODE_UP] && (perso->pos->rect->y - perso->speed) > 0) {
            perso->pos->rect->y -= perso->speed;
        }
        if (keyboardState[SDL_SCANCODE_DOWN] && (perso->pos->rect->y + perso->speed + 50) <= hauteur) {
            perso->pos->rect->y += perso->speed;
        }
    }
}
