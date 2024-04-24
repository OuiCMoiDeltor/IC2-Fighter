/**
 * @file perso.c
 * @brief Fichier contenant les fonctions de gestion des personnages dans le jeu.
 *
 * Ce fichier implémente les fonctions nécessaires pour créer, mettre à jour et détruire les personnages
 * dans le jeu, en gérant les textures, animations et interactions de ces derniers.
 */

#include <SDL2/SDL.h>
#include "../lib/creation.h"
#include "../lib/perso.h"
#include "../lib/touches.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#define TTF_FONT "ttf/Act_Of_Rejection.ttf"
#define DMG 10

/**
 * @brief Crée un nouveau personnage avec des animations définies.
 *
 * Cette fonction initialise un personnage, y compris sa position, sa texture,
 * et ses animations. Elle prépare également les rectangles SDL pour chaque frame d'animation.
 *
 * @param renderer Pointeur vers le renderer SDL utilisé pour le dessin.
 * @param image Chemin vers le fichier d'image à utiliser pour la texture du personnage.
 * @param largeur Pointeur vers la largeur de la fenêtre du jeu.
 * @param hauteur Pointeur vers la hauteur de la fenêtre du jeu.
 * @param rX Coordonnée X de la position relative du personnage.
 * @param rY Coordonnée Y de la position relative du personnage.
 * @param rW Largeur relative du personnage.
 * @param rH Hauteur relative du personnage.
 * @param listeRectangle Liste des rectangles pour la gestion des collisions et interactions.
 * @return Un pointeur vers la structure `personnage` nouvellement créée, ou NULL en cas d'erreur.
 */

extern
personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle)
{
    personnage *perso = malloc(sizeof(personnage));
    perso->pos = creerRectangle(largeur, hauteur, rX, rY, rW, rH);
    perso->texture = creerImage(renderer, image);
    if(perso->texture == NULL) return NULL;
    perso->etatIdle = perso->etatWalk = perso->animation = perso->etatAnimation = perso->crouching = perso->etatCrouch = perso->reverseIdle = perso->reverseWalk = perso->stunned = perso->etatStun = 0;

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

    perso->punchLat = malloc(sizeof(SDL_Rect*)*3);
    for( i = 0 ; i < 3 ; i++) {
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
    perso->hp->barrePv = malloc(sizeof(SDL_Rect));
    perso->hp->barrePv->x = 0;
    perso->hp->barrePv->y = 0;
    perso->hp->barrePv->w = 0;
    perso->hp->barrePv->h = 0;
    
    perso->pseudo = malloc(sizeof(pseudo_t));
    perso->pseudo->txt = NULL;
    perso->pseudo->rect = creerRectangle(largeur, hauteur, 100.0, 100.0, 100/20.0, 15.0);

    perso->hitBox = creerRectangle(largeur, hauteur, rX, rY, rW, rH);
    perso->hitBox->rect->w = (perso->pos->rect->w / 145) * 62.0;
    perso->hitBox->rect->h = (perso->pos->rect->h / 126) * 128.0;

    perso->hurtBox = creerRectangle(largeur, hauteur, rX, rY, 20.0, 20.0);

    return perso;
}

/**
 * @brief Détruit un personnage et libère toutes les ressources associées.
 *
 * Cette fonction libère toutes les ressources allouées pour un personnage, y compris les textures,
 * les rectangles SDL, et les structures de données internes. Elle doit être appelée pour éviter les fuites de mémoire.
 *
 * @param perso Pointeur vers le pointeur du personnage à détruire. Le pointeur est mis à NULL après la destruction.
 */

extern
void detruirePerso(personnage ** perso) {
    // Destruction rectangles
    free((*perso)->pseudo->rect->rect);
    free((*perso)->pseudo->rect);
    (*perso)->pseudo->rect = NULL;

    free((*perso)->hitBox->rect);
    free((*perso)->hitBox);
    (*perso)->hitBox = NULL;

    free((*perso)->hurtBox->rect);
    free((*perso)->hurtBox);
    (*perso)->hurtBox = NULL;

    free((*perso)->pos->rect);
    free((*perso)->pos);
    (*perso)->pos = NULL;

    // Destruction texture
    SDL_DestroyTexture((*perso)->texture);

    // Destruction SDL_Rect
    int i;

    for( i = 0 ; i < 5 ; i++)
        free((*perso)->idle[i]);
    free((*perso)->idle);

    for( i = 0 ; i < 6 ; i++)
        free((*perso)->walk[i]);
    free((*perso)->walk);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->punchLat[i]);
    free((*perso)->punchLat);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->kick[i]);
    free((*perso)->kick);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->punchUp[i]);
    free((*perso)->punchUp);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->kickDown[i]);
    free((*perso)->kickDown);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->block[i]);
    free((*perso)->block);

    for( i = 0 ; i < 7 ; i++)
        free((*perso)->jump[i]);
    free((*perso)->jump);

    for( i = 0 ; i < 8 ; i++)
        free((*perso)->moveJump[i]);
    free((*perso)->moveJump);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->crouch[i]);
    free((*perso)->crouch);

    for( i = 0 ; i < 2 ; i++)
        free((*perso)->crouchPunch[i]);
    free((*perso)->crouchPunch);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->crouchKick[i]);
    free((*perso)->crouchKick);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->standHurt[i]);
    free((*perso)->standHurt);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->jumpHurt[i]);
    free((*perso)->jumpHurt);

    for( i = 0 ; i < 3 ; i++)
        free((*perso)->crouchHurt[i]);
    free((*perso)->crouchHurt);

    // Destruction pseudo
    SDL_DestroyTexture((*perso)->pseudo->txt);
    free((*perso)->pseudo);

    // Destruction barre hp
    free((*perso)->hp->barrePv);
    free((*perso)->hp);

    // Destruction perso
    free(*perso);
    *perso = NULL;
}

