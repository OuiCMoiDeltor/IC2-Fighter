#include "../lib/controle.h"

extern
int controle(SDL_Event e, SDL_Renderer * renderer, int largeurF, int hauteurF, int * scene, int * liste_touches) {

    listeT_t *listeTexture = creerListeT(); // Stock les pointeurs sur texture
    listeRect *listeRectangle = creerListeRect(); // Stock les pointeurs sur Rectangle
    listeBouton *listeBoutons = creerListeBouton(); // Stock les pointeurs sur Bouton

    // Création de l'image de fond
    SDL_Texture *controleBGTexture = creerImage(renderer, IMG_CONTROLE_BG);
    if(controleBGTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &controleBGTexture);

    // Création image titre des Controles
    SDL_Texture *controleTitleTexture = creerImage(renderer, IMG_CONTROLE);
    if(controleTitleTexture == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &controleTitleTexture);
    rectangle *controleTitleRect = creerRectangle(&largeurF, &hauteurF, 4.0, 4*8.0, 2.0, 2.0);
    ajoutListeRect(&listeRectangle, &controleTitleRect);

    // Création image J1
    SDL_Texture *J1 = creerImage(renderer, IMG_J1);
    if(J1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &J1);
    rectangle *J1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/11.65, 11.0/2, 16.0, 16.0);
    ajoutListeRect(&listeRectangle, &J1Rect);

    // Création image J2
    SDL_Texture *J2 = creerImage(renderer, IMG_J2);
    if(J2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &J2);
    rectangle *J2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/16.65, 11.0/2, 13.0, 13.0);
    ajoutListeRect(&listeRectangle, &J2Rect);

    // Txt

    // Chargement de la police en taille 64
    TTF_Font *font = TTF_OpenFont(TTF_FONT, 64);
    if(!font) {
        printf("Erreur lors du chargement de la police TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    // Couleurs
    SDL_Color noire = {0,0,0};

    // saut

    SDL_Texture *sauter = creerImage(renderer, IMG_SAUTER);
    if(sauter == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &sauter);
    rectangle *sautRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/3, 6.0, 6.0);
    ajoutListeRect(&listeRectangle, &sautRect);
    
    // saut J1
    SDL_Texture *sauterJ1 = creerTexte(renderer,font,"Z",noire);
    if(sauterJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &sauterJ1);
    rectangle *sauterJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/3.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &sauterJ1Rect);

    // saut J2
    SDL_Texture *sauterJ2 = creerTexte(renderer,font,"Up",noire);
    if(sauterJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &sauterJ2);
    rectangle *sauterJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/3.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &sauterJ2Rect);

    // accroupi

    SDL_Texture *accroupir = creerImage(renderer, IMG_ACCROUPI);
    if(accroupir == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &accroupir);
    rectangle *accroupirRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/4, 4.0, 4.0);
    ajoutListeRect(&listeRectangle, &accroupirRect);
    
    // accroupi J1
    SDL_Texture *accroupirJ1 = creerTexte(renderer,font,"S",noire);
    if(accroupirJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &accroupirJ1);
    rectangle *accroupirJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/4.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &accroupirJ1Rect);

    // accroupi J2
    SDL_Texture *accroupirJ2 = creerTexte(renderer,font,"DOWN",noire);
    if(accroupirJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &accroupirJ2);
    rectangle *accroupirJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/4.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &accroupirJ2Rect);

    // gauche

    SDL_Texture *gauche = creerImage(renderer, IMG_GAUCHE);
    if(gauche == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gauche);
    rectangle *gaucheRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/5, 6.0, 6.0);
    ajoutListeRect(&listeRectangle, &gaucheRect);
    
    // gauche J1
    SDL_Texture *gaucheJ1 = creerTexte(renderer,font,"Q",noire);
    if(gaucheJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gaucheJ1);
    rectangle *gaucheJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/5.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &gaucheJ1Rect);

    // gauche J2
    SDL_Texture *gaucheJ2 = creerTexte(renderer,font,"LEFT",noire);
    if(gaucheJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gaucheJ2);
    rectangle *gaucheJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/5.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &gaucheJ2Rect);

    // droite

    SDL_Texture *droite = creerImage(renderer, IMG_DROITE);
    if(droite == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &droite);
    rectangle *droiteRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/6, 6.0, 6.0);
    ajoutListeRect(&listeRectangle, &droiteRect);
    
    // droite J1
    SDL_Texture *droiteJ1 = creerTexte(renderer,font,"D",noire);
    if(droiteJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &droiteJ1);
    rectangle *droiteJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/6.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &droiteJ1Rect);

    // droite J2
    SDL_Texture *droiteJ2 = creerTexte(renderer,font,"RIGHT",noire);
    if(droiteJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &droiteJ2);
    rectangle *droiteJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/6.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &droiteJ2Rect);

    // poing

    SDL_Texture *poing = creerImage(renderer, IMG_POING);
    if(poing == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &poing);
    rectangle *poingRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/7, 6.0, 6.0);
    ajoutListeRect(&listeRectangle, &poingRect);
    
    // poing J1
    SDL_Texture *poingJ1 = creerTexte(renderer,font,"C",noire);
    if(poingJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &poingJ1);
    rectangle *poingJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/7.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &poingJ1Rect);

    // poing J2
    SDL_Texture *poingJ2 = creerTexte(renderer,font,"Keypad 5",noire);
    if(poingJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &poingJ2);
    rectangle *poingJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/7.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &poingJ2Rect);

    // kick

    SDL_Texture *kick = creerImage(renderer, IMG_KICK);
    if(kick == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &kick);
    rectangle *kickRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/8, 8.0, 8.0);
    ajoutListeRect(&listeRectangle, &kickRect);
    
    // kick J1
    SDL_Texture *kickJ1 = creerTexte(renderer,font,"V",noire);
    if(kickJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &kickJ1);
    rectangle *kickJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/8.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &kickJ1Rect);

    // kick J2
    SDL_Texture *kickJ2 = creerTexte(renderer,font,"Keypad 6",noire);
    if(kickJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &kickJ2);
    rectangle *kickJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/8.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &kickJ2Rect);

    // garde

    SDL_Texture *garde = creerImage(renderer, IMG_GARDE);
    if(garde == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &garde);
    rectangle *gardeRect = creerRectangle(&largeurF, &hauteurF, 24.0/3, 11.0/9, 6.0, 6.0);
    ajoutListeRect(&listeRectangle, &gardeRect);
    
    // garde J1
    SDL_Texture *gardeJ1 = creerTexte(renderer,font,"F",noire);
    if(gardeJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gardeJ1);
    rectangle *gardeJ1Rect = creerRectangle(&largeurF, &hauteurF, 24.0/12, 11.0/9.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &gardeJ1Rect);

    // garde J2
    SDL_Texture *gardeJ2 = creerTexte(renderer,font,"Keypad 4",noire);
    if(gardeJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeT(&listeTexture, &gardeJ2);
    rectangle *gardeJ2Rect = creerRectangle(&largeurF, &hauteurF, 24.0/17, 11.0/9.25, 32.0, 32.0);
    ajoutListeRect(&listeRectangle, &gardeJ2Rect);

    

    // Boutons
    // retour
    bouton *boutonControleBack = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 100.0, 100.0, 11.0, 11.0, IMG_BACK, 0, 0);
    if(boutonControleBack == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonControleBack);

    // saut J1
    bouton *boutonSautJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/3.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonSautJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonSautJ1);
    // saut J2
    bouton *boutonSautJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/3.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonSautJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonSautJ2);
    // accroupi J1
    bouton *boutonAccroupirJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/4.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonAccroupirJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonAccroupirJ1);
    // accroupi J2
    bouton *boutonAccroupirJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/4.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonAccroupirJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonAccroupirJ2);
    // gauche J1
    bouton *boutonGaucheJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/5.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonGaucheJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonGaucheJ1);
    // gauche J2
    bouton *boutonGaucheJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/5.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonGaucheJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonGaucheJ2);
    // droite J1
    bouton *boutonDroiteJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/6.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonDroiteJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonDroiteJ1);
    // droite J2
    bouton *boutonDroiteJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/6.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonDroiteJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonDroiteJ2);
    // poing J1
    bouton *boutonPoingJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/7.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonPoingJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonPoingJ1);
    // poing J2
    bouton *boutonPoingJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/7.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonPoingJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonPoingJ2);
    // kick J1
    bouton *boutonKickJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/8.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonKickJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonKickJ1);
    // kick J2
    bouton *boutonKickJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/8.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonKickJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonKickJ2);
    // garde J1
    bouton *boutonGardeJ1 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/12, 11.0/9.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonGardeJ1 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonGardeJ1);
    // garde J2
    bouton *boutonGardeJ2 = creerBouton(renderer, &listeRectangle, &largeurF, &hauteurF, 24.0/17, 11.0/9.25, 32.0, 32.0, IMG_EMPLACEMENT_TOUCHE, 0, 0);
    if(boutonGardeJ2 == NULL) exit(EXIT_FAILURE);
    ajoutListeBouton(&listeBoutons, &boutonGardeJ2);

    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            else if (e.type == SDL_KEYDOWN) // Vérifier si un événement clavier est survenu
            {
                if (e.key.keysym.sym == SDLK_ESCAPE) // Vérifier si la touche pressée est Échap
                {
                    quit = 1 ; // Mettre fin à la boucle de jeu et fermer l'application
                }
            }
            // Bouton retour
            // Appuie sur le bouton
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h) {
                boutonControleBack->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h) {
                (*scene)++;
                boutonControleBack->etat = BOUTON_RELACHE;
                quit = 2;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonControleBack->etat == BOUTON_APPUYE  || boutonControleBack->etat == BOUTON_OVER && !(e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h)) {
                boutonControleBack->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonControleBack->position->rect->x && e.motion.x < boutonControleBack->position->rect->x + boutonControleBack->position->rect->w && e.motion.y > boutonControleBack->position->rect->y && e.motion.y < boutonControleBack->position->rect->y + boutonControleBack->position->rect->h && boutonControleBack->etat == BOUTON_RELACHE) {
                boutonControleBack->etat = BOUTON_OVER;
            } 
            // Bouton saut J1
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h) {
                boutonSautJ1->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, SauterJ1, &sauterJ1);
                boutonSautJ1->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonSautJ1->etat == BOUTON_APPUYE  || boutonSautJ1->etat == BOUTON_OVER && !(e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h)) {
                boutonSautJ1->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonSautJ1->position->rect->x && e.motion.x < boutonSautJ1->position->rect->x + boutonSautJ1->position->rect->w && e.motion.y > boutonSautJ1->position->rect->y && e.motion.y < boutonSautJ1->position->rect->y + boutonSautJ1->position->rect->h && boutonSautJ1->etat == BOUTON_RELACHE) {
                boutonSautJ1->etat = BOUTON_OVER;
            } 

            // Bouton saut J2
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h) {
                boutonSautJ2->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, SauterJ2, &sauterJ2);
                boutonSautJ2->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonSautJ2->etat == BOUTON_APPUYE  || boutonSautJ2->etat == BOUTON_OVER && !(e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h)) {
                boutonSautJ2->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonSautJ2->position->rect->x && e.motion.x < boutonSautJ2->position->rect->x + boutonSautJ2->position->rect->w && e.motion.y > boutonSautJ2->position->rect->y && e.motion.y < boutonSautJ2->position->rect->y + boutonSautJ2->position->rect->h && boutonSautJ2->etat == BOUTON_RELACHE) {
                boutonSautJ2->etat = BOUTON_OVER;
            } 
            // Bouton accroupir J1
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h) {
                boutonAccroupirJ1->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, AccroupirJ1, &accroupirJ1);
                boutonAccroupirJ1->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonAccroupirJ1->etat == BOUTON_APPUYE  || boutonAccroupirJ1->etat == BOUTON_OVER && !(e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h)) {
                boutonAccroupirJ1->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonAccroupirJ1->position->rect->x && e.motion.x < boutonAccroupirJ1->position->rect->x + boutonAccroupirJ1->position->rect->w && e.motion.y > boutonAccroupirJ1->position->rect->y && e.motion.y < boutonAccroupirJ1->position->rect->y + boutonAccroupirJ1->position->rect->h && boutonAccroupirJ1->etat == BOUTON_RELACHE) {
                boutonAccroupirJ1->etat = BOUTON_OVER;
            } 

            // Bouton accroupir J2
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h) {
                boutonAccroupirJ2->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, AccroupirJ2, &accroupirJ2);
                boutonAccroupirJ2->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonAccroupirJ2->etat == BOUTON_APPUYE  || boutonAccroupirJ2->etat == BOUTON_OVER && !(e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h)) {
                boutonAccroupirJ2->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonAccroupirJ2->position->rect->x && e.motion.x < boutonAccroupirJ2->position->rect->x + boutonAccroupirJ2->position->rect->w && e.motion.y > boutonAccroupirJ2->position->rect->y && e.motion.y < boutonAccroupirJ2->position->rect->y + boutonAccroupirJ2->position->rect->h && boutonAccroupirJ2->etat == BOUTON_RELACHE) {
                boutonAccroupirJ2->etat = BOUTON_OVER;
            } 

            // Bouton gauche J1
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h) {
                boutonGaucheJ1->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, GaucheJ1, &gaucheJ1);
                boutonGaucheJ1->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonGaucheJ1->etat == BOUTON_APPUYE  || boutonGaucheJ1->etat == BOUTON_OVER && !(e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h)) {
                boutonGaucheJ1->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonGaucheJ1->position->rect->x && e.motion.x < boutonGaucheJ1->position->rect->x + boutonGaucheJ1->position->rect->w && e.motion.y > boutonGaucheJ1->position->rect->y && e.motion.y < boutonGaucheJ1->position->rect->y + boutonGaucheJ1->position->rect->h && boutonGaucheJ1->etat == BOUTON_RELACHE) {
                boutonGaucheJ1->etat = BOUTON_OVER;
            } 

            // Bouton gauche J2
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h) {
                boutonGaucheJ2->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, GaucheJ2, &gaucheJ2);
                boutonGaucheJ2->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonGaucheJ2->etat == BOUTON_APPUYE  || boutonGaucheJ2->etat == BOUTON_OVER && !(e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h)) {
                boutonGaucheJ2->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonGaucheJ2->position->rect->x && e.motion.x < boutonGaucheJ2->position->rect->x + boutonGaucheJ2->position->rect->w && e.motion.y > boutonGaucheJ2->position->rect->y && e.motion.y < boutonGaucheJ2->position->rect->y + boutonGaucheJ2->position->rect->h && boutonGaucheJ2->etat == BOUTON_RELACHE) {
                boutonGaucheJ2->etat = BOUTON_OVER;
            } 

            // Bouton droite J1
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h) {
                boutonDroiteJ1->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, DroitJ1, &droiteJ1);
                boutonDroiteJ1->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonDroiteJ1->etat == BOUTON_APPUYE  || boutonDroiteJ1->etat == BOUTON_OVER && !(e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h)) {
                boutonDroiteJ1->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonDroiteJ1->position->rect->x && e.motion.x < boutonDroiteJ1->position->rect->x + boutonDroiteJ1->position->rect->w && e.motion.y > boutonDroiteJ1->position->rect->y && e.motion.y < boutonDroiteJ1->position->rect->y + boutonDroiteJ1->position->rect->h && boutonDroiteJ1->etat == BOUTON_RELACHE) {
                boutonDroiteJ1->etat = BOUTON_OVER;
            } 

            // Bouton droite J2
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h) {
                boutonDroiteJ2->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, DroitJ2, &droiteJ2);
                boutonDroiteJ2->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonDroiteJ2->etat == BOUTON_APPUYE  || boutonDroiteJ2->etat == BOUTON_OVER && !(e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h)) {
                boutonDroiteJ2->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonDroiteJ2->position->rect->x && e.motion.x < boutonDroiteJ2->position->rect->x + boutonDroiteJ2->position->rect->w && e.motion.y > boutonDroiteJ2->position->rect->y && e.motion.y < boutonDroiteJ2->position->rect->y + boutonDroiteJ2->position->rect->h && boutonDroiteJ2->etat == BOUTON_RELACHE) {
                boutonDroiteJ2->etat = BOUTON_OVER;
            } 

            // Bouton poing J1
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h) {
                boutonPoingJ1->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, PoingJ1, &poingJ1);
                boutonPoingJ1->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonPoingJ1->etat == BOUTON_APPUYE  || boutonPoingJ1->etat == BOUTON_OVER && !(e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h)) {
                boutonPoingJ1->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonPoingJ1->position->rect->x && e.motion.x < boutonPoingJ1->position->rect->x + boutonPoingJ1->position->rect->w && e.motion.y > boutonPoingJ1->position->rect->y && e.motion.y < boutonPoingJ1->position->rect->y + boutonPoingJ1->position->rect->h && boutonPoingJ1->etat == BOUTON_RELACHE) {
                boutonPoingJ1->etat = BOUTON_OVER;
            } 

            // Bouton poing J2
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h) {
                boutonPoingJ2->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, PoingJ2, &poingJ2);
                boutonPoingJ2->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonPoingJ2->etat == BOUTON_APPUYE  || boutonPoingJ2->etat == BOUTON_OVER && !(e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h)) {
                boutonPoingJ2->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonPoingJ2->position->rect->x && e.motion.x < boutonPoingJ2->position->rect->x + boutonPoingJ2->position->rect->w && e.motion.y > boutonPoingJ2->position->rect->y && e.motion.y < boutonPoingJ2->position->rect->y + boutonPoingJ2->position->rect->h && boutonPoingJ2->etat == BOUTON_RELACHE) {
                boutonPoingJ2->etat = BOUTON_OVER;
            } 

            // Bouton kick J1
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h) {
                boutonKickJ1->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, KickJ1, &kickJ1);
                boutonKickJ1->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonKickJ1->etat == BOUTON_APPUYE  || boutonKickJ1->etat == BOUTON_OVER && !(e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h)) {
                boutonKickJ1->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonKickJ1->position->rect->x && e.motion.x < boutonKickJ1->position->rect->x + boutonKickJ1->position->rect->w && e.motion.y > boutonKickJ1->position->rect->y && e.motion.y < boutonKickJ1->position->rect->y + boutonKickJ1->position->rect->h && boutonKickJ1->etat == BOUTON_RELACHE) {
                boutonKickJ1->etat = BOUTON_OVER;
            } 

            // Bouton kick J2
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h) {
                boutonKickJ2->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, KickJ2, &kickJ2);
                boutonKickJ2->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonKickJ2->etat == BOUTON_APPUYE  || boutonKickJ2->etat == BOUTON_OVER && !(e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h)) {
                boutonKickJ2->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonKickJ2->position->rect->x && e.motion.x < boutonKickJ2->position->rect->x + boutonKickJ2->position->rect->w && e.motion.y > boutonKickJ2->position->rect->y && e.motion.y < boutonKickJ2->position->rect->y + boutonKickJ2->position->rect->h && boutonKickJ2->etat == BOUTON_RELACHE) {
                boutonKickJ2->etat = BOUTON_OVER;
            } 

            // Bouton garde J1
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h) {
                boutonGardeJ1->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, ParadeJ1, &gardeJ1);
                boutonGardeJ1->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonGardeJ1->etat == BOUTON_APPUYE  || boutonGardeJ1->etat == BOUTON_OVER && !(e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h)) {
                boutonGardeJ1->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonGardeJ1->position->rect->x && e.motion.x < boutonGardeJ1->position->rect->x + boutonGardeJ1->position->rect->w && e.motion.y > boutonGardeJ1->position->rect->y && e.motion.y < boutonGardeJ1->position->rect->y + boutonGardeJ1->position->rect->h && boutonGardeJ1->etat == BOUTON_RELACHE) {
                boutonGardeJ1->etat = BOUTON_OVER;
            } 

            // Bouton garde J2
            if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h) {
                boutonGardeJ2->etat = BOUTON_APPUYE;
            // Appuie et relache sur le bouton
            }else if (e.type == SDL_MOUSEBUTTONUP && e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h) {
                saisirTouche(renderer, font, e, liste_touches, ParadeJ2, &gardeJ2);
                boutonGardeJ2->etat = BOUTON_RELACHE;
            // Appuie sur le bouton et relache ailleurs
            }else if (e.type == SDL_MOUSEBUTTONUP && boutonGardeJ2->etat == BOUTON_APPUYE  || boutonGardeJ2->etat == BOUTON_OVER && !(e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h)) {
                boutonGardeJ2->etat = BOUTON_RELACHE;
            // Passe sur le bouton
            }else if (e.motion.x > boutonGardeJ2->position->rect->x && e.motion.x < boutonGardeJ2->position->rect->x + boutonGardeJ2->position->rect->w && e.motion.y > boutonGardeJ2->position->rect->y && e.motion.y < boutonGardeJ2->position->rect->y + boutonGardeJ2->position->rect->h && boutonGardeJ2->etat == BOUTON_RELACHE) {
                boutonGardeJ2->etat = BOUTON_OVER;
            } 
        }

        // Effacement de l'écran
        SDL_RenderClear(renderer);

        // Dessiner l'image de fond
        SDL_RenderCopy(renderer, controleBGTexture, NULL, NULL);

        // Dessiner l'image du titre des controles
        SDL_RenderCopy(renderer, controleTitleTexture, NULL, controleTitleRect->rect);

        SDL_RenderCopy(renderer, J1, NULL, J1Rect->rect);
        SDL_RenderCopy(renderer, J2, NULL, J2Rect->rect);

        SDL_RenderCopy(renderer, sauter, NULL, sautRect->rect);
        SDL_RenderCopy(renderer, accroupir, NULL, accroupirRect->rect);
        SDL_RenderCopy(renderer, gauche, NULL, gaucheRect->rect);
        SDL_RenderCopy(renderer, droite, NULL, droiteRect->rect);
        SDL_RenderCopy(renderer, poing, NULL, poingRect->rect);
        SDL_RenderCopy(renderer, kick, NULL, kickRect->rect);
        SDL_RenderCopy(renderer, garde, NULL, gardeRect->rect);

        // Dessiner le bouton retour
        if(boutonControleBack->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonControleBack->texture, boutonControleBack->relache, boutonControleBack->position->rect);
        else if (boutonControleBack->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonControleBack->texture, boutonControleBack->appuye, boutonControleBack->position->rect);
        else if (boutonControleBack->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonControleBack->texture, boutonControleBack->over, boutonControleBack->position->rect);

        // Commande
        //saut J1
        if(boutonSautJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonSautJ1->texture, boutonSautJ1->relache, boutonSautJ1->position->rect);
        else if (boutonSautJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonSautJ1->texture, boutonSautJ1->appuye, boutonSautJ1->position->rect);
        else if (boutonSautJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonSautJ1->texture, boutonSautJ1->over, boutonSautJ1->position->rect);
        //saut J2
        if(boutonSautJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonSautJ2->texture, boutonSautJ2->relache, boutonSautJ2->position->rect);
        else if (boutonSautJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonSautJ2->texture, boutonSautJ2->appuye, boutonSautJ2->position->rect);
        else if (boutonSautJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonSautJ2->texture, boutonSautJ2->over, boutonSautJ2->position->rect);
        //accroupi J1
        
        if(boutonAccroupirJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonAccroupirJ1->texture, boutonAccroupirJ1->relache, boutonAccroupirJ1->position->rect);
        else if (boutonAccroupirJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonAccroupirJ1->texture, boutonAccroupirJ1->appuye, boutonAccroupirJ1->position->rect);
        else if (boutonAccroupirJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonAccroupirJ1->texture, boutonAccroupirJ1->over, boutonAccroupirJ1->position->rect);
        //accroupi J2
        if(boutonAccroupirJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonAccroupirJ2->texture, boutonAccroupirJ2->relache, boutonAccroupirJ2->position->rect);
        else if (boutonAccroupirJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonAccroupirJ2->texture, boutonAccroupirJ2->appuye, boutonAccroupirJ2->position->rect);
        else if (boutonAccroupirJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonAccroupirJ2->texture, boutonAccroupirJ2->over, boutonAccroupirJ2->position->rect);
        //gauche J1
        if(boutonGaucheJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGaucheJ1->texture, boutonGaucheJ1->relache, boutonGaucheJ1->position->rect);
        else if (boutonGaucheJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGaucheJ1->texture, boutonGaucheJ1->appuye, boutonGaucheJ1->position->rect);
        else if (boutonGaucheJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGaucheJ1->texture, boutonGaucheJ1->over, boutonGaucheJ1->position->rect);
        //gauche J2
        if(boutonGaucheJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGaucheJ2->texture, boutonGaucheJ2->relache, boutonGaucheJ2->position->rect);
        else if (boutonGaucheJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGaucheJ2->texture, boutonGaucheJ2->appuye, boutonGaucheJ2->position->rect);
        else if (boutonGaucheJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGaucheJ2->texture, boutonGaucheJ2->over, boutonGaucheJ2->position->rect);
        //droite J1
        if(boutonDroiteJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonDroiteJ1->texture, boutonDroiteJ1->relache, boutonDroiteJ1->position->rect);
        else if (boutonDroiteJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonDroiteJ1->texture, boutonDroiteJ1->appuye, boutonDroiteJ1->position->rect);
        else if (boutonDroiteJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonDroiteJ1->texture, boutonDroiteJ1->over, boutonDroiteJ1->position->rect);
        //droite J2
        if(boutonDroiteJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonDroiteJ2->texture, boutonDroiteJ2->relache, boutonDroiteJ2->position->rect);
        else if (boutonDroiteJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonDroiteJ2->texture, boutonDroiteJ2->appuye, boutonDroiteJ2->position->rect);
        else if (boutonDroiteJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonDroiteJ2->texture, boutonDroiteJ2->over, boutonDroiteJ2->position->rect);
        //kick J1
        if(boutonKickJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonKickJ1->texture, boutonKickJ1->relache, boutonKickJ1->position->rect);
        else if (boutonKickJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonKickJ1->texture, boutonKickJ1->appuye, boutonKickJ1->position->rect);
        else if (boutonKickJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonKickJ1->texture, boutonKickJ1->over, boutonKickJ1->position->rect);
        //kick J2
        if(boutonKickJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonKickJ2->texture, boutonKickJ2->relache, boutonKickJ2->position->rect);
        else if (boutonKickJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonKickJ2->texture, boutonKickJ2->appuye, boutonKickJ2->position->rect);
        else if (boutonKickJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonKickJ2->texture, boutonKickJ2->over, boutonKickJ2->position->rect);
        //poing J1
        if(boutonPoingJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonPoingJ1->texture, boutonPoingJ1->relache, boutonPoingJ1->position->rect);
        else if (boutonPoingJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonPoingJ1->texture, boutonPoingJ1->appuye, boutonPoingJ1->position->rect);
        else if (boutonPoingJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonPoingJ1->texture, boutonPoingJ1->over, boutonPoingJ1->position->rect);
        //poing J2
        if(boutonPoingJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonPoingJ2->texture, boutonPoingJ2->relache, boutonPoingJ2->position->rect);
        else if (boutonPoingJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonPoingJ2->texture, boutonPoingJ2->appuye, boutonPoingJ2->position->rect);
        else if (boutonPoingJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonPoingJ2->texture, boutonPoingJ2->over, boutonPoingJ2->position->rect);
        //garde J1
        if(boutonGardeJ1->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGardeJ1->texture, boutonGardeJ1->relache, boutonGardeJ1->position->rect);
        else if (boutonGardeJ1->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGardeJ1->texture, boutonGardeJ1->appuye, boutonGardeJ1->position->rect);
        else if (boutonGardeJ1->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGardeJ1->texture, boutonGardeJ1->over, boutonGardeJ1->position->rect);
        //garde J2
        if(boutonGardeJ2->etat == BOUTON_RELACHE) SDL_RenderCopy(renderer, boutonGardeJ2->texture, boutonGardeJ2->relache, boutonGardeJ2->position->rect);
        else if (boutonGardeJ2->etat == BOUTON_APPUYE) SDL_RenderCopy(renderer, boutonGardeJ2->texture, boutonGardeJ2->appuye, boutonGardeJ2->position->rect);
        else if (boutonGardeJ2->etat == BOUTON_OVER) SDL_RenderCopy(renderer, boutonGardeJ2->texture, boutonGardeJ2->over, boutonGardeJ2->position->rect);


        // Txt
        // J1
        SDL_RenderCopy(renderer, sauterJ1, NULL, sauterJ1Rect->rect);
        SDL_RenderCopy(renderer, accroupirJ1, NULL, accroupirJ1Rect->rect);
        SDL_RenderCopy(renderer, gaucheJ1, NULL, gaucheJ1Rect->rect);
        SDL_RenderCopy(renderer, droiteJ1, NULL, droiteJ1Rect->rect);
        SDL_RenderCopy(renderer, poingJ1, NULL, poingJ1Rect->rect);
        SDL_RenderCopy(renderer, kickJ1, NULL, kickJ1Rect->rect);
        SDL_RenderCopy(renderer, gardeJ1, NULL, gardeJ1Rect->rect);

        // J2
        SDL_RenderCopy(renderer, sauterJ2, NULL, sauterJ2Rect->rect);        
        SDL_RenderCopy(renderer, accroupirJ2, NULL, accroupirJ2Rect->rect);      
        SDL_RenderCopy(renderer, gaucheJ2, NULL, gaucheJ2Rect->rect);      
        SDL_RenderCopy(renderer, droiteJ2, NULL, droiteJ2Rect->rect);      
        SDL_RenderCopy(renderer, poingJ2, NULL, poingJ2Rect->rect);      
        SDL_RenderCopy(renderer, kickJ2, NULL, kickJ2Rect->rect);      
        SDL_RenderCopy(renderer, gardeJ2, NULL, gardeJ2Rect->rect);

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }

    TTF_CloseFont(font); font = NULL;
    detruireListeRect(&listeRectangle);
    detruireListeBouton(&listeBoutons);
    detruireListeT(&listeTexture);

    return quit > 1 ? 0 : 1;
}