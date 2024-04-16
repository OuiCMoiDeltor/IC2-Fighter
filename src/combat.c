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
int roundStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int waitForFrame, Mix_Chunk * hit, Mix_Chunk * dmg) {

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
        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF, &waitForFrame, hit, dmg);

        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }
    SDL_DestroyTexture(gameBGTexture);
    return 0;
}

extern
void combatStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int son) {
    // Son
    // Chargement musique de fond
    Mix_Music *backgroundCombatSound = Mix_LoadMUS(SOUND_BACKGROUND_COMBAT);
    Mix_Chunk *soundHIT = Mix_LoadWAV("mixer/hit.wav") ;
    Mix_VolumeChunk(soundHIT, MIX_MAX_VOLUME / 8);
    Mix_Chunk *soundDMG = Mix_LoadWAV("mixer/ouh.wav");
    Mix_VolumeChunk(soundDMG, MIX_MAX_VOLUME / 3);

    Mix_VolumeMusic(MIX_MAX_VOLUME * 0.1); //Réglage niveau de son
    if(son) {
        Mix_HaltMusic(); // Arrête toute musique actuellement jouée
        Mix_PlayMusic(backgroundCombatSound, -1); // Joue la musique de fond pour l'écran de sélection
    }

    initPerso(renderer, Joueur1, Joueur2);
    roundStart(renderer, keyboardState, Joueur1, Joueur2, largeurF, hauteurF, 0, soundHIT, soundDMG);

    initPerso(renderer, Joueur1, Joueur2);
    roundStart(renderer, keyboardState, Joueur1, Joueur2, largeurF, hauteurF, 0, soundHIT, soundDMG);

    initPerso(renderer, Joueur1, Joueur2);
    roundStart(renderer, keyboardState, Joueur1, Joueur2, largeurF, hauteurF, 0, soundHIT, soundDMG);

    Mix_FreeMusic(backgroundCombatSound);
    Mix_FreeChunk(soundHIT);
    Mix_FreeChunk(soundDMG);

    // Free des persos
    // Retour Champ select

}
