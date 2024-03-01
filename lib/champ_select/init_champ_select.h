// Création de l'image de fond
    /*SDL_Texture *champSelectBGTexture = creerImage(renderer, IMG_CHAMPSELECT_BG);
    if(champSelectBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectBGTexture);*/

// Boutons
    // Local
        bouton *boutonRYU = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 5.0, 8.0, IMG_CHAMPSELECT_RYU, 0, 0);
        if(boutonRYU == NULL) exit(EXIT_FAILURE);