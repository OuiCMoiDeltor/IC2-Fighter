#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../lib/combat.h"
#include "../lib/perso.h"

// Images
#define IMG_GAME_BG "img/amphi_combat.bmp"
#define SOUND_BACKGROUND_COMBAT "mixer/son_combat.mp3"
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

extern 
void afficherRound(SDL_Renderer* renderer, int round, int duree_round) {
    char roundText[20];
    sprintf(roundText, "Round %d", round);
    SDL_Color textColor = {0, 0, 0, 255};

    TTF_Font* font = TTF_OpenFont(TTF_FONT, 64);
    if (font == NULL) {
        fprintf(stderr, "Erreur chargement de la police : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Texture* bgTexture = IMG_LoadTexture(renderer, IMG_GAME_BG);
    if (bgTexture == NULL) {
        fprintf(stderr, "Erreur chargement de l'image de fond : %s\n", SDL_GetError());
        TTF_CloseFont(font);
        exit(EXIT_FAILURE);
    }

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, roundText, textColor);
    if (textSurface == NULL) {
        fprintf(stderr, "Erreur création surface de texte : %s\n", SDL_GetError());
        TTF_CloseFont(font);
        SDL_DestroyTexture(bgTexture);
        exit(EXIT_FAILURE);
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
        fprintf(stderr, "Erreur création texture de texte : %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        SDL_DestroyTexture(bgTexture);
        exit(EXIT_FAILURE);
    }

    SDL_Rect textRect = {500 - textSurface->w / 2, 300 - textSurface->h / 2, textSurface->w, textSurface->h};
    SDL_FreeSurface(textSurface);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(textTexture);
    SDL_Delay(2000);

    for (int i = 3; i > 0; i--) {
        char countdownText[20];
        sprintf(countdownText, "Combat dans %d", i);
        textSurface = TTF_RenderText_Solid(font, countdownText, textColor);
        if (textSurface == NULL) {
            fprintf(stderr, "Erreur création surface de décompte : %s\n", SDL_GetError());
            TTF_CloseFont(font);
            SDL_DestroyTexture(bgTexture);
            exit(EXIT_FAILURE);
        }
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (textTexture == NULL) {
            fprintf(stderr, "Erreur création texture de décompte : %s\n", SDL_GetError());
            SDL_FreeSurface(textSurface);
            TTF_CloseFont(font);
            SDL_DestroyTexture(bgTexture);
            exit(EXIT_FAILURE);
        }
        SDL_Rect countdownRect = {320 - textSurface->w / 2, 300 - textSurface->h / 2, textSurface->w, textSurface->h};
        SDL_FreeSurface(textSurface);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
        SDL_RenderCopy(renderer, textTexture, NULL, &countdownRect);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(textTexture);
        SDL_Delay(1000);
    }

    SDL_DestroyTexture(bgTexture);
    TTF_CloseFont(font);
}





extern
void initPerso(SDL_Renderer * renderer, personnage * J1, personnage * J2) {
    // Position
    J1->pos->rect->x = *J1->pos->largeur/10.0;
    J1->pos->rect->y = *J1->pos->hauteur/10.0;

    J2->pos->rect->x = *J2->pos->largeur/10*5.0;
    J2->pos->rect->y = *J2->pos->hauteur/10.0;

    // HP
    J1->hp->pv = VIE_MAX;
    J1->hp->barrePv->x = 100/8;
    J1->hp->barrePv->y = 100/2;
    J1->hp->barrePv->w = 550;
    J1->hp->barrePv->h = 35;

    J2->hp->pv = VIE_MAX;
    J2->hp->barrePv->x = 720;
    J2->hp->barrePv->y = 100/2;
    J2->hp->barrePv->w = 550;
    J2->hp->barrePv->h = 35;

    // Pseudo
    TTF_Font * font = TTF_OpenFont(TTF_FONT, 32);
    SDL_Color textColor = {255, 255, 255, 255};
    J1->pseudo->txt = creerTexte(renderer, font, "Joueur1", textColor);
    J1->pseudo->rect = creerRectangle(J1->pos->largeur, J1->pos->hauteur, 100.0, 100.0, 100/20.0, 15.0);

    J2->pseudo->txt = creerTexte(renderer, font, "Joueur2", textColor);
    J2->pseudo->rect = creerRectangle(J2->pos->largeur, J2->pos->hauteur, 100/79.0, 100.0, 100/20.0, 15.0);

    TTF_CloseFont(font);
}

extern
int roundStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int waitForFrame, Mix_Chunk * hit, Mix_Chunk * dmg, int * liste_touches) {

    // Création de l'image de fond
    SDL_Texture *gameBGTexture = creerImage(renderer, IMG_GAME_BG);
    if(gameBGTexture == NULL) exit(EXIT_FAILURE);

    SDL_RenderCopy(renderer, gameBGTexture, NULL, NULL);
    SDL_RenderCopy(renderer, Joueur1->pseudo->txt, NULL, Joueur1->pseudo->rect->rect);
    SDL_RenderCopy(renderer, Joueur2->pseudo->txt, NULL, Joueur2->pseudo->rect->rect);
    SDL_RenderCopy(renderer, Joueur1->texture, Joueur1->idle[0], Joueur1->pos->rect);
    SDL_RenderCopy(renderer, Joueur2->texture, Joueur2->idle[0], Joueur2->pos->rect);

    SDL_Event e;
    int quit = 0;
    while (!quit && Joueur1->hp->pv > 0 && Joueur2->hp->pv > 0) {
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
        }
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, gameBGTexture, NULL, NULL);

        SDL_RenderCopy(renderer, Joueur1->pseudo->txt, NULL, Joueur1->pseudo->rect->rect);
        SDL_RenderCopy(renderer, Joueur2->pseudo->txt, NULL, Joueur2->pseudo->rect->rect);

        waitForFrame++;
        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF, &waitForFrame, hit, dmg, liste_touches);

        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }
    SDL_DestroyTexture(gameBGTexture);
    return 0;
}

extern 
void combatStart(SDL_Renderer* renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int son, int * liste_touches) {
    // Chargement de la musique de fond et des effets sonores
    Mix_Music *backgroundCombatSound = Mix_LoadMUS(SOUND_BACKGROUND_COMBAT);
    Mix_Chunk *soundHIT = Mix_LoadWAV("mixer/hit.wav");
    Mix_VolumeChunk(soundHIT, MIX_MAX_VOLUME / 8);
    Mix_Chunk *soundDMG = Mix_LoadWAV("mixer/ouh.wav");
    Mix_VolumeChunk(soundDMG, MIX_MAX_VOLUME / 3);

    // Configuration initiale du volume
    Mix_VolumeMusic(MIX_MAX_VOLUME * 0.1);
    if(son) {
        Mix_HaltMusic();
        Mix_PlayMusic(backgroundCombatSound, -1);
    }

    // Déroulement des rounds
    for (int round = 1; round <= 3; round++) {
        // Affiche "Round x" et fait un compte à rebours
        afficherRound(renderer, round, SDL_GetTicks());

        // Initialisation des personnages et démarrage du round
        initPerso(renderer, Joueur1, Joueur2);
        roundStart(renderer, keyboardState, Joueur1, Joueur2, largeurF, hauteurF, 0, soundHIT, soundDMG, liste_touches);
    }

    // Nettoyage des ressources audio
    Mix_FreeMusic(backgroundCombatSound);
    Mix_FreeChunk(soundHIT);
    Mix_FreeChunk(soundDMG);
}
