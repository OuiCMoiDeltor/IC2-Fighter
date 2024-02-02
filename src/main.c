#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// .h
#include "../lib/creation.h"
#include "../lib/bouton.h"

// Fenêtre
#define NOM_JEU "IC2 Fighter"
#define LARGEUR_F 800
#define HAUTEUR_F 600

// Images
#define IMG_MAIN_SCREEN "../img/ic2.bmp"
#define IMG_LOGO "../img/Logo.bmp"
#define IMG_BOUTON_OPT "../img/Options.bmp"

// Texte
#define TTF_CONTRAST "../ttf/city_contrasts/contrast.ttf"

typedef enum {MENU_PRINCIPAL, OPTIONS}scenes;

int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Initialisation de TTF
    if(TTF_Init()==-1) {
        printf("Erreur lors de l'initialisation de la librairie TTF_Init: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    // Chargement de la police en taille 16
    TTF_Font *font = TTF_OpenFont(TTF_CONTRAST, 64);
    if(!font) {
        printf("Erreur lors du chargement de la police TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    // Couleurs
    SDL_Color noire = {0,0,0};

    // Création de la fenêtre
    SDL_Window *window = SDL_CreateWindow(NOM_JEU, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_F, HAUTEUR_F, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    #include "../lib/menu_principal/init_menu_principal.h"

    // Boucle principale
    int quit = 0;
    SDL_Event e;
    scenes scene = MENU_PRINCIPAL;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            #include "../lib/menu_principal/event_menu_principal.h"
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        #include "../lib/menu_principal/affichage_menu_principal.h"

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);
    }

    // Libération des ressources
    DestroyBouton(&boutonOptions);
    SDL_DestroyTexture(imageTexture); imageTexture = NULL;
    SDL_DestroyTexture(logoTexture); logoTexture = NULL;
    SDL_DestroyRenderer(renderer); renderer = NULL;
    SDL_DestroyWindow(window); window = NULL;
    TTF_CloseFont(font); font = NULL;
    TTF_Quit();
    SDL_Quit();

    return 0;
}
