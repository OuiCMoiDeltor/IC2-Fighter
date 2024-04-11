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
// Dessiner le bouton de DIM
        SDL_RenderCopy(renderer, boutonRYU2->texture, boutonRYU2->frames[boutonRYU2->etat], boutonRYU2->position->rect);
// Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU3->texture, boutonRYU3->frames[boutonRYU3->etat], boutonRYU3->position->rect);
// Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU4->texture, boutonRYU4->frames[boutonRYU4->etat], boutonRYU4->position->rect);
// Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU5->texture, boutonRYU5->frames[boutonRYU5->etat], boutonRYU5->position->rect);
// Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU6->texture, boutonRYU6->frames[boutonRYU6->etat], boutonRYU6->position->rect);
// Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU7->texture, boutonRYU7->frames[boutonRYU7->etat], boutonRYU7->position->rect);
// Dessiner le bouton de 
        SDL_RenderCopy(renderer, boutonRYU8->texture, boutonRYU8->frames[boutonRYU8->etat], boutonRYU8->position->rect);
// Animation
// Animation
        waitForFrame++;
        if(waitForFrame > 10) {
                boutonRYU->etat =  ++boutonRYU->etat%10;
                boutonRYU2->etat =  ++boutonRYU2->etat%10;
                boutonRYU3->etat =  ++boutonRYU3->etat%10;
                boutonRYU4->etat =  ++boutonRYU4->etat%10;
                boutonRYU5->etat =  ++boutonRYU5->etat%10;
                boutonRYU6->etat =  ++boutonRYU6->etat%10;
                boutonRYU7->etat =  ++boutonRYU7->etat%10;
                boutonRYU8->etat =  ++boutonRYU8->etat%10;
                waitForFrame = 0;
        }
}
