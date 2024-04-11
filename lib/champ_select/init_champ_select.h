int J2Pick = 0;
personnage *Joueur1 = NULL;
personnage *Joueur2 = NULL;

// Création de l'image de fond
    SDL_Texture *champSelectBGTexture = creerImage(renderer, IMG_CHAMPSELECT_BG);
    if(champSelectBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectBGTexture);

// Création des images de séléction du joueur courant
    SDL_Texture *champSelectJ1 = creerImage(renderer, IMG_CHAMPSELECT_J1);
    if(champSelectJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectJ1);
    rectangle *champSelectJ1Rect = creerRectangle(&largeurF, &hauteurF, 25/5.0, 100/2.0, 25/15.0, 100/16.0);
    ajoutListeRect(&listeRectangle, &champSelectJ1Rect);

    SDL_Texture *champSelectJ2 = creerImage(renderer, IMG_CHAMPSELECT_J2);
    if(champSelectJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectJ2);
    rectangle *champSelectJ2Rect = creerRectangle(&largeurF, &hauteurF, 25/5.0, 100/2.0, 25/15.0, 100/16.0);
    ajoutListeRect(&listeRectangle, &champSelectJ2Rect);

// Boutons
    // Local
        bouton *boutonRYU = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/2.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 1, 10);
        if(boutonRYU == NULL) exit(EXIT_FAILURE);

        bouton *boutonRYU2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/6.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_DIM, 1, 10);
        if(boutonRYU2 == NULL) exit(EXIT_FAILURE);
// Son 
    // Chargement musique de fond
        Mix_Music *backgroundSoundSelect = Mix_LoadMUS(SOUND_BACKGROUND_SELECT);



