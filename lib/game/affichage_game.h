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
                                case SAUT:
                                                if(Joueur1->pos->rect->y < hauteurF/AIR && !Joueur1->air)
                                                        Joueur1->pos->rect->y += VY;
                                                else
                                                        Joueur1->pos->rect->y -= VY;
                                                if(Joueur1->pos->rect->y >= hauteurF/AIR && !Joueur1->air) {
                                                        Joueur1->air = 1;
                                                }
                                                if(Joueur1->etatAnimation < 6) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->animation = AUCUNE;
                                                        Joueur1->air = 0;
                                                        if(Joueur1->pos->rect->y < hauteurF/SOL)
                                                                Joueur1->pos->rect->y = hauteurF/SOL;
                                                break;
                                                }
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
                                case SAUT:
                                                if(Joueur2->pos->rect->y < hauteurF/AIR && !Joueur2->air)
                                                        Joueur2->pos->rect->y += VY;
                                                else
                                                        Joueur2->pos->rect->y -= VY;
                                                if(Joueur2->pos->rect->y >= hauteurF/AIR && !Joueur2->air) {
                                                        Joueur2->air = 1;
                                                }
                                                if(Joueur2->etatAnimation < 6) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->animation = AUCUNE;
                                                        Joueur2->air = 0;
                                                        if(Joueur2->pos->rect->y < hauteurF/SOL)
                                                                Joueur2->pos->rect->y = hauteurF/SOL;
                                                break;
                                                }
                        }
                }

                waitForFrame = 0;
        }

        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF);
}