/**
 * @brief Met à jour les points de vie d'un personnage en fonction des dégâts reçus.
 *
 * Cette fonction réduit les points de vie du personnage en fonction des dégâts reçus et ajuste la taille de la barre de vie.
 * Elle joue également un son de dégât si nécessaire.
 *
 * @param renderer Pointeur vers le renderer SDL.
 * @param perso Pointeur vers le personnage dont les points de vie doivent être mis à jour.
 * @param degat Quantité de dégâts infligés au personnage.
 * @param persoID Identifiant du personnage pour gérer les comportements spécifiques.
 * @param soundDMG Pointeur vers le chunk de son à jouer lorsque des dégâts sont reçus.
 */

extern
void mettreAJourHp(SDL_Renderer *renderer, personnage * perso, int degat, int persoID, Mix_Chunk * soundDMG) {
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

}

/**
 * @brief Met à jour les animations et les états de deux personnages en fonction de l'input utilisateur et d'autres conditions de jeu.
 *
 * Cette fonction gère la logique d'animation, les déplacements, les attaques, et autres interactions entre deux personnages.
 * Elle est appelée à chaque frame du jeu pour assurer que les états des personnages sont correctement mis à jour en fonction
 * des actions du joueur et des règles du jeu.
 *
 * @param renderer Pointeur vers le renderer SDL utilisé pour le dessin.
 * @param perso1 Pointeur vers le premier personnage.
 * @param perso2 Pointeur vers le deuxième personnage.
 * @param keyboardState État actuel du clavier pour lire les inputs du joueur.
 * @param largeur Largeur de la fenêtre du jeu.
 * @param hauteur Hauteur de la fenêtre du jeu.
 * @param framerate Pointeur vers la variable de contrôle du framerate, utilisée pour la synchronisation des animations.
 * @param soundHIT Pointeur vers le chunk de son joué lors d'une attaque réussie.
 * @param soundDMG Pointeur vers le chunk de son joué lors de la réception de dégâts.
 * @param soundStun Pointeur vers le chunk de son joué lorsqu'un personnage est étourdi.
 * @param liste_touches Tableau des touches configurées pour le contrôle des personnages.
 * @param stunTexture Texture utilisée pour l'effet visuel lorsqu'un personnage est étourdi.
 * @param stunRect Rectangle SDL représentant la position et la taille de l'effet de stun.
 * @param stunTextureRect Tableau de rectangles SDL pour l'animation de l'effet de stun.
 */

