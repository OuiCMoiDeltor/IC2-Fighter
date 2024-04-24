/**
 * \file   combat.c
 * \brief  Gestion des combats dans le jeu
 *
 * Ce fichier contient les fonctions nécessaires pour orchestrer les combats dans le jeu, gérant les interactions
 * entre les personnages, le déroulement des rounds, et les affichages associés. Il comprend la gestion de l'interface
 * du combat, le suivi du temps, l'affichage des informations des personnages (santé, état), ainsi que la gestion des
 * effets sonores et de la musique de fond pour une expérience immersive. Les transitions entre les états de combat et
 * les rounds sont également pris en charge.
 *
 * \author IC2-Fighter
 * \version 1.0
 * \date 2024
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../lib/combat.h"
#include "../lib/perso.h"

// Images
#define IMG_GAME_BG "img/combat/amphi_combat.bmp"
#define IMG_STUN "img/combat/etourdi.bmp"
#define IMG_VICTOIRE1 "img/combat/victoireJ1.bmp"
#define IMG_VICTOIRE2 "img/combat/victoireJ2.bmp"
#define SOUND_BACKGROUND_COMBAT "mixer/son_combat.mp3"
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

#define DUREE_ROUND 120
#define ROUND_GAGNANT 2

/**
 * \brief Affiche le début d'un round avec un décompte avant le début du combat.
 *
 * Cette fonction initialise l'affichage pour un nouveau round en affichant le fond, les personnages
 * et un texte indiquant le numéro du round suivi d'un décompte. Elle prépare l'écran pour le combat,
 * permettant aux joueurs de se préparer visuellement.
 *
 * \param renderer Pointeur vers le rendu SDL.
 * \param largeurF Largeur de la fenêtre d'affichage.
 * \param hauteurF Hauteur de la fenêtre d'affichage.
 * \param round Numéro du round en cours.
 * \param Joueur1 Pointeur vers la structure du premier joueur.
 * \param Joueur2 Pointeur vers la structure du deuxième joueur.
 * \param BG Texture de fond à utiliser pour l'affichage.
 */

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

/**
 * \brief Initialise les personnages au début d'un round.
 *
 * Réinitialise les états et positions des personnages, définissant leur santé initiale, position sur l'écran,
 * et prépare les pseudonymes pour l'affichage. Cette fonction est appelée à chaque début de round pour
 * remettre à zéro les conditions des combattants.
 *
 * \param renderer Pointeur vers le rendu SDL.
 * \param J1 Pointeur vers la structure du premier combattant.
 * \param J2 Pointeur vers la structure du deuxième combattant.
 */

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
    if(J1->pseudo->txt == NULL) {
        J1->pseudo->txt = creerTexte(renderer, font, "Joueur1", textColor);
        J1->pseudo->rect->rect->x = *J1->pos->largeur/100.0;
        J1->pseudo->rect->rect->y = *J1->pos->hauteur/100.0;
        J1->pseudo->rect->rect->w = (*J1->pos->largeur/100)*20.0;
        J1->pseudo->rect->rect->h = *J1->pos->hauteur/15.0;
    }

    if(J2->pseudo->txt == NULL) {
        J2->pseudo->txt = creerTexte(renderer, font, "Joueur2", textColor);
        J2->pseudo->rect->rect->x = (*J2->pos->largeur/100)*85.0;
        J2->pseudo->rect->rect->y = *J2->pos->hauteur/100.0;
        J2->pseudo->rect->rect->w = (*J2->pos->largeur/100)*20.0;
        J2->pseudo->rect->rect->h = *J2->pos->hauteur/15.0;
    }

    TTF_CloseFont(font);
}

/**
 * \brief Gère le déroulement d'un round de combat.
 *
 * Cette fonction contrôle le temps, gère les entrées des utilisateurs et met à jour l'affichage
 * des personnages et de leurs interactions. Elle détermine également le résultat du round en
 * fonction de la santé des personnages et du temps écoulé.
 *
 * \param renderer Pointeur vers le rendu SDL.
 * \param keyboardState État actuel du clavier pour détecter les entrées.
 * \param Joueur1 Pointeur vers le premier joueur.
 * \param Joueur2 Pointeur vers le deuxième joueur.
 * \param largeurF Largeur de la fenêtre d'affichage.
 * \param hauteurF Hauteur de la fenêtre d'affichage.
 * \param waitForFrame Délai pour synchroniser l'affichage.
 * \param hit Effet sonore pour les coups réussis.
 * \param dmg Effet sonore pour les dégâts reçus.
 * \param stun Effet sonore pour les étourdissements.
 * \param liste_touches Tableau pour le suivi des touches pressées.
 * \param round Numéro du round actuel.
 * \param stunTexture Texture utilisée pour l'affichage de l'étourdissement.
 * \param stunRect Rectangle pour l'affichage de l'étourdissement.
 * \param stunTextureRect Rectangles pour les animations d'étourdissement.
 * \return État du round (-1 pour la défaite du Joueur1, 1 pour la défaite du Joueur2, 0 pour autre).
 */

