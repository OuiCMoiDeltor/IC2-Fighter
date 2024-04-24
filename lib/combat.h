/**
 * @file combat.h
 * @brief Fichier d'en-tête pour la gestion des combats dans le jeu.
 *
 * Ce fichier d'en-tête contient les déclarations des fonctions responsables de la gestion des combats dans le jeu,
 * y compris l'initialisation des personnages, le démarrage des rounds de combat, et la gestion des interactions de combat.
 * Il gère également les animations spécifiques et les effets sonores associés aux actions des personnages.
 */

#ifndef _COMBAT_H_
#define _COMBAT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "perso.h"

/**
 * @file combat.h
 * @brief Fichier d'en-tête pour la gestion des combats dans le jeu.
 *
 * Ce fichier d'en-tête contient les déclarations des fonctions responsables de la gestion des combats dans le jeu,
 * y compris l'initialisation des personnages, le démarrage des rounds de combat, et la gestion des interactions de combat.
 * Il gère également les animations spécifiques et les effets sonores associés aux actions des personnages.
 */

extern void initPerso(SDL_Renderer * renderer, personnage * J1, personnage * J2);

/**
 * @brief Démarre un round de combat.
 *
 * Gère le début d'un round de combat, traite les entrées du clavier et met à jour les états des personnages en fonction des interactions.
 *
 * @param renderer Pointeur vers le renderer SDL.
 * @param keyboardState État actuel du clavier.
 * @param Joueur1 Pointeur vers le premier personnage (joueur 1).
 * @param Joueur2 Pointeur vers le second personnage (joueur 2).
 * @param largeurF Largeur de la fenêtre de jeu.
 * @param hauteurF Hauteur de la fenêtre de jeu.
 * @param waitForFrame Délai d'attente entre les frames pour la synchronisation.
 * @param hit Effet sonore pour un coup réussi.
 * @param dmg Effet sonore pour des dégâts subis.
 * @param stun Effet sonore pour un étourdissement.
 * @param liste_touches Tableau des touches configurées pour le jeu.
 * @param round Numéro du round actuel.
 * @param stunTexture Texture utilisée pour l'affichage de l'étourdissement.
 * @param stunRect Rectangle définissant la position et les dimensions de l'effet d'étourdissement.
 * @param stunTextureRect Rectangles définissant les cadres de l'animation d'étourdissement.
 * @return int Statut indiquant la progression ou la fin du round.
 */

extern int roundStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int waitForFrame, Mix_Chunk * hit, Mix_Chunk * dmg, Mix_Chunk * stun, int * liste_touches, int round, SDL_Texture * stunTexture, rectangle * stunRect, SDL_Rect ** stunTextureRect);

/**
 * @brief Lance le combat entre deux personnages.
 *
 * Cette fonction est appelée pour démarrer les interactions de combat effectives entre deux personnages après l'initialisation.
 *
 * @param renderer Pointeur vers le renderer SDL.
 * @param keyboardState État actuel du clavier.
 * @param Joueur1 Pointeur vers le premier personnage (joueur 1).
 * @param Joueur2 Pointeur vers le second personnage (joueur 2).
 * @param largeurF Largeur de la fenêtre de jeu.
 * @param hauteurF Hauteur de la fenêtre de jeu.
 * @param son Indicateur d'activation du son.
 * @param liste_touches Tableau des touches configurées pour le jeu.
 */

extern void combatStart(SDL_Renderer * renderer, Uint8 *keyboardState, personnage * Joueur1, personnage * Joueur2, int largeurF, int hauteurF, int son, int * liste_touches);

/**
 * @brief Affiche les informations d'un round de combat.
 *
 * Affiche le numéro du round actuel ainsi que les états de santé des personnages.
 *
 * @param renderer Pointeur vers le renderer SDL.
 * @param largeurF Largeur de la fenêtre de jeu.
 * @param hauteurF Hauteur de la fenêtre de jeu.
 * @param round Numéro du round actuel.
 * @param Joueur1 Pointeur vers le premier personnage (joueur 1).
 * @param Joueur2 Pointeur vers le second personnage (joueur 2).
 * @param BG Texture de l'arrière-plan du combat.
 */
 
void afficherRound(SDL_Renderer* renderer, int largeurF, int hauteurF, int round, personnage * Joueur1, personnage * Joueur2, SDL_Texture * BG);

#endif
