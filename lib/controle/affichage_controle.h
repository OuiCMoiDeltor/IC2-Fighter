else if(scene == CONTROLE) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, controleBGTexture, NULL, NULL);

// Dessiner l'image du titre des controles
        SDL_RenderCopy(renderer, controleTitleTexture, NULL, controleTitleRect->rect);

        SDL_RenderCopy(renderer, J1, NULL, J1Rect->rect);
        SDL_RenderCopy(renderer, J2, NULL, J2Rect->rect);

        SDL_RenderCopy(renderer, sauter, NULL, sautRect->rect);
        SDL_RenderCopy(renderer, accroupir, NULL, accroupirRect->rect);
        SDL_RenderCopy(renderer, gauche, NULL, gaucheRect->rect);
        SDL_RenderCopy(renderer, droite, NULL, droiteRect->rect);
        SDL_RenderCopy(renderer, poing, NULL, poingRect->rect);
        SDL_RenderCopy(renderer, kick, NULL, kickRect->rect);
        SDL_RenderCopy(renderer, garde, NULL, gardeRect->rect);

// Dessiner le bouton retour
        if(boutonControleBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonControleBack->texture, boutonControleBack->relache, boutonControleBack->position->rect);
        else if (boutonControleBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonControleBack->texture, boutonControleBack->appuye, boutonControleBack->position->rect);
        else if (boutonControleBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonControleBack->texture, boutonControleBack->over, boutonControleBack->position->rect);

// Commande
        //saut J1
        if(boutonSautJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonSautJ1->texture, boutonSautJ1->relache, boutonSautJ1->position->rect);
        else if (boutonSautJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonSautJ1->texture, boutonSautJ1->appuye, boutonSautJ1->position->rect);
        else if (boutonSautJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonSautJ1->texture, boutonSautJ1->over, boutonSautJ1->position->rect);
        //saut J2
        if(boutonSautJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonSautJ2->texture, boutonSautJ2->relache, boutonSautJ2->position->rect);
        else if (boutonSautJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonSautJ2->texture, boutonSautJ2->appuye, boutonSautJ2->position->rect);
        else if (boutonSautJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonSautJ2->texture, boutonSautJ2->over, boutonSautJ2->position->rect);
        //accroupi J1
        
        if(boutonAccroupirJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonAccroupirJ1->texture, boutonAccroupirJ1->relache, boutonAccroupirJ1->position->rect);
        else if (boutonAccroupirJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonAccroupirJ1->texture, boutonAccroupirJ1->appuye, boutonAccroupirJ1->position->rect);
        else if (boutonAccroupirJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonAccroupirJ1->texture, boutonAccroupirJ1->over, boutonAccroupirJ1->position->rect);
        //accroupi J2
        if(boutonAccroupirJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonAccroupirJ2->texture, boutonAccroupirJ2->relache, boutonAccroupirJ2->position->rect);
        else if (boutonAccroupirJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonAccroupirJ2->texture, boutonAccroupirJ2->appuye, boutonAccroupirJ2->position->rect);
        else if (boutonAccroupirJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonAccroupirJ2->texture, boutonAccroupirJ2->over, boutonAccroupirJ2->position->rect);
        //gauche J1
        if(boutonGaucheJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGaucheJ1->texture, boutonGaucheJ1->relache, boutonGaucheJ1->position->rect);
        else if (boutonGaucheJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGaucheJ1->texture, boutonGaucheJ1->appuye, boutonGaucheJ1->position->rect);
        else if (boutonGaucheJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGaucheJ1->texture, boutonGaucheJ1->over, boutonGaucheJ1->position->rect);
        //gauche J2
        if(boutonGaucheJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGaucheJ2->texture, boutonGaucheJ2->relache, boutonGaucheJ2->position->rect);
        else if (boutonGaucheJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGaucheJ2->texture, boutonGaucheJ2->appuye, boutonGaucheJ2->position->rect);
        else if (boutonGaucheJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGaucheJ2->texture, boutonGaucheJ2->over, boutonGaucheJ2->position->rect);
        //droite J1
        if(boutonDroiteJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonDroiteJ1->texture, boutonDroiteJ1->relache, boutonDroiteJ1->position->rect);
        else if (boutonDroiteJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonDroiteJ1->texture, boutonDroiteJ1->appuye, boutonDroiteJ1->position->rect);
        else if (boutonDroiteJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonDroiteJ1->texture, boutonDroiteJ1->over, boutonDroiteJ1->position->rect);
        //droite J2
        if(boutonDroiteJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonDroiteJ2->texture, boutonDroiteJ2->relache, boutonDroiteJ2->position->rect);
        else if (boutonDroiteJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonDroiteJ2->texture, boutonDroiteJ2->appuye, boutonDroiteJ2->position->rect);
        else if (boutonDroiteJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonDroiteJ2->texture, boutonDroiteJ2->over, boutonDroiteJ2->position->rect);
        //kick J1
        if(boutonKickJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonKickJ1->texture, boutonKickJ1->relache, boutonKickJ1->position->rect);
        else if (boutonKickJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonKickJ1->texture, boutonKickJ1->appuye, boutonKickJ1->position->rect);
        else if (boutonKickJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonKickJ1->texture, boutonKickJ1->over, boutonKickJ1->position->rect);
        //kick J2
        if(boutonKickJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonKickJ2->texture, boutonKickJ2->relache, boutonKickJ2->position->rect);
        else if (boutonKickJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonKickJ2->texture, boutonKickJ2->appuye, boutonKickJ2->position->rect);
        else if (boutonKickJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonKickJ2->texture, boutonKickJ2->over, boutonKickJ2->position->rect);
        //poing J1
        if(boutonPoingJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonPoingJ1->texture, boutonPoingJ1->relache, boutonPoingJ1->position->rect);
        else if (boutonPoingJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonPoingJ1->texture, boutonPoingJ1->appuye, boutonPoingJ1->position->rect);
        else if (boutonPoingJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonPoingJ1->texture, boutonPoingJ1->over, boutonPoingJ1->position->rect);
        //poing J2
        if(boutonPoingJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonPoingJ2->texture, boutonPoingJ2->relache, boutonPoingJ2->position->rect);
        else if (boutonPoingJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonPoingJ2->texture, boutonPoingJ2->appuye, boutonPoingJ2->position->rect);
        else if (boutonPoingJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonPoingJ2->texture, boutonPoingJ2->over, boutonPoingJ2->position->rect);
        //garde J1
        if(boutonGardeJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGardeJ1->texture, boutonGardeJ1->relache, boutonGardeJ1->position->rect);
        else if (boutonGardeJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGardeJ1->texture, boutonGardeJ1->appuye, boutonGardeJ1->position->rect);
        else if (boutonGardeJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGardeJ1->texture, boutonGardeJ1->over, boutonGardeJ1->position->rect);
        //garde J2
        if(boutonGardeJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGardeJ2->texture, boutonGardeJ2->relache, boutonGardeJ2->position->rect);
        else if (boutonGardeJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGardeJ2->texture, boutonGardeJ2->appuye, boutonGardeJ2->position->rect);
        else if (boutonGardeJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGardeJ2->texture, boutonGardeJ2->over, boutonGardeJ2->position->rect);


