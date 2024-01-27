#include <SDL2/SDL.h>
#include "../lib/creation.h"

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
    return NULL;
  }

  // Libération de la surface d'image car la texture a été créée
  SDL_FreeSurface(imageSurface);
  
  return imageTexture;
}
