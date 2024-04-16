if(scene == GAME) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, gameBGTexture, NULL, NULL);

        waitForFrame++;
        mettreAJourPersonnage(renderer, Joueur1, Joueur2, keyboardState, largeurF, hauteurF, &waitForFrame);
}