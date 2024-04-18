#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

// Images
#define IMG_OPTIONS_BG "img/options/optionsBG.bmp"
#define IMG_OPTIONS_TITLE "img/options/optionsTitle.bmp"
#define IMG_OPTIONS_SOUND_ON "img/options/optionsSoundOn.bmp"
#define IMG_OPTIONS_SOUND_OFF "img/options/optionsSoundOff.bmp"
#define IMG_OPTIONS_RESOLUTION "img/options/optionsResolution.bmp"
#define IMG_OPTIONS_RESOLUTION_LEFT "img/options/optionsFGauche.bmp"
#define IMG_OPTIONS_RESOLUTION_RIGHT "img/options/optionsFDroite.bmp"
#define IMG_OPTIONS_RESOLUTION_APPLIKER "img/options/optionsAppRes.bmp"
#define IMG_OPTIONS_FULLSCREEN "img/options/optionsPleinEcran.bmp"
#define IMG_OPTIONS_FULLSCREEN_TURN_ON "img/options/optionsFullscreenTurnOn.bmp"
#define IMG_OPTIONS_FULLSCREEN_TURN_OFF "img/options/optionsFullscreenTurnOff.bmp"
#define IMG_OPTIONS_BACK "img/options/optionsBack.bmp"
#define IMG_OPTIONS_CONTROLE "img/options/optionsBack.bmp"

extern int options(SDL_Event e, SDL_Renderer * renderer, SDL_Window * window, int largeurF, int hauteurF, int * scene, int * son, int * fullscreen, Mix_Music * backgroundSound);