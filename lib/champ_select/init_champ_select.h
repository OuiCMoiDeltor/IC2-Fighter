int J2Pick = 0;
personnage *Joueur1 = NULL;
personnage *Joueur2 = NULL;

// Création de l'image de fond
    /*SDL_Texture *champSelectBGTexture = creerImage(renderer, IMG_CHAMPSELECT_BG);
    if(champSelectBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &champSelectBGTexture);*/

// Boutons
    // Local
        bouton *boutonRYU = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 25/1.0, 100/20.0, 25/3.0, 100/30.0, IMG_CHAMPSELECT_RYU, 0, 0);
        if(boutonRYU == NULL) exit(EXIT_FAILURE);