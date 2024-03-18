if(scene == CHAMP_SELECT) {
// Dessiner l'image de fond
        //SDL_RenderCopy(renderer, champSelectBGTexture, NULL, NULL);

// Dessiner l'image de séléction du joueur courant
        if(J2Pick)
                SDL_RenderCopy(renderer, champSelectJ2, NULL, champSelectJ1Rect->rect);
        else
                SDL_RenderCopy(renderer, champSelectJ1, NULL, champSelectJ2Rect->rect);

// Dessiner le bouton de RYU
        if(boutonRYU->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonRYU->texture, boutonRYU->relache, boutonRYU->position->rect);
        else if (boutonRYU->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonRYU->texture, boutonRYU->appuye, boutonRYU->position->rect);
        else if (boutonRYU->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonRYU->texture, boutonRYU->over, boutonRYU->position->rect);
}