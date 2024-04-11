static int isMusicPlaying = 0; // Pour garder la trace si la musique de fond est déjà en train de jouer

if(scene == CHAMP_SELECT) {
    if(son == 1 && isMusicPlaying == 0) {
        Mix_HaltMusic(); // Arrête toute musique actuellement jouée
        Mix_PlayMusic(backgroundSoundSelect, -1); // Joue la musique de fond pour l'écran de sélection
        isMusicPlaying = 1; // Marque la musique comme étant en cours de lecture
    }
    else if (son == 0) {
        Mix_HaltMusic(); // Arrête la musique si 'son' est désactivé
        isMusicPlaying = 0; // Marque la musique comme n'étant pas en cours
    }
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

                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU2->position->rect->x && e.motion.x < boutonRYU2->position->rect->x + boutonRYU2->position->rect->w && e.motion.y > boutonRYU2->position->rect->y && e.motion.y < boutonRYU2->position->rect->y + boutonRYU2->position->rect->h) {
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

                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU3->position->rect->x && e.motion.x < boutonRYU3->position->rect->x + boutonRYU3->position->rect->w && e.motion.y > boutonRYU3->position->rect->y && e.motion.y < boutonRYU3->position->rect->y + boutonRYU3->position->rect->h) {
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

                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU4->position->rect->x && e.motion.x < boutonRYU4->position->rect->x + boutonRYU4->position->rect->w && e.motion.y > boutonRYU4->position->rect->y && e.motion.y < boutonRYU4->position->rect->y + boutonRYU4->position->rect->h) {
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

                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU5->position->rect->x && e.motion.x < boutonRYU5->position->rect->x + boutonRYU5->position->rect->w && e.motion.y > boutonRYU5->position->rect->y && e.motion.y < boutonRYU5->position->rect->y + boutonRYU5->position->rect->h) {
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

                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU6->position->rect->x && e.motion.x < boutonRYU6->position->rect->x + boutonRYU6->position->rect->w && e.motion.y > boutonRYU6->position->rect->y && e.motion.y < boutonRYU6->position->rect->y + boutonRYU6->position->rect->h) {
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

                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU7->position->rect->x && e.motion.x < boutonRYU7->position->rect->x + boutonRYU7->position->rect->w && e.motion.y > boutonRYU7->position->rect->y && e.motion.y < boutonRYU7->position->rect->y + boutonRYU7->position->rect->h) {
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

                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonRYU8->position->rect->x && e.motion.x < boutonRYU8->position->rect->x + boutonRYU8->position->rect->w && e.motion.y > boutonRYU8->position->rect->y && e.motion.y < boutonRYU8->position->rect->y + boutonRYU8->position->rect->h) {
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

