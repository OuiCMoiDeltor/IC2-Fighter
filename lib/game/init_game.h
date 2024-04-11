const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
int reverseIdle = 0; int reverseWalk = 0;
int reverseIdle2 = 0; int reverseWalk2 = 0;

// Création de l'image de fond
    SDL_Texture *gameBGTexture = creerImage(renderer, IMG_GAME_BG);
    if(gameBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gameBGTexture);

// Mise à jour de l'écran
SDL_RenderPresent(renderer);
