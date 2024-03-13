if(scene == GAME) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, gameBGTexture, NULL, NULL);

        waitForFrame++;
        if(waitForFrame > 10) {
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
                waitForFrame = 0;
        }
        mettreAJourPersonnage(renderer, Joueur1, keyboardState, largeurF, hauteurF);
}