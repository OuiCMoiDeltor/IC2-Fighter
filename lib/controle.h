/**
 * @file controle.c
 * @brief Fichier source pour la gestion des contrôles dans le jeu.
 *
 * Ce fichier contient les définitions des fonctions nécessaires pour la gestion de l'interface des contrôles dans le jeu,
 * permettant aux joueurs de visualiser et de modifier les touches de contrôle.
 * Il gère également le chargement et l'affichage des éléments graphiques associés aux contrôles.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Fonctions
#include "bouton.h"
#include "touches.h"

// Texte
#define TTF_FONT "ttf/Act_Of_Rejection.ttf"

// Images
#define IMG_CONTROLE_BG "img/controle/FondControles.bmp"
#define IMG_BACK "img/options/optionsBack.bmp"

#define IMG_CONTROLE "img/controle/Controlespx.bmp"
#define IMG_EMPLACEMENT_TOUCHE "img/controle/FondTouches.bmp"

#define IMG_J1 "img/controle/J1px.bmp"
#define IMG_J2 "img/controle/J2px.bmp"

#define IMG_SAUTER "img/controle/Sauterpx.bmp"
#define IMG_ACCROUPI "img/controle/Accroupirpx.bmp"
#define IMG_GAUCHE "img/controle/Gauchepx.bmp"
#define IMG_DROITE "img/controle/Droitepx.bmp"
#define IMG_POING "img/controle/Poingpx.bmp"
#define IMG_KICK "img/controle/Kickpx.bmp" 
#define IMG_GARDE "img/controle/Paradepx.bmp"

#define IMG_RESET "img/controle/BoutonReset.bmp"

/**
 * @brief Gère la page des contrôles dans le jeu.
 *
 * Cette fonction est appelée pour afficher et gérer la page des contrôles où les utilisateurs peuvent visualiser et modifier
 * les touches utilisées pour les actions dans le jeu. Elle gère les événements d'entrée et met à jour l'interface en conséquence.
 *
 * @param e Événement SDL capturé.
 * @param renderer Pointeur vers le renderer SDL.
 * @param largeurF Largeur de la fenêtre du jeu.
 * @param hauteurF Hauteur de la fenêtre du jeu.
 * @param scene Pointeur vers l'identifiant de la scène courante, permettant de naviguer entre différentes vues.
 * @param liste_touches Tableau contenant les codes des touches configurées pour le jeu.
 * @param f_touches Chemin vers le fichier contenant les touches actuelles.
 * @param r_touches Chemin vers le fichier de réinitialisation des touches.
 * @return int Un code indiquant l'état après exécution (continuer, quitter, etc.).
 */

extern int controle(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int * liste_touches, char * f_touches, char * r_touches);