if(scene == MENU_PRINCIPAL) {
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions) {
                    boutonOptions->etat = BOUTON_APPUYE;
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions) {
                    quit = 1;
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptions->etat == BOUTON_APPUYE  || boutonOptions->etat == BOUTON_OVER && !(e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions)) {
                    boutonOptions->etat = BOUTON_RELACHE;
                }else if (e.motion.x > boutonOptions->position->x && e.motion.x < boutonOptions->position->x + largeurOptions && e.motion.y > boutonOptions->position->y && e.motion.y < boutonOptions->position->y + hauteurOptions && boutonOptions->etat == BOUTON_RELACHE) {
                    boutonOptions->etat = BOUTON_OVER;
                }
            }