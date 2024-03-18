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
        perso->idle[i]->x = 145*i+i;
        perso->idle[i]->y = 0;
        perso->idle[i]->w = 145;
        perso->idle[i]->h = 125;
    }

    perso->walk = malloc(sizeof(SDL_Rect*)*6);
    for( i = 0 ; i < 6 ; i++) {
        perso->walk[i] = malloc(sizeof(SDL_Rect));
        perso->walk[i]->x = 145*i+i;
        perso->walk[i]->y = 126;
        perso->walk[i]->w = 145;
        perso->walk[i]->h = 125;
    }

    perso->speed = 2;

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
void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso1, personnage *perso2, const Uint8 *keyboardState, int largeur, int hauteur) {
    // perso1
    if(!(keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_D] || keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_S])) {
        SDL_RenderCopy(renderer, perso1->texture, perso1->idle[perso1->etatIdle], perso1->pos->rect);
    }else {
        perso1->etatIdle = 0;
        if (keyboardState[SDL_SCANCODE_A]) {
            if ((perso1->pos->rect->x - perso1->speed) > 0)
                perso1->pos->rect->x -= perso1->speed;
            SDL_RenderCopy(renderer, perso1->texture, perso1->walk[perso1->etatWalk], perso1->pos->rect);
        }
        if (keyboardState[SDL_SCANCODE_D]) {
            if ((perso1->pos->rect->x + perso1->speed + 50) <= largeur)
                perso1->pos->rect->x += perso1->speed;
            SDL_RenderCopy(renderer, perso1->texture, perso1->walk[perso1->etatWalk], perso1->pos->rect);
        }
        if (!keyboardState[SDL_SCANCODE_A] && !keyboardState[SDL_SCANCODE_D]) perso1->etatWalk = 0;
        
        if (keyboardState[SDL_SCANCODE_W] && (perso1->pos->rect->y - perso1->speed) > 0) {
            perso1->pos->rect->y -= perso1->speed;
        }
        if (keyboardState[SDL_SCANCODE_S] && (perso1->pos->rect->y + perso1->speed + 50) <= hauteur) {
            perso1->pos->rect->y += perso1->speed;
        }
    }

    // perso2
    if(!(keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_DOWN])) {
        SDL_RenderCopyEx(renderer, perso2->texture, perso2->idle[perso2->etatIdle], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
    }else {
        perso2->etatIdle = 0;
        if (keyboardState[SDL_SCANCODE_LEFT]) {
            if ((perso2->pos->rect->x - perso2->speed) > 0)
                perso2->pos->rect->x -= perso2->speed;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->walk[perso2->etatWalk], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
        }
        if (keyboardState[SDL_SCANCODE_RIGHT]) {
            if ((perso2->pos->rect->x + perso2->speed + 50) <= largeur)
                perso2->pos->rect->x += perso2->speed;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->walk[perso2->etatWalk], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
        }
        if (!keyboardState[SDL_SCANCODE_LEFT] && !keyboardState[SDL_SCANCODE_RIGHT]) perso2->etatWalk = 0;
        
        if (keyboardState[SDL_SCANCODE_UP] && (perso2->pos->rect->y - perso2->speed) > 0) {
            perso2->pos->rect->y -= perso2->speed;
        }
        if (keyboardState[SDL_SCANCODE_DOWN] && (perso2->pos->rect->y + perso2->speed + 50) <= hauteur) {
            perso2->pos->rect->y += perso2->speed;
        }
    }
}
