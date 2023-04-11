//Implemente um programa que leia duas matriz de inteiros m1 e m2 de ordem M x N e preeencha uma terceira matriz soma que é resultado da soma 
//de m1 e m2. As matrizes devem ser alocadas dinamicamente. Não esqueça de verificar se é possivel fazer a alocação de memoria;
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int** aloca_matriz (int M, int N){
    int **matriz_aloca, i;

        matriz_aloca = (int **) malloc(M * sizeof(int *));
            if(matriz_aloca == NULL){
                printf("\nERRO\n");
                exit(1);
            }
            for(i = 0; i < M; i++){
                matriz_aloca[i] = (int *) malloc(N * sizeof(int));
                    if (matriz_aloca == NULL){
                        printf("\nERRO\n");
                        exit(1);
                    }
            }
    return matriz_aloca;
}
void** preenche_matriz (int **matriz, int M, int N){
    int i, j;
        for (i = 0; i < M; i++){
            for (j = 0; j < N; j++){
                printf("\nPreencha a matriz: \n");
                scanf("%d", &matriz[i][j]);
            }
        }
}
int main (){
    int **m1, **m2, **soma;
    int M, N;
    int i, j;

    printf("\nEntre com a dimensao de M e N respectivamente: \n");
    scanf("%d%d", &M, &N);

    m1 = aloca_matriz(M, N);
    m2 = aloca_matriz(M, N);

    printf("\n\t....PREENCHE A MATRIZ M1....\n");
    preenche_matriz(m1, M, N);
    printf("\n\t....PREENCHE A MATRIZ M2...\n");
    preenche_matriz (m2, M, N);

    soma = aloca_matriz(M, N);

        for (i = 0; i < M; i++){
            for (j =0; j < N; j++){
                soma[i][j] = m1[i][j] + m2[i][j];
            }
        }
    printf("\n\t....MATRIZ RESULTANTE....\n");  
        for (i = 0; i < M; i++){
            for (j = 0; j < N; j++){
                printf(" %d ", soma[i][j]);
            }
            printf("\n");
        }
    return 0;
}   