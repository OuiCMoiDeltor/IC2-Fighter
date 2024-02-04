#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "../lib/creation.h"
#include "../lib/bouton.h"

// Fenêtre
#define NOM_JEU "IC2 Fighter"

// Texte
#define TTF_CONTRAST "../ttf/city_contrasts/contrast.ttf"

#include "../lib/menu_principal/define_menu_principal.h"
#include "../lib/options/define_options.h"

typedef enum {MENU_PRINCIPAL, OPTIONS}scenes;

int main(int argc, char* argv[]) {
    // Initialisation de la taille de la fenêtre
    int largeurF = 800;
    int hauteurF = 600;

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
    SDL_Window *window = SDL_CreateWindow(NOM_JEU, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largeurF, hauteurF, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    
    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    #include "../lib/menu_principal/init_menu_principal.h" // Initialisation du menu principal
    #include "../lib/options/init_options.h" // Initialisation du menu options

    // Boucle principale
    int quit = 0;
    SDL_Event e;
    scenes scene = MENU_PRINCIPAL; // Première scene à afficher

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            #include "../lib/menu_principal/event_menu_principal.h" // Evenements du menu principal
            #include "../lib/options/event_options.h" // Evenements du menu options
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        #include "../lib/menu_principal/affichage_menu_principal.h" // Affichage du menu principal
        #include "../lib/options/affichage_options.h" // Affichage du menu options

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);
    }

    // Libération des ressources
    DestroyBouton(&boutonOptions);
    SDL_DestroyTexture(mainMenuBGTexture); mainMenuBGTexture = NULL;
    SDL_DestroyTexture(logoTexture); logoTexture = NULL;
    SDL_DestroyRenderer(renderer); renderer = NULL;
    SDL_DestroyWindow(window); window = NULL;
    TTF_CloseFont(font); font = NULL;
    TTF_Quit();
    SDL_Quit();

    return 0;
}
