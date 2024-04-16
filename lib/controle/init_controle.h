int liste_touches[14] = {SDL_SCANCODE_W, SDL_SCANCODE_UP, SDL_SCANCODE_S, SDL_SCANCODE_DOWN, SDL_SCANCODE_A, SDL_SCANCODE_LEFT, SDL_SCANCODE_D, SDL_SCANCODE_RIGHT, SDL_SCANCODE_C, SDL_SCANCODE_KP_5, SDL_SCANCODE_V, SDL_SCANCODE_KP_6, SDL_SCANCODE_F, SDL_SCANCODE_KP_4};

// Création de l'image de fond
    SDL_Texture *controleBGTexture = creerImage(renderer, IMG_CONTROLE_BG);
    if(controleBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &controleBGTexture);

// Création image titre des Controles
    SDL_Texture *controleTitleTexture = creerImage(renderer, IMG_CONTROLE);
    if(controleTitleTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &controleTitleTexture);
    rectangle *controleTitleRect = creerRectangle(&largeurF, &hauteurF, 4.0, 4*8.0, 2.0, 2.0);
    ajoutListeRect(&listeRectangle, &controleTitleRect);

// Création image J1
    SDL_Texture *J1 = creerImage(renderer, IMG_J1);
    if(J1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &J1);
    rectangle *J1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/11.65, 11.0/2, 16.0, 16.0);
    ajoutListeRect(&listeRectangle, &J1Rect);

// Création image J2
    SDL_Texture *J2 = creerImage(renderer, IMG_J2);
    if(J2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &J2);
    rectangle *J2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/16.65, 11.0/2, 13.0, 13.0);
    ajoutListeRect(&listeRectangle, &J2Rect);

// Txt
    // saut

        SDL_Texture *sauter = creerImage(renderer, IMG_SAUTER);
        if(sauter == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &sauter);
        rectangle *sautRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/3, 6.0, 6.0);
        ajoutListeRect(&listeRectangle, &sautRect);
    
    // saut J1
        SDL_Texture *sauterJ1 = creerTexte(renderer,font,"Z",noire);
        if(sauterJ1 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &sauterJ1);
        rectangle *sauterJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/3.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &sauterJ1Rect);

    // saut J2
        SDL_Texture *sauterJ2 = creerTexte(renderer,font,"Up",noire);
        if(sauterJ2 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &sauterJ2);
        rectangle *sauterJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/3.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &sauterJ2Rect);

    // accroupi

        SDL_Texture *accroupir = creerImage(renderer, IMG_ACCROUPI);
        if(accroupir == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &accroupir);
        rectangle *accroupirRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/4, 4.0, 4.0);
        ajoutListeRect(&listeRectangle, &accroupirRect);
    
    // accroupi J1
        SDL_Texture *accroupirJ1 = creerTexte(renderer,font,"S",noire);
        if(accroupirJ1 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &accroupirJ1);
        rectangle *accroupirJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/4.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &accroupirJ1Rect);

    // accroupi J2
        SDL_Texture *accroupirJ2 = creerTexte(renderer,font,"DOWN",noire);
        if(accroupirJ2 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &accroupirJ2);
        rectangle *accroupirJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/4.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &accroupirJ2Rect);

    // gauche

        SDL_Texture *gauche = creerImage(renderer, IMG_GAUCHE);
        if(gauche == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &gauche);
        rectangle *gaucheRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/5, 6.0, 6.0);
        ajoutListeRect(&listeRectangle, &gaucheRect);
    
    // gauche J1
        SDL_Texture *gaucheJ1 = creerTexte(renderer,font,"Q",noire);
        if(gaucheJ1 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &gaucheJ1);
        rectangle *gaucheJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/5.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &gaucheJ1Rect);

    // gauche J2
        SDL_Texture *gaucheJ2 = creerTexte(renderer,font,"LEFT",noire);
        if(gaucheJ2 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &gaucheJ2);
        rectangle *gaucheJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/5.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &gaucheJ2Rect);

    // droite

        SDL_Texture *droite = creerImage(renderer, IMG_DROITE);
        if(droite == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &droite);
        rectangle *droiteRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/6, 6.0, 6.0);
        ajoutListeRect(&listeRectangle, &droiteRect);
    
    // droite J1
        SDL_Texture *droiteJ1 = creerTexte(renderer,font,"D",noire);
        if(droiteJ1 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &droiteJ1);
        rectangle *droiteJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/6.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &droiteJ1Rect);

    // droite J2
        SDL_Texture *droiteJ2 = creerTexte(renderer,font,"RIGHT",noire);
        if(droiteJ2 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &droiteJ2);
        rectangle *droiteJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/6.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &droiteJ2Rect);

    // poing

        SDL_Texture *poing = creerImage(renderer, IMG_POING);
        if(poing == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &poing);
        rectangle *poingRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/7, 6.0, 6.0);
        ajoutListeRect(&listeRectangle, &poingRect);
    
    // poing J1
        SDL_Texture *poingJ1 = creerTexte(renderer,font,"C",noire);
        if(poingJ1 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &poingJ1);
        rectangle *poingJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/7.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &poingJ1Rect);

    // poing J2
        SDL_Texture *poingJ2 = creerTexte(renderer,font,"Keypad 5",noire);
        if(poingJ2 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &poingJ2);
        rectangle *poingJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/7.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &poingJ2Rect);

    // kick

        SDL_Texture *kick = creerImage(renderer, IMG_KICK);
        if(kick == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &kick);
        rectangle *kickRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/8, 8.0, 8.0);
        ajoutListeRect(&listeRectangle, &kickRect);
    
    // kick J1
        SDL_Texture *kickJ1 = creerTexte(renderer,font,"V",noire);
        if(kickJ1 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &kickJ1);
        rectangle *kickJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/8.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &kickJ1Rect);

    // kick J2
        SDL_Texture *kickJ2 = creerTexte(renderer,font,"Keypad 6",noire);
        if(kickJ2 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &kickJ2);
        rectangle *kickJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/8.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &kickJ2Rect);

    // garde

        SDL_Texture *garde = creerImage(renderer, IMG_GARDE);
        if(garde == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &garde);
        rectangle *gardeRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/9, 6.0, 6.0);
        ajoutListeRect(&listeRectangle, &gardeRect);
    
    // garde J1
        SDL_Texture *gardeJ1 = creerTexte(renderer,font,"F",noire);
        if(gardeJ1 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &gardeJ1);
        rectangle *gardeJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/9.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &gardeJ1Rect);

    // garde J2
        SDL_Texture *gardeJ2 = creerTexte(renderer,font,"Keypad 4",noire);
        if(gardeJ2 == NULL) exit(EXIT_FAILURE);
        ajoutListeT(&listeTexture, &gardeJ2);
        rectangle *gardeJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/9.25, 32.0, 32.0);
        ajoutListeRect(&listeRectangle, &gardeJ2Rect);

    

