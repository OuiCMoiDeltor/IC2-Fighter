/**
 * @file menu_principal.c
 * @brief Fichier gérant le menu principal du jeu "IC2 Fighter".
 *
 * Ce fichier contient les déclarations nécessaires pour afficher et gérer le menu principal du jeu. Il inclut
 * les interactions avec les boutons du menu pour naviguer dans les différentes options du jeu comme jouer, accéder 
 * aux options, ou quitter le jeu. Les ressources graphiques et sonores utilisées pour le menu sont également définies ici.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"

// Fenêtre
#define NOM_JEU "IC2 Fighter"
#define ICONE "img/menu_principal/logo.bmp"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

// Images
#define IMG_MAIN_MENU_BG "img/menu_principal/ic2.bmp"
#define IMG_LOGO "img/menu_principal/logo.bmp"
#define IMG_BOUTON_OPT "img/menu_principal/options.bmp"
#define IMG_BOUTON_QUIT "img/menu_principal/quit.bmp"
#define IMG_BOUTON_PLAY "img/menu_principal/play.bmp"
#define SOUND_BACKGROUND "mixer/Leateq - Tokyo.mp3"

/**
 * @brief Fonction pour initialiser et gérer le menu principal du jeu.
 *
 * Cette fonction configure l'affichage du menu principal et gère les interactions de l'utilisateur avec les boutons du menu.
 * Elle met à jour la scène du jeu en fonction des interactions de l'utilisateur pour naviguer entre jouer, options ou quitter le jeu.
 *
 * @param e Un SDL_Event pour gérer les entrées utilisateur.
 * @param renderer Le renderer SDL utilisé pour dessiner à l'écran.
 * @param largeurF La largeur de la fenêtre du jeu.
 * @param hauteurF La hauteur de la fenêtre du jeu.
 * @param scene Un pointeur vers l'entier qui contrôle la scène actuelle de l'application.
 * @return Un entier indiquant le succès ou l'échec de la fonction.
 */

extern int menu_principal(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene);