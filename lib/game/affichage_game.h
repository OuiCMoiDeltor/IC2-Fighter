if(scene == GAME) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, gameBGTexture, NULL, NULL);

        waitForFrame++;
        if(waitForFrame > 10) {
                // Joueur 1
                if(!reverseIdle) {
                        Joueur1->etatIdle = ++Joueur1->etatIdle;
                        if(Joueur1->etatIdle == 5) {
                                reverseIdle = 1;
                                Joueur1->etatIdle = 3;
                        }
                }else {
                        Joueur1->etatIdle = --Joueur1->etatIdle;
                        if(Joueur1->etatIdle == -1) {
                                reverseIdle = 0;
                                Joueur1->etatIdle = 1;
                        }
                }
                if(!reverseWalk) {
                        Joueur1->etatWalk = ++Joueur1->etatWalk;
                        if(Joueur1->etatWalk == 6) {
                                reverseWalk = 1;
                                Joueur1->etatWalk = 4;
                        }
                }else {
                        Joueur1->etatWalk = --Joueur1->etatWalk;
                        if(Joueur1->etatWalk == -1) {
                                reverseWalk = 0;
                                Joueur1->etatWalk = 1;
                        }
                }
                if(Joueur1->crouching) {
                        if(Joueur1->etatCrouch < 2)
                                Joueur1->etatCrouch++;
                }else {
                        Joueur1->etatCrouch = 0;
                }
                if(Joueur1->animation) {
                        switch(Joueur1->animation) {
                                case POINGLATERAL:
                                                if(Joueur1->etatAnimation == 3)
                                                        Joueur1->canHit = 1;
                                                if(Joueur1->etatAnimation < 4) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->canHit = 0;
                                                        Joueur1->animation = AUCUNE;
                                                }
                                                break;
                                case KICK:
                                case POINGHAUT:
                                case KICKBAS:
                                case KICKACCROUPI:
                                                if(Joueur1->etatAnimation == 1)
                                                        Joueur1->canHit = 1;
                                                if(Joueur1->etatAnimation < 2) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->canHit = 0;
                                                        Joueur1->animation = AUCUNE;
                                                }
                                                break;
                                case PARADE:
                                                if(Joueur1->etatAnimation < 2) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->animation = AUCUNE;
                                                }
                                                break;
                                case SAUT:
                                                if(Joueur1->etatAnimation < 6) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->animation = AUCUNE;
                                                }
                                                break;
                                case SAUTGAUCHE:
                                                if(Joueur1->etatAnimation > 0) {
                                                        Joueur1->etatAnimation--;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->animation = AUCUNE;
                                                }
                                                break;
                                case SAUTDROIT:
                                                if(Joueur1->etatAnimation < 7) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->animation = AUCUNE;
                                                }
                                                break;
                                case POINGACCROUPI:
                                                if(Joueur1->etatAnimation == 1)
                                                        Joueur1->canHit = 1;
                                case DEGAT:
                                case DEGATACCROUPI:
                                case DEGATSAUT:
                                                if(Joueur1->etatAnimation < 1) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->canHit = 0;
                                                        Joueur1->animation = AUCUNE;
                                                }
                                                break;
                        }
                }

                // Joueur 2
                if(!reverseIdle2) {
                        Joueur2->etatIdle = ++Joueur2->etatIdle;
                        if(Joueur2->etatIdle == 5) {
                                reverseIdle2 = 1;
                                Joueur2->etatIdle = 3;
                        }
                }else {
                        Joueur2->etatIdle = --Joueur2->etatIdle;
                        if(Joueur2->etatIdle == -1) {
                                reverseIdle2 = 0;
                                Joueur2->etatIdle = 1;
                        }
                }
                if(!reverseWalk2) {
                        Joueur2->etatWalk = ++Joueur2->etatWalk;
                        if(Joueur2->etatWalk == 6) {
                                reverseWalk2 = 1;
                                Joueur2->etatWalk = 4;
                        }
                }else {
                        Joueur2->etatWalk = --Joueur2->etatWalk;
                        if(Joueur2->etatWalk == -1) {
                                reverseWalk2 = 0;
                                Joueur2->etatWalk = 1;
                        }
                }
                if(Joueur2->crouching) {
                        if(Joueur2->etatCrouch < 2)
                                Joueur2->etatCrouch++;
                }else {
                        Joueur2->etatCrouch = 0;
                }
                if(Joueur2->animation) {
                        switch(Joueur2->animation) {
                                case POINGLATERAL:
                                                if(Joueur2->etatAnimation == 3)
                                                        Joueur2->canHit = 1;
                                                if(Joueur2->etatAnimation < 4) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->canHit = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                                                break;
                                case KICK:
                                case POINGHAUT:
                                case KICKBAS:
                                case KICKACCROUPI:
                                                if(Joueur2->etatAnimation == 1)
                                                        Joueur2->canHit = 1;
                                                if(Joueur2->etatAnimation < 2) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->canHit = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                                                break;
                                case PARADE:
                                                if(Joueur2->etatAnimation < 2) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                                                break;
                                case SAUT:
                                                if(Joueur2->etatAnimation < 6) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                                                break;
                                case SAUTDROIT:
                                                if(Joueur2->etatAnimation > 0) {
                                                        Joueur2->etatAnimation--;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                                                break;
                                case SAUTGAUCHE:
                                                if(Joueur2->etatAnimation < 7) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                                                break;
                                case POINGACCROUPI:
                                                if(Joueur2->etatAnimation == 1)
                                                        Joueur2->canHit = 1;
                                case DEGAT:
                                case DEGATACCROUPI:
                                case DEGATSAUT:
                                                if(Joueur2->etatAnimation < 1) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->canHit = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                                                break;
                        }
                }

                waitForFrame = 0;
        }

        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF);
}