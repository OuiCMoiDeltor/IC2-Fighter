else if(scene == OPTIONS) {
// Dessiner l'image de fond
        SDL_RenderCopy(renderer, optionsBGTexture, NULL, NULL);

        SDL_RenderCopy(renderer, optionsTitleTexture, NULL, &optionsTitleRect);
}