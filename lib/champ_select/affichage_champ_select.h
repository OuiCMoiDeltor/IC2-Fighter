if(scene == CHAMP_SELECT) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, champSelectBGTexture, NULL, NULL);

// Dessiner l'image de séléction du joueur courant
        if(J2Pick)
                SDL_RenderCopy(renderer, champSelectJ2, NULL, champSelectJ1Rect->rect);
        else
                SDL_RenderCopy(renderer, champSelectJ1, NULL, champSelectJ2Rect->rect);

// Dessiner le bouton de RYU
        SDL_RenderCopy(renderer, boutonRYU->texture, boutonRYU->frames[boutonRYU->etat], boutonRYU->position->rect);
        // Animation
        waitForFrame++;
        if(waitForFrame > 10) {
                boutonRYU->etat =  ++boutonRYU->etat%10;
                waitForFrame = 0;
        }
// Dessiner le bouton de DIM
        SDL_RenderCopy(renderer, boutonRYU2->texture, boutonRYU2->frames[boutonRYU2->etat], boutonRYU2->position->rect);
        // Animation
        waitForFrame++;
        if(waitForFrame > 10) {
                boutonRYU2->etat =  ++boutonRYU2->etat%10;
                waitForFrame = 0;
        }
}