// Boutons
    // retour
        bouton *boutonControleBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 11.0, 11.0, IMG_BACK, 0, 0);
        if(boutonControleBack == NULL) exit(EXIT_FAILURE);

    // saut J1
        bouton *boutonSautJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/3.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonSautJ1 == NULL) exit(EXIT_FAILURE);
    // saut J2
        bouton *boutonSautJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/3.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonSautJ2 == NULL) exit(EXIT_FAILURE);
    // accroupi J1
        bouton *boutonAccroupirJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/4.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonAccroupirJ1 == NULL) exit(EXIT_FAILURE);
    // accroupi J2
        bouton *boutonAccroupirJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/4.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonAccroupirJ2 == NULL) exit(EXIT_FAILURE);
    // gauche J1
        bouton *boutonGaucheJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/5.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonGaucheJ1 == NULL) exit(EXIT_FAILURE);
    // gauche J2
        bouton *boutonGaucheJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/5.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonGaucheJ2 == NULL) exit(EXIT_FAILURE);
    // droite J1
        bouton *boutonDroiteJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/6.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonDroiteJ1 == NULL) exit(EXIT_FAILURE);
    // droite J2
        bouton *boutonDroiteJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/6.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonDroiteJ2 == NULL) exit(EXIT_FAILURE);
    // poing J1
        bouton *boutonPoingJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/7.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonPoingJ1 == NULL) exit(EXIT_FAILURE);
    // poing J2
        bouton *boutonPoingJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/7.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonPoingJ2 == NULL) exit(EXIT_FAILURE);
    // kick J1
        bouton *boutonKickJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/8.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonKickJ1 == NULL) exit(EXIT_FAILURE);
    // kick J2
        bouton *boutonKickJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/8.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonKickJ2 == NULL) exit(EXIT_FAILURE);
    // garde J1
        bouton *boutonGardeJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/9.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonGardeJ1 == NULL) exit(EXIT_FAILURE);
    // garde J2
        bouton *boutonGardeJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/9.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
        if(boutonGardeJ2 == NULL) exit(EXIT_FAILURE);
