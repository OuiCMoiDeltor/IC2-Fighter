/**
 * @file gamemode_selection.c
 * @brief Fichier implémentant la sélection du mode de jeu dans l'application.
 *
 * Ce fichier contient les fonctions et définitions nécessaires pour permettre à l'utilisateur de choisir entre
 * différents modes de jeu dans l'application. Il gère également l'affichage des différents modes de jeu et 
 * intègre des interactions utilisateur via des boutons.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"

// Images
#define IMG_GAMEMODE_BG "img/gamemode_select/menu-multi.bmp"
#define IMG_GAMEMODE_LOCAL "img/gamemode_select/local.bmp"
#define IMG_GAMEMODE_LIGNE "img/gamemode_select/ligne.bmp"
#define IMG_GAMEMODE_RETOUR "img/options/optionsBack.bmp"

/**
 * @brief Fonction pour gérer la sélection du mode de jeu.
 *
 * Cette fonction affiche les options de mode de jeu et gère les interactions de l'utilisateur avec les boutons
 * pour choisir entre jouer localement ou en ligne. Elle met à jour la scène en fonction du choix de l'utilisateur.
 *
 * @param e Un SDL_Event pour gérer les entrées utilisateur.
 * @param renderer Le renderer SDL utilisé pour dessiner à l'écran.
 * @param largeurF La largeur de la fenêtre du jeu.
 * @param hauteurF La hauteur de la fenêtre du jeu.
 * @param scene Un pointeur vers l'entier qui contrôle la scène actuelle de l'application.
 * @param son Indicateur si le son est activé ou non.
 * @param backgroundSoundSelect Le son de fond à jouer pendant la sélection du mode.
 * @return Un entier indiquant le succès ou l'échec de la fonction.
 */
 
extern int gamemode_selection(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int son, Mix_Music * backgroundSoundSelect);
