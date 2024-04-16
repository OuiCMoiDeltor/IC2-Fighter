#include <SDL2/SDL.h>
#include "../lib/creation.h"
#include "../lib/perso.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>


#define VIE_MAX 100
#define DMG 5

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
    perso->etatIdle = perso->etatWalk = perso->animation = perso->etatAnimation = perso->canHit = perso->crouching = perso->etatCrouch = perso->reverseIdle = perso->reverseWalk = 0;

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

    perso->block = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
        perso->block[i] = malloc(sizeof(SDL_Rect));
        perso->block[i]->x = 145*4+4+145*i+i;
        perso->block[i]->y = 126*5;
        perso->block[i]->w = 145;
        perso->block[i]->h = 125;
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

    perso->standHurt = malloc(sizeof(SDL_Rect*)*2);
    for( i = 0 ; i < 3 ; i++) {
        perso->standHurt[i] = malloc(sizeof(SDL_Rect));
        perso->standHurt[i]->x = 145*i+i;
        perso->standHurt[i]->y = 126*16;
        perso->standHurt[i]->w = 145;
        perso->standHurt[i]->h = 125;
    }

    perso->jumpHurt = malloc(sizeof(SDL_Rect*)*2);
    for( i = 0 ; i < 3 ; i++) {
        perso->jumpHurt[i] = malloc(sizeof(SDL_Rect));
        perso->jumpHurt[i]->x = 145*6+6+145*i+i;
        perso->jumpHurt[i]->y = 126*16;
        perso->jumpHurt[i]->w = 145;
        perso->jumpHurt[i]->h = 125;
    }

    perso->crouchHurt = malloc(sizeof(SDL_Rect*)*2);
    for( i = 0 ; i < 3 ; i++) {
        perso->crouchHurt[i] = malloc(sizeof(SDL_Rect));
        perso->crouchHurt[i]->x = 145*3+3+145*i+i;
        perso->crouchHurt[i]->y = 126*18;
        perso->crouchHurt[i]->w = 145;
        perso->crouchHurt[i]->h = 125;
    }

    perso->speed = *largeur/250;

    //Création barre de vie
    perso->hp = malloc(sizeof(pv_t));
    perso->hp->pv = VIE_MAX;
    perso->hp->barrePv = malloc(sizeof(SDL_Rect));
    perso->hp->barrePv->x = 100/8;
    perso->hp->barrePv->y = 100/2;
    perso->hp->barrePv->w = 550;
    perso->hp->barrePv->h = 35;
    
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
void mettreAJourHp(SDL_Renderer *renderer, personnage * perso, int degat, int persoID) {
    Mix_Chunk *soundDMG = Mix_LoadWAV("mixer/ouh.wav");
    Mix_VolumeChunk(soundDMG, MIX_MAX_VOLUME / 3);
    SDL_Log("%d", perso->hp->pv);  // Affiche les points de vie restants pour le test
    perso->hp->pv = perso->hp->pv - degat < 0 ? 0 : perso->hp->pv - degat;  // Réduit la vie sans descendre en dessous de 0

    // Calcule la nouvelle largeur de la barre de vie en fonction des points de vie actuels
    int newWidth = 550 * perso->hp->pv / VIE_MAX;

    // Comportement inversé (réduction de droite à gauche) pour perso2
    if (persoID == 1) {
        int deltaX = perso->hp->barrePv->w - newWidth;
        perso->hp->barrePv->x += deltaX;
        perso->hp->barrePv->w = newWidth;
    } else {
        
        perso->hp->barrePv->w = newWidth;  
    }

    Mix_PlayChannel(-1, soundDMG, 0);

    SDL_Delay(100);
}





