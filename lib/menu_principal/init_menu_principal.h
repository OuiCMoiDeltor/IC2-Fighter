// Création de l'image de fond
    SDL_Texture *imageTexture = creerImage(renderer, IMG_MAIN_SCREEN);
    if(imageTexture == NULL) exit(EXIT_FAILURE);
    
// Création du logo
    SDL_Texture *logoTexture = creerImage(renderer, IMG_LOGO);
    if(logoTexture == NULL) exit(EXIT_FAILURE);
    SDL_Rect logoRect = {LARGEUR_F/4, HAUTEUR_F/3/4, LARGEUR_F/2, HAUTEUR_F/3 - HAUTEUR_F/3/4};

// Boutons du menu principal
    //Options
        int largeurOptions = LARGEUR_F/(1400/280);
        int hauteurOptions = HAUTEUR_F/2;
        bouton *boutonOptions = creerBouton(renderer, LARGEUR_F/(1400/65), HAUTEUR_F/(1045/115), largeurOptions, hauteurOptions, IMG_BOUTON_OPT);
        if(boutonOptions == NULL) exit(EXIT_FAILURE);