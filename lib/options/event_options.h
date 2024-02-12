else if(scene == OPTIONS) {
            // Bouton résolution
                // Gauche
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h) {
                        boutonOptionsSwapResLeft->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h) {
                        Res --;
                        if(Res<0)Res = 4;
                        boutonOptionsSwapResLeft->etat = BOUTON_OVER;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapResLeft->etat == BOUTON_APPUYE  || boutonOptionsSwapResLeft->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h)) {
                        boutonOptionsSwapResLeft->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsSwapResLeft->position->rect->x && e.motion.x < boutonOptionsSwapResLeft->position->rect->x + boutonOptionsSwapResLeft->position->rect->w && e.motion.y > boutonOptionsSwapResLeft->position->rect->y && e.motion.y < boutonOptionsSwapResLeft->position->rect->y + boutonOptionsSwapResLeft->position->rect->h && boutonOptionsSwapResLeft->etat == BOUTON_RELACHE) {
                        boutonOptionsSwapResLeft->etat = BOUTON_OVER;
                    }
                // Droit
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h) {
                        boutonOptionsSwapResRight->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h) {
                        Res ++;
                        Res = Res%5;
                        boutonOptionsSwapResRight->etat = BOUTON_OVER;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapResRight->etat == BOUTON_APPUYE  || boutonOptionsSwapResRight->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h)) {
                        boutonOptionsSwapResRight->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsSwapResRight->position->rect->x && e.motion.x < boutonOptionsSwapResRight->position->rect->x + boutonOptionsSwapResRight->position->rect->w && e.motion.y > boutonOptionsSwapResRight->position->rect->y && e.motion.y < boutonOptionsSwapResRight->position->rect->y + boutonOptionsSwapResRight->position->rect->h && boutonOptionsSwapResRight->etat == BOUTON_RELACHE) {
                        boutonOptionsSwapResRight->etat = BOUTON_OVER;
                    }
                // Accepter
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h) {
                        boutonOptionsSwapAccept->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h) {
                        switch(Res)
                        {
                            case(0):
                                SDL_SetWindowSize(window, 1920, 1080);
                                largeurF = 1920;
                                hauteurF = 1080;
                                break;
                            case(1):
                                SDL_SetWindowSize(window, 1680, 1050);
                                largeurF = 1680;
                                hauteurF = 1050;
                                break;
                            case(2):
                                SDL_SetWindowSize(window, 1280, 720);
                                largeurF = 1280;
                                hauteurF = 720;
                                break;
                            case(3):
                                SDL_SetWindowSize(window, 1024, 768);
                                largeurF = 1024;
                                hauteurF = 768;
                                break;
                            case(4):
                                SDL_SetWindowSize(window, 720, 480);
                                largeurF = 720;
                                hauteurF = 480;
                                break;
                        }
                        updateRectangles(listeRectangle);

                        boutonOptionsSwapAccept->etat = BOUTON_RELACHE;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsSwapAccept->etat == BOUTON_APPUYE  || boutonOptionsSwapAccept->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h)) {
                        boutonOptionsSwapAccept->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsSwapAccept->position->rect->x && e.motion.x < boutonOptionsSwapAccept->position->rect->x + boutonOptionsSwapAccept->position->rect->w && e.motion.y > boutonOptionsSwapAccept->position->rect->y && e.motion.y < boutonOptionsSwapAccept->position->rect->y + boutonOptionsSwapAccept->position->rect->h && boutonOptionsSwapAccept->etat == BOUTON_RELACHE) {
                        boutonOptionsSwapAccept->etat = BOUTON_OVER;
                    }
            
            // Bouton plein écran
                // "Activer"
                if(fullscreen){
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h) {
                        boutonOptionsFullscreenOff->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h) {
                        SDL_SetWindowFullscreen(window, 0);
                        fullscreen = 0;
                        boutonOptionsFullscreenOff->etat = BOUTON_RELACHE;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsFullscreenOff->etat == BOUTON_APPUYE  || boutonOptionsFullscreenOff->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h)) {
                        boutonOptionsFullscreenOff->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsFullscreenOff->position->rect->x && e.motion.x < boutonOptionsFullscreenOff->position->rect->x + boutonOptionsFullscreenOff->position->rect->w && e.motion.y > boutonOptionsFullscreenOff->position->rect->y && e.motion.y < boutonOptionsFullscreenOff->position->rect->y + boutonOptionsFullscreenOff->position->rect->h && boutonOptionsFullscreenOff->etat == BOUTON_RELACHE) {
                        boutonOptionsFullscreenOff->etat = BOUTON_OVER;
                    }
                }
                // "Désactiver"
                else {
                    // Appuie sur le bouton
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h) {
                        boutonOptionsFullscreenOn->etat = BOUTON_APPUYE;
                    // Appuie et relache sur le bouton
                    }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h) {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                        fullscreen = 1;
                        boutonOptionsFullscreenOn->etat = BOUTON_RELACHE;
                    // Appuie sur le bouton et relache ailleurs
                    }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsFullscreenOn->etat == BOUTON_APPUYE  || boutonOptionsFullscreenOn->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h)) {
                        boutonOptionsFullscreenOn->etat = BOUTON_RELACHE;
                    // Passe sur le bouton
                    }else if (e.motion.x > boutonOptionsFullscreenOn->position->rect->x && e.motion.x < boutonOptionsFullscreenOn->position->rect->x + boutonOptionsFullscreenOn->position->rect->w && e.motion.y > boutonOptionsFullscreenOn->position->rect->y && e.motion.y < boutonOptionsFullscreenOn->position->rect->y + boutonOptionsFullscreenOn->position->rect->h && boutonOptionsFullscreenOn->etat == BOUTON_RELACHE) {
                        boutonOptionsFullscreenOn->etat = BOUTON_OVER;
                    }
                }

            // Bouton retour
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h) {
                    boutonOptionsBack->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h) {
                    scene = MENU_PRINCIPAL;
                    boutonOptionsBack->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonOptionsBack->etat == BOUTON_APPUYE  || boutonOptionsBack->etat == BOUTON_OVER && !(e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h)) {
                    boutonOptionsBack->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonOptionsBack->position->rect->x && e.motion.x < boutonOptionsBack->position->rect->x + boutonOptionsBack->position->rect->w && e.motion.y > boutonOptionsBack->position->rect->y && e.motion.y < boutonOptionsBack->position->rect->y + boutonOptionsBack->position->rect->h && boutonOptionsBack->etat == BOUTON_RELACHE) {
                    boutonOptionsBack->etat = BOUTON_OVER;
                }
            }