// Txt
        // J1
                SDL_RenderCopy(renderer, sauterJ1, NULL, sauterJ1Rect->rect);
                SDL_RenderCopy(renderer, accroupirJ1, NULL, accroupirJ1Rect->rect);
                SDL_RenderCopy(renderer, gaucheJ1, NULL, gaucheJ1Rect->rect);
                SDL_RenderCopy(renderer, droiteJ1, NULL, droiteJ1Rect->rect);
                SDL_RenderCopy(renderer, poingJ1, NULL, poingJ1Rect->rect);
                SDL_RenderCopy(renderer, kickJ1, NULL, kickJ1Rect->rect);
                SDL_RenderCopy(renderer, gardeJ1, NULL, gardeJ1Rect->rect);

        // J2
                SDL_RenderCopy(renderer, sauterJ2, NULL, sauterJ2Rect->rect);        
                SDL_RenderCopy(renderer, accroupirJ2, NULL, accroupirJ2Rect->rect);      
                SDL_RenderCopy(renderer, gaucheJ2, NULL, gaucheJ2Rect->rect);      
                SDL_RenderCopy(renderer, droiteJ2, NULL, droiteJ2Rect->rect);      
                SDL_RenderCopy(renderer, poingJ2, NULL, poingJ2Rect->rect);      
                SDL_RenderCopy(renderer, kickJ2, NULL, kickJ2Rect->rect);      
                SDL_RenderCopy(renderer, gardeJ2, NULL, gardeJ2Rect->rect);

}
