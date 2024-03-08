#include <SDL2/SDL.h>
#include "../lib/creation.h"
#include "../lib/perso.h"

extern
personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle)
{
    personnage *perso = malloc(sizeof(personnage));
    perso->pos = creerRectangle(largeur, hauteur, rX, rY, rW, rH);
    ajoutListeRect(listeRectangle, &perso->pos);
    perso->texture = creerImage(renderer, image);
    if(perso->texture == NULL) return NULL;
    perso->etat = 0;

    int i;

    perso->garde = malloc(sizeof(SDL_Rect*)*5);
    for( i = 0 ; i < 5 ; i++) {
        perso->garde[i] = malloc(sizeof(SDL_Rect));
        perso->garde[i]->x = 87*i;
        perso->garde[i]->y = 0;
        perso->garde[i]->w = 87;
        perso->garde[i]->h = 104;
    }
    perso->speed = 1;

    return perso;
}

extern
void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso, const Uint8 *keyboardState, int largeur, int hauteur) {
    if(!(keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_DOWN])) {
        SDL_RenderCopy(renderer, perso->texture, perso->garde[perso->etat], perso->pos->rect);
    }else {
        perso->etat = 0;
        if (keyboardState[SDL_SCANCODE_LEFT] && (perso->pos->rect->x - perso->speed) > 0) {
            perso->pos->rect->x -= perso->speed;
        }
        if (keyboardState[SDL_SCANCODE_RIGHT] && (perso->pos->rect->x + perso->speed + 50) <= largeur) {
            perso->pos->rect->x += perso->speed;
        }
        if (keyboardState[SDL_SCANCODE_UP] && (perso->pos->rect->y - perso->speed) > 0) {
            perso->pos->rect->y -= perso->speed;
        }
        if (keyboardState[SDL_SCANCODE_DOWN] && (perso->pos->rect->y + perso->speed + 50) <= hauteur) {
            perso->pos->rect->y += perso->speed;
        }
    }
}