extern
void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso1, personnage *perso2, const Uint8 *keyboardState, int largeur, int hauteur, int * framerate) {
    /*Test avant que Quentin commence à crier, fonctionne mais comme ttf charge en boucle lors d'appel -> jeu tres ralenti*/
    /*
    TTF_Font *font = TTF_OpenFont("ttf/Act_Of_Rejection.ttf", 32);
    SDL_Color textColor = {255, 255, 255, 255}; 
    SDL_Surface *surfaceJ1 = TTF_RenderText_Solid(font, "CACAPAGNAN", textColor);
    SDL_Texture *textureJ1 = SDL_CreateTextureFromSurface(renderer, surfaceJ1);
    SDL_Rect textRectJ1 = {100/8, 100/16, surfaceJ1->w, surfaceJ1->h};

    SDL_RenderCopy(renderer, textureJ1, NULL, &textRectJ1);
    SDL_DestroyTexture(textureJ1);
    SDL_FreeSurface(surfaceJ1);

    SDL_Surface *surface = TTF_RenderText_Solid(font, "easy", textColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect textRect = {720, 100/16, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &textRect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    */
    Mix_Chunk *soundHIT = Mix_LoadWAV("mixer/hit.wav") ;
    Mix_VolumeChunk(soundHIT, MIX_MAX_VOLUME / 8);
    // Gestion dégats J1
    if (keyboardState[SDL_SCANCODE_P]) {
        perso1->etatAnimation = 0;
        perso1->canHit = 0;
        if(perso1->blocking) {
            perso1->etatAnimation = 1;
            perso1->animation = PARADE;
            mettreAJourHp(renderer, perso1, DMG / 2, 1) ;
        }else if(perso1->animation == SAUT) {
            perso1->animation = DEGATSAUT;
            mettreAJourHp(renderer, perso1, DMG, 1) ;
        }else if(perso1->crouching) {
            perso1->animation = DEGATACCROUPI;
            mettreAJourHp(renderer, perso1, DMG, 1) ; 
        }else {
            perso1->animation = DEGAT;
            mettreAJourHp(renderer, perso1, DMG, 1) ;
        }
    }

    //Barre de vie à états, changement de sa couleur en fonction des points de vie restants
    if (perso1->hp->pv > 80) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Vert
    } else if (perso1->hp->pv > 60) {
        SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255);  // Vert clair
    } else if (perso1->hp->pv > 40) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Jaune
    } else if (perso1->hp->pv > 20) {
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);  // Orange
    } else {
        SDL_SetRenderDrawColor(renderer, 220, 20, 60, 255);  // Rouge
    }
    SDL_RenderFillRect(renderer, perso1->hp->barrePv);
    //Condition à compléter lorsque écran rematch fait
    if (perso1->hp->pv <= 0) {
    fprintf(stderr, "Plus de vie. \n");
    }

    // Positionnement barre de vie perso2
    perso2->hp->barrePv->x = 720;
    perso2->hp->barrePv->y = 100 / 2;

    // Gestion dégats J2
    if (keyboardState[SDL_SCANCODE_O]) {
        perso2->etatAnimation = 0;
        perso2->canHit = 0;
        if(perso2->blocking) {
            perso2->etatAnimation = 1;
            perso2->animation = PARADE;
            mettreAJourHp(renderer, perso2, DMG / 2, 2) ;
        }else if(perso2->animation == SAUT) {
            perso2->animation = DEGATSAUT;
            mettreAJourHp(renderer, perso2, DMG, 2) ;
        }else if(perso2->crouching) {
            perso2->animation = DEGATACCROUPI;
            mettreAJourHp(renderer, perso2, DMG, 2) ;
        }else {
            perso2->animation = DEGAT;
            mettreAJourHp(renderer, perso2, DMG, 2) ;
        }
    }

    //Barre de vie à états, changement de sa couleur en fonction des points de vie restants
    if (perso2->hp->pv > 80) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Vert
    } else if (perso2->hp->pv > 60) {
        SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255);  // Vert clair
    } else if (perso2->hp->pv > 40) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Jaune
    } else if (perso2->hp->pv > 20) {
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);  // Orange
    } else {
        SDL_SetRenderDrawColor(renderer, 220, 20, 60, 255);  // Rouge
    }
    SDL_RenderFillRect(renderer, perso2->hp->barrePv);
    //Condition à compléter lorsque écran rematch fait
    if (perso2->hp->pv <= 0) {
    fprintf(stderr, "Plus de vie. \n");
    }

    // Animations des actions
    if(*framerate > 10) {
        // Joueur 1
        if(!perso1->reverseIdle) {
                perso1->etatIdle = ++perso1->etatIdle;
                if(perso1->etatIdle == 5) {
                        perso1->reverseIdle = 1;
                        perso1->etatIdle = 3;
                }
        }else {
                perso1->etatIdle = --perso1->etatIdle;
                if(perso1->etatIdle == -1) {
                        perso1->reverseIdle = 0;
                        perso1->etatIdle = 1;
                }
        }
        if(!perso1->reverseWalk) {
                perso1->etatWalk = ++perso1->etatWalk;
                if(perso1->etatWalk == 6) {
                        perso1->reverseWalk = 1;
                        perso1->etatWalk = 4;
                }
        }else {
                perso1->etatWalk = --perso1->etatWalk;
                if(perso1->etatWalk == -1) {
                        perso1->reverseWalk = 0;
                        perso1->etatWalk = 1;
                }
        }
        if(perso1->crouching) {
                if(perso1->etatCrouch < 2)
                        perso1->etatCrouch++;
        }else {
                perso1->etatCrouch = 0;
        }
        if(perso1->animation) {
                switch(perso1->animation) {
                        case POINGLATERAL:
                                        if(perso1->etatAnimation == 3)
                                                perso1->canHit = 1;
                                        if(perso1->etatAnimation < 4) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->canHit = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case KICK:
                        case POINGHAUT:
                        case KICKBAS:
                        case KICKACCROUPI:
                                        if(perso1->etatAnimation == 1)
                                                perso1->canHit = 1;
                                        if(perso1->etatAnimation < 2) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->canHit = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case PARADE:
                                        if(perso1->etatAnimation < 2) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case SAUT:
                                        if(perso1->etatAnimation < 6) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case SAUTGAUCHE:
                                        if(perso1->etatAnimation > 0) {
                                                perso1->etatAnimation--;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case SAUTDROIT:
                                        if(perso1->etatAnimation < 7) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case POINGACCROUPI:
                                        if(perso1->etatAnimation == 1)
                                                perso1->canHit = 1;
                        case DEGAT:
                        case DEGATACCROUPI:
                        case DEGATSAUT:
                                        if(perso1->etatAnimation < 1) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->canHit = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                }
        }

        // Joueur 2
        if(!perso2->reverseIdle) {
                perso2->etatIdle = ++perso2->etatIdle;
                if(perso2->etatIdle == 5) {
                        perso2->reverseIdle = 1;
                        perso2->etatIdle = 3;
                }
        }else {
                perso2->etatIdle = --perso2->etatIdle;
                if(perso2->etatIdle == -1) {
                        perso2->reverseIdle = 0;
                        perso2->etatIdle = 1;
                }
        }
        if(!perso2->reverseWalk) {
                perso2->etatWalk = ++perso2->etatWalk;
                if(perso2->etatWalk == 6) {
                        perso2->reverseWalk = 1;
                        perso2->etatWalk = 4;
                }
        }else {
                perso2->etatWalk = --perso2->etatWalk;
                if(perso2->etatWalk == -1) {
                        perso2->reverseWalk = 0;
                        perso2->etatWalk = 1;
                }
        }
        if(perso2->crouching) {
                if(perso2->etatCrouch < 2)
                        perso2->etatCrouch++;
        }else {
                perso2->etatCrouch = 0;
        }
        if(perso2->animation) {
                switch(perso2->animation) {
                        case POINGLATERAL:
                                        if(perso2->etatAnimation == 3)
                                                perso2->canHit = 1;
                                        if(perso2->etatAnimation < 4) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->canHit = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case KICK:
                        case POINGHAUT:
                        case KICKBAS:
                        case KICKACCROUPI:
                                        if(perso2->etatAnimation == 1)
                                                perso2->canHit = 1;
                                        if(perso2->etatAnimation < 2) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->canHit = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case PARADE:
                                        if(perso2->etatAnimation < 2) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case SAUT:
                                        if(perso2->etatAnimation < 6) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case SAUTDROIT:
                                        if(perso2->etatAnimation > 0) {
                                                perso2->etatAnimation--;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case SAUTGAUCHE:
                                        if(perso2->etatAnimation < 7) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case POINGACCROUPI:
                                        if(perso2->etatAnimation == 1)
                                                perso2->canHit = 1;
                        case DEGAT:
                        case DEGATACCROUPI:
                        case DEGATSAUT:
                                        if(perso2->etatAnimation < 1) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->canHit = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                }
        }

        *framerate = 0;
    }

    // perso1
    if(!perso1->animation){
        perso1->blocking = 0;
        // Parade
        if(keyboardState[SDL_SCANCODE_F] && !perso1->crouching) {
            perso1->blocking = 1;
            SDL_RenderCopy(renderer, perso1->texture, perso1->block[0], perso1->pos->rect);
        // Coup de peid en bas
        }else if (keyboardState[SDL_SCANCODE_S] && keyboardState[SDL_SCANCODE_V] && !perso1->crouching) {
            perso1->animation = KICKBAS;
            Mix_PlayChannel(-1, soundHIT, 0);
        // Accroupi
        }else if (keyboardState[SDL_SCANCODE_S]) {
            perso1->crouching = 1;
            SDL_RenderCopy(renderer, perso1->texture, perso1->crouch[perso1->etatCrouch], perso1->pos->rect);
            if (perso1->etatCrouch == 2) {
                // Coup de poing
                if (keyboardState[SDL_SCANCODE_C]) {
                    perso1->animation = POINGACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
                // Coup de pied
                else if (keyboardState[SDL_SCANCODE_V]) {
                    perso1->animation = KICKACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
            }
        }else {
            // Coup de poing droit 
            perso1->crouching = 0;
            if (keyboardState[SDL_SCANCODE_C] && !keyboardState[SDL_SCANCODE_W]) {
                perso1->animation = POINGLATERAL;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de pied devant
            }else if (keyboardState[SDL_SCANCODE_V]) {
                perso1->animation = KICK;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de poing haut 
            }else if (keyboardState[SDL_SCANCODE_C] && keyboardState[SDL_SCANCODE_W]) {
                perso1->animation = POINGHAUT;
                Mix_PlayChannel(-1, soundHIT, 0);;
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
            case PARADE:
                perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->block[perso1->etatAnimation], perso1->pos->rect); break;
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
            case DEGAT:
                perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->standHurt[perso1->etatAnimation], perso1->pos->rect); break;
            case DEGATACCROUPI:
                perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->crouchHurt[perso1->etatAnimation], perso1->pos->rect); break;
            case DEGATSAUT:
                perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->jumpHurt[perso1->etatAnimation], perso1->pos->rect); break;
        }
    }

    // perso2
    if(!perso2->animation){
        perso2->blocking = 0;
        // Parade
        if(keyboardState[SDL_SCANCODE_KP_4] && !perso2->crouching) {
            perso2->blocking = 1;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->block[0], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
        // Coup de peid en bas
        }else if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_KP_6] && !perso2->crouching) {
            perso2->animation = KICKBAS;
            Mix_PlayChannel(-1, soundHIT, 0);
        // Accroupi
        }else if (keyboardState[SDL_SCANCODE_DOWN]) {
            perso2->crouching = 1;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouch[perso2->etatCrouch], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
            if (perso2->etatCrouch == 2) {
                // Coup de poing
                if (keyboardState[SDL_SCANCODE_KP_5]) {
                    perso2->animation = POINGACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
                // Coup de pied
                else if (keyboardState[SDL_SCANCODE_KP_6]) {
                    perso2->animation = KICKACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
            }
        }else {
            perso2->crouching = 0;
            // Coup de poing droit 
            if (keyboardState[SDL_SCANCODE_KP_5] && !keyboardState[SDL_SCANCODE_UP]) {
                perso2->animation = POINGLATERAL;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de pied devant
            }else if (keyboardState[SDL_SCANCODE_KP_6]) {
                perso2->animation = KICK;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de poing haut 
            }else if (keyboardState[SDL_SCANCODE_KP_5] && keyboardState[SDL_SCANCODE_UP]) {
                perso2->animation = POINGHAUT;
                Mix_PlayChannel(-1, soundHIT, 0);
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
            case PARADE:
                perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->block[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
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
            case DEGAT:
                perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->standHurt[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case DEGATACCROUPI:
                perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouchHurt[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case DEGATSAUT:
                perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->jumpHurt[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
        }
    }
}


