#include <stdlib.h>
#include <stdio.h>

int calc(char *nbr, int taille){
    char *num   = malloc(taille * sizeof(char));
    int n       = 0;
    int number1 = 0;
    int number2 = 0;
    int res     = 0;
    char op;

    //printf("You entered: %s\n", nbr);

    for (int i = 0; nbr[i] != '\0'; i++){

        if (nbr[i] != '+' && nbr[i] != '-' && nbr[i] != '/' ){
            num[n] = nbr[i];
            n++;
            num[n] = '\0';
        }
        else{
            number1 = atoi(num);
            op = nbr[i];
            //printf("Operator is: %c\n", op);

            n =0;
            num[n] = '\0';
        }
        
    }
    number2 = atoi(num);
    /*printf("Number is: %d\n", number1);
    printf("Second number is: %d\n", number2);*/

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
        default:
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