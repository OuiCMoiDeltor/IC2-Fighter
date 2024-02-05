else if(scene == OPTIONS) {
            // Bouton plein écran
                // "Activer"
                if(fullscreen){
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsFullscreenOff->position->x && e.motion.x < boutonOptionsFullscreenOff->position->x + boutonOptionsFullscreenOff->position->w && e.motion.y > boutonOptionsFullscreenOff->position->y && e.motion.y < boutonOptionsFullscreenOff->position->y + boutonOptionsFullscreenOff->position->h) {
                        boutonOptionsFullscreenOff->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsFullscreenOff->position->x && e.motion.x < boutonOptionsFullscreenOff->position->x + boutonOptionsFullscreenOff->position->w && e.motion.y > boutonOptionsFullscreenOff->position->y && e.motion.y < boutonOptionsFullscreenOff->position->y + boutonOptionsFullscreenOff->position->h) {
                        SDL_SetWindowFullscreen(window, 0);
                        fullscreen = 0;
                        boutonOptionsFullscreenOff->etat = BOUTON_RELACHE;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsFullscreenOff->etat == BOUTON_APPUYE  || boutonOptionsFullscreenOff->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsFullscreenOff->position->x && e.motion.x < boutonOptionsFullscreenOff->position->x + boutonOptionsFullscreenOff->position->w && e.motion.y > boutonOptionsFullscreenOff->position->y && e.motion.y < boutonOptionsFullscreenOff->position->y + boutonOptionsFullscreenOff->position->h)) {
                        boutonOptionsFullscreenOff->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsFullscreenOff->position->x && e.motion.x < boutonOptionsFullscreenOff->position->x + boutonOptionsFullscreenOff->position->w && e.motion.y > boutonOptionsFullscreenOff->position->y && e.motion.y < boutonOptionsFullscreenOff->position->y + boutonOptionsFullscreenOff->position->h && boutonOptionsFullscreenOff->etat == BOUTON_RELACHE) {
                        boutonOptionsFullscreenOff->etat = BOUTON_OVER;
                    }
                }
                // "Désactiver"
                else {
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsFullscreenOn->position->x && e.motion.x < boutonOptionsFullscreenOn->position->x + boutonOptionsFullscreenOn->position->w && e.motion.y > boutonOptionsFullscreenOn->position->y && e.motion.y < boutonOptionsFullscreenOn->position->y + boutonOptionsFullscreenOn->position->h) {
                        boutonOptionsFullscreenOn->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsFullscreenOn->position->x && e.motion.x < boutonOptionsFullscreenOn->position->x + boutonOptionsFullscreenOn->position->w && e.motion.y > boutonOptionsFullscreenOn->position->y && e.motion.y < boutonOptionsFullscreenOn->position->y + boutonOptionsFullscreenOn->position->h) {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                        fullscreen = 1;
                        boutonOptionsFullscreenOn->etat = BOUTON_RELACHE;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsFullscreenOn->etat == BOUTON_APPUYE  || boutonOptionsFullscreenOn->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsFullscreenOn->position->x && e.motion.x < boutonOptionsFullscreenOn->position->x + boutonOptionsFullscreenOn->position->w && e.motion.y > boutonOptionsFullscreenOn->position->y && e.motion.y < boutonOptionsFullscreenOn->position->y + boutonOptionsFullscreenOn->position->h)) {
                        boutonOptionsFullscreenOn->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsFullscreenOn->position->x && e.motion.x < boutonOptionsFullscreenOn->position->x + boutonOptionsFullscreenOn->position->w && e.motion.y > boutonOptionsFullscreenOn->position->y && e.motion.y < boutonOptionsFullscreenOn->position->y + boutonOptionsFullscreenOn->position->h && boutonOptionsFullscreenOn->etat == BOUTON_RELACHE) {
                        boutonOptionsFullscreenOn->etat = BOUTON_OVER;
                    }
                }
            // Bouton retour
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsBack->position->x && e.motion.x < boutonOptionsBack->position->x + boutonOptionsBack->position->w && e.motion.y > boutonOptionsBack->position->y && e.motion.y < boutonOptionsBack->position->y + boutonOptionsBack->position->h) {
                    boutonOptionsBack->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsBack->position->x && e.motion.x < boutonOptionsBack->position->x + boutonOptionsBack->position->w && e.motion.y > boutonOptionsBack->position->y && e.motion.y < boutonOptionsBack->position->y + boutonOptionsBack->position->h) {
                    scene = MENU_PRINCIPAL;
                    boutonOptionsBack->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsBack->etat == BOUTON_APPUYE  || boutonOptionsBack->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsBack->position->x && e.motion.x < boutonOptionsBack->position->x + boutonOptionsBack->position->w && e.motion.y > boutonOptionsBack->position->y && e.motion.y < boutonOptionsBack->position->y + boutonOptionsBack->position->h)) {
                    boutonOptionsBack->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptionsBack->position->x && e.motion.x < boutonOptionsBack->position->x + boutonOptionsBack->position->w && e.motion.y > boutonOptionsBack->position->y && e.motion.y < boutonOptionsBack->position->y + boutonOptionsBack->position->h && boutonOptionsBack->etat == BOUTON_RELACHE) {
                    boutonOptionsBack->etat = BOUTON_OVER;
                }
            }