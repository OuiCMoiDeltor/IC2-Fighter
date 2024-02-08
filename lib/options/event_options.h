else if(scene == OPTIONS) {
            // Bouton résolution
                // Gauche
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapResLeft->position->x && e.motion.x < boutonOptionsSwapResLeft->position->x + boutonOptionsSwapResLeft->position->w && e.motion.y > boutonOptionsSwapResLeft->position->y && e.motion.y < boutonOptionsSwapResLeft->position->y + boutonOptionsSwapResLeft->position->h) {
                        boutonOptionsSwapResLeft->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapResLeft->position->x && e.motion.x < boutonOptionsSwapResLeft->position->x + boutonOptionsSwapResLeft->position->w && e.motion.y > boutonOptionsSwapResLeft->position->y && e.motion.y < boutonOptionsSwapResLeft->position->y + boutonOptionsSwapResLeft->position->h) {
                        Res --;
                        if(Res<0)Res = 1;
                        boutonOptionsSwapResLeft->etat = BOUTON_OVER;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapResLeft->etat == BOUTON_APPUYE  || boutonOptionsSwapResLeft->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapResLeft->position->x && e.motion.x < boutonOptionsSwapResLeft->position->x + boutonOptionsSwapResLeft->position->w && e.motion.y > boutonOptionsSwapResLeft->position->y && e.motion.y < boutonOptionsSwapResLeft->position->y + boutonOptionsSwapResLeft->position->h)) {
                        boutonOptionsSwapResLeft->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsSwapResLeft->position->x && e.motion.x < boutonOptionsSwapResLeft->position->x + boutonOptionsSwapResLeft->position->w && e.motion.y > boutonOptionsSwapResLeft->position->y && e.motion.y < boutonOptionsSwapResLeft->position->y + boutonOptionsSwapResLeft->position->h && boutonOptionsSwapResLeft->etat == BOUTON_RELACHE) {
                        boutonOptionsSwapResLeft->etat = BOUTON_OVER;
                    }
                // Droit
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapResRight->position->x && e.motion.x < boutonOptionsSwapResRight->position->x + boutonOptionsSwapResRight->position->w && e.motion.y > boutonOptionsSwapResRight->position->y && e.motion.y < boutonOptionsSwapResRight->position->y + boutonOptionsSwapResRight->position->h) {
                        boutonOptionsSwapResRight->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapResRight->position->x && e.motion.x < boutonOptionsSwapResRight->position->x + boutonOptionsSwapResRight->position->w && e.motion.y > boutonOptionsSwapResRight->position->y && e.motion.y < boutonOptionsSwapResRight->position->y + boutonOptionsSwapResRight->position->h) {
                        Res ++;
                        Res = Res%2;
                        boutonOptionsSwapResRight->etat = BOUTON_OVER;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapResRight->etat == BOUTON_APPUYE  || boutonOptionsSwapResRight->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapResRight->position->x && e.motion.x < boutonOptionsSwapResRight->position->x + boutonOptionsSwapResRight->position->w && e.motion.y > boutonOptionsSwapResRight->position->y && e.motion.y < boutonOptionsSwapResRight->position->y + boutonOptionsSwapResRight->position->h)) {
                        boutonOptionsSwapResRight->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsSwapResRight->position->x && e.motion.x < boutonOptionsSwapResRight->position->x + boutonOptionsSwapResRight->position->w && e.motion.y > boutonOptionsSwapResRight->position->y && e.motion.y < boutonOptionsSwapResRight->position->y + boutonOptionsSwapResRight->position->h && boutonOptionsSwapResRight->etat == BOUTON_RELACHE) {
                        boutonOptionsSwapResRight->etat = BOUTON_OVER;
                    }
                // Accepter
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapAccept->position->x && e.motion.x < boutonOptionsSwapAccept->position->x + boutonOptionsSwapAccept->position->w && e.motion.y > boutonOptionsSwapAccept->position->y && e.motion.y < boutonOptionsSwapAccept->position->y + boutonOptionsSwapAccept->position->h) {
                        boutonOptionsSwapAccept->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapAccept->position->x && e.motion.x < boutonOptionsSwapAccept->position->x + boutonOptionsSwapAccept->position->w && e.motion.y > boutonOptionsSwapAccept->position->y && e.motion.y < boutonOptionsSwapAccept->position->y + boutonOptionsSwapAccept->position->h) {
                        switch(Res)
                        {
                            case(0):
                                SDL_SetWindowSize(window, 1680, 1050);
                                break;
                            case(1):
                                SDL_SetWindowSize(window, 1024, 768);
                                break;

                        }
                        boutonOptionsSwapAccept->etat = BOUTON_OVER;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapAccept->etat == BOUTON_APPUYE  || boutonOptionsSwapAccept->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapAccept->position->x && e.motion.x < boutonOptionsSwapAccept->position->x + boutonOptionsSwapAccept->position->w && e.motion.y > boutonOptionsSwapAccept->position->y && e.motion.y < boutonOptionsSwapAccept->position->y + boutonOptionsSwapAccept->position->h)) {
                        boutonOptionsSwapAccept->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsSwapAccept->position->x && e.motion.x < boutonOptionsSwapAccept->position->x + boutonOptionsSwapAccept->position->w && e.motion.y > boutonOptionsSwapAccept->position->y && e.motion.y < boutonOptionsSwapAccept->position->y + boutonOptionsSwapAccept->position->h && boutonOptionsSwapAccept->etat == BOUTON_RELACHE) {
                        boutonOptionsSwapAccept->etat = BOUTON_OVER;
                    }
            
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