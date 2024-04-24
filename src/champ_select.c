/**
 * \file   champ_select.c
 * \brief  Gestion de la sélection des personnages dans le jeu
 *
 * Ce fichier implémente les fonctions nécessaires pour la sélection des personnages dans l'interface de sélection du jeu.
 * Il gère la création et l'interaction avec les boutons de sélection de personnages et le bouton de retour,
 * ainsi que l'affichage des images représentant les personnages disponibles. Le fichier traite également les
 * entrées utilisateur via le clavier et la souris pour naviguer entre les options et effectuer la sélection.
 * Les états visuels des boutons et les transitions entre les scènes de jeu sont manipulés en fonction des
 * interactions de l'utilisateur. De plus, la gestion de la musique de fond pendant la sélection est incluse,
 * offrant une expérience utilisateur immersive.
 *
 * \author IC2-Fighter
 * \version 1.0
 * \date 2024
 */
 
#include "../lib/champ_select.h"

/**
 * \brief Gère la sélection des personnages et la navigation dans le menu de sélection.
 *
 * Cette fonction crée l'environnement de sélection des personnages, gère les interactions avec les boutons
 * de sélection et le bouton de retour. Elle maintient une boucle d'événements pour traiter les entrées
 * utilisateur jusqu'à ce qu'une sélection soit faite ou que l'utilisateur quitte le menu. Elle utilise
 * également des textures et des boutons pour afficher les personnages disponibles et gérer les états de
 * sélection. La musique de fond peut être jouée si spécifié.
 *
 * \param e SDL_Event utilisé pour gérer les événements.
 * \param renderer Pointeur vers le rendu SDL utilisé pour dessiner les éléments graphiques.
 * \param largeurF Largeur de la fenêtre de l'affichage.
 * \param hauteurF Hauteur de la fenêtre de l'affichage.
 * \param scene Pointeur vers l'entier qui contrôle la scène courante dans l'application.
 * \param son Indicateur pour jouer de la musique (1 pour jouer, 0 pour ne pas jouer).
 * \param liste_touches Tableau d'entiers représentant l'état des touches (utilisé pour la navigation).
 * \param keyboardState État du clavier pour gérer les entrées directes.
 * \return Entier indiquant si l'utilisateur quitte la sélection (1) ou retourne au menu précédent (0).
 */

