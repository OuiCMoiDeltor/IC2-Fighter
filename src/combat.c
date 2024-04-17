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

#define DUREE_ROUND 60
#define ROUND_GAGNANT 2

extern 
void afficherRound(SDL_Renderer* renderer, int largeurF, int hauteurF, int round, personnage * Joueur1, personnage * Joueur2, SDL_Texture * BG) {
    char roundText[20];
    sprintf(roundText, "Round %d", round);
    SDL_Color textColor = {0, 0, 0, 255};

    TTF_Font* font = TTF_OpenFont(TTF_FONT, 64);
    if (font == NULL) {
        fprintf(stderr, "Erreur chargement de la police : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Texture* textTexture = creerTexte(renderer, font, roundText, textColor);
    if (textTexture == NULL) {
        fprintf(stderr, "Erreur création texture de texte : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    rectangle * textRect = creerRectangle(&largeurF, &hauteurF, 4.0, 100.0, 4/2.0, 8.0);

    // Affichage du "Round x"
    SDL_RenderCopy(renderer, BG, NULL, NULL);
    SDL_RenderCopy(renderer, textTexture, NULL, textRect->rect);
    SDL_RenderCopy(renderer, Joueur1->texture, Joueur1->idle[0], Joueur1->pos->rect);
    SDL_RenderCopyEx(renderer, Joueur2->texture, Joueur2->idle[0], Joueur2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(textTexture);
    free(textRect->rect);
    free(textRect);
    SDL_Delay(2000);

    char countdownText[20];
    // Décompte "Combat dans x"
    for (int i = 3; i > 0; i--) {
        sprintf(countdownText, "Combat dans %d", i);
        textTexture = creerTexte(renderer, font, countdownText, textColor);
        if (textTexture == NULL) {
            fprintf(stderr, "Erreur création texture de décompte : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        rectangle * countdownRect = creerRectangle(&largeurF, &hauteurF, 4.0, 100.0, 4/2.0, 8.0);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, BG, NULL, NULL);
        SDL_RenderCopy(renderer, textTexture, NULL, countdownRect->rect);
        SDL_RenderCopy(renderer, Joueur1->texture, Joueur1->idle[0], Joueur1->pos->rect);
        SDL_RenderCopyEx(renderer, Joueur2->texture, Joueur2->idle[0], Joueur2->pos->rect, 180, NULL, SDL_FLIP_VERTICAL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(textTexture);
        free(countdownRect->rect);
        free(countdownRect);
        SDL_Delay(1000);
    }

    TTF_CloseFont(font);
}





extern
void initPerso(SDL_Renderer * renderer, personnage * J1, personnage * J2) {
    // Reset animation
    J1->animation = AUCUNE;
    J1->etatAnimation = 0;

    J2->animation = AUCUNE;
    J2->etatAnimation = 0;

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

extern int roundStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int waitForFrame, Mix_Chunk * hit, Mix_Chunk * dmg, int * liste_touches, int round) {
    Uint32 roundStart = SDL_GetTicks();  // Temps de démarrage du round
    Uint32 currentTime;
    int timer = DUREE_ROUND;  // Démarre le timer à partir de roundDuration
    
    SDL_Texture *gameBGTexture = creerImage(renderer, IMG_GAME_BG);
    if(gameBGTexture == NULL) exit(EXIT_FAILURE);

    TTF_Font *font = TTF_OpenFont(TTF_FONT, 32); // Pour afficher le timer
    if (font == NULL) {
        fprintf(stderr, "Erreur chargement de la police pour le timer : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    
    SDL_Color textColor = {0, 0, 0, 255};  // Couleur du texte pour le timer

    afficherRound(renderer, largeurF, hauteurF, round, Joueur1, Joueur2, gameBGTexture);

    SDL_Event e;
    int quit = 0;
    while (!quit && Joueur1->hp->pv > 0 && Joueur2->hp->pv > 0 && timer > 0) {
        currentTime = SDL_GetTicks();
        timer = DUREE_ROUND - (currentTime - roundStart) / 1000;  // Décrémenter le timer
        
        if (timer < 0) timer = 0;  // Garantir que le timer ne passe pas en dessous de zéro

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
                quit = 1;
            }
        }
        
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, gameBGTexture, NULL, NULL);
        
        // Affichage du timer
        char timerText[10];
        sprintf(timerText, "%d", timer);
        SDL_Texture * textTexture = creerTexte(renderer, font, timerText, textColor);
        rectangle * textRect = creerRectangle(&largeurF, &hauteurF, 100/48.0, 100/5.0, 100/4.0, 12.0);
        SDL_RenderCopy(renderer, textTexture, NULL, textRect->rect);
        free(textRect->rect);
        free(textRect);
        SDL_DestroyTexture(textTexture);
        
        // Affichage des autres éléments du jeu
        SDL_RenderCopy(renderer, Joueur1->pseudo->txt, NULL, Joueur1->pseudo->rect->rect);
        SDL_RenderCopy(renderer, Joueur2->pseudo->txt, NULL, Joueur2->pseudo->rect->rect);
        
        waitForFrame++;
        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF, &waitForFrame, hit, dmg, liste_touches);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }

    SDL_DestroyTexture(gameBGTexture);
    TTF_CloseFont(font);
    if(quit) exit(EXIT_FAILURE) ;
    return Joueur1->hp->pv > 0 ? 1 : 0;
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

    int v1 = 0, v2 = 0;

    // Déroulement des rounds
    while(v1 != ROUND_GAGNANT && v2 != ROUND_GAGNANT) {
        initPerso(renderer, Joueur1, Joueur2);
        if(roundStart(renderer, keyboardState, Joueur1, Joueur2, largeurF, hauteurF, 0, soundHIT, soundDMG, liste_touches, v1+v2+1)) v1++;
        else v2++;
    }

    // Après les trois rounds, afficher un fond spécifique
    SDL_Texture *finalBGTexture = IMG_LoadTexture(renderer, "img/apagnan.bmp");
    if (finalBGTexture == NULL) {
        fprintf(stderr, "Erreur chargement de l'image de fond finale : %s\n", SDL_GetError());
    } else {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, finalBGTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(5000);
        SDL_DestroyTexture(finalBGTexture);
    }

    // Nettoyage des ressources audio
    Mix_FreeMusic(backgroundCombatSound);
    Mix_FreeChunk(soundHIT);
    Mix_FreeChunk(soundDMG);
}
