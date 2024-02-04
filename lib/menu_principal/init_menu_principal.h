// Création de l'image de fond
    SDL_Texture *mainMenuBGTexture = creerImage(renderer, IMG_MAIN_MENU_BG);
    if(mainMenuBGTexture == NULL) exit(EXIT_FAILURE);
    
// Création du logo
    SDL_Texture *logoTexture = creerImage(renderer, IMG_LOGO);
    if(logoTexture == NULL) exit(EXIT_FAILURE);
    SDL_Rect logoRect = {largeurF/4, hauteurF/3/4, largeurF/2, hauteurF/3 - hauteurF/3/4};

// Boutons du menu principal
    //Options
        bouton *boutonOptions = creerBouton(renderer, largeurF/(1400/65), hauteurF/(1045/115), largeurF/(1400/280), hauteurF/2, IMG_BOUTON_OPT);
        if(boutonOptions == NULL) exit(EXIT_FAILURE);