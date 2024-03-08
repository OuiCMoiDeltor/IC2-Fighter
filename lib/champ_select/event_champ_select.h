if(scene == CHAMP_SELECT) {
            // RYU
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonRYU->position->rect->x && e.motion.x < boutonRYU->position->rect->x + boutonRYU->position->rect->w && e.motion.y > boutonRYU->position->rect->y && e.motion.y < boutonRYU->position->rect->y + boutonRYU->position->rect->h) {
                    boutonRYU->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU->position->rect->x && e.motion.x < boutonRYU->position->rect->x + boutonRYU->position->rect->w && e.motion.y > boutonRYU->position->rect->y && e.motion.y < boutonRYU->position->rect->y + boutonRYU->position->rect->h) {
                    Joueur1 = creerPerso(renderer, "img/ryu4.bmp", &largeurF, &hauteurF, 10.0, 10.0, 5.0, 9/7.0, &listeRectangle);
                    if(Joueur1 == NULL) exit(EXIT_FAILURE);
                    scene = GAME;
                    boutonRYU->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonRYU->etat == BOUTON_APPUYE  || boutonRYU->etat == BOUTON_OVER && !(e.motion.x > boutonRYU->position->rect->x && e.motion.x < boutonRYU->position->rect->x + boutonRYU->position->rect->w && e.motion.y > boutonRYU->position->rect->y && e.motion.y < boutonRYU->position->rect->y + boutonRYU->position->rect->h)) {
                    boutonRYU->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonRYU->position->rect->x && e.motion.x < boutonRYU->position->rect->x + boutonRYU->position->rect->w && e.motion.y > boutonRYU->position->rect->y && e.motion.y < boutonRYU->position->rect->y + boutonRYU->position->rect->h && boutonRYU->etat == BOUTON_RELACHE) {
                    boutonRYU->etat = BOUTON_OVER;
                }
            }