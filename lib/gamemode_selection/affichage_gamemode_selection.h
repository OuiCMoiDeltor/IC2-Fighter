if(scene == GAMEMODE) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, gamemodeBGTexture, NULL, NULL);

// Dessiner le bouton du mode Local
        if(boutonLocal->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->relache, boutonLocal->position->rect);
        else if (boutonLocal->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->appuye, boutonLocal->position->rect);
        else if (boutonLocal->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->over, boutonLocal->position->rect);

// Dessiner l'image du mode En ligne (Temporaire)

/*
// Dessiner le bouton du mode En ligne
        if(boutonQuitter->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->relache, boutonQuitter->position->rect);
        else if (boutonQuitter->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->appuye, boutonQuitter->position->rect);
        else if (boutonQuitter->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonQuitter->texture, boutonQuitter->over, boutonQuitter->position->rect);
*/
}