#include "../lib/champ_select.h"

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
        bouton *boutonRYU = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/2.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_YASS, 1, 25);
        if(boutonRYU == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU);

        bouton *boutonRYU2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/6.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_DIM, 1, 10);
        if(boutonRYU2 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU2);

        bouton *boutonRYU3 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/16.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 1, 10);
        if(boutonRYU3 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU3);

        bouton *boutonRYU4 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/20.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 1, 10);
        if(boutonRYU4 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU4);

        bouton *boutonRYU5 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/20.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 1, 10);
        if(boutonRYU5 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU5);

        bouton *boutonRYU6 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/2.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 1, 10);
        if(boutonRYU6 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU6);

        bouton *boutonRYU7 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/16.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 1, 10);
        if(boutonRYU7 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU7);

        bouton *boutonRYU8 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/6.0, 100/60.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 1, 10);
        if(boutonRYU8 == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonRYU8);
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
            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU->position->rect->x && e.motion.x < boutonRYU->position->rect->x + boutonRYU->position->rect->w && e.motion.y > boutonRYU->position->rect->y && e.motion.y < boutonRYU->position->rect->y + boutonRYU->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, YASS, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU2->position->rect->x && e.motion.x < boutonRYU2->position->rect->x + boutonRYU2->position->rect->w && e.motion.y > boutonRYU2->position->rect->y && e.motion.y < boutonRYU2->position->rect->y + boutonRYU2->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, MNX, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU3->position->rect->x && e.motion.x < boutonRYU3->position->rect->x + boutonRYU3->position->rect->w && e.motion.y > boutonRYU3->position->rect->y && e.motion.y < boutonRYU3->position->rect->y + boutonRYU3->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, DAM, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU4->position->rect->x && e.motion.x < boutonRYU4->position->rect->x + boutonRYU4->position->rect->w && e.motion.y > boutonRYU4->position->rect->y && e.motion.y < boutonRYU4->position->rect->y + boutonRYU4->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU5->position->rect->x && e.motion.x < boutonRYU5->position->rect->x + boutonRYU5->position->rect->w && e.motion.y > boutonRYU5->position->rect->y && e.motion.y < boutonRYU5->position->rect->y + boutonRYU5->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU6->position->rect->x && e.motion.x < boutonRYU6->position->rect->x + boutonRYU6->position->rect->w && e.motion.y > boutonRYU6->position->rect->y && e.motion.y < boutonRYU6->position->rect->y + boutonRYU6->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU7->position->rect->x && e.motion.x < boutonRYU7->position->rect->x + boutonRYU7->position->rect->w && e.motion.y > boutonRYU7->position->rect->y && e.motion.y < boutonRYU7->position->rect->y + boutonRYU7->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }

            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU8->position->rect->x && e.motion.x < boutonRYU8->position->rect->x + boutonRYU8->position->rect->w && e.motion.y > boutonRYU8->position->rect->y && e.motion.y < boutonRYU8->position->rect->y + boutonRYU8->position->rect->h) {
                if(J2Pick) {
                    Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                    if(Joueur2 == NULL) exit(EXIT_FAILURE);
                    boutonRYU->etat = 0;
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
                    boutonRYU->etat = 0;
                    J2Pick = 1;
                }
            }
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
        SDL_RenderCopy(renderer, boutonRYU->texture, boutonRYU->frames[boutonRYU->etat], boutonRYU->position->rect);
        // Dessiner le bouton de DIM
        SDL_RenderCopy(renderer, boutonRYU2->texture, boutonRYU2->frames[boutonRYU2->etat], boutonRYU2->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU3->texture, boutonRYU3->frames[boutonRYU3->etat], boutonRYU3->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU4->texture, boutonRYU4->frames[boutonRYU4->etat], boutonRYU4->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU5->texture, boutonRYU5->frames[boutonRYU5->etat], boutonRYU5->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU6->texture, boutonRYU6->frames[boutonRYU6->etat], boutonRYU6->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU7->texture, boutonRYU7->frames[boutonRYU7->etat], boutonRYU7->position->rect);
        // Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU8->texture, boutonRYU8->frames[boutonRYU8->etat], boutonRYU8->position->rect);

        // Dessiner le bouton retour
        if(boutonGmBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->relache, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->appuye, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->over, boutonGmBack->position->rect);

        // Animation
        waitForFrame++;
        if(waitForFrame > 10) {
                boutonRYU->etat =  ++boutonRYU->etat%25;
                boutonRYU2->etat =  ++boutonRYU2->etat%10;
                boutonRYU3->etat =  ++boutonRYU3->etat%10;
                boutonRYU4->etat =  ++boutonRYU4->etat%10;
                boutonRYU5->etat =  ++boutonRYU5->etat%10;
                boutonRYU6->etat =  ++boutonRYU6->etat%10;
                boutonRYU7->etat =  ++boutonRYU7->etat%10;
                boutonRYU8->etat =  ++boutonRYU8->etat%10;
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