extern
int champ_select(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int son, int * liste_touches, Uint8 * keyboardState) {

    listeT_t *listeTexture = creerListeT(); // Stock les pointeurs sur texture
    listeRect *listeRectangle = creerListeRect(); // Stock les pointeurs sur Rectangle
    listeBouton *listeBoutons = creerListeBouton(); // Stock les pointeurs sur Bouton

    int J2Pick = 0;
    personnage *Joueur1 = NULL;
    personnage *Joueur2 = NULL;

    // Création de l'image de fond
    SDL_Texture *champSelectBGTexture = creerImage(renderer, IMG_CHAMPSELECT_BG);
    if(champSelectBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectBGTexture);

    // Création des images de séléction du joueur courant
    SDL_Texture *champSelectJ1 = creerImage(renderer, IMG_CHAMPSELECT_J1);
    if(champSelectJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectJ1);
    rectangle *champSelectJ1Rect = creerRectangle(&largeurF, &hauteurF, 25/5.0, 100/2.0, 25/15.0, 100/16.0);
    ajoutListeRect(&listeRectangle, &champSelectJ1Rect);

    SDL_Texture *champSelectJ2 = creerImage(renderer, IMG_CHAMPSELECT_J2);
    if(champSelectJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectJ2);
    rectangle *champSelectJ2Rect = creerRectangle(&largeurF, &hauteurF, 25/5.0, 100/2.0, 25/15.0, 100/16.0);
    ajoutListeRect(&listeRectangle, &champSelectJ2Rect);

    // Boutons
    // Local
        bouton *boutonYASS = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/2.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_YASS, 1, 25);
        if(boutonYASS == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonYASS);

        bouton *boutonDIM = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/6.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_DIM, 1, 34);
        if(boutonDIM == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonDIM);

        bouton *boutonDAM = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/16.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_DAM, 1, 26);
        if(boutonDAM == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonDAM);

        bouton *boutonLocked4 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/20.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_LOCKED, 1, 1);
        if(boutonLocked4 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonLocked4);

        bouton *boutonLocked5 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/20.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_LOCKED, 1, 1);
        if(boutonLocked5 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonLocked5);

        bouton *boutonLocked6 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/2.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_LOCKED, 1, 1);
        if(boutonLocked6 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonLocked6);

        bouton *boutonLocked7 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/16.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_LOCKED, 1, 1);
        if(boutonLocked7 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonLocked7);

        bouton *boutonLocked8 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/6.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_LOCKED, 1, 1);
        if(boutonLocked8 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonLocked8);
    // Bouton 
    // Retour
    bouton *boutonGmBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 11.0, 11.0, IMG_GAMEMODE_RETOUR, 0, 0);
    if(boutonGmBack == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonGmBack);

    // Son 
    // Chargement musique de fond
        Mix_Music *backgroundSoundSelect = Mix_LoadMUS(SOUND_BACKGROUND_SELECT);

    if(son) {
        Mix_HaltMusic();
        Mix_PlayMusic(backgroundSoundSelect, -1);
    }

    int waitForFrame = 0;
    int quit = 0;
    while (!quit) {
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
            // RYU
            // Appuie et relache sur le bouton
            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonYASS->position->rect->x && e.motion.x < boutonYASS->position->rect->x + boutonYASS->position->rect->w && e.motion.y > boutonYASS->position->rect->y && e.motion.y < boutonYASS->position->rect->y + boutonYASS->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, YASS, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonYASS->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, YASS, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonYASS->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonDIM->position->rect->x && e.motion.x < boutonDIM->position->rect->x + boutonDIM->position->rect->w && e.motion.y > boutonDIM->position->rect->y && e.motion.y < boutonDIM->position->rect->y + boutonDIM->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, MNX, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonDIM->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, MNX, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonDIM->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonDAM->position->rect->x && e.motion.x < boutonDAM->position->rect->x + boutonDAM->position->rect->w && e.motion.y > boutonDAM->position->rect->y && e.motion.y < boutonDAM->position->rect->y + boutonDAM->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, DAM, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonDAM->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, DAM, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonDAM->etat = 0;
                    J2Pick = 1;
                }
            }

            /*if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLocked4->position->rect->x && e.motion.x < boutonLocked4->position->rect->x + boutonLocked4->position->rect->w && e.motion.y > boutonLocked4->position->rect->y && e.motion.y < boutonLocked4->position->rect->y + boutonLocked4->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonLocked4->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonLocked4->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLocked5->position->rect->x && e.motion.x < boutonLocked5->position->rect->x + boutonLocked5->position->rect->w && e.motion.y > boutonLocked5->position->rect->y && e.motion.y < boutonLocked5->position->rect->y + boutonLocked5->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonLocked5->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonLocked5->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLocked6->position->rect->x && e.motion.x < boutonLocked6->position->rect->x + boutonLocked6->position->rect->w && e.motion.y > boutonLocked6->position->rect->y && e.motion.y < boutonLocked6->position->rect->y + boutonLocked6->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonLocked6->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonLocked6->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLocked7->position->rect->x && e.motion.x < boutonLocked7->position->rect->x + boutonLocked7->position->rect->w && e.motion.y > boutonLocked7->position->rect->y && e.motion.y < boutonLocked7->position->rect->y + boutonLocked7->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonLocked7->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonLocked7->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLocked8->position->rect->x && e.motion.x < boutonLocked8->position->rect->x + boutonLocked8->position->rect->w && e.motion.y > boutonLocked8->position->rect->y && e.motion.y < boutonLocked8->position->rect->y + boutonLocked8->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonLocked8->etat = 0;
                    J2Pick = 0;
                    combatStart(renderer,keyboardState,Joueur1,Joueur2, largeurF, hauteurF, son, liste_touches);
                    if(son) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                }
                else {
                    Joueur1 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    boutonLocked8->etat = 0;
                    J2Pick = 1;
                }
            }*/
            // Retour
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h) {
                boutonGmBack->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h) {
                (*scene)--;
                boutonGmBack->etat = BOUTON_RELACHE;
                quit = 2;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonGmBack->etat == BOUTON_APPUYE  || boutonGmBack->etat == BOUTON_OVER && !(e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h)) {
                boutonGmBack->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h && boutonGmBack->etat == BOUTON_RELACHE) {
                boutonGmBack->etat = BOUTON_OVER;
            }
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        // Dessiner l'image de fond
        SDL_RenderCopy(renderer, champSelectBGTexture, NULL, NULL);

        // Dessiner l'image de séléction du joueur courant
        if(J2Pick)
                SDL_RenderCopy(renderer, champSelectJ2, NULL, champSelectJ1Rect->rect);
        else
                SDL_RenderCopy(renderer, champSelectJ1, NULL, champSelectJ2Rect->rect);

        // Dessiner le bouton de RYU
        SDL_RenderCopy(renderer, boutonYASS->texture, boutonYASS->frames[boutonYASS->etat], boutonYASS->position->rect);
        // Dessiner le bouton de DIM
        SDL_RenderCopy(renderer, boutonDIM->texture, boutonDIM->frames[boutonDIM->etat], boutonDIM->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonDAM->texture, boutonDAM->frames[boutonDAM->etat], boutonDAM->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonLocked4->texture, boutonLocked4->frames[boutonLocked4->etat], boutonLocked4->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonLocked5->texture, boutonLocked5->frames[boutonLocked5->etat], boutonLocked5->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonLocked6->texture, boutonLocked6->frames[boutonLocked6->etat], boutonLocked6->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonLocked7->texture, boutonLocked7->frames[boutonLocked7->etat], boutonLocked7->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonLocked8->texture, boutonLocked8->frames[boutonLocked8->etat], boutonLocked8->position->rect);

        // Dessiner le bouton retour
        if(boutonGmBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->relache, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->appuye, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->over, boutonGmBack->position->rect);

        // Animation
        waitForFrame++;
        if(waitForFrame > 10) {
                boutonYASS->etat =  ++boutonYASS->etat%25;
                boutonDIM->etat =  ++boutonDIM->etat%34;
                boutonDAM->etat =  ++boutonDAM->etat%26;
                /*boutonLocked4->etat =  ++boutonLocked4->etat%1;
                boutonLocked5->etat =  ++boutonLocked5->etat%1;
                boutonLocked6->etat =  ++boutonLocked6->etat%1;
                boutonLocked7->etat =  ++boutonLocked7->etat%1;
                boutonLocked8->etat =  ++boutonLocked8->etat%1;*/
                waitForFrame = 0;
        }

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }
    
    Mix_FreeMusic(backgroundSoundSelect);
    detruireListeRect(&listeRectangle);
    detruireListeBouton(&listeBoutons);
    detruireListeT(&listeTexture);

    return quit > 1 ? 0 : 1;
}
