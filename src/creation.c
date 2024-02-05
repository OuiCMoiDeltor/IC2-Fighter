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
void ajoutListeT(listeT_t **liste, SDL_Texture *Texture) {
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
    SDL_DestroyTexture((*liste)->pTexture);
    (*liste)->pTexture = NULL;
    (*liste)->suivant = NULL;
    free((*liste));
    (*liste) = temp;
    temp = (*liste)->suivant;
  }
  temp = NULL;
  (*liste)->suivant = NULL;
  SDL_DestroyTexture((*liste)->pTexture);
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