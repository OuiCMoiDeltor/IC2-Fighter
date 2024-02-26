if(scene == MENU_PRINCIPAL) {
            // Options
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h) {
                    boutonOptions->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h) {
                    scene = OPTIONS;
                    boutonOptions->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptions->etat == BOUTON_APPUYE  || boutonOptions->etat == BOUTON_OVER && !(e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h)) {
                    boutonOptions->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptions->position->rect->x && e.motion.x < boutonOptions->position->rect->x + boutonOptions->position->rect->w && e.motion.y > boutonOptions->position->rect->y && e.motion.y < boutonOptions->position->rect->y + boutonOptions->position->rect->h && boutonOptions->etat == BOUTON_RELACHE) {
                    boutonOptions->etat = BOUTON_OVER;
                }

            // Quitter
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h) {
                    boutonQuitter->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h) {
                    quit = 1;
                    boutonQuitter->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonQuitter->etat == BOUTON_APPUYE  || boutonQuitter->etat == BOUTON_OVER && !(e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h)) {
                    boutonQuitter->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonQuitter->position->rect->x && e.motion.x < boutonQuitter->position->rect->x + boutonQuitter->position->rect->w && e.motion.y > boutonQuitter->position->rect->y && e.motion.y < boutonQuitter->position->rect->y + boutonQuitter->position->rect->h && boutonQuitter->etat == BOUTON_RELACHE) {
                    boutonQuitter->etat = BOUTON_OVER;
                }

            // Jouer
                // Appuie et relache sur le bouton
                if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonJouer->position->rect->x && e.motion.x < boutonJouer->position->rect->x + boutonJouer->position->rect->w && e.motion.y > boutonJouer->position->rect->y && e.motion.y < boutonJouer->position->rect->y + boutonJouer->position->rect->h) {
                    scene = GAMEMODE;
                    if(son)
                        Mix_HaltMusic();
                    boutonJouer->etat = boutonJouer->nbEtat-1;
                // Passe sur le bouton
                }else if (e.motion.x > boutonJouer->position->rect->x && e.motion.x < boutonJouer->position->rect->x + boutonJouer->position->rect->w && e.motion.y > boutonJouer->position->rect->y && e.motion.y < boutonJouer->position->rect->y + boutonJouer->position->rect->h) {
                    overBoutonJouer = 1;
                }else {
                    overBoutonJouer = 0;
                }
            }