extern int roundStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int waitForFrame, Mix_Chunk * hit, Mix_Chunk * dmg, Mix_Chunk * stun, int * liste_touches, int round, SDL_Texture * stunTexture, rectangle * stunRect, SDL_Rect ** stunTextureRect) {
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
        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF, &waitForFrame, hit, dmg, stun, liste_touches, stunTexture, stunRect, stunTextureRect);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }

    SDL_DestroyTexture(gameBGTexture);
    TTF_CloseFont(font);
    if(quit) exit(EXIT_FAILURE) ;
    if(Joueur1->hp->pv <= 0 && Joueur2->hp->pv <= 0)
        return 0;
    if(Joueur1->hp->pv <= 0)
        return -1;
    if(Joueur2->hp->pv <= 0)
        return 1;
    return 0;
}

/**
 * \brief Lance et gère les séquences de combat jusqu'à la fin du match.
 *
 * Cette fonction orchestre les combats, gérant le chargement des ressources sonores, la préparation des personnages,
 * et le déroulement des rounds jusqu'à la conclusion du match. Elle détermine le gagnant et affiche l'écran de victoire.
 *
 * \param renderer Pointeur vers le rendu SDL.
 * \param keyboardState État du clavier pour détecter les entrées des utilisateurs.
 * \param Joueur1 Pointeur vers le premier joueur.
 * \param Joueur2 Pointeur vers le deuxième joueur.
 * \param largeurF Largeur de la fenêtre d'affichage.
 * \param hauteurF Hauteur de la fenêtre d'affichage.
 * \param son Indicateur pour la gestion de la musique de fond (1 pour activer, 0 pour désactiver).
 * \param liste_touches Tableau des touches actives pour la gestion des entrées.
 */

extern 
void combatStart(SDL_Renderer* renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int son, int * liste_touches) {
    // Chargement de la musique de fond et des effets sonores
    Mix_Music *backgroundCombatSound = Mix_LoadMUS(SOUND_BACKGROUND_COMBAT);
    Mix_Chunk *soundHIT = Mix_LoadWAV("mixer/hit.wav");
    Mix_VolumeChunk(soundHIT, MIX_MAX_VOLUME / 8);
    Mix_Chunk *soundDMG = Mix_LoadWAV("mixer/ouh.wav");
    Mix_VolumeChunk(soundDMG, MIX_MAX_VOLUME / 3);
    Mix_Chunk *soundStun = Mix_LoadWAV("mixer/Pika.wav");
    Mix_VolumeChunk(soundStun, MIX_MAX_VOLUME);

    // Configuration initiale du volume
    Mix_VolumeMusic(MIX_MAX_VOLUME * 0.1);
    if(son) {
        Mix_HaltMusic();
        Mix_PlayMusic(backgroundCombatSound, -1);
    }

    SDL_Texture * stunTexture = creerImage(renderer, IMG_STUN);
    rectangle * stunRect = creerRectangle(&largeurF, &hauteurF, 1.0, 4.0, 20.0, 20.0);
    SDL_Rect ** stunTextureRect = malloc(sizeof(SDL_Rect*)*4);
    int i;
    for(i = 0 ; i < 4 ; i++) {
        stunTextureRect[i] = malloc(sizeof(SDL_Rect));
        stunTextureRect[i]->x = 380*i;
        stunTextureRect[i]->y = 0;
        stunTextureRect[i]->w = 380;
        stunTextureRect[i]->h = 270;
    }

    int v1 = 0, v2 = 0, v;

    // Déroulement des rounds
    while(v1 != ROUND_GAGNANT && v2 != ROUND_GAGNANT) {
        initPerso(renderer, Joueur1, Joueur2);
        if((v = roundStart(renderer, keyboardState, Joueur1, Joueur2, largeurF, hauteurF, 0, soundHIT, soundDMG, soundStun, liste_touches, v1+v2+1, stunTexture, stunRect, stunTextureRect)) == 1) v1++;
        else if(v == -1) v2++;
    }

    // Après les trois rounds, afficher un fond spécifique
    SDL_Texture *finalBGTexture;
    if(v1 == ROUND_GAGNANT) {
        finalBGTexture = IMG_LoadTexture(renderer, IMG_VICTOIRE1);
        if (finalBGTexture == NULL) {
            fprintf(stderr, "Erreur chargement de l'image de fond finale : %s\n", SDL_GetError());
        } else {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, finalBGTexture, NULL, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            SDL_DestroyTexture(finalBGTexture);
        }
    }else {
        finalBGTexture = IMG_LoadTexture(renderer, IMG_VICTOIRE2);
        if (finalBGTexture == NULL) {
            fprintf(stderr, "Erreur chargement de l'image de fond finale : %s\n", SDL_GetError());
        } else {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, finalBGTexture, NULL, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            SDL_DestroyTexture(finalBGTexture);
        }
    }

    detruirePerso(&Joueur1);
    detruirePerso(&Joueur2);

    SDL_DestroyTexture(stunTexture);
    free(stunRect->rect);
    free(stunRect);
    for( i = 0 ; i < 4 ; i++)
        free(stunTextureRect[i]);
    free(stunTextureRect);

    // Nettoyage des ressources audio
    Mix_FreeMusic(backgroundCombatSound);
    Mix_FreeChunk(soundHIT);
    Mix_FreeChunk(soundDMG);
    Mix_FreeChunk(soundStun);
}
