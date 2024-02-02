#include <SDL2/SDL.h>
#include "../lib/bouton.h"
#include "../lib/creation.h"

extern
bouton *creerBouton(SDL_Renderer *renderer, int x, int y, int w, int h, char *img)
{
    bouton *b = malloc(sizeof(bouton));
    b->texture = creerImage(renderer, img);
    if(b->texture == NULL) {
        free(b);
        b = NULL;
        return (bouton *)NULL;
    }
    b->position = malloc(sizeof(SDL_Rect));
    b->relache = malloc(sizeof(SDL_Rect));
    b->appuye = malloc(sizeof(SDL_Rect));
    b->over = malloc(sizeof(SDL_Rect));

    // affectation de la position (.x et .y) et des dimensions (.w et .h) du bouton
    b->position->x = x;
    b->position->y = y;
    b->position->w = w;
    b->position->h = h;

    b->etat = BOUTON_RELACHE;

    int image_w, image_h;
    SDL_QueryTexture(b->texture, NULL, NULL, &image_w, &image_h);

    b->relache->x = 0;
    b->relache->y = 0;
    b->relache->w = image_w/NB_ETAT;
    b->relache->h = image_h;

    b->appuye->x = image_w/NB_ETAT;
    b->appuye->y = 0;
    b->appuye->w = image_w/NB_ETAT;
    b->appuye->h = image_h;

    b->over->x = image_w/NB_ETAT*2;
    b->over->y = 0;
    b->over->w = image_w/NB_ETAT;
    b->over->h = image_h;

    return b;
}

extern
void DestroyBouton(bouton **b)
{
    SDL_DestroyTexture((*b)->texture); (*b)->texture = NULL;
    free((*b)->position); (*b)->position = NULL;
    free((*b)->relache); (*b)->relache = NULL;
    free((*b)->appuye); (*b)->appuye = NULL;
    free((*b)->over); (*b)->over = NULL;
    free(*b); *b = NULL;
}