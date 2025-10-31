#include <stdlib.h>
#include <stdio.h>

int calc(char *nbr, int taille){

    char *num   = malloc(taille * sizeof(char));
     if (num == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return -1;
    }

    int n       = 0;
    int number1 = 0;
    int number2 = 0;
    int res     = 0;
    char op;
    // Parse the input string to extract numbers and operator
    for (int i = 0; nbr[i] != '\0'; i++){
        // if first character is an operator
        if (n == 0 && (nbr[i] == '+' || nbr[i] == '-' || nbr[i] == '/' || nbr[i] == '*')){
            num[n] = nbr[i];
            n++;
        }
        // if the character is not an operator
        else if (nbr[i] != '+' && nbr[i] != '-' && nbr[i] != '/' && nbr[i] != '*'){
            num[n] = nbr[i];
            n++;
            num[n] = '\0';
        }
        
        else{
            // if it is an operator
            number1 = atoi(num);
            op = nbr[i];
            n =0 ;
            num[n] = '\0';
        }
        
    }
    number2 = atoi(num);
        // Perform calculation based on the operator
    switch (op){
        case '+':
            res = number1 + number2;
            break;
        case '-':
            res = number1 - number2;
            break;
        case '/':
            if (number2 == 0){
                printf("WOOOOOOOW \n");
                return -1;
            }
            res = number1 / number2;
            break;
        case '*':
            res = number1 * number2;
            break;
        default:
        // in case the operator is unknown
            printf("Error: Unknown operator %c\n", op);
            break;
    }
    free(num);
     return res;
}

int main(){
    int taille = 100;
    printf("Ultra Modern Optimised Calculator !");
    printf("\nEnter your number baby girl : ");
    char *nbr = malloc(taille * sizeof(char));
    scanf("%s", nbr);
   printf("Result is: %d\n", calc(nbr,taille));
    free(nbr);
    return 0;

}