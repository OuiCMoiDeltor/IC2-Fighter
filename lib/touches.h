#ifndef _TOUCHES_H_
#define _TOUCHES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef enum touches{SauterJ1, SauterJ2, AccroupirJ1, AccroupirJ2, GaucheJ1, GaucheJ2, DroitJ1, DroitJ2, KickJ1, KickJ2, PoingJ1, PoingJ2, ParadeJ1, ParadeJ2}touches_e; 

extern void saisirTouche(SDL_Renderer * renderer, TTF_Font * font, SDL_Event event, int * liste_touches, touches_e touche, SDL_Texture ** txt);

#endif