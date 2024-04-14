#include <SDL2/SDL.h>
#include "creation.h"

typedef enum anime{AUCUNE,POINGLATERAL,KICK,POINGHAUT,KICKBAS,PARADE,SAUT,POINGACCROUPI,KICKACCROUPI,SAUTGAUCHE,SAUTDROIT}animation_e;

typedef struct {
    int pv;
    SDL_Rect * barrePv;
} pv_t;

typedef struct {
    rectangle *pos;
    SDL_Texture *texture;
    int etatIdle;
    SDL_Rect **idle;
    int etatWalk;
    SDL_Rect **walk;
    SDL_Rect **punchLat;
    SDL_Rect **kick;
    SDL_Rect **punchUp;
    SDL_Rect **kickDown;
    SDL_Rect **block;
    int blocking;
    SDL_Rect **jump;
    SDL_Rect **moveJump;
    SDL_Rect **crouch;
    int crouching;
    int etatCrouch;
    SDL_Rect **crouchPunch;
    SDL_Rect **crouchKick;
    SDL_Rect **standHurt;
    SDL_Rect **jumpHurt;
    SDL_Rect **crouchHurt;
    animation_e animation;
    int etatAnimation;
    int canHit;
    float speed ;
    pv_t * hp;
} personnage;

extern personnage *creerPerso(SDL_Renderer *renderer, char *image, int *largeur, int *hauteur, float rX, float rY, float rW, float rH, listeRect **listeRectangle);
extern void mettreAJourPersonnage(SDL_Renderer *renderer, personnage *perso1, personnage *perso2, const Uint8 *keyboardState, int largeur, int hauteur);
