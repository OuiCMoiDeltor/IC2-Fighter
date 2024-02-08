else if(scene == OPTIONS) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, optionsBGTexture, NULL, NULL);

// Dessiner l'image du titre des options
        SDL_RenderCopy(renderer, optionsTitleTexture, NULL, &optionsTitleRect);

// Dessiner l'image Résolution des options
        SDL_RenderCopy(renderer, optionsResolutionTexture, NULL, &optionsResolutionRect);

// Dessiner l'image Plein écran des options
        SDL_RenderCopy(renderer, optionsFullscreenTexture, NULL, &optionsFullscreenRect);

// Dessiner le texte des résolutions des options
        switch(Res)
        {
                case(0):
                        SDL_RenderCopy(renderer, optionsRes1680x1050, NULL, &optionsResTextRect);
                        break;
                case(1):
                        SDL_RenderCopy(renderer, optionsRes1024x768, NULL, &optionsResTextRect);
                        break;
        }

// Dessiner le bouton gauche de la résolution
        if(boutonOptionsSwapResLeft->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->relache, boutonOptionsSwapResLeft->position);
        else if (boutonOptionsSwapResLeft->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->appuye, boutonOptionsSwapResLeft->position);
        else if (boutonOptionsSwapResLeft->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->over, boutonOptionsSwapResLeft->position);
// Dessiner le bouton droit de la résolution
        if(boutonOptionsSwapResRight->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->relache, boutonOptionsSwapResRight->position);
        else if (boutonOptionsSwapResRight->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->appuye, boutonOptionsSwapResRight->position);
        else if (boutonOptionsSwapResRight->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->over, boutonOptionsSwapResRight->position);
// Dessiner le bouton accepter de la résolution
        if(boutonOptionsSwapAccept->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->relache, boutonOptionsSwapAccept->position);
        else if (boutonOptionsSwapAccept->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->appuye, boutonOptionsSwapAccept->position);
        else if (boutonOptionsSwapAccept->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->over, boutonOptionsSwapAccept->position);

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