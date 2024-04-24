/**
 * \file   creation.c
 * \brief  Fonctions pour créer et gérer des textures et des rectangles
 *
 * Ce fichier contient des fonctions pour la création et la gestion de textures et de rectangles
 * utilisés dans un contexte graphique SDL. Il permet de gérer des listes de ces objets pour faciliter
 * la manipulation et la destruction en masse lors du nettoyage de la mémoire.
 *
 * \author IC2-Fighter
 * \version 1.0
 * \date 2024
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../lib/creation.h"

/**
 * \brief Crée une nouvelle liste de textures.
 *
 * Cette fonction alloue de la mémoire pour une nouvelle liste de textures et initialise ses membres.
 *
 * \return Pointeur vers la nouvelle liste de textures créée.
 */

extern
listeT_t *creerListeT() {
  listeT_t *liste = malloc(sizeof(listeT_t));
  liste->pTexture = NULL;
  liste->suivant = NULL;
  return liste;
}

/**
 * \brief Ajoute une texture à la liste de textures.
 *
 * Cette fonction insère une nouvelle texture dans la liste de textures. Si la liste est vide, la texture
 * est ajoutée en premier élément. Sinon, elle est ajoutée à la fin de la liste.
 *
 * \param liste Pointeur double vers la liste de textures.
 * \param Texture Pointeur double vers la texture à ajouter.
 */

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

/**
 * \brief Détruit une liste de textures et libère la mémoire associée.
 *
 * Cette fonction parcourt la liste de textures et détruit chaque texture SDL, libérant ainsi la mémoire
 * associée à chaque texture et à la liste elle-même.
 *
 * \param liste Pointeur double vers la liste de textures à détruire.
 */

extern
void detruireListeT(listeT_t **liste) {
  if(*liste!=NULL) {
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
}

/**
 * \brief Crée une texture à partir d'un fichier image.
 *
 * Cette fonction charge une image à partir d'un fichier spécifié et crée une texture SDL à partir de cette image.
 *
 * \param renderer Le renderer SDL utilisé pour créer la texture.
 * \param image Chemin vers le fichier image à charger.
 * \return La texture SDL créée ou NULL en cas d'erreur.
 */

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

/**
 * \brief Crée une texture de texte à partir d'une chaîne de caractères.
 *
 * Cette fonction crée une texture SDL à partir d'une chaîne de caractères en utilisant une police spécifiée.
 *
 * \param renderer Le renderer SDL utilisé pour créer la texture.
 * \param font La police TTF utilisée pour rendre le texte.
 * \param texte La chaîne de caractères à rendre en texture.
 * \param couleur La couleur du texte.
 * \return La texture SDL créée ou NULL en cas d'erreur.
 */

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

/**
 * \brief Crée une nouvelle liste de rectangles.
 *
 * Cette fonction alloue de la mémoire pour une nouvelle liste de rectangles et initialise ses membres.
 *
 * \return Pointeur vers la nouvelle liste de rectangles créée.
 */

extern
listeRect *creerListeRect() {
  listeRect *liste = malloc(sizeof(listeRect));
  liste->pRect = NULL;
  liste->suivant = NULL;
  return liste;
}

/**
 * \brief Ajoute un rectangle à la liste de rectangles.
 *
 * Cette fonction insère un nouveau rectangle dans la liste de rectangles. Si la liste est vide, le rectangle
 * est ajouté en premier élément. Sinon, il est ajouté à la fin de la liste.
 *
 * \param liste Pointeur double vers la liste de rectangles.
 * \param Rect Pointeur double vers le rectangle à ajouter.
 */

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

/**
 * \brief Détruit une liste de rectangles et libère la mémoire associée.
 *
 * Cette fonction parcourt la liste de rectangles et libère la mémoire associée à chaque rectangle et à la liste elle-même.
 *
 * \param liste Pointeur double vers la liste de rectangles à détruire.
 */

extern
void detruireListeRect(listeRect **liste)
{
  if(*liste!=NULL) {
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
}

/**
 * \brief Met à jour les dimensions et positions des rectangles dans la liste en fonction des ratios spécifiés.
 *
 * Cette fonction ajuste les dimensions et les positions des rectangles dans la liste en utilisant les ratios
 * stockés dans chaque structure de rectangle. Cela permet d'ajuster dynamiquement les dimensions des éléments
 * graphiques en fonction des dimensions de la fenêtre.
 *
 * \param liste Pointeur vers la liste de rectangles à mettre à jour.
 */

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

/**
 * \brief Crée un nouveau rectangle avec des dimensions et des positions calculées à partir de ratios.
 *
 * Cette fonction crée un nouveau rectangle dont les dimensions et la position sont déterminées par des ratios
 * appliqués aux dimensions fournies. Cela permet un positionnement et un dimensionnement flexibles en fonction
 * des dimensions de la fenêtre ou d'autres références.
 *
 * \param largeur Pointeur vers la largeur de référence.
 * \param hauteur Pointeur vers la hauteur de référence.
 * \param rX Ratio pour calculer la position x du rectangle.
 * \param rY Ratio pour calculer la position y du rectangle.
 * \param rW Ratio pour calculer la largeur du rectangle.
 * \param rH Ratio pour calculer la hauteur du rectangle.
 * \return Pointeur vers le nouveau rectangle créé.
 */

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