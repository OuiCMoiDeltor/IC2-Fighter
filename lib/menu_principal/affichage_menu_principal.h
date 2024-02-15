if(scene == MENU_PRINCIPAL) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, mainMenuBGTexture, NULL, NULL);

// Dessiner le logo
        SDL_RenderCopy(renderer, logoTexture, NULL, logoRect->rect);

// Dessiner le bouton des Options
        if(boutonOptions->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->relache, boutonOptions->position->rect);
        else if (boutonOptions->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->appuye, boutonOptions->position->rect);
        else if (boutonOptions->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptions->texture, boutonOptions->over, boutonOptions->position->rect);

// Dessiner le bouton Quitter
        if(boutonQuitter->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->relache, boutonQuitter->position->rect);
        else if (boutonQuitter->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->appuye, boutonQuitter->position->rect);
        else if (boutonQuitter->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->over, boutonQuitter->position->rect);
}