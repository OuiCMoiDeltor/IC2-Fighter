/**
 * @file perso.h
 * @brief Fichier contenant les définitions de structures et les déclarations de fonctions pour la gestion des personnages dans le jeu.
 *
 * Ce fichier définit les structures nécessaires pour créer et gérer les personnages dans le jeu. Il contient également les déclarations des fonctions pour créer, mettre à jour et détruire les personnages, ainsi que pour gérer leurs interactions avec d'autres personnages et avec l'environnement.
 */

#ifndef _PERSO_H_
#define _PERSO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "creation.h"

#define VIE_MAX 100


typedef enum anime{AUCUNE,POINGLATERAL,KICK,POINGHAUT,KICKBAS,PARADE,SAUT,POINGACCROUPI,KICKACCROUPI,SAUTGAUCHE,SAUTDROIT,DEGAT,DEGATSAUT,DEGATACCROUPI}animation_e;

/**
 * @struct pseudo_t
 * @brief Structure représentant le pseudo d'un joueur.
 *
 * Cette structure contient la texture du pseudo ainsi que sa position et ses dimensions dans le rendu.
 */

typedef struct {
    SDL_Texture * txt;
    rectangle * rect;
}pseudo_t;

/**
 * @struct pv_t
 * @brief Structure représentant la barre de points de vie d'un personnage.
 *
 * Cette structure contient le nombre de points de vie actuels du personnage et un rectangle représentant la barre de points de vie dans le rendu.
 */

typedef struct {
    int pv;
    SDL_Rect * barrePv;
} pv_t;

/**
 * @struct personnage
 * @brief Structure représentant un personnage dans le jeu.
 *
 * Cette structure contient toutes les informations nécessaires pour représenter un personnage dans le jeu, y compris sa texture, ses animations, ses points de vie, etc.
 */

typedef struct {
    rectangle *pos;
    SDL_Texture *texture;
    int etatIdle;
    int reverseIdle;
    SDL_Rect **idle;
    int etatWalk;
    int reverseWalk;
    SDL_Rect **walk;
    SDL_Rect **punchLat;
    SDL_Rect **kick;
    SDL_Rect **punchUp;
    SDL_Rect **kickDown;
    SDL_Rect **block;
    int blocking;
    SDL_Rect **jump;
    SDL_Rect **moveJump;
    SDL_Rect **crouch;
    int crouching;
    int etatCrouch;
    SDL_Rect **crouchPunch;
    SDL_Rect **crouchKick;
    SDL_Rect **standHurt;
    SDL_Rect **jumpHurt;
    SDL_Rect **crouchHurt;
    animation_e animation;
    int etatAnimation;
    int stunned;
    int etatStun;
    float speed ;
    pv_t * hp;
    pseudo_t * pseudo;
    rectangle *hitBox;
    rectangle *hurtBox;
} personnage;

extern personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle);
extern void detruirePerso(personnage ** perso);
extern void mettreAJourHp(SDL_Renderer *renderer, personnage * perso, int degat, int persoID, Mix_Chunk * soundDMG);
extern void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso1, personnage *perso2, const Uint8 *keyboardState, int largeur, int hauteur, int * framerate, Mix_Chunk * hit, Mix_Chunk * dmg, Mix_Chunk * stun, int * liste_touches, SDL_Texture * stunTexture, rectangle * stunRect, SDL_Rect ** stunTextureRect);

#endif
