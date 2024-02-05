#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct listeT_s {
    SDL_Texture * pTexture;
    struct listeT_s * suivant;
}listeT_t;

extern listeT_t *creerListeT(void);
extern void ajoutListeT(listeT_t **,SDL_Texture *);
extern void detruireListeT(listeT_t **);
extern SDL_Texture *creerImage(SDL_Renderer *,char *);
extern SDL_Texture *creerTexte(SDL_Renderer *,TTF_Font *,char *,SDL_Color);
