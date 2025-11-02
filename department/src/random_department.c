#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "depf.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

        // Donne une valeur aléatoire entre 1 et 95
        int random_value = (rand() % 95) + 1;
        
        // Convertir le nombre en chaîne
        char code_str[10];
        snprintf(code_str, sizeof(code_str), "%02d", random_value);
        
        // Créer un tableau d'arguments simulé
        char *fake_argv[] = {"rdep", code_str};
        printf("Le departement du jour est :\n");
        // Appeler department avec 2 arguments
        department(2, fake_argv);
    
    
    return 0;
}