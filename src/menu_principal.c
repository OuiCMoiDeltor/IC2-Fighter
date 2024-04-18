#include "../lib/menu_principal.h"

extern
int menu_principal(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene) {

    listeT_t *listeTexture = creerListeT(); // Stock les pointeurs sur texture
    listeRect *listeRectangle = creerListeRect(); // Stock les pointeurs sur Rectangle
    listeBouton *listeBoutons = creerListeBouton(); // Stock les pointeurs sur Bouton

    // Variables
    int overBoutonJouer = 0;

    // Création de l'image de fond
    SDL_Texture *mainMenuBGTexture = creerImage(renderer, IMG_MAIN_MENU_BG);
    if(mainMenuBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &mainMenuBGTexture);
    
    // Création du logo
    SDL_Texture *logoTexture = creerImage(renderer, IMG_LOGO);
    if(logoTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &logoTexture);
    rectangle *logoRect = creerRectangle(&largeurF, &hauteurF, 4.0, 3*6.0, 2.0, 3*8/7.0);
    ajoutListeRect(&listeRectangle, &logoRect);

    // Boutons du menu principal
    // Options
        bouton *boutonOptions = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 1400/65.0, 787/115.0, 1400/280.0, 787/525.0, IMG_BOUTON_OPT, 0, 0);
        if(boutonOptions == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonOptions);

    // Quitter
        bouton *boutonQuitter = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 10/8.0, 5/2.7, 1400/280.0, 2.0, IMG_BOUTON_QUIT, 0, 0);
        if(boutonQuitter == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonQuitter);

    // Jouer
        bouton *boutonJouer = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 1400/995.0, 787/435.0, 1400/115.0, 787/110.0, IMG_BOUTON_PLAY, 1, 11);
        if(boutonJouer == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonJouer);

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
            // Options
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h) {
                boutonOptions->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h) {
                (*scene)--;
                boutonOptions->etat = BOUTON_RELACHE;
                quit = 2;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptions->etat == BOUTON_APPUYE  || boutonOptions->etat == BOUTON_OVER && !(e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h)) {
                boutonOptions->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h && boutonOptions->etat == BOUTON_RELACHE) {
                boutonOptions->etat = BOUTON_OVER;
            }

            // Quitter
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h) {
                boutonQuitter->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h) {
                quit = 1;
                boutonQuitter->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonQuitter->etat == BOUTON_APPUYE  || boutonQuitter->etat == BOUTON_OVER && !(e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h)) {
                boutonQuitter->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h && boutonQuitter->etat == BOUTON_RELACHE) {
                boutonQuitter->etat = BOUTON_OVER;
            }

            // Jouer
            // Appuie et relache sur le bouton
            if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonJouer->position->rect->x && e.motion.x < boutonJouer->position->rect->x + boutonJouer->position->rect->w && e.motion.y > boutonJouer->position->rect->y && e.motion.y < boutonJouer->position->rect->y + boutonJouer->position->rect->h) {
                (*scene)++;
                boutonJouer->etat = boutonJouer->nbEtat-1;
                quit = 2;
            // Passe sur le bouton
            }else if (e.motion.x > boutonJouer->position->rect->x && e.motion.x < boutonJouer->position->rect->x + boutonJouer->position->rect->w && e.motion.y > boutonJouer->position->rect->y && e.motion.y < boutonJouer->position->rect->y + boutonJouer->position->rect->h) {
                overBoutonJouer = 1;
            }else {
                overBoutonJouer = 0;
            }
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);
        
        // Dessiner l'image de fond
        SDL_RenderCopy(renderer, mainMenuBGTexture, NULL, NULL);

        // Dessiner le logo
        SDL_RenderCopy(renderer, logoTexture, NULL, logoRect->rect);

        // Dessiner le bouton des Options
        if(boutonOptions->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->relache, boutonOptions->position->rect);
        else if (boutonOptions->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->appuye, boutonOptions->position->rect);
        else if (boutonOptions->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->over, boutonOptions->position->rect);

        // Dessiner le bouton Quitter
        if(boutonQuitter->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->relache, boutonQuitter->position->rect);
        else if (boutonQuitter->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->appuye, boutonQuitter->position->rect);
        else if (boutonQuitter->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->over, boutonQuitter->position->rect);

        // Dessiner le bouton Jouer
        SDL_RenderCopy(renderer, boutonJouer->texture, boutonJouer->frames[boutonJouer->etat], boutonJouer->position->rect);
        // Animation
        if(overBoutonJouer && boutonJouer->etat < boutonJouer->nbEtat-1) {
            waitForFrame++;
            if(waitForFrame > 20) {
                boutonJouer->etat ++;
                waitForFrame = 0;
            }
        }else if(!overBoutonJouer && boutonJouer->etat > 0) {
            waitForFrame--;
            if(waitForFrame < 0) {
                boutonJouer->etat --;
                waitForFrame = 20;
            }
        }

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }
    
    detruireListeRect(&listeRectangle);
    detruireListeBouton(&listeBoutons);
    detruireListeT(&listeTexture);

    return quit > 1 ? 0 : 1;
}