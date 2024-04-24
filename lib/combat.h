#ifndef _COMBAT_H_
#define _COMBAT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "perso.h"

extern void initPerso(SDL_Renderer * renderer, personnage * J1, personnage * J2);
extern int roundStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int waitForFrame, Mix_Chunk * hit, Mix_Chunk * dmg, Mix_Chunk * stun, int * liste_touches, int round, SDL_Texture * stunTexture, rectangle * stunRect, SDL_Rect ** stunTextureRect);
extern void combatStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int son, int * liste_touches);
void afficherRound(SDL_Renderer* renderer, int largeurF, int hauteurF, int round, personnage * Joueur1, personnage * Joueur2, SDL_Texture * BG);

#endif
