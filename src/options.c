#include "../lib/options.h"

extern
int options(SDL_Event e, SDL_Renderer * renderer, SDL_Window * window, int largeurF, int hauteurF, int * scene, int * son, int * fullscreen, Mix_Music * backgroundSound) {
    
    listeT_t *listeTexture = creerListeT(); // Stock les pointeurs sur texture
    listeRect *listeRectangle = creerListeRect(); // Stock les pointeurs sur Rectangle
    listeBouton *listeBoutons = creerListeBouton(); // Stock les pointeurs sur Bouton
    
    // Création de l'image de fond
    SDL_Texture *optionsBGTexture = creerImage(renderer, IMG_OPTIONS_BG);
    if(optionsBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsBGTexture);

    // Création image titre des Options
    SDL_Texture *optionsTitleTexture = creerImage(renderer, IMG_OPTIONS_TITLE);
    if(optionsTitleTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsTitleTexture);
    rectangle *optionsTitleRect = creerRectangle(&largeurF, &hauteurF, 4.0, 4*8.0, 2.0, 4.0);
    ajoutListeRect(&listeRectangle, &optionsTitleRect);

    // Création image résolution des Options
    SDL_Texture *optionsResolutionTexture = creerImage(renderer, IMG_OPTIONS_RESOLUTION);
    if(optionsResolutionTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsResolutionTexture);
    rectangle *optionsResolutionRect = creerRectangle(&largeurF, &hauteurF, 10.0, 3*4/3.0, 10/8.0, 5.0);
    ajoutListeRect(&listeRectangle, &optionsResolutionRect);

    // Chargement de la police en taille 64
    TTF_Font *font = TTF_OpenFont(TTF_FONT, 64);
    if(!font) {
        printf("Erreur lors du chargement de la police TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    // Couleurs
    SDL_Color noire = {0,0,0};

    // Création textes résolutions
    int Res = 0;
    // 1920x1080
    SDL_Texture *optionsRes1920x1080 = creerTexte(renderer,font,"1920x1080",noire);
    if(optionsRes1920x1080 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsRes1920x1080);
    // 1280x720
    SDL_Texture *optionsRes1280x720 = creerTexte(renderer,font,"1280x720",noire);
    if(optionsRes1280x720 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsRes1280x720);
    // 854x480
    SDL_Texture *optionsRes854x480 = creerTexte(renderer,font,"854x480",noire);
    if(optionsRes854x480 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsRes854x480);
    // 640x360
    SDL_Texture *optionsRes640x360 = creerTexte(renderer,font,"640x360",noire);
    if(optionsRes640x360 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsRes640x360);
    // 426x240
    SDL_Texture *optionsRes426x240 = creerTexte(renderer,font,"426x240",noire);
    if(optionsRes426x240 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsRes426x240);

    rectangle *optionsResTextRect = creerRectangle(&largeurF, &hauteurF, 10/4.0, 3*3/4.0, 10/2.0, 11.0);
    ajoutListeRect(&listeRectangle, &optionsResTextRect);

    // Création image plein écran des Options
    SDL_Texture *optionsFullscreenTexture = creerImage(renderer, IMG_OPTIONS_FULLSCREEN);
    if(optionsFullscreenTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &optionsFullscreenTexture);
    rectangle *optionsFullscreenRect = creerRectangle(&largeurF, &hauteurF, 10.0, 3*3/6.0, 10/8.0, 5.0);
    ajoutListeRect(&listeRectangle, &optionsFullscreenRect);

    // Boutons
    // changement de résolution
    // gauche
    bouton *boutonOptionsSwapResLeft = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 20/7.0, 30/14.0, 30.0, 21.0, IMG_OPTIONS_RESOLUTION_LEFT, 0, 0);
    if(boutonOptionsSwapResLeft == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsSwapResLeft);
    // droit
    bouton *boutonOptionsSwapResRight = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 40/25.0, 30/14.0, 30.0, 21.0, IMG_OPTIONS_RESOLUTION_RIGHT, 0, 0);
    if(boutonOptionsSwapResRight == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsSwapResRight);
    // appliquer
    bouton *boutonOptionsSwapAccept = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/5.0, 11/3.0, 11.0, IMG_OPTIONS_RESOLUTION_APPLIKER, 0, 0);
    if(boutonOptionsSwapAccept == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsSwapAccept);

    // plein écran
    // "activer"
    bouton *boutonOptionsFullscreenOn = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/8.0, 11/3.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_ON, 0, 0);
    if(boutonOptionsFullscreenOn == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsFullscreenOn);
    // "désactiver"
    bouton *boutonOptionsFullscreenOff = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/8.0, 11/3.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_OFF, 0, 0);
    if(boutonOptionsFullscreenOff == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsFullscreenOff);

    // retour
    bouton *boutonOptionsBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 11.0, 11.0, IMG_OPTIONS_BACK, 0, 0);
    if(boutonOptionsBack == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsBack);

    // son
    // on
    bouton *boutonOptionsSoundOn = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/10.0, 100.0, 11/1.0, 11.0, IMG_OPTIONS_SOUND_ON, 0, 0);
    if(boutonOptionsSoundOn == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsSoundOn);
    // off
    bouton *boutonOptionsSoundOff = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/10.0, 100.0, 11/1.0, 11.0, IMG_OPTIONS_SOUND_OFF, 0, 0);
    if(boutonOptionsSoundOff == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsSoundOff);
    // controle
    bouton *boutonOptionsControle = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 6/4.0, 3*3/8.0, 11/3.0, 11.0, IMG_OPTIONS_CONTROLE, 0, 0);
    if(boutonOptionsControle == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonOptionsControle);

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
            // Bouton son
            // On
            if(*son){
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSoundOn->position->rect->x && e.motion.x < boutonOptionsSoundOn->position->rect->x + boutonOptionsSoundOn->position->rect->w && e.motion.y > boutonOptionsSoundOn->position->rect->y && e.motion.y < boutonOptionsSoundOn->position->rect->y + boutonOptionsSoundOn->position->rect->h) {
                    boutonOptionsSoundOn->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSoundOn->position->rect->x && e.motion.x < boutonOptionsSoundOn->position->rect->x + boutonOptionsSoundOn->position->rect->w && e.motion.y > boutonOptionsSoundOn->position->rect->y && e.motion.y < boutonOptionsSoundOn->position->rect->y + boutonOptionsSoundOn->position->rect->h) {
                    *son = 0;
                    Mix_HaltMusic();
                    boutonOptionsSoundOn->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSoundOn->etat == BOUTON_APPUYE  || boutonOptionsSoundOn->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSoundOn->position->rect->x && e.motion.x < boutonOptionsSoundOn->position->rect->x + boutonOptionsSoundOn->position->rect->w && e.motion.y > boutonOptionsSoundOn->position->rect->y && e.motion.y < boutonOptionsSoundOn->position->rect->y + boutonOptionsSoundOn->position->rect->h)) {
                    boutonOptionsSoundOn->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptionsSoundOn->position->rect->x && e.motion.x < boutonOptionsSoundOn->position->rect->x + boutonOptionsSoundOn->position->rect->w && e.motion.y > boutonOptionsSoundOn->position->rect->y && e.motion.y < boutonOptionsSoundOn->position->rect->y + boutonOptionsSoundOn->position->rect->h && boutonOptionsSoundOn->etat == BOUTON_RELACHE) {
                    boutonOptionsSoundOn->etat = BOUTON_OVER;
                }
            }
            // Off
            else {
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSoundOff->position->rect->x && e.motion.x < boutonOptionsSoundOff->position->rect->x + boutonOptionsSoundOff->position->rect->w && e.motion.y > boutonOptionsSoundOff->position->rect->y && e.motion.y < boutonOptionsSoundOff->position->rect->y + boutonOptionsSoundOff->position->rect->h) {
                    boutonOptionsSoundOff->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSoundOff->position->rect->x && e.motion.x < boutonOptionsSoundOff->position->rect->x + boutonOptionsSoundOff->position->rect->w && e.motion.y > boutonOptionsSoundOff->position->rect->y && e.motion.y < boutonOptionsSoundOff->position->rect->y + boutonOptionsSoundOff->position->rect->h) {
                    *son = 1;
                    Mix_PlayMusic(backgroundSound, -1); // Son background joué indéfiniment
                    boutonOptionsSoundOff->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSoundOff->etat == BOUTON_APPUYE  || boutonOptionsSoundOff->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSoundOff->position->rect->x && e.motion.x < boutonOptionsSoundOff->position->rect->x + boutonOptionsSoundOff->position->rect->w && e.motion.y > boutonOptionsSoundOff->position->rect->y && e.motion.y < boutonOptionsSoundOff->position->rect->y + boutonOptionsSoundOff->position->rect->h)) {
                    boutonOptionsSoundOff->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptionsSoundOff->position->rect->x && e.motion.x < boutonOptionsSoundOff->position->rect->x + boutonOptionsSoundOff->position->rect->w && e.motion.y > boutonOptionsSoundOff->position->rect->y && e.motion.y < boutonOptionsSoundOff->position->rect->y + boutonOptionsSoundOff->position->rect->h && boutonOptionsSoundOff->etat == BOUTON_RELACHE) {
                    boutonOptionsSoundOff->etat = BOUTON_OVER;
                }
            }

            // Bouton résolution
            // Gauche
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h) {
                boutonOptionsSwapResLeft->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h) {
                Res --;
                if(Res<0)Res = 4;
                boutonOptionsSwapResLeft->etat = BOUTON_OVER;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapResLeft->etat == BOUTON_APPUYE  || boutonOptionsSwapResLeft->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h)) {
                boutonOptionsSwapResLeft->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h && boutonOptionsSwapResLeft->etat == BOUTON_RELACHE) {
                boutonOptionsSwapResLeft->etat = BOUTON_OVER;
            }
            // Droit
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h) {
                boutonOptionsSwapResRight->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h) {
                Res ++;
                Res = Res%5;
                boutonOptionsSwapResRight->etat = BOUTON_OVER;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapResRight->etat == BOUTON_APPUYE  || boutonOptionsSwapResRight->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h)) {
                boutonOptionsSwapResRight->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h && boutonOptionsSwapResRight->etat == BOUTON_RELACHE) {
                boutonOptionsSwapResRight->etat = BOUTON_OVER;
            }
            // Accepter
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h) {
                boutonOptionsSwapAccept->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h) {
                switch(Res)
                {
                    case(0):
                        SDL_SetWindowSize(window, 1920, 1080);
                        largeurF = 1920;
                        hauteurF = 1080;
                        break;
                    case(1):
                        SDL_SetWindowSize(window, 1280, 720);
                        largeurF = 1280;
                        hauteurF = 720;
                        break;
                    case(2):
                        SDL_SetWindowSize(window, 854, 480);
                        largeurF = 854;
                        hauteurF = 480;
                        break;
                    case(3):
                        SDL_SetWindowSize(window, 640, 360);
                        largeurF = 640;
                        hauteurF = 360;
                        break;
                    case(4):
                        SDL_SetWindowSize(window, 426, 240);
                        largeurF = 426;
                        hauteurF = 240;
                        break;
                }
                updateRectangles(listeRectangle);

                boutonOptionsSwapAccept->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapAccept->etat == BOUTON_APPUYE  || boutonOptionsSwapAccept->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h)) {
                boutonOptionsSwapAccept->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h && boutonOptionsSwapAccept->etat == BOUTON_RELACHE) {
                boutonOptionsSwapAccept->etat = BOUTON_OVER;
            }
        
            // Bouton plein écran
            // "Activer"
            if(*fullscreen){
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h) {
                    boutonOptionsFullscreenOff->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h) {
                    SDL_SetWindowFullscreen(window, 0);
                    *fullscreen = 0;
                    boutonOptionsFullscreenOff->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsFullscreenOff->etat == BOUTON_APPUYE  || boutonOptionsFullscreenOff->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h)) {
                    boutonOptionsFullscreenOff->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h && boutonOptionsFullscreenOff->etat == BOUTON_RELACHE) {
                    boutonOptionsFullscreenOff->etat = BOUTON_OVER;
                }
            }
            // "Désactiver"
            else {
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h) {
                    boutonOptionsFullscreenOn->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h) {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    *fullscreen = 1;
                    boutonOptionsFullscreenOn->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsFullscreenOn->etat == BOUTON_APPUYE  || boutonOptionsFullscreenOn->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h)) {
                    boutonOptionsFullscreenOn->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h && boutonOptionsFullscreenOn->etat == BOUTON_RELACHE) {
                    boutonOptionsFullscreenOn->etat = BOUTON_OVER;
                }
            }

            // Bouton retour
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h) {
                boutonOptionsBack->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h) {
                (*scene)++;
                boutonOptionsBack->etat = BOUTON_RELACHE;
                quit = 2;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsBack->etat == BOUTON_APPUYE  || boutonOptionsBack->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h)) {
                boutonOptionsBack->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h && boutonOptionsBack->etat == BOUTON_RELACHE) {
                boutonOptionsBack->etat = BOUTON_OVER;
            }

            // Bouton controle

            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsControle->position->rect->x && e.motion.x < boutonOptionsControle->position->rect->x + boutonOptionsControle->position->rect->w && e.motion.y > boutonOptionsControle->position->rect->y && e.motion.y < boutonOptionsControle->position->rect->y + boutonOptionsControle->position->rect->h) {
                boutonOptionsControle->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsControle->position->rect->x && e.motion.x < boutonOptionsControle->position->rect->x + boutonOptionsControle->position->rect->w && e.motion.y > boutonOptionsControle->position->rect->y && e.motion.y < boutonOptionsControle->position->rect->y + boutonOptionsControle->position->rect->h) {
                (*scene)--;
                boutonOptionsControle->etat = BOUTON_RELACHE;
                quit = 2;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsControle->etat == BOUTON_APPUYE  || boutonOptionsControle->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsControle->position->rect->x && e.motion.x < boutonOptionsControle->position->rect->x + boutonOptionsControle->position->rect->w && e.motion.y > boutonOptionsControle->position->rect->y && e.motion.y < boutonOptionsControle->position->rect->y + boutonOptionsControle->position->rect->h)) {
                boutonOptionsControle->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonOptionsControle->position->rect->x && e.motion.x < boutonOptionsControle->position->rect->x + boutonOptionsControle->position->rect->w && e.motion.y > boutonOptionsControle->position->rect->y && e.motion.y < boutonOptionsControle->position->rect->y + boutonOptionsControle->position->rect->h && boutonOptionsControle->etat == BOUTON_RELACHE) {
                boutonOptionsControle->etat = BOUTON_OVER;
            }
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        // Dessiner l'image de fond
        SDL_RenderCopy(renderer, optionsBGTexture, NULL, NULL);

        // Dessiner l'image du titre des options
        SDL_RenderCopy(renderer, optionsTitleTexture, NULL, optionsTitleRect->rect);

        // Dessiner l'image Résolution des options
        SDL_RenderCopy(renderer, optionsResolutionTexture, NULL, optionsResolutionRect->rect);

        // Dessiner l'image Plein écran des options
        SDL_RenderCopy(renderer, optionsFullscreenTexture, NULL, optionsFullscreenRect->rect);

        // Dessiner le texte des résolutions des options
        switch(Res)
        {
            case(0):
                    SDL_RenderCopy(renderer, optionsRes1920x1080, NULL, optionsResTextRect->rect);
                    break;
            case(1):
                    SDL_RenderCopy(renderer, optionsRes1280x720, NULL, optionsResTextRect->rect);
                    break;
            case(2):
                    SDL_RenderCopy(renderer, optionsRes854x480, NULL, optionsResTextRect->rect);
                    break;
            case(3):
                    SDL_RenderCopy(renderer, optionsRes640x360, NULL, optionsResTextRect->rect);
                    break;
            case(4):
                    SDL_RenderCopy(renderer, optionsRes426x240, NULL, optionsResTextRect->rect);
                    break;
        }

        // Dessiner le bouton du son
        if(son) {
                if(boutonOptionsSoundOn->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSoundOn->texture, boutonOptionsSoundOn->relache, boutonOptionsSoundOn->position->rect);
                else if (boutonOptionsSoundOn->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSoundOn->texture, boutonOptionsSoundOn->appuye, boutonOptionsSoundOn->position->rect);
                else if (boutonOptionsSoundOn->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSoundOn->texture, boutonOptionsSoundOn->over, boutonOptionsSoundOn->position->rect);
        }else {
                if(boutonOptionsSoundOff->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSoundOff->texture, boutonOptionsSoundOff->relache, boutonOptionsSoundOff->position->rect);
                else if (boutonOptionsSoundOff->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSoundOff->texture, boutonOptionsSoundOff->appuye, boutonOptionsSoundOff->position->rect);
                else if (boutonOptionsSoundOff->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSoundOff->texture, boutonOptionsSoundOff->over, boutonOptionsSoundOff->position->rect);
        }

        // Dessiner le bouton gauche de la résolution
        if(boutonOptionsSwapResLeft->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->relache, boutonOptionsSwapResLeft->position->rect);
        else if (boutonOptionsSwapResLeft->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->appuye, boutonOptionsSwapResLeft->position->rect);
        else if (boutonOptionsSwapResLeft->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->over, boutonOptionsSwapResLeft->position->rect);
        // Dessiner le bouton droit de la résolution
        if(boutonOptionsSwapResRight->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->relache, boutonOptionsSwapResRight->position->rect);
        else if (boutonOptionsSwapResRight->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->appuye, boutonOptionsSwapResRight->position->rect);
        else if (boutonOptionsSwapResRight->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->over, boutonOptionsSwapResRight->position->rect);
        // Dessiner le bouton appliquer de la résolution
        if(boutonOptionsSwapAccept->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->relache, boutonOptionsSwapAccept->position->rect);
        else if (boutonOptionsSwapAccept->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->appuye, boutonOptionsSwapAccept->position->rect);
        else if (boutonOptionsSwapAccept->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->over, boutonOptionsSwapAccept->position->rect);

        // Dessiner le bouton du plein écran
        if(*fullscreen) {
                if(boutonOptionsFullscreenOff->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->relache, boutonOptionsFullscreenOff->position->rect);
                else if (boutonOptionsFullscreenOff->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->appuye, boutonOptionsFullscreenOff->position->rect);
                else if (boutonOptionsFullscreenOff->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->over, boutonOptionsFullscreenOff->position->rect);
        }else {
                if(boutonOptionsFullscreenOn->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->relache, boutonOptionsFullscreenOn->position->rect);
                else if (boutonOptionsFullscreenOn->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->appuye, boutonOptionsFullscreenOn->position->rect);
                else if (boutonOptionsFullscreenOn->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->over, boutonOptionsFullscreenOn->position->rect);
        }

        // Dessiner le bouton retour
        if(boutonOptionsBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->relache, boutonOptionsBack->position->rect);
        else if (boutonOptionsBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->appuye, boutonOptionsBack->position->rect);
        else if (boutonOptionsBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->over, boutonOptionsBack->position->rect);

        // Dessiner le bouton du menu des controles
        if(boutonOptionsControle->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsControle->texture, boutonOptionsControle->relache, boutonOptionsControle->position->rect);
        else if (boutonOptionsControle->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsControle->texture, boutonOptionsControle->appuye, boutonOptionsControle->position->rect);
        else if (boutonOptionsControle->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsControle->texture, boutonOptionsControle->over, boutonOptionsControle->position->rect);

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }
    
    TTF_CloseFont(font); font = NULL;
    detruireListeRect(&listeRectangle);
    detruireListeBouton(&listeBoutons);
    detruireListeT(&listeTexture);

    return quit > 1 ? 0 : 1;
}