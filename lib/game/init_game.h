const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

// Création de l'image de fond
    SDL_Texture *gameBGTexture = creerImage(renderer, IMG_GAME_BG);
    if(gameBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gameBGTexture);

// Mise à jour de l'écran
SDL_RenderPresent(renderer);

// Son 
    // Chargement musique de fond
        Mix_Music *backgroundCombatSound = Mix_LoadMUS(SOUND_BACKGROUND_COMBAT);
