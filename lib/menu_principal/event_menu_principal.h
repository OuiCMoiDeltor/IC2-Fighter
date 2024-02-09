if(scene == MENU_PRINCIPAL) {
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
            }