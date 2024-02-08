// Création de l'image de fond
    SDL_Texture *optionsBGTexture = creerImage(renderer, IMG_OPTIONS_BG);
    if(optionsBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsBGTexture);

// Création image titre des Options
    SDL_Texture *optionsTitleTexture = creerImage(renderer, IMG_OPTIONS_TITLE);
    if(optionsTitleTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsTitleTexture);
    SDL_Rect optionsTitleRect = {largeurF/4, hauteurF/3/4, largeurF/2, hauteurF/4};

//Création image résolution des Options
    SDL_Texture *optionsResolutionTexture = creerImage(renderer, IMG_OPTIONS_RESOLUTION);
    if(optionsResolutionTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsResolutionTexture);
    SDL_Rect optionsResolutionRect = {largeurF/4, (hauteurF/3/4)*3, largeurF/2, hauteurF/4};

// Création image plein écran des Options
    SDL_Texture *optionsFullscreenTexture = creerImage(renderer, IMG_OPTIONS_FULLSCREEN);
    if(optionsFullscreenTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsFullscreenTexture);
    SDL_Rect optionsFullscreenRect= {largeurF/4, (hauteurF/9)*5, largeurF/2, hauteurF/4};

// Boutons
    // plein écran
        // "activer"
            bouton *boutonOptionsFullscreenOn = creerBouton(renderer, largeurF/11*5, hauteurF/11*5, largeurF/11, hauteurF/11, IMG_OPTIONS_FULLSCREEN_TURN_ON);
            if(boutonOptionsFullscreenOn == NULL) exit(EXIT_FAILURE);
        // "désactiver"
            bouton *boutonOptionsFullscreenOff = creerBouton(renderer, largeurF/11*5, hauteurF/11*5, largeurF/11, hauteurF/11, IMG_OPTIONS_FULLSCREEN_TURN_OFF);
            if(boutonOptionsFullscreenOff == NULL) exit(EXIT_FAILURE);
    // retour
            bouton *boutonOptionsBack = creerBouton(renderer, largeurF/11*5, hauteurF/11*10, largeurF/11, hauteurF/11, IMG_OPTIONS_BACK);
            if(boutonOptionsBack == NULL) exit(EXIT_FAILURE);