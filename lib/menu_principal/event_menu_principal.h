if(scene == MENU_PRINCIPAL) {
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + boutonOptions->position->w && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + boutonOptions->position->h) {
                    boutonOptions->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + boutonOptions->position->w && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + boutonOptions->position->h) {
                    scene = OPTIONS;
                    boutonOptions->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptions->etat == BOUTON_APPUYE  || boutonOptions->etat == BOUTON_OVER && !(e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + boutonOptions->position->w && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + boutonOptions->position->h)) {
                    boutonOptions->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + boutonOptions->position->w && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + boutonOptions->position->h && boutonOptions->etat == BOUTON_RELACHE) {
                    boutonOptions->etat = BOUTON_OVER;
                }
            }