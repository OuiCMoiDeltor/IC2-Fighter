#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"

// Images
#define IMG_GAMEMODE_BG "img/gamemode_select/menu-multi.bmp"
#define IMG_GAMEMODE_LOCAL "img/gamemode_select/local.bmp"
#define IMG_GAMEMODE_LIGNE "img/gamemode_select/ligne.bmp"
#define IMG_GAMEMODE_RETOUR "img/options/optionsBack.bmp"


extern int gamemode_selection(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int son, Mix_Music * backgroundSoundSelect);
