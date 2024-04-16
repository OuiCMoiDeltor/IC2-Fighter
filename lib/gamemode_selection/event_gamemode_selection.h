if(scene == GAMEMODE) {
            // Local
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h) {
                    boutonLocal->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h) {
                    scene = CHAMP_SELECT;
                    if(son) {
                        Mix_VolumeMusic(MIX_MAX_VOLUME * 0.1); //Réglage niveau de son
                        Mix_HaltMusic();
                        Mix_PlayMusic(backgroundSoundSelect, -1);
                    }
                    boutonLocal->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonLocal->etat == BOUTON_APPUYE  || boutonLocal->etat == BOUTON_OVER && !(e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h)) {
                    boutonLocal->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonLocal->position->rect->x && e.motion.x < boutonLocal->position->rect->x + boutonLocal->position->rect->w && e.motion.y > boutonLocal->position->rect->y && e.motion.y < boutonLocal->position->rect->y + boutonLocal->position->rect->h && boutonLocal->etat == BOUTON_RELACHE) {
                    boutonLocal->etat = BOUTON_OVER;
                }

            // En Ligne
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h) {
                    boutonLigne->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h) {
                    // A COMPLETER !_!
                    boutonLigne->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonLigne->etat == BOUTON_APPUYE  || boutonLigne->etat == BOUTON_OVER && !(e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h)) {
                    boutonLigne->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonLigne->position->rect->x && e.motion.x < boutonLigne->position->rect->x + boutonLigne->position->rect->w && e.motion.y > boutonLigne->position->rect->y && e.motion.y < boutonLigne->position->rect->y + boutonLigne->position->rect->h && boutonLigne->etat == BOUTON_RELACHE) {
                    boutonLigne->etat = BOUTON_OVER;
                }

            // Retour
                // Appuie sur le bouton
                if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h) {
                    boutonGmBack->etat = BOUTON_APPUYE;
                // Appuie et relache sur le bouton
                }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h) {
                    scene = MENU_PRINCIPAL;
                    boutonGmBack->etat = BOUTON_RELACHE;
                // Appuie sur le bouton et relache ailleurs
                }else if (e.type == SDL_MOUSEBUTTONUP && boutonGmBack->etat == BOUTON_APPUYE  || boutonGmBack->etat == BOUTON_OVER && !(e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h)) {
                    boutonGmBack->etat = BOUTON_RELACHE;
                // Passe sur le bouton
                }else if (e.motion.x > boutonGmBack->position->rect->x && e.motion.x < boutonGmBack->position->rect->x + boutonGmBack->position->rect->w && e.motion.y > boutonGmBack->position->rect->y && e.motion.y < boutonGmBack->position->rect->y + boutonGmBack->position->rect->h && boutonGmBack->etat == BOUTON_RELACHE) {
                    boutonGmBack->etat = BOUTON_OVER;
                }
            }