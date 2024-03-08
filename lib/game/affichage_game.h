if(scene == GAME) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, gameBGTexture, NULL, NULL);

        waitForFrame++;
        if(waitForFrame > 10) {
                if(!reverse) {
                        Joueur1->etat = ++Joueur1->etat;
                        if(Joueur1->etat == 5) {
                                reverse = 1;
                                Joueur1->etat = 3;
                        }
                }else {
                        Joueur1->etat = --Joueur1->etat;
                        if(Joueur1->etat == -1) {
                                reverse = 0;
                                Joueur1->etat = 1;
                        }
                }
                waitForFrame = 0;
        }
        mettreAJourPersonnage(renderer, Joueur1, keyboardState, largeurF, hauteurF);
}