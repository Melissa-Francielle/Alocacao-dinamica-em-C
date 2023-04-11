#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct endereco {
    char rua[50];
    char bairro[50];
};
struct loja {
    char nome[50];
    struct endereco ender;
    char telefone [50];
    float preco;
};
void* preenche_dados (struct loja *lj, int n){
    int i;
        for (i = 0; i < n; i++){
            printf("\nCADASTRO DA LOJA (%d)\n", i);
            printf("\nDigite o nome da loja: \n");
            fgets(lj[i].nome, 50, stdin);
            printf("\nDigite o endereco: \n");
            printf("\nRua: \n");
            fgets(lj[i].ender.rua, 50, stdin);
            printf("\nBairro: \n");
            fgets(lj[i].ender.bairro, 50, stdin);
            printf("\nDigite o telefone: \n");
            fgets(lj[i].telefone, 50, stdin);
            printf("\nDigite o preco do produto : \n");
            scanf("%f", &lj[i].preco);
            setbuf(stdin, NULL);
            
        }
}
void* exibe_dados (struct loja *lj, int n){
    int i;
        for (i = 0; i < n; i++){
            printf("\n__________________________________\n");
            printf("\nLOJA (%d)", i);
            printf("\nNOME: %s\n", lj[i].nome);
            printf("\nRUA: %s\n", lj[i].ender.rua);
            printf("\nBAIRRO: %s\n", lj[i].ender.bairro);
            printf("\nTELEFONE: %s\n", lj[i].telefone);
            printf("\nPreco do produto: %.2f\n", lj[i].preco);
            
        }
}
void menor_preco (struct loja *lj, int n, float media){
        for (int i = 0; i < n; i++){
            if(lj[i].preco < media){
                printf("\nO nome da loja com menor preco: %s\nEndereco\nRua: %s\nBairro: %s\nTelefone: %s\n", lj[i].nome, lj[i].ender.rua, lj[i].ender.bairro, lj[i].telefone);
            }
        }
}
int main (){
    struct loja *lj;
    int n;
    
    printf("\nDigite o numero de registros: \n");
    scanf("%d", &n);
    setbuf(stdin, NULL);
    
    lj = (struct loja *) malloc (n * sizeof(struct loja));
    
    printf("\n\t....PREENCHENDO DADOS....\n");
    preenche_dados(lj, n);
   
    printf("\n\t....EXIBE DADOS....\n");
    exibe_dados(lj, n);

    printf("\n\t....MEDIA GERAL....\n");
    float soma= 0;
        for(int i = 0; i < n; i++){
            soma += lj[i].preco;
        }
    float media = soma / n;
    printf("\nMEDIA GERAL = %.2f\n", media);

    printf("\n\t....MENOR PRECO....\n");
    menor_preco (lj, n, media);

    return 0;
}