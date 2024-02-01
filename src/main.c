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

    // Création de l'image de fond
    SDL_Texture *imageTexture = creerImage(renderer, IMG_MAIN_SCREEN);
    if(imageTexture == NULL) exit(EXIT_FAILURE);
    
    // Création du logo
    SDL_Texture *logoTexture = creerImage(renderer, IMG_LOGO);
    if(logoTexture == NULL) exit(EXIT_FAILURE);
    SDL_Rect logoRect = {LARGEUR_F/4, HAUTEUR_F/3/4, LARGEUR_F/2, HAUTEUR_F/3 - HAUTEUR_F/3/4};

    // Boutons du menu principal
        //Options
        int largeurOptions = LARGEUR_F/(1400/280);
        int hauteurOptions = HAUTEUR_F/2;
        bouton *boutonOptions = creerBouton(renderer, LARGEUR_F/(1400/65), HAUTEUR_F/(1045/115), largeurOptions, hauteurOptions, IMG_BOUTON_OPT);
        if(boutonOptions == NULL) exit(EXIT_FAILURE);

    // Boucle principale
    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions) {
                boutonOptions->etat = BOUTON_APPUYE;
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions) {
                quit = 1;
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptions->etat == BOUTON_APPUYE  || boutonOptions->etat == BOUTON_OVER && !(e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions)) {
                boutonOptions->etat = BOUTON_RELACHE;
            }else if (e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions && boutonOptions->etat == BOUTON_RELACHE) {
                boutonOptions->etat = BOUTON_OVER;
            }
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        // Dessiner l'image
        SDL_RenderCopy(renderer, imageTexture, NULL, NULL);

        // Dessiner le logo
        SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect);

        // Dessiner le bouton des Options
        if(boutonOptions->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->relache, boutonOptions->position);
        else if (boutonOptions->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->appuye, boutonOptions->position);
        else if (boutonOptions->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->over, boutonOptions->position);

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
