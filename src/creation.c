#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../lib/creation.h"

extern
listeT_t *creerListeT() {
  listeT_t *liste = malloc(sizeof(listeT_t));
  liste->pTexture = NULL;
  liste->suivant = NULL;
  return liste;
}

extern
void ajoutListeT(listeT_t **liste, SDL_Texture **Texture) {
  if((*liste)->suivant == NULL) {
    (*liste)->pTexture = Texture;
    (*liste)->suivant = (*liste);
  }
  else {
    listeT_t *new = malloc(sizeof(listeT_t));
    listeT_t *temp = (*liste)->suivant;
    (*liste)->suivant = new;
    (*liste)->suivant->suivant = temp;
    temp = NULL;
    new = NULL;
    (*liste) = (*liste)->suivant;
    (*liste)->pTexture = Texture;
  }
}

extern
void detruireListeT(listeT_t **liste) {
  listeT_t *dernier = (*liste);
  (*liste) = (*liste)->suivant;
  listeT_t *temp = (*liste)->suivant;
  while((*liste) != dernier) {
    SDL_DestroyTexture((*(*liste)->pTexture));
    (*(*liste)->pTexture) = NULL;
    (*liste)->pTexture = NULL;
    (*liste)->suivant = NULL;
    free((*liste));
    (*liste) = temp;
    temp = (*liste)->suivant;
  }
  temp = NULL;
  dernier = NULL;
  (*liste)->suivant = NULL;
  SDL_DestroyTexture((*(*liste)->pTexture));
  (*(*liste)->pTexture) = NULL;
  (*liste)->pTexture = NULL;
  free((*liste));
  (*liste) = NULL;
}

extern
SDL_Texture *creerImage(SDL_Renderer *renderer, char *image)
{
  // Chargement de l'image
  SDL_Surface *imageSurface = SDL_LoadBMP(image);
  if (imageSurface == NULL)
  {
    printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
    return NULL;
  }

  // Création de la texture de l'image
  SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
  if (imageTexture == NULL)
  {
    printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
    SDL_FreeSurface(imageSurface);
    return NULL;
  }

  // Libération de la surface d'image car la texture a été créée
  SDL_FreeSurface(imageSurface);
  
  return imageTexture;
}

extern
SDL_Texture *creerTexte(SDL_Renderer *renderer, TTF_Font *font, char *texte, SDL_Color couleur)
{
  // Chargement du texte
  SDL_Surface *texteSurface = TTF_RenderUTF8_Blended(font, texte, couleur);
  if (texteSurface == NULL)
  {
    printf("Erreur lors du chargement du texte : %s\n", SDL_GetError());
    return NULL;
  }

  // Création de la texture du texte
  SDL_Texture *texteTexture = SDL_CreateTextureFromSurface(renderer, texteSurface);
  if (texteTexture == NULL)
  {
    printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
    SDL_FreeSurface(texteSurface);
    return NULL;
  }

  // Libération de la surface d'image car la texture a été créée
  SDL_FreeSurface(texteSurface);
  
  return texteTexture;
}

extern
listeRect *creerListeRect() {
  listeRect *liste = malloc(sizeof(listeRect));
  liste->pRect = NULL;
  liste->suivant = NULL;
  return liste;
}

extern
void ajoutListeRect(listeRect **liste, rectangle **Rect)
{
  if((*liste)->suivant == NULL) {
    (*liste)->pRect = Rect;
    (*liste)->suivant = (*liste);
  }
  else {
    listeRect *new = malloc(sizeof(listeRect));
    listeRect *temp = (*liste)->suivant;
    (*liste)->suivant = new;
    (*liste)->suivant->suivant = temp;
    temp = NULL;
    new = NULL;
    (*liste) = (*liste)->suivant;
    (*liste)->pRect = Rect;
  }
}

extern
void detruireListeRect(listeRect **liste)
{
  listeRect *dernier = (*liste);
  (*liste) = (*liste)->suivant;
  listeRect *temp = (*liste)->suivant;
  while((*liste) != dernier) {
    free((*(*liste)->pRect)->rect);
    free((*(*liste)->pRect));
    (*(*liste)->pRect) = NULL;
    (*liste)->pRect = NULL;
    free((*liste));
    (*liste) = temp;
    temp = (*liste)->suivant;
  }
  dernier = NULL;
  temp = NULL;
  free((*(*liste)->pRect)->rect);
  free((*(*liste)->pRect));
  (*(*liste)->pRect) = NULL;
  (*liste)->pRect = NULL;
  free((*liste));
  (*liste) = NULL;
}

extern
void updateRectangles(listeRect *liste)
{
  listeRect *pListe = liste;
  do{
    (*pListe->pRect)->rect->x = (*(*pListe->pRect)->largeur)/(*pListe->pRect)->ratioX;
    (*pListe->pRect)->rect->y = (*(*pListe->pRect)->hauteur)/(*pListe->pRect)->ratioY;
    (*pListe->pRect)->rect->w = (*(*pListe->pRect)->largeur)/(*pListe->pRect)->ratioW;
    (*pListe->pRect)->rect->h = (*(*pListe->pRect)->hauteur)/(*pListe->pRect)->ratioH;
    pListe = pListe->suivant;
  }while(pListe != liste);
}

extern
rectangle *creerRectangle(int *largeur, int *hauteur, float rX, float rY, float rW, float rH)
{
  rectangle *pRect = malloc(sizeof(rectangle));
  pRect->largeur = largeur;
  pRect->hauteur = hauteur;
  pRect->ratioX = rX;
  pRect->ratioY = rY;
  pRect->ratioW = rW;
  pRect->ratioH = rH;
  pRect->rect = malloc(sizeof(SDL_Rect));
  pRect->rect->x = (*largeur)/rX;
  pRect->rect->y = (*hauteur)/rY;
  pRect->rect->w = (*largeur)/rW;
  pRect->rect->h = (*hauteur)/rH;

  return pRect;
}