extern
void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso1, personnage *perso2, const Uint8 *keyboardState, int largeur, int hauteur, int * framerate, Mix_Chunk * soundHIT, Mix_Chunk * soundDMG, Mix_Chunk * soundStun, int * liste_touches, SDL_Texture * stunTexture, rectangle * stunRect, SDL_Rect ** stunTextureRect) {
    /*Test avant que Quentin commence à crier, fonctionne mais comme ttf charge en boucle lors d'appel -> jeu tres ralenti*/
    int hitJ1 = 0, hitJ2 = 0;

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
        if(perso1->stunned)
            perso1->etatStun = (perso1->etatStun+1)%4;
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
                                        if(perso1->etatAnimation == 0) {
                                            perso1->hurtBox->rect->x = perso1->hitBox->rect->x + (perso1->hitBox->rect->w * 1.25);
                                            perso1->hurtBox->rect->y = (perso1->pos->rect->h / 126) * 71.0;
                                        }
                                        if(perso1->etatAnimation < 2) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case KICK:
                        case POINGHAUT:
                                        if(perso1->etatAnimation == 1) {
                                            perso1->hurtBox->rect->x = perso1->hitBox->rect->x + (perso1->hitBox->rect->w * 1.25);
                                            perso1->hurtBox->rect->y = (perso1->pos->rect->h / 126) * 71.0;
                                        }
                                        if(perso1->etatAnimation < 2) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case KICKBAS:
                                        if(perso1->etatAnimation == 1) {
                                            perso1->hurtBox->rect->x = perso1->hitBox->rect->x + (perso1->hitBox->rect->w * 1.40);
                                            perso1->hurtBox->rect->y = (perso1->pos->rect->h / 126) * 120.0;
                                        }
                                        if(perso1->etatAnimation < 2) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                        case KICKACCROUPI:
                                        if(perso1->etatAnimation == 1) {
                                            perso1->hurtBox->rect->x = perso1->hitBox->rect->x + (perso1->hitBox->rect->w * 1.25);
                                            perso1->hurtBox->rect->y = (perso1->pos->rect->h / 126) * 120.0;
                                        }
                                        if(perso1->etatAnimation < 2) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
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
                                        if(perso1->etatAnimation == 0) {
                                            perso1->hurtBox->rect->x = perso1->hitBox->rect->x + (perso1->hitBox->rect->w * 1.25);
                                            perso1->hurtBox->rect->y = (perso1->pos->rect->h / 126) * 120.0;
                                        }
                        case DEGAT:
                        case DEGATACCROUPI:
                        case DEGATSAUT:
                                        if(perso1->etatAnimation < 1) {
                                                perso1->etatAnimation++;
                                        }else {
                                                perso1->etatAnimation = 0;
                                                perso1->animation = AUCUNE;
                                        }
                                        break;
                }
        }


        // Joueur 2
        if(perso2->stunned)
            perso2->etatStun = (perso2->etatStun+1)%4;
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
                                        if(perso2->etatAnimation == 0) {
                                                perso2->hurtBox->rect->x = perso2->hitBox->rect->x - (perso2->hitBox->rect->w * 0.25) - perso2->hurtBox->rect->w;
                                                perso2->hurtBox->rect->y = (perso2->pos->rect->h / 126) * 71.0;
                                        }
                                        if(perso2->etatAnimation < 2) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case KICK:
                        case POINGHAUT:
                                        if(perso2->etatAnimation == 1) {
                                                perso2->hurtBox->rect->x = perso2->hitBox->rect->x - (perso2->hitBox->rect->w * 0.25) - perso2->hurtBox->rect->w;
                                                perso2->hurtBox->rect->y = (perso2->pos->rect->h / 126) * 71.0;
                                        }
                                        if(perso2->etatAnimation < 2) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case KICKBAS:
                                        if(perso2->etatAnimation == 1) {
                                                perso2->hurtBox->rect->x = perso2->hitBox->rect->x - (perso2->hitBox->rect->w * 0.40) - perso2->hurtBox->rect->w;
                                                perso2->hurtBox->rect->y = (perso2->pos->rect->h / 126) * 120.0;
                                        }
                                        if(perso2->etatAnimation < 2) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                        case KICKACCROUPI:
                                        if(perso2->etatAnimation == 1) {
                                                perso2->hurtBox->rect->x = perso2->hitBox->rect->x - (perso2->hitBox->rect->w * 0.25) - perso2->hurtBox->rect->w;
                                                perso2->hurtBox->rect->y = (perso2->pos->rect->h / 126) * 120.0;
                                        }
                                        if(perso2->etatAnimation < 2) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
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
                                        if(perso2->etatAnimation == 0) {
                                                perso2->hurtBox->rect->x = perso2->hitBox->rect->x - (perso2->hitBox->rect->w * 0.25) - perso2->hurtBox->rect->w;
                                                perso2->hurtBox->rect->y = (perso2->pos->rect->h / 126) * 120.0;
                                        }
                        case DEGAT:
                        case DEGATACCROUPI:
                        case DEGATSAUT:
                                        if(perso2->etatAnimation < 1) {
                                                perso2->etatAnimation++;
                                        }else {
                                                perso2->etatAnimation = 0;
                                                perso2->animation = AUCUNE;
                                        }
                                        break;
                }
        }


        // Gestion dégats
        hitJ1 = SDL_HasIntersection(perso1->hurtBox->rect, perso2->hitBox->rect);
        hitJ2 = SDL_HasIntersection(perso2->hurtBox->rect, perso1->hitBox->rect);
        if(hitJ1 && hitJ2) {
            // Gestion dégats J1
            perso1->etatAnimation = 0;
            if(perso1->blocking) {
                perso1->etatAnimation = 1;
                perso1->animation = PARADE;
                mettreAJourHp(renderer, perso1, DMG / 2, 1, soundDMG) ;
            }else if(perso1->animation == SAUT) {
                perso1->animation = DEGATSAUT;
                mettreAJourHp(renderer, perso1, DMG, 1, soundDMG) ;
            }else if(perso1->crouching) {
                perso1->animation = DEGATACCROUPI;
                mettreAJourHp(renderer, perso1, DMG, 1, soundDMG) ; 
            }else {
                perso1->animation = DEGAT;
                mettreAJourHp(renderer, perso1, DMG, 1, soundDMG) ;
            }

            // Gestion dégats J2
            perso2->etatAnimation = 0;
            if(perso2->blocking) {
                perso2->etatAnimation = 1;
                perso2->animation = PARADE;
                mettreAJourHp(renderer, perso2, DMG / 2, 2, soundDMG) ;
            }else if(perso2->animation == SAUT) {
                perso2->animation = DEGATSAUT;
                mettreAJourHp(renderer, perso2, DMG, 2, soundDMG) ;
            }else if(perso2->crouching) {
                perso2->animation = DEGATACCROUPI;
                mettreAJourHp(renderer, perso2, DMG, 2, soundDMG) ;
            }else {
                perso2->animation = DEGAT;
                mettreAJourHp(renderer, perso2, DMG, 2, soundDMG) ;
            }
        }else if(hitJ1) {
            // Gestion dégats J2
            perso2->etatAnimation = 0;
            if(perso2->blocking) {
                perso2->etatAnimation = 1;
                perso2->animation = PARADE;
                if(!(perso1->animation == KICKBAS || perso1->animation == KICKACCROUPI || perso1->animation == POINGACCROUPI)) {
                    perso1->stunned = 1;
                    Mix_PlayChannel(-1, soundStun, 0);
                    mettreAJourHp(renderer, perso2, DMG / 2, 2, soundDMG) ;
                }else
                    mettreAJourHp(renderer, perso2, DMG, 2, soundDMG) ;
            }else if(perso2->animation == SAUT) {
                perso2->animation = DEGATSAUT;
                perso2->stunned = 0;
                mettreAJourHp(renderer, perso2, DMG, 2, soundDMG) ;
            }else if(perso2->crouching) {
                perso2->animation = DEGATACCROUPI;
                perso2->stunned = 0;
                mettreAJourHp(renderer, perso2, DMG, 2, soundDMG) ;
            }else {
                perso2->animation = DEGAT;
                perso2->stunned = 0;
                mettreAJourHp(renderer, perso2, DMG, 2, soundDMG) ;
            }
        }else if(hitJ2) {
            // Gestion dégats J1
            perso1->etatAnimation = 0;
            if(perso1->blocking) {
                perso1->etatAnimation = 1;
                perso1->animation = PARADE;
                if(!(perso2->animation == KICKBAS || perso2->animation == KICKACCROUPI || perso2->animation == POINGACCROUPI)) {
                    perso2->stunned = 1;
                    Mix_PlayChannel(-1, soundStun, 0);
                    mettreAJourHp(renderer, perso1, DMG / 2, 1, soundDMG) ;
                }else
                    mettreAJourHp(renderer, perso1, DMG, 1, soundDMG) ;
            }else if(perso1->animation == SAUT) {
                perso1->animation = DEGATSAUT;
                perso1->stunned = 0;
                mettreAJourHp(renderer, perso1, DMG, 1, soundDMG) ;
            }else if(perso1->crouching) {
                perso1->animation = DEGATACCROUPI;
                perso1->stunned = 0;
                mettreAJourHp(renderer, perso1, DMG, 1, soundDMG) ; 
            }else {
                perso1->animation = DEGAT;
                perso1->stunned = 0;
                mettreAJourHp(renderer, perso1, DMG, 1, soundDMG) ;
            }
        }else if(!hitJ1 && perso1->animation == KICKBAS && perso1->etatAnimation == 2) {
            perso1->stunned = 1;
            Mix_PlayChannel(-1, soundStun, 0);
        }else if(!hitJ2 && perso2->animation == KICKBAS && perso2->etatAnimation == 2) {
            perso2->stunned = 1;
            Mix_PlayChannel(-1, soundStun, 0);
        }


        // Reset HurtBoxs
        perso1->hurtBox->rect->x = 0;
        perso1->hurtBox->rect->y = 0;
        perso2->hurtBox->rect->x = largeur;
        perso2->hurtBox->rect->y = hauteur;

        // Reset double stun
        if(perso1->stunned && perso2->stunned)
            perso1->stunned = perso2->stunned = 0;

        *framerate = 0;
    }

    // perso1
    if(!perso1->animation){
        perso1->blocking = 0;
        // Etourdi
        if(perso1->stunned) {
            stunRect->rect->x = perso1->hitBox->rect->x + perso1->hitBox->rect->w * 0.5;
            SDL_RenderCopy(renderer, stunTexture, stunTextureRect[perso1->etatStun], stunRect->rect);
            SDL_RenderCopy(renderer, perso1->texture, perso1->idle[perso1->etatIdle], perso1->pos->rect);
        // Parade
        }else if(keyboardState[liste_touches[ParadeJ1]] && !perso1->crouching) {
            perso1->blocking = 1;
            SDL_RenderCopy(renderer, perso1->texture, perso1->block[0], perso1->pos->rect);
        // Coup de peid en bas
        }else if (keyboardState[liste_touches[AccroupirJ1]] && keyboardState[liste_touches[KickJ1]] && !perso1->crouching) {
            perso1->animation = KICKBAS;
            Mix_PlayChannel(-1, soundHIT, 0);
        // Accroupi
        }else if (keyboardState[liste_touches[AccroupirJ1]]) {
            perso1->crouching = 1;
            SDL_RenderCopy(renderer, perso1->texture, perso1->crouch[perso1->etatCrouch], perso1->pos->rect);
            if (perso1->etatCrouch == 2) {
                // Coup de poing
                if (keyboardState[liste_touches[PoingJ1]]) {
                    perso1->animation = POINGACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
                // Coup de pied
                else if (keyboardState[liste_touches[KickJ1]]) {
                    perso1->animation = KICKACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
            }
        }else {
            // Coup de poing droit 
            perso1->crouching = 0;
            if (keyboardState[liste_touches[PoingJ1]] && !keyboardState[liste_touches[SauterJ1]]) {
                perso1->animation = POINGLATERAL;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de pied devant
            }else if (keyboardState[liste_touches[KickJ1]]) {
                perso1->animation = KICK;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de poing haut 
            }else if (keyboardState[liste_touches[PoingJ1]] && keyboardState[liste_touches[SauterJ1]]) {
                perso1->animation = POINGHAUT;
                Mix_PlayChannel(-1, soundHIT, 0);;
            // Saut
            }else if (keyboardState[liste_touches[SauterJ1]]) {
                if(keyboardState[liste_touches[GaucheJ1]]) {
                    perso1->animation = SAUTGAUCHE;
                    perso1->etatAnimation = 7;
                }else if(keyboardState[liste_touches[DroitJ1]])
                    perso1->animation = SAUTDROIT;
                else perso1->animation = SAUT;
            // Surplace
            }else if(!(keyboardState[liste_touches[GaucheJ1]] || keyboardState[liste_touches[DroitJ1]]) || (keyboardState[liste_touches[GaucheJ1]] && keyboardState[liste_touches[DroitJ1]])) {
                perso1->etatWalk = 0;
                SDL_RenderCopy(renderer, perso1->texture, perso1->idle[perso1->etatIdle], perso1->pos->rect);
            }else {
                perso1->etatIdle = 0;
                // Gauche
                if (keyboardState[liste_touches[GaucheJ1]]) {
                    if ((perso1->hitBox->rect->x - perso1->speed) > 0)
                        perso1->pos->rect->x -= perso1->speed;
                }
                // Droite
                if (keyboardState[liste_touches[DroitJ1]]) {
                    if ((perso1->hitBox->rect->x + perso1->speed + perso1->hitBox->rect->w) < perso2->hitBox->rect->x)
                        perso1->pos->rect->x += perso1->speed;
                }
                if (!keyboardState[liste_touches[GaucheJ1]] && !keyboardState[liste_touches[DroitJ1]]) perso1->etatWalk = 0;
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
                if ((perso1->hitBox->rect->x - perso1->speed) > 0)
                        perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->block[perso1->etatAnimation], perso1->pos->rect); break;
            case SAUT:
                SDL_RenderCopy(renderer, perso1->texture, perso1->jump[perso1->etatAnimation], perso1->pos->rect); break;
            case POINGACCROUPI:
                SDL_RenderCopy(renderer, perso1->texture, perso1->crouchPunch[perso1->etatAnimation], perso1->pos->rect); break;
            case KICKACCROUPI:
                SDL_RenderCopy(renderer, perso1->texture, perso1->crouchKick[perso1->etatAnimation], perso1->pos->rect); break;
            case SAUTGAUCHE:
                if ((perso1->hitBox->rect->x - perso1->speed) > 0)
                        perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->moveJump[perso1->etatAnimation], perso1->pos->rect); break;
            case SAUTDROIT:
                if ((perso1->hitBox->rect->x + perso1->speed + perso1->hitBox->rect->w) < perso2->hitBox->rect->x)
                        perso1->pos->rect->x += perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->moveJump[perso1->etatAnimation], perso1->pos->rect); break;
            case DEGAT:
                if ((perso1->hitBox->rect->x - perso1->speed) > 0)
                        perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->standHurt[perso1->etatAnimation], perso1->pos->rect); break;
            case DEGATACCROUPI:
                if ((perso1->hitBox->rect->x - perso1->speed) > 0)
                        perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->crouchHurt[perso1->etatAnimation], perso1->pos->rect); break;
            case DEGATSAUT:
                if ((perso1->hitBox->rect->x - perso1->speed) > 0)
                        perso1->pos->rect->x -= perso1->speed;
                SDL_RenderCopy(renderer, perso1->texture, perso1->jumpHurt[perso1->etatAnimation], perso1->pos->rect); break;
        }
    }

    // perso2
    if(!perso2->animation){
        perso2->blocking = 0;
        // Etourdi
        if(perso2->stunned) {
            stunRect->rect->x = perso2->hitBox->rect->x + perso2->hitBox->rect->w * 0.5;
            SDL_RenderCopy(renderer, stunTexture, stunTextureRect[perso2->etatStun], stunRect->rect);
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->idle[perso2->etatIdle], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
        // Parade
        }else if(keyboardState[liste_touches[ParadeJ2]] && !perso2->crouching) {
            perso2->blocking = 1;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->block[0], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
        // Coup de peid en bas
        }else if (keyboardState[liste_touches[AccroupirJ2]] && keyboardState[liste_touches[KickJ2]] && !perso2->crouching) {
            perso2->animation = KICKBAS;
            Mix_PlayChannel(-1, soundHIT, 0);
        // Accroupi
        }else if (keyboardState[liste_touches[AccroupirJ2]]) {
            perso2->crouching = 1;
            SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouch[perso2->etatCrouch], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
            if (perso2->etatCrouch == 2) {
                // Coup de poing
                if (keyboardState[liste_touches[PoingJ2]]) {
                    perso2->animation = POINGACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
                // Coup de pied
                else if (keyboardState[liste_touches[KickJ2]]) {
                    perso2->animation = KICKACCROUPI;
                    Mix_PlayChannel(-1, soundHIT, 0);
                }
            }
        }else {
            perso2->crouching = 0;
            // Coup de poing droit 
            if (keyboardState[liste_touches[PoingJ2]] && !keyboardState[liste_touches[SauterJ2]]) {
                perso2->animation = POINGLATERAL;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de pied devant
            }else if (keyboardState[liste_touches[KickJ2]]) {
                perso2->animation = KICK;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Coup de poing haut 
            }else if (keyboardState[liste_touches[PoingJ2]] && keyboardState[liste_touches[SauterJ2]]) {
                perso2->animation = POINGHAUT;
                Mix_PlayChannel(-1, soundHIT, 0);
            // Saut
            }else if (keyboardState[liste_touches[SauterJ2]]) {
                if(keyboardState[liste_touches[GaucheJ2]])
                    perso2->animation = SAUTGAUCHE;
                else if(keyboardState[liste_touches[DroitJ2]]) {
                    perso2->animation = SAUTDROIT;
                    perso2->etatAnimation = 7;
                }else perso2->animation = SAUT;
            // Surplace
            }else if(!(keyboardState[liste_touches[GaucheJ2]] || keyboardState[liste_touches[DroitJ2]]) || (keyboardState[liste_touches[GaucheJ2]] && keyboardState[liste_touches[ParadeJ2]])) {
                perso2->etatWalk = 0;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->idle[perso2->etatIdle], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
            }else {
                perso2->etatIdle = 0;
                // Gauche
                if (keyboardState[liste_touches[GaucheJ2]]) {
                    if ((perso2->hitBox->rect->x - perso2->speed) > perso1->hitBox->rect->x + perso1->hitBox->rect->w)
                        perso2->pos->rect->x -= perso2->speed;
                }
                // Droite
                if (keyboardState[liste_touches[DroitJ2]]) {
                    if ((perso2->hitBox->rect->x + perso2->speed + perso2->hitBox->rect->w) <= largeur)
                        perso2->pos->rect->x += perso2->speed;
                }
                if (!keyboardState[liste_touches[GaucheJ2]] && !keyboardState[liste_touches[DroitJ2]]) perso2->etatWalk = 0;
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
                if ((perso2->hitBox->rect->x + perso2->speed + perso2->hitBox->rect->w) <= largeur)
                        perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->block[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case SAUT:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->jump[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case POINGACCROUPI:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouchPunch[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case KICKACCROUPI:
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouchKick[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case SAUTGAUCHE:
                if ((perso2->hitBox->rect->x - perso2->speed) > perso1->hitBox->rect->x + perso1->hitBox->rect->w)
                        perso2->pos->rect->x -= perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->moveJump[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case SAUTDROIT:
                if ((perso2->hitBox->rect->x + perso2->speed + perso2->hitBox->rect->w) <= largeur)
                        perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->moveJump[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case DEGAT:
                if ((perso2->hitBox->rect->x + perso2->speed + perso2->hitBox->rect->w) <= largeur)
                        perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->standHurt[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case DEGATACCROUPI:
                if ((perso2->hitBox->rect->x + perso2->speed + perso2->hitBox->rect->w) <= largeur)
                        perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->crouchHurt[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
            case DEGATSAUT:
                if ((perso2->hitBox->rect->x + perso2->speed + perso2->hitBox->rect->w) <= largeur)
                        perso2->pos->rect->x += perso2->speed;
                SDL_RenderCopyEx(renderer, perso2->texture, perso2->jumpHurt[perso2->etatAnimation], perso2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL); break;
        }
    }

    // Hitboxs
    if(perso1->crouching)
        perso1->hitBox->rect->y = (perso1->pos->rect->h / 126) * 87.0;
    else if(perso1->animation == SAUT || perso1->animation == SAUTDROIT || perso1->animation == SAUTGAUCHE)
        perso1->hitBox->rect->y = (perso1->pos->rect->h / 126) * -10.0;
    else
        perso1->hitBox->rect->y = (perso1->pos->rect->h / 126) * 55.0;
    perso1->hitBox->rect->x = perso1->pos->rect->x + (perso1->pos->rect->w / 145) * 48.0;

    if(perso2->crouching)
        perso2->hitBox->rect->y = (perso2->pos->rect->h / 126) * 87.0;
    else if(perso2->animation == SAUT || perso2->animation == SAUTDROIT || perso2->animation == SAUTGAUCHE)
        perso2->hitBox->rect->y = (perso2->pos->rect->h / 126) * -10.0;
    else
        perso2->hitBox->rect->y = (perso2->pos->rect->h / 126) * 55.0;
    perso2->hitBox->rect->x = perso2->pos->rect->x + (perso2->pos->rect->w / 145) * 60.0;
}



