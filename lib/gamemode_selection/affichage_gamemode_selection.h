if(scene == GAMEMODE) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, gamemodeBGTexture, NULL, NULL);

// Dessiner le bouton du mode Local
        if(boutonLocal->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->relache, boutonLocal->position->rect);
        else if (boutonLocal->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->appuye, boutonLocal->position->rect);
        else if (boutonLocal->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonLocal->texture, boutonLocal->over, boutonLocal->position->rect);

// Dessiner le bouton du mode En ligne
        if(boutonLigne->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonLigne->texture, boutonLigne->relache, boutonLigne->position->rect);
        else if (boutonLigne->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonLigne->texture, boutonLigne->appuye, boutonLigne->position->rect);
        else if (boutonLigne->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonLigne->texture, boutonLigne->over, boutonLigne->position->rect);

// Dessiner le bouton retour
        if(boutonGmBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->relache, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->appuye, boutonGmBack->position->rect);
        else if (boutonGmBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGmBack->texture, boutonGmBack->over, boutonGmBack->position->rect);
}