#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../lib/creation.h"

//Fenêtre
#define NOM_JEU "IC2 Fighter"
#define LARGEUR_F 800
#define HAUTEUR_F 600

//Images
#define IMG_MAIN_SCREEN "../img/ic2.bmp"
#define IMG_LOGO "../img/Logo.bmp"


int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    SDL_Window *window = SDL_CreateWindow(NOM_JEU, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_F, HAUTEUR_F, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        return 1;
    }
    
    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        return 1;
    }

    // Création de l'image de fond
    SDL_Texture *imageTexture = creerImage(renderer, IMG_MAIN_SCREEN);
    if(imageTexture == NULL) return 1;
    
    // Création de l'image du logo
    SDL_Texture *logoTexture = creerImage(renderer, IMG_LOGO);
    if(logoTexture == NULL) return 1;

    // Création du rectangle pour le logo
    SDL_Rect logoRect = {LARGEUR_F/4, HAUTEUR_F/3/4, LARGEUR_F/2, HAUTEUR_F/3 - HAUTEUR_F/3/4};
    
    // Boucle principale
    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        // Dessiner l'image
        SDL_RenderCopy(renderer, imageTexture, NULL, NULL);

        // Dessiner le logo
        SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect);

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);
    }

    // Libération des ressources
    SDL_DestroyTexture(imageTexture);
    SDL_DestroyTexture(logoTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
