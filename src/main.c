#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "../lib/bouton.h"
#include "../lib/perso.h"
#include "../lib/combat.h"
#include "../lib/touches.h"
#include "../lib/champ_select.h"
#include "../lib/controle.h"
#include "../lib/gamemode_selection.h"
#include "../lib/menu_principal.h"
#include "../lib/options.h"

// Fenêtre
#define NOM_JEU "IC2 Fighter"
#define ICONE "img/menu_principal/logo.bmp"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

// Music
#define SOUND_BACKGROUND "mixer/Leateq - Tokyo.mp3"

typedef enum {CONTROLE, OPTIONS, MENU_PRINCIPAL, GAMEMODE, CHAMP_SELECT}scenes;

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

    // Boucle principale
    int quit = 0;
    SDL_Event e;
    scenes scene = MENU_PRINCIPAL; // Première scene à afficher
    Mix_Music *backgroundSound = Mix_LoadMUS(SOUND_BACKGROUND); // Chargement musique de fond
    Mix_VolumeMusic(MIX_MAX_VOLUME * 0.1); //Réglage niveau de son
    Mix_PlayMusic(backgroundSound, -1); // Son background joué indéfiniment
    int liste_touches[14] = {SDL_SCANCODE_W, SDL_SCANCODE_UP, SDL_SCANCODE_S, SDL_SCANCODE_DOWN, SDL_SCANCODE_A, SDL_SCANCODE_LEFT, SDL_SCANCODE_D, SDL_SCANCODE_RIGHT, SDL_SCANCODE_C, SDL_SCANCODE_KP_5, SDL_SCANCODE_V, SDL_SCANCODE_KP_6, SDL_SCANCODE_F, SDL_SCANCODE_KP_4};
    Uint8 *keyboardState = (Uint8 *)SDL_GetKeyboardState(NULL);

    while (!quit) {
        switch (scene)
        {
        case CONTROLE:
            quit = controle(e, renderer, largeurF, hauteurF, (int*)&scene, liste_touches);
            break;

        case OPTIONS:
            quit = options(e, renderer, window, largeurF, hauteurF, (int*)&scene, &son, &fullscreen, backgroundSound);
            break;

        case MENU_PRINCIPAL:
            quit = menu_principal(e, renderer, largeurF, hauteurF, (int*)&scene);
            break;

        case GAMEMODE:
            quit = gamemode_selection(e, renderer, largeurF, hauteurF, (int*)&scene, son, backgroundSound);
            break;

        case CHAMP_SELECT:
            quit = champ_select(e, renderer, largeurF, hauteurF, (int*)&scene, son, liste_touches, keyboardState);
            break;
        
        default:
            break;
        }
        SDL_Log("%d", scene);
    }

    // Libération des ressources
    Mix_HaltMusic();
    Mix_FreeMusic(backgroundSound);
    SDL_DestroyRenderer(renderer); renderer = NULL;
    SDL_DestroyWindow(window); window = NULL;
    Mix_CloseAudio();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();

    return 0;
}
