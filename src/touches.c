#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../lib/creation.h"
#include "../lib/touches.h"


extern
void LireTouches(int * liste_touches){
    
    char line[100];
    char *lines[14];  
    int num_lines = 0;
    int touche;
    FILE * file = fopen("touches.txt", "r");
    if (file == NULL) exit(1);
    while (fgets(line, 100, file) != NULL && num_lines < 14) {
        line[strcspn(line, "\n")] = '\0';
        lines[num_lines] = malloc(strlen(line) + 1);
        if (lines[num_lines] == NULL) exit(1);
        strcpy(lines[num_lines], line);
        num_lines++;
    }
    fclose(file);
    for (int i = 0; i < num_lines; i++) {
        if(atoi(lines[i]))
            touche = atoi(lines[i]);
        liste_touches[i] = touche;
        free(lines[i]);
    }
}

extern
void ModifierTouche(int * liste_touches, int numero_ligne, int touche) {

    FILE *file;
    FILE *tempFile;
    char line[100];
    char nb[20];
    int line_number = 0;

    file = fopen("touches.txt", "r");
    if (file == NULL) exit(1);

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fprintf(stderr, "Impossible de créer le fichier temporaire.\n");
        fclose(file);
        exit(1);
    }

    while (fgets(line, 100, file) != NULL) {
        
        line_number++;
        if (line_number == numero_ligne+1) {
            liste_touches[numero_ligne] = touche;
            sprintf(nb,"%d",touche);
            strcat(nb,"\n");
            fputs(nb, tempFile);
            
        }else{ 
            fputs(line, tempFile);
        }
    }
    // On ferme les fichiers
    fclose(file);
    fclose(tempFile);
    // On supprime le fichier original
    if (remove("touches.txt") != 0) {
        fprintf(stderr, "Erreur lors de la suppression du fichier original.\n");
        exit(1);
    }
    // Et on renomme le fichier temporaire pour remplacer l'original
    if (rename("temp.txt", "touches.txt") != 0) {
        fprintf(stderr, "Erreur lors du renommage du fichier temporaire.\n");
        exit(1);
    }
}


extern
void saisirTouche(SDL_Renderer * renderer, TTF_Font * font, SDL_Event event, int * liste_touches, touches_e touche, SDL_Texture ** txt){

    while(SDL_PollEvent(&event) != 0);
    SDL_WaitEvent(&event);
    if(event.type == SDL_KEYDOWN) {
        liste_touches[touche] = (event.key.keysym.scancode);
        ModifierTouche(liste_touches,touche,liste_touches[touche]);
        SDL_DestroyTexture(*txt);
        SDL_Color noire = {0,0,0};
        SDL_Log("%s", (char*)SDL_GetScancodeName(liste_touches[touche]));
        *txt = creerTexte(renderer,font,(char*)SDL_GetScancodeName(liste_touches[touche]),noire);
        if(*txt == NULL) exit(EXIT_FAILURE);
    }
}