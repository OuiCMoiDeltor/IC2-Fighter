// Création de l'image de fond
    SDL_Texture *optionsBGTexture = creerImage(renderer, IMG_OPTIONS_BG);
    if(optionsBGTexture == NULL) exit(EXIT_FAILURE);

// Création image titre des Options
    SDL_Texture *optionsTitleTexture = creerImage(renderer, IMG_OPTIONS_TITLE);
    if(optionsTitleTexture == NULL) exit(EXIT_FAILURE);
    SDL_Rect optionsTitleRect = {largeurF/4, 0, largeurF/2, hauteurF/8};
/*
// Création image résolution des Options
    SDL_Texture *optionsResolutionTexture = creerImage(renderer, IMG_OPTIONS_RESOLUTION);
    if(optionsResolutionTexture == NULL) exit(EXIT_FAILURE);

// Création image plein écran des Options
    SDL_Texture *optionsFullscreenTexture = creerImage(renderer, IMG_OPTIONS_FULLSCREEN);
    if(optionsFullscreenTexture == NULL) exit(EXIT_FAILURE);

// Boutons
    // Bouton plein écran "activer"
        SDL_Texture *optionsFullscreenOnTexture = creerBouton(renderer, "largeur", "hauteur", largeurOptions, hauteurOptions, IMG_OPTIONS_FULLSCREEN_TURN_ON);
        if(optionsFullscreenOnTexture == NULL) exit(EXIT_FAILURE);
    // Bouton plein écran "désactiver"
        SDL_Texture *optionsFullscreenOffTexture = creerBouton(renderer, "largeur", "hauteur", largeurOptions, hauteurOptions, IMG_OPTIONS_FULLSCREEN_TURN_OFF);
        if(optionsFullscreenOffTexture == NULL) exit(EXIT_FAILURE);
*/