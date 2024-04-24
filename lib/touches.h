/**
 * @file touches.h
 * @brief Fichier d'en-tête contenant les déclarations des fonctions de gestion des touches.
 *
 * Ce fichier contient les déclarations des fonctions permettant de gérer les touches du clavier dans le jeu, y compris la réinitialisation des touches, la lecture des touches à partir d'un fichier, la modification d'une touche spécifique, et la saisie d'une nouvelle touche.
 */

#ifndef _TOUCHES_H_
#define _TOUCHES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

typedef enum touches{SauterJ1, SauterJ2, AccroupirJ1, AccroupirJ2, GaucheJ1, GaucheJ2, DroitJ1, DroitJ2, KickJ1, KickJ2, PoingJ1, PoingJ2, ParadeJ1, ParadeJ2}touches_e; 

/**
 * @brief Réinitialise les touches du clavier en les remettant à leur configuration par défaut.
 * 
 * @param liste_touches Tableau des touches du clavier
 * @param f_fichier Nom du fichier de configuration actuel
 * @param r_fichier Nom du fichier de configuration par défaut
 */

extern void resetTouches(int * liste_touches, char * f_fichier, char * r_fichier);

/**
 * @brief Lit les touches du clavier à partir d'un fichier de configuration.
 * 
 * @param liste_touches Tableau des touches du clavier
 * @param fichier Nom du fichier de configuration
 */

extern void LireTouches(int * liste_touches, char * fichier);

/**
 * @brief Modifie une touche spécifique du clavier dans le fichier de configuration.
 * 
 * @param liste_touches Tableau des touches du clavier
 * @param numero_ligne Numéro de la ligne correspondant à la touche à modifier
 * @param touche Nouvelle valeur de la touche
 * @param fichier Nom du fichier de configuration
 */

extern void ModifierTouche(int * liste_touches, int numero_ligne, int touche, char * fichier);

/**
 * @brief Saisit une nouvelle touche du clavier pour une fonctionnalité spécifique.
 * 
 * @param renderer Le renderer SDL
 * @param font La police de caractères utilisée pour afficher le texte
 * @param event L'événement SDL
 * @param liste_touches Tableau des touches du clavier
 * @param touche Enumération représentant la fonctionnalité pour laquelle la touche est saisie
 * @param txt Pointeur vers la texture du texte
 * @param fichier Nom du fichier de configuration
 */

extern void saisirTouche(SDL_Renderer * renderer, TTF_Font * font, SDL_Event event, int * liste_touches, touches_e touche, SDL_Texture ** txt, char * fichier);

#endif
