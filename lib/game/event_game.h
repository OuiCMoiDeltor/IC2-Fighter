static int isMusicPlaying1 = 0; // Pour garder la trace si la musique de fond est déjà en train de jouer

if(scene == GAME) {
    Mix_VolumeMusic(MIX_MAX_VOLUME * 0.1); //Réglage niveau de son
    if(son == 1 && isMusicPlaying1 == 0) {
        Mix_HaltMusic(); // Arrête toute musique actuellement jouée
        Mix_PlayMusic(backgroundCombatSound, -1); // Joue la musique de fond pour l'écran de sélection
        isMusicPlaying1 = 1; // Marque la musique comme étant en cours de lecture
    }
    else if (son == 0) {
        Mix_HaltMusic(); // Arrête la musique si 'son' est désactivé
        isMusicPlaying1 = 0; // Marque la musique comme n'étant pas en cours
    }
            }
            
            
            
            
