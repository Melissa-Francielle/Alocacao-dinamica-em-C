//Implemente uma função que receba como parametro dois vetores vetX, vetY de tamanho n. A função deve retorne o ponteiro
//para um vetor soma de tamanho n alocado dinamicamente, em que soma = vetX + vetY;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void preencher_vetor(int vet[], int n){
    int i;
        for (i =0; i < n; i++){
            printf("\nDigite os valores do vetor %d: ", i);
            scanf("%d", &vet[i]);
            setbuf(stdin, NULL);
        }
}
int soma_vetores (int *vetX, int *vetY, int n){
    int i, *soma;
        soma = (int *) malloc (n * sizeof(int));
        if (soma == NULL){
            printf("\n\tERRO!\n");
            exit (1);
        }
        else {
            for (i =0; i < n; i++){
                soma[i] = vetX[i] + vetY[i];
            }
        }
    return soma;
}
int main () {
    int n, i;

    printf("\nDigite o tamanho desse vetor: \n");
    scanf("%d", &n);
    setbuf(stdin, NULL);

    int vetX[n], vetY[n];
    preencher_vetor (vetX, n);
    preencher_vetor(vetY, n);

    int *soma; 
    printf("\t\n____Exiba a soma dos vetores____\n");
    soma = soma_vetores (vetX, vetY, n);
        for (i = 0; i < n; i++){
            printf("A soma dos vetores = %d\n", *(soma+i));
        }
    return 0;
}