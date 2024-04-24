#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"
#include "touches.h"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

// Images
#define IMG_CONTROLE_BG "img/controle/FondControles.bmp"
#define IMG_BACK "img/options/optionsBack.bmp"

#define IMG_CONTROLE "img/controle/Controlespx.bmp"
#define IMG_EMPLACEMENT_TOUCHE "img/controle/FondTouches.bmp"

#define IMG_J1 "img/controle/J1px.bmp"
#define IMG_J2 "img/controle/J2px.bmp"

#define IMG_SAUTER "img/controle/Sauterpx.bmp"
#define IMG_ACCROUPI "img/controle/Accroupirpx.bmp"
#define IMG_GAUCHE "img/controle/Gauchepx.bmp"
#define IMG_DROITE "img/controle/Droitepx.bmp"
#define IMG_POING "img/controle/Poingpx.bmp"
#define IMG_KICK "img/controle/Kickpx.bmp" 
#define IMG_GARDE "img/controle/Paradepx.bmp"

#define IMG_RESET "img/controle/BoutonReset.bmp"

extern int controle(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int * liste_touches, char * f_touches, char * r_touches);