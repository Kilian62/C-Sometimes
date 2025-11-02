#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "depf.h"


int department(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage : %s dep <code_ou_nom>\n", argv[0]);
        return 1;
    }

    char *valeur = argv[1];

    FILE *f = fopen("C:\\Users\\kilia\\Documents\\git\\c-sometimes\\department\\data\\france-department.csv", "r");

    if (f == NULL) {
        perror("Erreur ouverture fichier CSV");
        return 1;
    }

    char ligne[200];
    char code[10], nom[50];
    int trouve = 0;


    fgets(ligne, sizeof(ligne), f);


    while (fgets(ligne, sizeof(ligne), f) != NULL) {

        if (sscanf(ligne, "%[^,],%[^,]", code, nom) == 2) {
            if (strcmp(valeur, code) == 0) {
                printf("%s : %s\n", nom,code);
                trouve = 1;
            } else if (strcmp(valeur, nom) == 0) {
                printf("%s : %s\n", nom,code);
                trouve = 1;
            }
        }
    }

    if (!trouve) {
        printf("Aucun departement trouve pour : %s\n", valeur);
    }

    fclose(f);
    return 0;
}
