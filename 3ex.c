#include <stdio.h>
#include <stdlib.h>

int main (){
    int **mat, *vet, i, j, aux;
    int l, c;
    int i, j;
    printf("\nDigite as dimensões de linha e coluna: \n");
    scanf("%d%d", &l, &c);

    mat = (int **) malloc (l * sizeof(int *));
        if (mat == NULL){
            printf("\nERRO\n");
            exit(1);
        }
        for (i =0; i < l; i++){
            mat[i] = (int *) malloc (c * sizeof(int));
            if (mat[i] == NULL){
                printf("\nERRO\n");
                exit(1);
            }
        }
    vet = (int *) malloc (l * c * sizeof(int));
        if (vet ==NULL){
            printf("\nERRO\n");
            exit(1);
        }
    aux = 0;
        for(i = 0; i < l; i++){
            for (j =0; j < c; j++){
                printf("\nPreencha a matriz: \n");
                scanf("%d", &mat[i][j]);
                setbuf(stdin, NULL);
            }
        }
        for(i = 0; i < l; i++){
            for (j =0; j < c; j++){
                if(mat[i][j] % 7 == 0 && mat[i][j] % 2 != 0){
                    vet[aux] = mat[i][j];
                    aux++;
                }
            }
        }
        for(i = 0; i < aux; i++){
            printf("%d", vet[i]);
        }
}