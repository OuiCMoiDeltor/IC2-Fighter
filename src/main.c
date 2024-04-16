#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "../lib/bouton.h"
#include "../lib/perso.h"
#include "../lib/combat.h"

// Fenêtre
#define NOM_JEU "IC2 Fighter"
#define ICONE "img/menu_principal/logo.bmp"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

#include "../lib/menu_principal/define_menu_principal.h"
#include "../lib/options/define_options.h"
#include "../lib/gamemode_selection/define_gamemode_selection.h"
#include "../lib/champ_select/define_champ_select.h"

typedef enum {MENU_PRINCIPAL, OPTIONS, GAMEMODE, CHAMP_SELECT, GAME}scenes;

int main(int argc, char* argv[]) {
    // Initialisation de la taille de la fenêtre
    int largeurF = 1280;
    int hauteurF = 720;

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    SDL_DisplayMode displayMode;
    if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) {
        SDL_Log("Erreur lors de l'obtention du mode d'affichage : %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Afficher la résolution de l'écran
    printf("Résolution de l'écran : %dx%d pixels\n", displayMode.w, displayMode.h);
    
    // Obtenir le nombre de modes d'affichage disponibles sur l'écran principal
    int displayIndex = 0; // Écran principal
    int numModes = SDL_GetNumDisplayModes(displayIndex);

    if (numModes < 1) {
        SDL_Log("Aucun mode d'affichage disponible : %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    printf("Résolutions prises en charge par l'écran principal :\n");

    for (int i = 0; i < numModes; i++) {
        SDL_DisplayMode mode;
        if (SDL_GetDisplayMode(displayIndex, i, &mode) != 0) {
            SDL_Log("Erreur lors de l'obtention du mode d'affichage : %s", SDL_GetError());
            SDL_Quit();
            return 1;
        }

        printf("Mode %d: %dx%d pixels, %dhz\n", i + 1, mode.w, mode.h, mode.refresh_rate);
    }

    // Initialisation de 
    if(TTF_Init()==-1) {
        printf("Erreur lors de l'initialisation de la librairie TTF_Init: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    // Chargement de la police en taille 16
    TTF_Font *font = TTF_OpenFont(TTF_FONT, 64);
    if(!font) {
        printf("Erreur lors du chargement de la police TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    // Couleurs
    SDL_Color noire = {0,0,0};

    // Initialisation de la musique de fond
     if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Erreur lors de l'initialisation de la musique de fond : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Initialisation format de l'audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    // Création de la fenêtre
    SDL_Window *window = SDL_CreateWindow(NOM_JEU, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largeurF, hauteurF, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowFullscreen(window, 0);
    int fullscreen = 0;
    int son = 1;
    
    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Surface *icone = SDL_LoadBMP(ICONE);
    if (icone == NULL)
    {
        printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_SetWindowIcon(window, icone);
    SDL_FreeSurface(icone);
    
    listeT_t *listeTexture = creerListeT(); // Stock les pointeurs sur texture
    listeRect *listeRectangle = creerListeRect(); // Stock les pointeurs sur Rectangle

    #include "../lib/menu_principal/init_menu_principal.h" // Initialisation du menu principal
    #include "../lib/options/init_options.h" // Initialisation du menu options
    #include "../lib/gamemode_selection/init_gamemode_selection.h" // Initialisation du menu de selection du mode de jeu
    #include "../lib/champ_select/init_champ_select.h" // Initialisation du menu de selection des personnages

    // Boucle principale
    int quit = 0;
    SDL_Event e;
    scenes scene = MENU_PRINCIPAL; // Première scene à afficher
    Mix_VolumeMusic(MIX_MAX_VOLUME * 0.3); //Réglage niveau de son
    Mix_PlayMusic(backgroundSound, -1); // Son background joué indéfiniment
    int waitForFrame = 0;
    Uint8 *keyboardState = (Uint8 *)SDL_GetKeyboardState(NULL);

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            else if (e.type == SDL_KEYDOWN) // Vérifier si un événement clavier est survenu
            {
                if (e.key.keysym.sym == SDLK_ESCAPE) // Vérifier si la touche pressée est Échap
                {
                    quit = 1 ; // Mettre fin à la boucle de jeu et fermer l'application
                }
            }
            #include "../lib/menu_principal/event_menu_principal.h" // Evenements du menu principal
            #include "../lib/options/event_options.h" // Evenements du menu options
            #include "../lib/gamemode_selection/event_gamemode_selection.h" // Evenements du menu de selection du mode de jeu
            #include "../lib/champ_select/event_champ_select.h" // Evenements du menu de selection des personnages
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        #include "../lib/menu_principal/affichage_menu_principal.h" // Affichage du menu principal
        #include "../lib/options/affichage_options.h" // Affichage du menu options
        #include "../lib/gamemode_selection/affichage_gamemode_selection.h" // Affichage du menu de selection du mode de jeu
        #include "../lib/champ_select/affichage_champ_select.h" // Affichage du menu de selection des personnages

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }

    // Libération des ressources
    detruireListeRect(&listeRectangle);
    DestroyBouton(&boutonRYU);
    DestroyBouton(&boutonGmBack);
    DestroyBouton(&boutonLigne);
    DestroyBouton(&boutonLocal);
    DestroyBouton(&boutonOptionsSoundOn);
    DestroyBouton(&boutonOptionsSoundOff);
    DestroyBouton(&boutonJouer);
    DestroyBouton(&boutonQuitter);
    DestroyBouton(&boutonOptions);
    DestroyBouton(&boutonOptionsSwapResLeft);
    DestroyBouton(&boutonOptionsSwapResRight);
    DestroyBouton(&boutonOptionsSwapAccept);
    DestroyBouton(&boutonOptionsFullscreenOn);
    DestroyBouton(&boutonOptionsFullscreenOff);
    DestroyBouton(&boutonOptionsBack);
    detruireListeT(&listeTexture);
    Mix_HaltMusic();
    Mix_FreeMusic(backgroundSound);
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer); renderer = NULL;
    SDL_DestroyWindow(window); window = NULL;
    TTF_CloseFont(font); font = NULL;
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();

    return 0;
}
