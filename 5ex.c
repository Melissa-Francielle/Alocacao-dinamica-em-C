#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz (int linha, int coluna){
    int **mat;
    mat = (int **) malloc(linha * sizeof(int *));
    if (mat == NULL){
        printf("ERRO\n");
        exit(1);
    }
    
    for (int i = 0; i < linha; i++){
        mat[i] = (int *) malloc(coluna * sizeof(int));
        if (mat[i] == NULL){
            printf("ERRO\n");
            exit(1);
        }
    }
    return mat;
}

int** preenche_matriz ( int linha, int coluna){
    int **mat;
    mat = aloca_matriz(linha, coluna);
    for (int i = 0; i < linha; i++){
        for ( int j = 0; j < coluna; j++){
            printf("\nDigite o valor da matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

int busca_numero(int numero, int **mat, int linha, int coluna){
    for (int i = 0; i < linha; i++){
        for ( int j = 0; j < coluna; j++){
            if (numero == mat[i][j]){
                return 1;
            }
            
        }
    }
    return 0;
}

int main(){
    int **mat, linha, coluna, numero, resultado;
    printf("\nDigite as dimensoes da linha e coluna respectivamente: \n");
    scanf("%d%d", &linha, &coluna);

    printf("\n\t....PREENCHENDO MATRIZ....\n");
    mat = preenche_matriz(linha, coluna);

    printf("\nDigite o numero que busca: \n");
    scanf("%d", &numero);
    
    printf("\n\t....RESULTADO DAS BUSCAS....\n");
    resultado = busca_numero(numero, mat, linha, coluna);
    printf("\n%d -", resultado);
    if (resultado == 1){
        printf("Elemento encontrado");
    }
    else{
        printf("Elemento não encontrado");
    }
    
    return 0;
}