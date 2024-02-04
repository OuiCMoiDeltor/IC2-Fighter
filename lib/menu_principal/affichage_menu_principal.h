if(scene == MENU_PRINCIPAL) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, mainMenuBGTexture, NULL, NULL);

// Dessiner le logo
        SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect);

// Dessiner le bouton des Options
        if(boutonOptions->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->relache, boutonOptions->position);
        else if (boutonOptions->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->appuye, boutonOptions->position);
        else if (boutonOptions->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->over, boutonOptions->position);
}