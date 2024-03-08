#include <SDL2/SDL.h>
#include "creation.h"

typedef struct {
    rectangle *pos;
    SDL_Texture *texture;
    int etat;
    SDL_Rect **garde;
    // Ult
    float speed ;
} personnage;

extern personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle);
extern void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso, const Uint8 *keyboardState, int largeur, int hauteur);