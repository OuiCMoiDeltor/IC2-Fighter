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
                                case POINGGAUCHE:
                                                if(Joueur1->etatAnimation == 3)
                                                        Joueur1->canHit = 1;
                                                if(Joueur1->etatAnimation < 4) {
                                                        Joueur1->etatAnimation++;
                                                }else {
                                                        Joueur1->etatAnimation = 0;
                                                        Joueur1->canHit = 0;
                                                        Joueur1->animation = AUCUNE;
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
                                case POINGGAUCHE:
                                                if(Joueur2->etatAnimation == 3)
                                                        Joueur2->canHit = 1;
                                                if(Joueur2->etatAnimation < 4) {
                                                        Joueur2->etatAnimation++;
                                                }else {
                                                        Joueur2->etatAnimation = 0;
                                                        Joueur2->canHit = 0;
                                                        Joueur2->animation = AUCUNE;
                                                }
                        }
                }

                waitForFrame = 0;
        }
        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF);
}