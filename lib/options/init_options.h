// Création de l'image de fond
    SDL_Texture *optionsBGTexture = creerImage(renderer, IMG_OPTIONS_BG);
    if(optionsBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsBGTexture);

// Création image titre des Options
    SDL_Texture *optionsTitleTexture = creerImage(renderer, IMG_OPTIONS_TITLE);
    if(optionsTitleTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsTitleTexture);
    SDL_Rect optionsTitleRect = {largeurF/4, hauteurF/4/8, largeurF/2, hauteurF/4};

// Création image résolution des Options
    SDL_Texture *optionsResolutionTexture = creerImage(renderer, IMG_OPTIONS_RESOLUTION);
    if(optionsResolutionTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsResolutionTexture);
    SDL_Rect optionsResolutionRect = {largeurF/10, (hauteurF/3/4)*3, (largeurF/10)*8, hauteurF/5};

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

    SDL_Rect optionsResTextRect = {(largeurF/10)*4, (hauteurF/3/3)*4, (largeurF/10)*2, hauteurF/11};

// Création image plein écran des Options
    SDL_Texture *optionsFullscreenTexture = creerImage(renderer, IMG_OPTIONS_FULLSCREEN);
    if(optionsFullscreenTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, optionsFullscreenTexture);
    SDL_Rect optionsFullscreenRect= {largeurF/10, (hauteurF/3/3)*5, (largeurF/10)*8, hauteurF/5};

// Boutons
    // changement de résolution
        // gauche
            bouton *boutonOptionsSwapResLeft = creerBouton(renderer, (largeurF/10)*3, (hauteurF/3/3)*4, largeurF/10, hauteurF/11, IMG_OPTIONS_FULLSCREEN_TURN_ON);
            if(boutonOptionsSwapResLeft == NULL) exit(EXIT_FAILURE);
        // droit
            bouton *boutonOptionsSwapResRight = creerBouton(renderer, (largeurF/10)*6, (hauteurF/3/3)*4, largeurF/10, hauteurF/11, IMG_OPTIONS_FULLSCREEN_TURN_OFF);
            if(boutonOptionsSwapResRight == NULL) exit(EXIT_FAILURE);
        // accepter
            bouton *boutonOptionsSwapAccept = creerBouton(renderer, (largeurF/10)*8, (hauteurF/3/3)*4, largeurF/10, hauteurF/11, IMG_OPTIONS_FULLSCREEN_TURN_ON);
            if(boutonOptionsSwapAccept == NULL) exit(EXIT_FAILURE);

    // plein écran
        // "activer"
            bouton *boutonOptionsFullscreenOn = creerBouton(renderer, largeurF/11*4, (hauteurF/3/3)*7, largeurF/11*3, hauteurF/11, IMG_OPTIONS_FULLSCREEN_TURN_ON);
            if(boutonOptionsFullscreenOn == NULL) exit(EXIT_FAILURE);
        // "désactiver"
            bouton *boutonOptionsFullscreenOff = creerBouton(renderer, largeurF/11*4, (hauteurF/3/3)*7, largeurF/11*3, hauteurF/11, IMG_OPTIONS_FULLSCREEN_TURN_OFF);
            if(boutonOptionsFullscreenOff == NULL) exit(EXIT_FAILURE);

    // retour
            bouton *boutonOptionsBack = creerBouton(renderer, largeurF/11*5, hauteurF/11*10, largeurF/11, hauteurF/11, IMG_OPTIONS_BACK);
            if(boutonOptionsBack == NULL) exit(EXIT_FAILURE);