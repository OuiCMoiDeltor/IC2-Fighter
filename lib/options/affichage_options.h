else if(scene == OPTIONS) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, optionsBGTexture, NULL, NULL);

// Dessiner l'image du titre des options
        SDL_RenderCopy(renderer, optionsTitleTexture, NULL, &optionsTitleRect);

// Dessiner le bouton du plein écran
        if(fullscreen) {
                if(boutonOptionsFullscreenOff->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->relache, boutonOptionsFullscreenOff->position);
                else if (boutonOptionsFullscreenOff->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->appuye, boutonOptionsFullscreenOff->position);
                else if (boutonOptionsFullscreenOff->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->over, boutonOptionsFullscreenOff->position);
        }else {
                if(boutonOptionsFullscreenOn->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->relache, boutonOptionsFullscreenOn->position);
                else if (boutonOptionsFullscreenOn->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->appuye, boutonOptionsFullscreenOn->position);
                else if (boutonOptionsFullscreenOn->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->over, boutonOptionsFullscreenOn->position);
        }

// Dessiner le bouton retour
        if(boutonOptionsBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->relache, boutonOptionsBack->position);
        else if (boutonOptionsBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->appuye, boutonOptionsBack->position);
        else if (boutonOptionsBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->over, boutonOptionsBack->position);
}