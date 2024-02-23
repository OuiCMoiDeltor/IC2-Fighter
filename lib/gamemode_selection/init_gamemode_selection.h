// Création de l'image de fond
    SDL_Texture *gamemodeBGTexture = creerImage(renderer, IMG_GAMEMODE_BG);
    if(gamemodeBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gamemodeBGTexture);

// Création de l'image En ligne (Temporaire)

// Boutons
    // Options
        bouton *boutonLocal = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 1400/65.0, 1045/115.0, 1400/280.0, 2.0, IMG_BOUTON_LOCAL, 0, 0);
        if(boutonLocal == NULL) exit(EXIT_FAILURE);

/*
    // Quitter
        bouton *boutonLigne = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 4/3.0, 5/2.5, 1400/280.0, 2.0, IMG_BOUTON_LIGNE, 0, 0);
        if(boutonLigne == NULL) exit(EXIT_FAILURE);
*/