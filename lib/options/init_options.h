// Création de l'image de fond
    SDL_Texture *optionsBGTexture = creerImage(renderer, IMG_OPTIONS_BG);
    if(optionsBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsBGTexture);

// Création image titre des Options
    SDL_Texture *optionsTitleTexture = creerImage(renderer, IMG_OPTIONS_TITLE);
    if(optionsTitleTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsTitleTexture);
    rectangle *optionsTitleRect = creerRectangle(&listeRectangle, &largeurF, &hauteurF, 4.0, 4*8.0, 2.0, 4.0);

// Création image résolution des Options
    SDL_Texture *optionsResolutionTexture = creerImage(renderer, IMG_OPTIONS_RESOLUTION);
    if(optionsResolutionTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsResolutionTexture);
    rectangle *optionsResolutionRect = creerRectangle(&listeRectangle, &largeurF, &hauteurF, 10.0, 3*4/3.0, 10/8.0, 5.0);

// Création textes résolutions
    int Res = 0;
    // 1680x1050
    SDL_Texture *optionsRes1680x1050 = creerTexte(renderer,font,"1680x1050",noire);
    if(optionsRes1680x1050 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsRes1680x1050);
    // 1024x768
    SDL_Texture *optionsRes1024x768 = creerTexte(renderer,font,"1024x768",noire);
    if(optionsRes1024x768 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsRes1024x768);

    rectangle *optionsResTextRect = creerRectangle(&listeRectangle, &largeurF, &hauteurF, 10/4.0, 3*3/4.0, 10/2.0, 11.0);

// Création image plein écran des Options
    SDL_Texture *optionsFullscreenTexture = creerImage(renderer, IMG_OPTIONS_FULLSCREEN);
    if(optionsFullscreenTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsFullscreenTexture);
    rectangle *optionsFullscreenRect = creerRectangle(&listeRectangle, &largeurF, &hauteurF, 10.0, 3*3/5.0, 10/8.0, 5.0);

// Boutons
    // changement de résolution
        // gauche
            bouton *boutonOptionsSwapResLeft = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 10/3.0, 3*3/4.0, 10.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_ON);
            if(boutonOptionsSwapResLeft == NULL) exit(EXIT_FAILURE);
        // droit
            bouton *boutonOptionsSwapResRight = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 10/6.0, 3*3/4.0, 10.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_OFF);
            if(boutonOptionsSwapResRight == NULL) exit(EXIT_FAILURE);
        // accepter
            bouton *boutonOptionsSwapAccept = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 10/8.0, 3*3/4.0, 10.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_ON);
            if(boutonOptionsSwapAccept == NULL) exit(EXIT_FAILURE);
            printf("%d , %d , %d , %d /", boutonOptionsSwapResLeft->position->rect->x, boutonOptionsSwapResLeft->position->rect->y, boutonOptionsSwapResLeft->position->rect->w, boutonOptionsSwapResLeft->position->rect->h);
            printf("%d , %d , %d , %d /", optionsResTextRect->rect->x, optionsResTextRect->rect->y, optionsResTextRect->rect->w, optionsResTextRect->rect->h);

    // plein écran
        // "activer"
            bouton *boutonOptionsFullscreenOn = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/7.0, 11/3.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_ON);
            if(boutonOptionsFullscreenOn == NULL) exit(EXIT_FAILURE);
        // "désactiver"
            bouton *boutonOptionsFullscreenOff = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/4.0, 3*3/7.0, 11/3.0, 11.0, IMG_OPTIONS_FULLSCREEN_TURN_OFF);
            if(boutonOptionsFullscreenOff == NULL) exit(EXIT_FAILURE);

    // retour
            bouton *boutonOptionsBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 11/5.0, 11/10.0, 11.0, 11.0, IMG_OPTIONS_BACK);
            if(boutonOptionsBack == NULL) exit(EXIT_FAILURE);