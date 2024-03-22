#include <SDL2/SDL.h>
#include "creation.h"

typedef enum anime{AUCUNE,POINGGAUCHE}animation_e;

typedef struct {
    rectangle *pos;
    SDL_Texture *texture;
    int etatIdle;
    SDL_Rect **idle;
    int etatWalk;
    SDL_Rect **walk;
    SDL_Rect **punch;
    animation_e animation;
    int etatAnimation;
    int canHit;
    float speed ;
} personnage;

extern personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle);
extern void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso1, personnage *perso2, const Uint8 *keyboardState, int largeur, int hauteur);