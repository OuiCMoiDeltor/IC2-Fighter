#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../lib/creation.h"
#include "../lib/touches.h"

extern
void saisirTouche(SDL_Renderer * renderer, TTF_Font * font, SDL_Event event, int * liste_touches, touches_e touche, SDL_Texture ** txt){

    while(SDL_PollEvent(&event) != 0);
    SDL_WaitEvent(&event);
    if(event.type == SDL_KEYDOWN) {
        liste_touches[touche] = (event.key.keysym.scancode);
        SDL_DestroyTexture(*txt);
        SDL_Color noire = {0,0,0};
        SDL_Log("%s", (char*)SDL_GetScancodeName(liste_touches[touche]));
        *txt = creerTexte(renderer,font,(char*)SDL_GetScancodeName(liste_touches[touche]),noire);
        if(*txt == NULL) exit(EXIT_FAILURE);
    }
}