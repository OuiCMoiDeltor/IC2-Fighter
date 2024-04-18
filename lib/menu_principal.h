#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"

// Fenêtre
#define NOM_JEU "IC2 Fighter"
#define ICONE "img/menu_principal/logo.bmp"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

// Images
#define IMG_MAIN_MENU_BG "img/menu_principal/ic2.bmp"
#define IMG_LOGO "img/menu_principal/logo.bmp"
#define IMG_BOUTON_OPT "img/menu_principal/options.bmp"
#define IMG_BOUTON_QUIT "img/menu_principal/quit.bmp"
#define IMG_BOUTON_PLAY "img/menu_principal/play.bmp"
#define SOUND_BACKGROUND "mixer/Leateq - Tokyo.mp3"

extern int menu_principal(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene);