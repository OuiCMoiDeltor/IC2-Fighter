// Création de l'image de fond
    SDL_Texture *gamemodeBGTexture = creerImage(renderer, IMG_GAMEMODE_BG);
    if(gamemodeBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gamemodeBGTexture);

// Création de l'image En ligne (Temporaire)

// Boutons
    // Local
        bouton *boutonLocal = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 5/2.0, 8/2.0, 5.0, 8.0, IMG_GAMEMODE_LOCAL, 0, 0);
        if(boutonLocal == NULL) exit(EXIT_FAILURE);

    // En ligne
        bouton *boutonLigne = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 5/2.0, 8/5.0, 5.0, 8.0, IMG_GAMEMODE_LIGNE, 0, 0);
        if(boutonLigne == NULL) exit(EXIT_FAILURE);

    // Retour
        bouton *boutonGmBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 11.0, 11.0, IMG_GAMEMODE_RETOUR, 0, 0);
        if(boutonGmBack == NULL) exit(EXIT_FAILURE);