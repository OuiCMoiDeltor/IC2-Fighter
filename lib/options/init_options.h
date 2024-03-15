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
        // droit
            bouton *boutonOptionsSwapResRight = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 40/25.0, 30/14.0, 30.0, 21.0, IMG_OPTIONS_RESOLUTION_RIGHT, 0, 0);
            if(boutonOptionsSwapResRight == NULL) exit(EXIT_FAILURE);
        // appliquer
            bouton *boutonOptionsSwapAccept = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/5.0, 11/3.0, 11.0, IMG_OPTIONS_RESOLUTION_APPLIKER, 0, 0);
            if(boutonOptionsSwapAccept == NULL) exit(EXIT_FAILURE);

    // plein écran
        // "activer"
            bouton *boutonOptionsFullscreenOn = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/8.0, 11/3.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_ON, 0, 0);
            if(boutonOptionsFullscreenOn == NULL) exit(EXIT_FAILURE);
        // "désactiver"
            bouton *boutonOptionsFullscreenOff = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/8.0, 11/3.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_OFF, 0, 0);
            if(boutonOptionsFullscreenOff == NULL) exit(EXIT_FAILURE);

    // retour
            bouton *boutonOptionsBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 11.0, 11.0, IMG_OPTIONS_BACK, 0, 0);
            if(boutonOptionsBack == NULL) exit(EXIT_FAILURE);

    // son
        // on
            bouton *boutonOptionsSoundOn = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/10.0, 100.0, 11/1.0, 11.0, IMG_OPTIONS_SOUND_ON, 0, 0);
            if(boutonOptionsSoundOn == NULL) exit(EXIT_FAILURE);
        // off
            bouton *boutonOptionsSoundOff = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/10.0, 100.0, 11/1.0, 11.0, IMG_OPTIONS_SOUND_OFF, 0, 0);
            if(boutonOptionsSoundOff == NULL) exit(EXIT_FAILURE);