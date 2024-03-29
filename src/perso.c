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
    perso->etatIdle = perso->etatWalk = perso->animation = perso->etatAnimation = perso->canHit = 0;

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

    perso->punch = malloc(sizeof(SDL_Rect*)*5);
    for( i = 0 ; i < 5 ; i++) {
        perso->punch[i] = malloc(sizeof(SDL_Rect));
        perso->punch[i]->x = 145*i+i;
        perso->punch[i]->y = 252;
        perso->punch[i]->w = 145;
        perso->punch[i]->h = 125;
    }

    perso->kick = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
        perso->kick[i] = malloc(sizeof(SDL_Rect));
        perso->kick[i]->x = 145*7+7+145*i+i;
        perso->kick[i]->y = 252;
        perso->kick[i]->w = 145;
        perso->kick[i]->h = 125;
    }

    perso->speed = *largeur/250;

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
    if(!perso1->animation){
        // Coup poing droit 
        if (keyboardState[SDL_SCANCODE_C]) {
            perso1->animation = POINGGAUCHE;
        }else if (keyboardState[SDL_SCANCODE_V]) {
            perso1->animation = KICK;
        // Surplace
        }else if(!(keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_D] || keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_S])) {
            perso1->etatWalk = 0;
            SDL_RenderCopy(renderer, perso1->texture, perso1->idle[perso1->etatIdle], perso1->pos->rect);
        }else {
            perso1->etatIdle = 0;
            // Gauche
            if (keyboardState[SDL_SCANCODE_A]) {
                if ((perso1->pos->rect->x - perso1->speed) > 0)
                    perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->walk[perso1->etatWalk], perso1->pos->rect);
            }
            // Droite
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
    }else {
        switch(perso1->animation) {
            case POINGGAUCHE:
                SDL_RenderCopy(renderer, perso1->texture, perso1->punch[perso1->etatAnimation], perso1->pos->rect); break;
            case KICK:
                SDL_RenderCopy(renderer, perso1->texture, perso1->kick[perso1->etatAnimation], perso1->pos->rect); break;
        }
    }

    // perso2
    if(!perso2->animation){
        // Coup poing droit 
        if (keyboardState[SDL_SCANCODE_KP_5]) {
            perso2->animation = POINGGAUCHE;
        }else if (keyboardState[SDL_SCANCODE_KP_6]) {
            perso2->animation = KICK;
        // Surplace
        }else if(!(keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_DOWN])) {
            perso2->etatWalk = 0;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->idle[perso2->etatIdle], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
        }else {
            perso2->etatIdle = 0;
            // Gauche
            if (keyboardState[SDL_SCANCODE_LEFT]) {
                if ((perso2->pos->rect->x - perso2->speed) > 0)
                    perso2->pos->rect->x -= perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->walk[perso2->etatWalk], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
            }
            // Droite
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
    }else {
        switch(perso2->animation) {
            case POINGGAUCHE:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->punch[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case KICK:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->kick[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
        }
    }
}
