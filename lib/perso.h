#ifndef _PERSO_H_
#define _PERSO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "creation.h"

#define VIE_MAX 100

/**
 * \struct animation_e
 * \brief structure de type enum pour les animations de combats
 *
 * 
 */


typedef enum anime{AUCUNE,POINGLATERAL,KICK,POINGHAUT,KICKBAS,PARADE,SAUT,POINGACCROUPI,KICKACCROUPI,SAUTGAUCHE,SAUTDROIT,DEGAT,DEGATSAUT,DEGATACCROUPI}animation_e;


/**
 * \struct pseudo_t
 * \brief structure pour mettre en place les prenoms
 *
 * 
 */

typedef struct {
    SDL_Texture * txt;
    rectangle * rect;
}pseudo_t;


/**
 * \struct pv_t
 * \brief structure pour la barre de vie
 *
 * 
 */

typedef struct {
    int pv;
    SDL_Rect * barrePv;
} pv_t;


/**
 * \struct personnage
 * \brief structure concernant le personnage, celle ci permet de mettre toute les animations textures
 *
 * 
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
    float speed ;
    pv_t * hp;
    pseudo_t * pseudo;
    rectangle *hitBox;
    rectangle *hurtBox;
} personnage;

extern personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle);
extern void mettreAJourHp(SDL_Renderer *renderer, personnage * perso, int degat, int persoID, Mix_Chunk * soundDMG);
extern void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso1, personnage *perso2, const Uint8 *keyboardState, int largeur, int hauteur, int * framerate, Mix_Chunk * hit, Mix_Chunk * dmg, int * liste_touches);

#endif
