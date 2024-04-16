else if(scene == OPTIONS) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, optionsBGTexture, NULL, NULL);

// Dessiner l'image du titre des options
        SDL_RenderCopy(renderer, optionsTitleTexture, NULL, optionsTitleRect->rect);

// Dessiner l'image Résolution des options
        SDL_RenderCopy(renderer, optionsResolutionTexture, NULL, optionsResolutionRect->rect);

// Dessiner l'image Plein écran des options
        SDL_RenderCopy(renderer, optionsFullscreenTexture, NULL, optionsFullscreenRect->rect);

// Dessiner le texte des résolutions des options
        switch(Res)
        {
                case(0):
                        SDL_RenderCopy(renderer, optionsRes1920x1080, NULL, optionsResTextRect->rect);
                        break;
                case(1):
                        SDL_RenderCopy(renderer, optionsRes1280x720, NULL, optionsResTextRect->rect);
                        break;
                case(2):
                        SDL_RenderCopy(renderer, optionsRes854x480, NULL, optionsResTextRect->rect);
                        break;
                case(3):
                        SDL_RenderCopy(renderer, optionsRes640x360, NULL, optionsResTextRect->rect);
                        break;
                case(4):
                        SDL_RenderCopy(renderer, optionsRes426x240, NULL, optionsResTextRect->rect);
                        break;
        }

// Dessiner le bouton du son
        if(son) {
                if(boutonOptionsSoundOn->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSoundOn->texture, boutonOptionsSoundOn->relache, boutonOptionsSoundOn->position->rect);
                else if (boutonOptionsSoundOn->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSoundOn->texture, boutonOptionsSoundOn->appuye, boutonOptionsSoundOn->position->rect);
                else if (boutonOptionsSoundOn->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSoundOn->texture, boutonOptionsSoundOn->over, boutonOptionsSoundOn->position->rect);
        }else {
                if(boutonOptionsSoundOff->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSoundOff->texture, boutonOptionsSoundOff->relache, boutonOptionsSoundOff->position->rect);
                else if (boutonOptionsSoundOff->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSoundOff->texture, boutonOptionsSoundOff->appuye, boutonOptionsSoundOff->position->rect);
                else if (boutonOptionsSoundOff->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSoundOff->texture, boutonOptionsSoundOff->over, boutonOptionsSoundOff->position->rect);
        }

// Dessiner le bouton gauche de la résolution
        if(boutonOptionsSwapResLeft->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->relache, boutonOptionsSwapResLeft->position->rect);
        else if (boutonOptionsSwapResLeft->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->appuye, boutonOptionsSwapResLeft->position->rect);
        else if (boutonOptionsSwapResLeft->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapResLeft->texture, boutonOptionsSwapResLeft->over, boutonOptionsSwapResLeft->position->rect);
// Dessiner le bouton droit de la résolution
        if(boutonOptionsSwapResRight->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->relache, boutonOptionsSwapResRight->position->rect);
        else if (boutonOptionsSwapResRight->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->appuye, boutonOptionsSwapResRight->position->rect);
        else if (boutonOptionsSwapResRight->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapResRight->texture, boutonOptionsSwapResRight->over, boutonOptionsSwapResRight->position->rect);
// Dessiner le bouton appliquer de la résolution
        if(boutonOptionsSwapAccept->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->relache, boutonOptionsSwapAccept->position->rect);
        else if (boutonOptionsSwapAccept->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->appuye, boutonOptionsSwapAccept->position->rect);
        else if (boutonOptionsSwapAccept->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsSwapAccept->texture, boutonOptionsSwapAccept->over, boutonOptionsSwapAccept->position->rect);

// Dessiner le bouton du plein écran
        if(fullscreen) {
                if(boutonOptionsFullscreenOff->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->relache, boutonOptionsFullscreenOff->position->rect);
                else if (boutonOptionsFullscreenOff->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->appuye, boutonOptionsFullscreenOff->position->rect);
                else if (boutonOptionsFullscreenOff->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsFullscreenOff->texture, boutonOptionsFullscreenOff->over, boutonOptionsFullscreenOff->position->rect);
        }else {
                if(boutonOptionsFullscreenOn->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->relache, boutonOptionsFullscreenOn->position->rect);
                else if (boutonOptionsFullscreenOn->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->appuye, boutonOptionsFullscreenOn->position->rect);
                else if (boutonOptionsFullscreenOn->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsFullscreenOn->texture, boutonOptionsFullscreenOn->over, boutonOptionsFullscreenOn->position->rect);
        }

// Dessiner le bouton retour
        if(boutonOptionsBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->relache, boutonOptionsBack->position->rect);
        else if (boutonOptionsBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->appuye, boutonOptionsBack->position->rect);
        else if (boutonOptionsBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsBack->texture, boutonOptionsBack->over, boutonOptionsBack->position->rect);

// Dessiner le bouton du menu des controles
        if(boutonOptionsControle->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonOptionsControle->texture, boutonOptionsControle->relache, boutonOptionsControle->position->rect);
        else if (boutonOptionsControle->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonOptionsControle->texture, boutonOptionsControle->appuye, boutonOptionsControle->position->rect);
        else if (boutonOptionsControle->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonOptionsControle->texture, boutonOptionsControle->over, boutonOptionsControle->position->rect);
}