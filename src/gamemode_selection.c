#include "../lib/gamemode_selection.h"

extern
int gamemode_selection(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int son, Mix_Music * backgroundSoundSelect) {

    listeT_t *listeTexture = creerListeT(); // Stock les pointeurs sur texture
    listeRect *listeRectangle = creerListeRect(); // Stock les pointeurs sur Rectangle
    listeBouton *listeBoutons = creerListeBouton(); // Stock les pointeurs sur Bouton

    // Création de l'image de fond
    SDL_Texture *gamemodeBGTexture = creerImage(renderer, IMG_GAMEMODE_BG);
    if(gamemodeBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gamemodeBGTexture);

    // Boutons
    // Local
        bouton *boutonLocal = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 5/2.0, 8/2.0, 5.0, 8.0, IMG_GAMEMODE_LOCAL, 0, 0);
        if(boutonLocal == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonLocal);

    // En ligne
        bouton *boutonLigne = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 5/2.0, 8/5.0, 5.0, 8.0, IMG_GAMEMODE_LIGNE, 0, 0);
        if(boutonLigne == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonLigne);

    // Retour
        bouton *boutonGmBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 11.0, 11.0, IMG_GAMEMODE_RETOUR, 0, 0);
        if(boutonGmBack == NULL) exit(EXIT_FAILURE);
        ajoutListeBouton(&listeBoutons, &boutonGmBack);

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
            // Local
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h) {
                boutonLocal->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h) {
                (*scene)++;
                if(son) {
                    Mix_VolumeMusic(MIX_MAX_VOLUME * 0.1); //Réglage niveau de son
                    Mix_HaltMusic();
                    Mix_PlayMusic(backgroundSoundSelect, -1);
                }
                boutonLocal->etat = BOUTON_RELACHE;
                quit = 2;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonLocal->etat == BOUTON_APPUYE  || boutonLocal->etat == BOUTON_OVER && !(e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h)) {
                boutonLocal->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h && boutonLocal->etat == BOUTON_RELACHE) {
                boutonLocal->etat = BOUTON_OVER;
            }

            // En Ligne
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h) {
                boutonLigne->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h) {
                // A COMPLETER !_!
                boutonLigne->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonLigne->etat == BOUTON_APPUYE  || boutonLigne->etat == BOUTON_OVER && !(e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h)) {
                boutonLigne->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h && boutonLigne->etat == BOUTON_RELACHE) {
                boutonLigne->etat = BOUTON_OVER;
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
        SDL_RenderCopy(renderer, gamemodeBGTexture, NULL, NULL);

        // Dessiner le bouton du mode Local
        if(boutonLocal->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->relache, boutonLocal->position->rect);
        else if (boutonLocal->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->appuye, boutonLocal->position->rect);
        else if (boutonLocal->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->over, boutonLocal->position->rect);

        // Dessiner le bouton du mode En ligne
        if(boutonLigne->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonLigne->texture, boutonLigne->relache, boutonLigne->position->rect);
        else if (boutonLigne->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonLigne->texture, boutonLigne->appuye, boutonLigne->position->rect);
        else if (boutonLigne->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonLigne->texture, boutonLigne->over, boutonLigne->position->rect);

        // Dessiner le bouton retour
        if(boutonGmBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->relache, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->appuye, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->over, boutonGmBack->position->rect);

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }

    detruireListeRect(&listeRectangle);
    detruireListeBouton(&listeBoutons);
    detruireListeT(&listeTexture);

    return quit > 1 ? 0 : 1;
}