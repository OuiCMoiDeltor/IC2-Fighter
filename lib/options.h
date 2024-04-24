/**
 * @file options.c
 * @brief Fichier gérant les options du jeu "IC2 Fighter".
 *
 * Ce fichier contient les déclarations nécessaires pour afficher et gérer les options du jeu. Il inclut les interactions avec les boutons et les éléments de l'interface utilisateur pour modifier les paramètres tels que le son, la résolution et le mode plein écran. Les ressources graphiques utilisées pour les options sont également définies ici.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

// Images
#define IMG_OPTIONS_BG "img/options/optionsBG.bmp"
#define IMG_OPTIONS_TITLE "img/options/optionsTitle.bmp"
#define IMG_OPTIONS_SOUND_ON "img/options/optionsSoundOn.bmp"
#define IMG_OPTIONS_SOUND_OFF "img/options/optionsSoundOff.bmp"
#define IMG_OPTIONS_RESOLUTION "img/options/optionsResolution.bmp"
#define IMG_OPTIONS_RESOLUTION_LEFT "img/options/optionsFGauche.bmp"
#define IMG_OPTIONS_RESOLUTION_RIGHT "img/options/optionsFDroite.bmp"
#define IMG_OPTIONS_RESOLUTION_APPLIKER "img/options/optionsAppRes.bmp"
#define IMG_OPTIONS_FULLSCREEN "img/options/optionsPleinEcran.bmp"
#define IMG_OPTIONS_FULLSCREEN_TURN_ON "img/options/optionsFullscreenTurnOn.bmp"
#define IMG_OPTIONS_FULLSCREEN_TURN_OFF "img/options/optionsFullscreenTurnOff.bmp"
#define IMG_OPTIONS_BACK "img/options/optionsBack.bmp"
#define IMG_OPTIONS_CONTROLE "img/options/clavier.bmp"

/**
 * @brief Fonction pour afficher et gérer l'écran des options du jeu.
 *
 * Cette fonction configure l'affichage de l'écran des options et gère les interactions de l'utilisateur avec les différents éléments de l'interface utilisateur. Elle permet de modifier les paramètres tels que le son, la résolution et le mode plein écran, et de revenir au menu principal.
 *
 * @param e Un SDL_Event pour gérer les entrées utilisateur.
 * @param renderer Le renderer SDL utilisé pour dessiner à l'écran.
 * @param window La fenêtre SDL du jeu.
 * @param largeurF Un pointeur vers la largeur de la fenêtre du jeu.
 * @param hauteurF Un pointeur vers la hauteur de la fenêtre du jeu.
 * @param scene Un pointeur vers l'entier qui contrôle la scène actuelle de l'application.
 * @param son Un pointeur vers l'entier qui contrôle l'état du son (activé/désactivé).
 * @param fullscreen Un pointeur vers l'entier qui contrôle le mode plein écran (activé/désactivé).
 * @param backgroundSound Le Mix_Music utilisé comme musique de fond dans les options.
 * @return Un entier indiquant le succès ou l'échec de la fonction.
 */

extern int options(SDL_Event e, SDL_Renderer * renderer, SDL_Window * window, int * largeurF, int * hauteurF, int * scene, int * son, int * fullscreen, Mix_Music * backgroundSound);