#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct listeT_s {
    SDL_Texture **pTexture;
    struct listeT_s *suivant;
}listeT_t;

typedef struct rectangle_s {
    int *largeur; // Largeur de la fenêtre
    int *hauteur; // Hauteur de la fenêtre
    float ratioX;
    float ratioY;
    float ratioW;
    float ratioH;
    SDL_Rect *rect;
}rectangle;

typedef struct listeRect_s {
    rectangle **pRect;
    struct listeRect_s *suivant;
}listeRect;

extern listeT_t *creerListeT(void);
extern void ajoutListeT(listeT_t **,SDL_Texture **);
extern void detruireListeT(listeT_t **);
extern SDL_Texture *creerImage(SDL_Renderer *,char *);
extern SDL_Texture *creerTexte(SDL_Renderer *,TTF_Font *,char *,SDL_Color);
extern listeRect *creerListeRect(void);
extern void ajoutListeRect(listeRect **,rectangle **);
extern void detruireListeRect(listeRect **);
extern void updateRectangles(listeRect *);
extern rectangle *creerRectangle(int *,int *,float,float,float,float);
