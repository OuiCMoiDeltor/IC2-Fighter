/**
 * @file champ_select.h
 * @brief En-tête pour la sélection des personnages dans le jeu.
 *
 * Ce fichier d'en-tête définit les ressources et fonctions nécessaires à la mise en œuvre de l'écran de sélection des personnages
 * dans le jeu. Il inclut des détails sur les textures utilisées pour les différents personnages et l'arrière-plan de l'écran de sélection,
 * ainsi que la fonction principale gérant cet écran.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"
#include "touches.h"
#include "perso.h"
#include "combat.h"

// Images
#define IMG_CHAMPSELECT_BG "img/champ_select/amphi.bmp"
#define IMG_CHAMPSELECT_LOCKED "img/champ_select/locked.bmp"
#define IMG_CHAMPSELECT_YASS "img/champ_select/YacineCS.bmp"
#define IMG_CHAMPSELECT_DIM "img/champ_select/DimCS.bmp"
#define IMG_CHAMPSELECT_DAM "img/champ_select/DamienCS.bmp"
#define IMG_CHAMPSELECT_J1 "img/champ_select/selectJ1.bmp"
#define IMG_CHAMPSELECT_J2 "img/champ_select/selectJ2.bmp"
#define IMG_GAMEMODE_RETOUR "img/options/optionsBack.bmp"
#define RYU "img/champ_select/ryuic2.bmp"
#define MNX "img/champ_select/sprite_mnx.bmp"
#define YASS "img/champ_select/sprite_yacine.bmp"
#define DAM "img/champ_select/damien_prout.bmp"
#define SOUND_BACKGROUND_SELECT "mixer/giga_chad.mp3"

/**
 * @brief Fonction de sélection des personnages.
 *
 * Cette fonction gère l'écran de sélection des personnages, permettant aux joueurs de choisir parmi plusieurs options.
 * Elle traite les entrées utilisateur et met à jour l'affichage en conséquence.
 *
 * @param e Événement SDL capturé.
 * @param renderer Pointeur vers le renderer SDL.
 * @param largeurF Largeur de la fenêtre.
 * @param hauteurF Hauteur de la fenêtre.
 * @param scene Pointeur vers la variable contrôlant la scène actuelle du jeu.
 * @param son Indicateur d'activation du son.
 * @param liste_touches Tableau des touches configurées pour le jeu.
 * @param keyboardState État actuel du clavier.
 * @return int Code pour contrôler le flux du jeu (continuer, changer de scène, quitter).
 */

extern int champ_select(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int son, int * liste_touches, Uint8 * keyboardState);

