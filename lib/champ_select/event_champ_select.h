if(scene == CHAMP_SELECT) {
            // RYU
                // Appuie et relache sur le bouton
                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU->position->rect->x && e.motion.x < boutonRYU->position->rect->x + boutonRYU->position->rect->w && e.motion.y > boutonRYU->position->rect->y && e.motion.y < boutonRYU->position->rect->y + boutonRYU->position->rect->h) {
                    if(J2Pick) {
                        Joueur2 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10/7.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                        if(Joueur2 == NULL) exit(EXIT_FAILURE);
                        scene = GAME;
                        boutonRYU->etat = 0;
                        J2Pick = 0;
                    }
                    else {
                        Joueur1 = creerPerso(renderer, RYU, &largeurF, &hauteurF, 10.0, 10.0, 2.5, 9/7.0, &listeRectangle);
                        if(Joueur1 == NULL) exit(EXIT_FAILURE);
                        boutonRYU->etat = 0;
                        J2Pick = 1;
                    }
            }
}
