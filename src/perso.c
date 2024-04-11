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
    perso->etatIdle = perso->etatWalk = perso->animation = perso->etatAnimation = perso->canHit = perso->crouching = perso->etatCrouch = 0;

    int i;

    perso->idle = malloc(sizeof(SDL_Rect*)*5);
    for( i = 0 ; i < 5 ; i++) {
        perso->idle[i] = malloc(sizeof(SDL_Rect));
        perso->idle[i]->x = 145*i+i;
        perso->idle[i]->y = 126*0;
        perso->idle[i]->w = 145;
        perso->idle[i]->h = 125;
    }

    perso->walk = malloc(sizeof(SDL_Rect*)*6);
    for( i = 0 ; i < 6 ; i++) {
        perso->walk[i] = malloc(sizeof(SDL_Rect));
        perso->walk[i]->x = 145*i+i;
        perso->walk[i]->y = 126*1;
        perso->walk[i]->w = 145;
        perso->walk[i]->h = 125;
    }

    perso->punchLat = malloc(sizeof(SDL_Rect*)*5);
    for( i = 0 ; i < 5 ; i++) {
        perso->punchLat[i] = malloc(sizeof(SDL_Rect));
        perso->punchLat[i]->x = 145*i+i;
        perso->punchLat[i]->y = 126*2;
        perso->punchLat[i]->w = 145;
        perso->punchLat[i]->h = 125;
    }

    perso->kick = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
        perso->kick[i] = malloc(sizeof(SDL_Rect));
        perso->kick[i]->x = 145*7+7+145*i+i;
        perso->kick[i]->y = 126*2;
        perso->kick[i]->w = 145;
        perso->kick[i]->h = 125;
    }

    perso->punchUp = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
        perso->punchUp[i] = malloc(sizeof(SDL_Rect));
        perso->punchUp[i]->x = 145*9+9+145*i+i;
        perso->punchUp[i]->y = 126*4;
        perso->punchUp[i]->w = 145;
        perso->punchUp[i]->h = 125;
    }

    perso->kickDown = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
        perso->kickDown[i] = malloc(sizeof(SDL_Rect));
        perso->kickDown[i]->x = 145*i+i;
        perso->kickDown[i]->y = 126*5;
        perso->kickDown[i]->w = 145;
        perso->kickDown[i]->h = 125;
    }

    perso->jump = malloc(sizeof(SDL_Rect*)*7);
    for( i = 0 ; i < 7 ; i++) {
        perso->jump[i] = malloc(sizeof(SDL_Rect));
        perso->jump[i]->x = 145*i+i;
        perso->jump[i]->y = 126*6;
        perso->jump[i]->w = 145;
        perso->jump[i]->h = 125;
    }

    perso->moveJump = malloc(sizeof(SDL_Rect*)*8);
    perso->moveJump[0] = malloc(sizeof(SDL_Rect));
    perso->moveJump[0]->x = 0;
    perso->moveJump[0]->y = 126*6;
    perso->moveJump[0]->w = 145;
    perso->moveJump[0]->h = 125;
    for( i = 1 ; i < 8 ; i++) {
        perso->moveJump[i] = malloc(sizeof(SDL_Rect));
        perso->moveJump[i]->x = 145*7+7+145*(i-1)+(i-1);
        perso->moveJump[i]->y = 126*6;
        perso->moveJump[i]->w = 145;
        perso->moveJump[i]->h = 125;
    }

    perso->crouch = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
        perso->crouch[i] = malloc(sizeof(SDL_Rect));
        perso->crouch[i]->x = 145*i+i;
        perso->crouch[i]->y = 126*9;
        perso->crouch[i]->w = 145;
        perso->crouch[i]->h = 125;
    }

    perso->crouchPunch = malloc(sizeof(SDL_Rect*)*2);
    for( i = 0 ; i < 2 ; i++) {
        perso->crouchPunch[i] = malloc(sizeof(SDL_Rect));
        perso->crouchPunch[i]->x = 145*i+i;
        perso->crouchPunch[i]->y = 126*10;
        perso->crouchPunch[i]->w = 145;
        perso->crouchPunch[i]->h = 125;
    }

    perso->crouchKick = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
        perso->crouchKick[i] = malloc(sizeof(SDL_Rect));
        perso->crouchKick[i]->x = 145*i+i;
        perso->crouchKick[i]->y = 126*11;
        perso->crouchKick[i]->w = 145;
        perso->crouchKick[i]->h = 125;
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
        // Coup de peid en bas
        if (keyboardState[SDL_SCANCODE_S] && keyboardState[SDL_SCANCODE_V] && !perso1->crouching) {
            perso1->animation = KICKBAS;
        // Accroupi
        }else if (keyboardState[SDL_SCANCODE_S]) {
            perso1->crouching = 1;
            SDL_RenderCopy(renderer, perso1->texture, perso1->crouch[perso1->etatCrouch], perso1->pos->rect);
            if (perso1->etatCrouch == 2) {
                // Coup de poing
                if (keyboardState[SDL_SCANCODE_C])
                    perso1->animation = POINGACCROUPI;
                // Coup de pied
                else if (keyboardState[SDL_SCANCODE_V])
                    perso1->animation = KICKACCROUPI;
            }
        }else {
            // Coup de poing droit 
            perso1->crouching = 0;
            if (keyboardState[SDL_SCANCODE_C] && !keyboardState[SDL_SCANCODE_W]) {
                perso1->animation = POINGLATERAL;
            // Coup de pied devant
            }else if (keyboardState[SDL_SCANCODE_V]) {
                perso1->animation = KICK;
            // Coup de poing haut 
            }else if (keyboardState[SDL_SCANCODE_C] && keyboardState[SDL_SCANCODE_W]) {
                perso1->animation = POINGHAUT;
            // Saut
            }else if (keyboardState[SDL_SCANCODE_W]) {
                if(keyboardState[SDL_SCANCODE_A]) {
                    perso1->animation = SAUTGAUCHE;
                    perso1->etatAnimation = 7;
                }else if(keyboardState[SDL_SCANCODE_D])
                    perso1->animation = SAUTDROIT;
                else perso1->animation = SAUT;
            // Surplace
            }else if(!(keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_D]) || (keyboardState[SDL_SCANCODE_A] && keyboardState[SDL_SCANCODE_D])) {
                perso1->etatWalk = 0;
                SDL_RenderCopy(renderer, perso1->texture, perso1->idle[perso1->etatIdle], perso1->pos->rect);
            }else {
                perso1->etatIdle = 0;
                // Gauche
                if (keyboardState[SDL_SCANCODE_A]) {
                    if ((perso1->pos->rect->x - perso1->speed) > 0)
                        perso1->pos->rect->x -= perso1->speed;
                }
                // Droite
                if (keyboardState[SDL_SCANCODE_D]) {
                    if ((perso1->pos->rect->x + perso1->speed + 50) <= largeur)
                        perso1->pos->rect->x += perso1->speed;
                }
                if (!keyboardState[SDL_SCANCODE_A] && !keyboardState[SDL_SCANCODE_D]) perso1->etatWalk = 0;
                SDL_RenderCopy(renderer, perso1->texture, perso1->walk[perso1->etatWalk], perso1->pos->rect);
            }
        }
    }else {
        switch(perso1->animation) {
            case POINGLATERAL:
                SDL_RenderCopy(renderer, perso1->texture, perso1->punchLat[perso1->etatAnimation], perso1->pos->rect); break;
            case KICK:
                SDL_RenderCopy(renderer, perso1->texture, perso1->kick[perso1->etatAnimation], perso1->pos->rect); break;
            case POINGHAUT:
                SDL_RenderCopy(renderer, perso1->texture, perso1->punchUp[perso1->etatAnimation], perso1->pos->rect); break;
            case KICKBAS:
                SDL_RenderCopy(renderer, perso1->texture, perso1->kickDown[perso1->etatAnimation], perso1->pos->rect); break;
            case SAUT:
                SDL_RenderCopy(renderer, perso1->texture, perso1->jump[perso1->etatAnimation], perso1->pos->rect); break;
            case POINGACCROUPI:
                SDL_RenderCopy(renderer, perso1->texture, perso1->crouchPunch[perso1->etatAnimation], perso1->pos->rect); break;
            case KICKACCROUPI:
                SDL_RenderCopy(renderer, perso1->texture, perso1->crouchKick[perso1->etatAnimation], perso1->pos->rect); break;
            case SAUTGAUCHE:
                perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->moveJump[perso1->etatAnimation], perso1->pos->rect); break;
            case SAUTDROIT:
                perso1->pos->rect->x += perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->moveJump[perso1->etatAnimation], perso1->pos->rect); break;
        }
    }

    // perso2
    if(!perso2->animation){
        // Coup de peid en bas
        if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_KP_6] && !perso2->crouching) {
            perso2->animation = KICKBAS;
        // Accroupi
        }else if (keyboardState[SDL_SCANCODE_DOWN]) {
            perso2->crouching = 1;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouch[perso2->etatCrouch], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
            if (perso2->etatCrouch == 2) {
                // Coup de poing
                if (keyboardState[SDL_SCANCODE_KP_5])
                    perso2->animation = POINGACCROUPI;
                // Coup de pied
                else if (keyboardState[SDL_SCANCODE_KP_6])
                    perso2->animation = KICKACCROUPI;
            }
        }else {
            perso2->crouching = 0;
            // Coup de poing droit 
            if (keyboardState[SDL_SCANCODE_KP_5] && !keyboardState[SDL_SCANCODE_UP]) {
                perso2->animation = POINGLATERAL;
            // Coup de pied devant
            }else if (keyboardState[SDL_SCANCODE_KP_6]) {
                perso2->animation = KICK;
            // Coup de poing haut 
            }else if (keyboardState[SDL_SCANCODE_KP_5] && keyboardState[SDL_SCANCODE_UP]) {
                perso2->animation = POINGHAUT;
            // Saut
            }else if (keyboardState[SDL_SCANCODE_UP]) {
                if(keyboardState[SDL_SCANCODE_LEFT])
                    perso2->animation = SAUTGAUCHE;
                else if(keyboardState[SDL_SCANCODE_RIGHT]) {
                    perso2->animation = SAUTDROIT;
                    perso2->etatAnimation = 7;
                }else perso2->animation = SAUT;
            // Surplace
            }else if(!(keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_RIGHT]) || (keyboardState[SDL_SCANCODE_LEFT] && keyboardState[SDL_SCANCODE_RIGHT])) {
                perso2->etatWalk = 0;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->idle[perso2->etatIdle], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
            }else {
                perso2->etatIdle = 0;
                // Gauche
                if (keyboardState[SDL_SCANCODE_LEFT]) {
                    if ((perso2->pos->rect->x - perso2->speed) > 0)
                        perso2->pos->rect->x -= perso2->speed;
                }
                // Droite
                if (keyboardState[SDL_SCANCODE_RIGHT]) {
                    if ((perso2->pos->rect->x + perso2->speed + 50) <= largeur)
                        perso2->pos->rect->x += perso2->speed;
                }
                if (!keyboardState[SDL_SCANCODE_LEFT] && !keyboardState[SDL_SCANCODE_RIGHT]) perso2->etatWalk = 0;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->walk[perso2->etatWalk], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
            }
        }
    }else {
        switch(perso2->animation) {
            case POINGLATERAL:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->punchLat[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case KICK:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->kick[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case POINGHAUT:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->punchUp[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case KICKBAS:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->kickDown[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case SAUT:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->jump[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case POINGACCROUPI:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouchPunch[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case KICKACCROUPI:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouchKick[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case SAUTGAUCHE:
                perso2->pos->rect->x -= perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->moveJump[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case SAUTDROIT:
                perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->moveJump[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
        }
    }
}
