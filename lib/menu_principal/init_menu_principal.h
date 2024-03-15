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
        bouton *boutonOptions = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 1400/64.0, 787/114.0, 1400/282.0, 787/527.0, IMG_BOUTON_OPT, 0, 0);
        if(boutonOptions == NULL) exit(EXIT_FAILURE);

    // Quitter
        bouton *boutonQuitter = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 4/3.0, 5/2.5, 1400/280.0, 2.0, IMG_BOUTON_QUIT, 0, 0);
        if(boutonQuitter == NULL) exit(EXIT_FAILURE);

    // Jouer
        bouton *boutonJouer = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 1400/995.0, 1045/435.0, 1400/105.0, 1045/110.0, IMG_BOUTON_PLAY, 1, 11);
        if(boutonJouer == NULL) exit(EXIT_FAILURE);

// Son 
    // Chargement musique de fond
        Mix_Music *backgroundSound = Mix_LoadMUS(SOUND_BACKGROUND);