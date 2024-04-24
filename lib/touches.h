#ifndef _TOUCHES_H_
#define _TOUCHES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

/**
 * \struct touches_e
 * \brief structure des touches afin de pouvoir les changer
 *
 * 
 */

typedef enum touches{SauterJ1, SauterJ2, AccroupirJ1, AccroupirJ2, GaucheJ1, GaucheJ2, DroitJ1, DroitJ2, KickJ1, KickJ2, PoingJ1, PoingJ2, ParadeJ1, ParadeJ2}touches_e; 

void reverse(char s[]);
void itoa(int n, char s[]);
extern void LireTouches(int * liste_touches);
extern void ModifierTouche(int * liste_touches, int numero_ligne, int touche);
extern void saisirTouche(SDL_Renderer * renderer, TTF_Font * font, SDL_Event event, int * liste_touches, touches_e touche, SDL_Texture ** txt);

#endif
