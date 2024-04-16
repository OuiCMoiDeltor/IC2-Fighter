else if(scene == CONTROLE) {
    // Bouton retour
        // Appuie sur le bouton
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h) {
            boutonControleBack->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h) {
            scene = OPTIONS;
            boutonControleBack->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonControleBack->etat == BOUTON_APPUYE  || boutonControleBack->etat == BOUTON_OVER && !(e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h)) {
            boutonControleBack->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h && boutonControleBack->etat == BOUTON_RELACHE) {
            boutonControleBack->etat = BOUTON_OVER;
        } 
    // Bouton saut J1
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h) {
            boutonSautJ1->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[SauterJ1], &sauterJ1);
            boutonSautJ1->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonSautJ1->etat == BOUTON_APPUYE  || boutonSautJ1->etat == BOUTON_OVER && !(e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h)) {
            boutonSautJ1->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h && boutonSautJ1->etat == BOUTON_RELACHE) {
            boutonSautJ1->etat = BOUTON_OVER;
        } 

    // Bouton saut J2
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h) {
            boutonSautJ2->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[SauterJ2], &sauterJ2);
            boutonSautJ2->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonSautJ2->etat == BOUTON_APPUYE  || boutonSautJ2->etat == BOUTON_OVER && !(e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h)) {
            boutonSautJ2->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h && boutonSautJ2->etat == BOUTON_RELACHE) {
            boutonSautJ2->etat = BOUTON_OVER;
        } 
    // Bouton accroupir J1
    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h) {
            boutonAccroupirJ1->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[AccroupirJ1], &accroupirJ1);
            boutonAccroupirJ1->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonAccroupirJ1->etat == BOUTON_APPUYE  || boutonAccroupirJ1->etat == BOUTON_OVER && !(e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h)) {
            boutonAccroupirJ1->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h && boutonAccroupirJ1->etat == BOUTON_RELACHE) {
            boutonAccroupirJ1->etat = BOUTON_OVER;
        } 

    // Bouton accroupir J2
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h) {
            boutonAccroupirJ2->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[AccroupirJ2], &accroupirJ2);
            boutonAccroupirJ2->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonAccroupirJ2->etat == BOUTON_APPUYE  || boutonAccroupirJ2->etat == BOUTON_OVER && !(e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h)) {
            boutonAccroupirJ2->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h && boutonAccroupirJ2->etat == BOUTON_RELACHE) {
            boutonAccroupirJ2->etat = BOUTON_OVER;
        } 
    
    // Bouton gauche J1
    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h) {
            boutonGaucheJ1->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[GaucheJ1], &gaucheJ1);
            boutonGaucheJ1->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonGaucheJ1->etat == BOUTON_APPUYE  || boutonGaucheJ1->etat == BOUTON_OVER && !(e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h)) {
            boutonGaucheJ1->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h && boutonGaucheJ1->etat == BOUTON_RELACHE) {
            boutonGaucheJ1->etat = BOUTON_OVER;
        } 

    // Bouton gauche J2
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h) {
            boutonGaucheJ2->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[GaucheJ2], &gaucheJ2);
            boutonGaucheJ2->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonGaucheJ2->etat == BOUTON_APPUYE  || boutonGaucheJ2->etat == BOUTON_OVER && !(e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h)) {
            boutonGaucheJ2->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h && boutonGaucheJ2->etat == BOUTON_RELACHE) {
            boutonGaucheJ2->etat = BOUTON_OVER;
        } 

    // Bouton droite J1
    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h) {
            boutonDroiteJ1->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[DroitJ1], &droiteJ1);
            boutonDroiteJ1->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonDroiteJ1->etat == BOUTON_APPUYE  || boutonDroiteJ1->etat == BOUTON_OVER && !(e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h)) {
            boutonDroiteJ1->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h && boutonDroiteJ1->etat == BOUTON_RELACHE) {
            boutonDroiteJ1->etat = BOUTON_OVER;
        } 

    // Bouton droite J2
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h) {
            boutonDroiteJ2->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[DroitJ2], &droiteJ2);
            boutonDroiteJ2->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonDroiteJ2->etat == BOUTON_APPUYE  || boutonDroiteJ2->etat == BOUTON_OVER && !(e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h)) {
            boutonDroiteJ2->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h && boutonDroiteJ2->etat == BOUTON_RELACHE) {
            boutonDroiteJ2->etat = BOUTON_OVER;
        } 

    // Bouton poing J1
    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h) {
            boutonPoingJ1->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[PoingJ1], &poingJ1);
            boutonPoingJ1->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonPoingJ1->etat == BOUTON_APPUYE  || boutonPoingJ1->etat == BOUTON_OVER && !(e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h)) {
            boutonPoingJ1->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h && boutonPoingJ1->etat == BOUTON_RELACHE) {
            boutonPoingJ1->etat = BOUTON_OVER;
        } 

    // Bouton poing J2
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h) {
            boutonPoingJ2->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[PoingJ2], &poingJ2);
            boutonPoingJ2->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonPoingJ2->etat == BOUTON_APPUYE  || boutonPoingJ2->etat == BOUTON_OVER && !(e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h)) {
            boutonPoingJ2->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h && boutonPoingJ2->etat == BOUTON_RELACHE) {
            boutonPoingJ2->etat = BOUTON_OVER;
        } 
    
    // Bouton kick J1
    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h) {
            boutonKickJ1->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[KickJ1], &kickJ1);
            boutonKickJ1->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonKickJ1->etat == BOUTON_APPUYE  || boutonKickJ1->etat == BOUTON_OVER && !(e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h)) {
            boutonKickJ1->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h && boutonKickJ1->etat == BOUTON_RELACHE) {
            boutonKickJ1->etat = BOUTON_OVER;
        } 

    // Bouton kick J2
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h) {
            boutonKickJ2->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[KickJ2], &kickJ2);
            boutonKickJ2->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonKickJ2->etat == BOUTON_APPUYE  || boutonKickJ2->etat == BOUTON_OVER && !(e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h)) {
            boutonKickJ2->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h && boutonKickJ2->etat == BOUTON_RELACHE) {
            boutonKickJ2->etat = BOUTON_OVER;
        } 

    // Bouton garde J1
    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h) {
            boutonGardeJ1->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[ParadeJ1], &gardeJ1);
            boutonGardeJ1->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonGardeJ1->etat == BOUTON_APPUYE  || boutonGardeJ1->etat == BOUTON_OVER && !(e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h)) {
            boutonGardeJ1->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h && boutonGardeJ1->etat == BOUTON_RELACHE) {
            boutonGardeJ1->etat = BOUTON_OVER;
        } 

    // Bouton garde J2
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h) {
            boutonGardeJ2->etat = BOUTON_APPUYE;
        // Appuie et relache sur le bouton
        }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h) {
            saisirTouche(renderer, font, e, liste_touches, liste_touches[ParadeJ2], &gardeJ2);
            boutonGardeJ2->etat = BOUTON_RELACHE;
        // Appuie sur le bouton et relache ailleurs
        }else if (e.type == SDL_MOUSEBUTTONUP && boutonGardeJ2->etat == BOUTON_APPUYE  || boutonGardeJ2->etat == BOUTON_OVER && !(e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h)) {
            boutonGardeJ2->etat = BOUTON_RELACHE;
        // Passe sur le bouton
        }else if (e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h && boutonGardeJ2->etat == BOUTON_RELACHE) {
            boutonGardeJ2->etat = BOUTON_OVER;
        } 
    
}