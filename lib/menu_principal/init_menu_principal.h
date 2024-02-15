// Création de l'image de fond
    SDL_Texture *mainMenuBGTexture = creerImage(renderer, IMG_MAIN_MENU_BG);
    if(mainMenuBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, mainMenuBGTexture);
    
// Création du logo
    SDL_Texture *logoTexture = creerImage(renderer, IMG_LOGO);
    if(logoTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, logoTexture);
    rectangle *logoRect = creerRectangle(&listeRectangle, &largeurF, &hauteurF, 4.0, 3*6.0, 2.0, 3*8/7.0);

// Boutons du menu principal
    // Options
        bouton *boutonOptions = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 1400/65.0, 1045/115.0, 1400/280.0, 2.0, IMG_BOUTON_OPT);
        if(boutonOptions == NULL) exit(EXIT_FAILURE);

    // Quitter
        bouton *boutonQuitter = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 4/3.0, 5/2.5, 1400/280.0, 2.0, IMG_BOUTON_QUIT);
        if(boutonQuitter == NULL) exit(EXIT_FAILURE);