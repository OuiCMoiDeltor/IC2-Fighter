/**
 * @file gestion_touches.c
 * @brief Fichier contenant les fonctions de gestion des touches pour le jeu.
 *
 * Ce fichier implémente les fonctions nécessaires pour configurer et gérer les touches utilisées
 * dans le jeu. Il permet la lecture et l'écriture des configurations de touches depuis et vers des fichiers,
 * la modification des touches en réponse aux actions de l'utilisateur, et la réinitialisation des touches
 * à leurs valeurs par défaut.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../lib/creation.h"
#include "../lib/touches.h"

/**
 * @brief Réinitialise les touches du jeu à partir des valeurs lues dans un fichier.
 *
 * Cette fonction lit les valeurs des touches depuis un fichier de configuration, les convertit en entiers,
 * et met à jour la liste des touches utilisées dans le jeu. Elle écrit également ces valeurs dans un autre
 * fichier pour les sauvegarder.
 *
 * @param liste_touches Tableau d'entiers représentant les codes des touches configurées.
 * @param f_fichier Chemin vers le fichier dans lequel écrire les touches.
 * @param r_fichier Chemin vers le fichier à lire pour les touches.
 */

extern
void resetTouches(int * liste_touches, char * f_fichier, char * r_fichier) {
    char line[100];
    char *lines[14];  
    int num_lines = 0;
    int touche;
    FILE * file = fopen(r_fichier, "r");
    if (file == NULL) exit(1);
    while (fgets(line, 100, file) != NULL && num_lines < 14) {
        line[strcspn(line, "\n")] = '\0';
        lines[num_lines] = malloc(strlen(line) + 1);
        if (lines[num_lines] == NULL) exit(1);
        strcpy(lines[num_lines], line);
        num_lines++;
    }
    fclose(file);
    file = fopen(f_fichier, "w");
    for (int i = 0; i < num_lines; i++) {
        if(touche = atoi(lines[i]));
        liste_touches[i] = touche;
        strcat(lines[i],"\n");
        fputs(lines[i], file);
        free(lines[i]);
    }
    fclose(file);
}

/**
 * @brief Lit les touches configurées à partir d'un fichier et les stocke dans un tableau.
 *
 * Cette fonction ouvre un fichier contenant les touches configurées, les lit ligne par ligne,
 * convertit chaque ligne en une valeur entière correspondant au code de la touche, et stocke
 * ces valeurs dans un tableau passé en paramètre.
 *
 * @param liste_touches Tableau pour stocker les touches lues.
 * @param fichier Chemin du fichier à lire.
 */

extern
void LireTouches(int * liste_touches, char * fichier){
    
    char line[100];
    char *lines[14];  
    int num_lines = 0;
    int touche;
    FILE * file = fopen(fichier, "r");
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

/**
 * @brief Modifie une touche spécifique dans le fichier de configuration et met à jour la liste des touches.
 *
 * Cette fonction remplace la valeur d'une touche spécifiée par l'utilisateur dans le fichier de configuration.
 * Elle lit le fichier ligne par ligne et remplace la ligne correspondant à la touche à modifier par la nouvelle valeur,
 * puis sauvegarde les changements dans un fichier temporaire qui est ensuite renommé.
 *
 * @param liste_touches Tableau contenant les codes des touches.
 * @param numero_ligne Index de la touche à modifier dans le tableau.
 * @param touche Nouveau code de la touche.
 * @param fichier Chemin du fichier de configuration.
 */

extern
void ModifierTouche(int * liste_touches, int numero_ligne, int touche, char * fichier) {

    FILE *file;
    FILE *tempFile;
    char line[100];
    char nb[20];
    int line_number = 0;

    file = fopen(fichier, "r");
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
    if (remove(fichier) != 0) {
        fprintf(stderr, "Erreur lors de la suppression du fichier original.\n");
        exit(1);
    }
    // Et on renomme le fichier temporaire pour remplacer l'original
    if (rename("temp.txt", fichier) != 0) {
        fprintf(stderr, "Erreur lors du renommage du fichier temporaire.\n");
        exit(1);
    }
}

/**
 * @brief Permet à l'utilisateur de saisir une nouvelle touche pour une action spécifique et met à jour l'affichage.
 *
 * Cette fonction attend un événement clavier, puis met à jour la touche correspondante dans la liste des touches
 * et dans le fichier de configuration. Elle met également à jour l'affichage de la touche à l'écran en utilisant
 * une texture SDL pour le texte.
 *
 * @param renderer Pointeur vers le renderer SDL utilisé pour le dessin.
 * @param font Police utilisée pour l'affichage du texte.
 * @param event Événement SDL à traiter.
 * @param liste_touches Tableau contenant les codes des touches.
 * @param touche Enumération spécifiant quelle touche doit être saisie.
 * @param txt Pointeur vers une texture SDL contenant le texte à mettre à jour.
 * @param fichier Chemin du fichier de configuration des touches.
 */

extern
void saisirTouche(SDL_Renderer * renderer, TTF_Font * font, SDL_Event event, int * liste_touches, touches_e touche, SDL_Texture ** txt, char * fichier){

    while(SDL_PollEvent(&event) != 0);
    SDL_WaitEvent(&event);
    if(event.type == SDL_KEYDOWN) {
        liste_touches[touche] = (event.key.keysym.scancode);
        ModifierTouche(liste_touches,touche,liste_touches[touche], fichier);
        SDL_DestroyTexture(*txt);
        SDL_Color noire = {0,0,0};
        SDL_Log("%s", (char*)SDL_GetScancodeName(liste_touches[touche]));
        *txt = creerTexte(renderer,font,(char*)SDL_GetScancodeName(liste_touches[touche]),noire);
        if(*txt == NULL) exit(EXIT_FAILURE);
    }
}