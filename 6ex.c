#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **alocar_matriz (int n){
    int **matriz;
    int i;
    matriz = (int **)calloc (n, sizeof(int *));
        if (matriz == NULL){
            printf("\nERRO\n");
            exit(1);
        }
        for (i =0; i < n; i++){
            matriz[i] = (int *) calloc (n, sizeof(int));
            if (matriz == NULL){
                printf("\nERRO\n");
                exit(1);
            }
        }
    return matriz;
}
int **preenche_matriz(int n){
    int **matriz, i, j;
    matriz = alocar_matriz(n);
    for( i = 0; i < n; i++){
        if (i + j == n - 1){
            matriz[i][j] = 1;
        }
    }
    return matriz;
}
void** exibe_matriz (int **matriz, int n){
    int i, j;

        for (i =0; i< n; i++){
            for (j = 0; j< n; j++){
                printf("\n\t%d", matriz[i][j]);
            }
        printf("\n");
        }
}
int main (){
    int n;

    printf("Entre com a dimensao da matriz: \n");
    scanf("%d", &n);
    setbuf(stdin, NULL);

    int **matriz = preenche_matriz(n);

    printf("\tMATRIZ RESULTANTE\n");
    exibe_matriz(matriz, n);
    return 0;
}