//Defina uma estrtura aluno contendo os campos nome, sobrenome, nota. O programa deve ler esses dados e armazenar dinamicamente na memória.
//Depois, implemente uma função para imprimir o nome e sobrenome do aluno que possui maior nota. o protótipo da função é seguinte:
//void aluno_maior_nota (struct aluno *vet_aluno, int tam){...};
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aluno {
    char nome[50];
    char sobrenome[50];
    float nota;
};
void aluno_maior_nota (struct aluno *vet_alunos, int tam){
    int i, posicao; 
    float maior =0; 
        for ( i= 0; i < tam; i++){
            if (vet_alunos[i].nota < maior){
                maior = vet_alunos[i].nota;
                posicao = i;
            }
        }
    printf("\n\tAluno com  a maior nota\n");
    printf("\t -> %s\n", vet_alunos[posicao].nome);

}

int main (){
    struct aluno *al;
    int n, i;
    printf("\nEntre com o numero de alunos a cadastrar: \n");
    scanf("%d", &n);

    al = (struct aluno *) malloc (n * sizeof(struct aluno));
        if ( al == NULL){
            printf("\nERRO\n");
            exit(1);
        }
        for (i = 0; i < n; i++){
            printf("\nEntre com o nome do aluno: \n");
            fgets(al[i].nome, 50, stdin);
            printf("\nEntre com o sobrenome do aluno %s", al[i].nome);
            fgets(al[i].sobrenome, 50, stdin);
            printf("\nNotas: \n");
            scanf("%f", &al[i].nota);
            setbuf(stdin, NULL);
        }

        aluno_maior_nota(al, n);
    return 0;
}