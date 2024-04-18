#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"
#include "touches.h"
#include "perso.h"
#include "combat.h"

// Images
#define IMG_CHAMPSELECT_BG "img/champ_select/amphi.bmp"
#define IMG_CHAMPSELECT_RYU "img/champ_select/wankulpix.bmp"
#define IMG_CHAMPSELECT_DIM "img/champ_select/casquepix.bmp"
#define IMG_CHAMPSELECT_J1 "img/champ_select/selectJ1.bmp"
#define IMG_CHAMPSELECT_J2 "img/champ_select/selectJ2.bmp"
#define RYU "img/champ_select/ryuic2.bmp"
#define SOUND_BACKGROUND_SELECT "mixer/giga_chad.mp3"

extern int champ_select(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int son, int * liste_touches, Uint8 * keyboardState);
