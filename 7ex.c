//Defina uma estrtura adequada para armazenar os dados de um livro, contendo, codigo, titulo, autor e assunto. Com base
//nessa estrutura, faça o cadastro de livros usando a alocação dinamica de memroia e depois mostre esses dados na tela.
//Por fim, implemente uma funcao que possibilite a busca de um determinado livro pormeio de seu codigo. A busca deve
//retornar 1 caso o livro seja encontrado e 0, caso contrario.
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 50
struct livros {
    int codigo_livro;
    char titulo_livro[MAX];
    char autor_livro[MAX];
    char assunto_livro[MAX];
};
void* preencher_dados (struct livros *dados, int tam) {
    int i;
        for (i =0; i < tam; i++){
            printf("\nEntre com o codigo do livro: \n");
            scanf("%d", &dados[i].codigo_livro);
            setbuf(stdin, NULL);
            printf("\nEntre com o titulo do livro: \n");
            fgets(dados[i].titulo_livro, MAX, stdin);
            printf("\nEntre com o nome do autor: \n");
            fgets(dados[i].autor_livro, MAX, stdin);
            printf("\nEntre com o assunto que o livro apresenta: \n");
            fgets(dados[i].assunto_livro, MAX, stdin);
        }
}
void* exibe_dados(struct livros *dados, int tam){
    int i;
        for (i = 0; i < tam; i++){
            printf("\n__________________________________________\n");
            printf("\nCODIGO DO LIVRO -> %d\n", dados[i].codigo_livro);
            printf("\nTITULO DO LIVRO -> %s\n", dados[i].titulo_livro);
            printf("\nAUTOR DO LIVRO -> %s\n", dados[i].autor_livro);
            printf("\nASSUNTO DO LIVRO -> %s\n", dados[i].assunto_livro);
        }
}
int* busca_livro (struct livros *dados, int tam, int busca){
    int i;
        for (i = 0; i < tam; i++){
           if (busca == dados[i].codigo_livro){
                return 1;
            }
            else{
                return 0;
            }
        }
}
int main (){
    struct livros *dados;
    int busca, tam;
    printf("\nDigite quantos livros voce quer registrar: \n");
    scanf("%d", &tam);
    setbuf(stdin, NULL);

    dados = (struct livros *) calloc (tam, sizeof(struct livros));
    if (dados == NULL){
        printf("\nERRO\n");
        exit(1);
    }
    printf("\n\t-------PREENCHENDO OS DADOS--------\n");
    preencher_dados(dados, tam);
    printf("\n\t---------DADOS DOS LIVROS---------\n");
    exibe_dados(dados, tam);

    printf("\nDigite o codigo do livro que deseja buscar: \n");
    scanf("%d", &busca);
    setbuf(stdin, NULL);
    printf("\n\t>>>>>> RESULTADO DA SUA BUSCA <<<<<<<<");
    int buscar = busca_livro(dados, tam, busca);
    printf("\nCaso a busca resulte 1 temos o livro caso for 0 infelizmente este livro nao se encontra no sistema: %d ", buscar);
    
    return 0;
}
