//Implemente um programa que leia os códigos de matrícula dos alunos de duas disciplinas (prog I e prog II) e mostre os códigos de matrículas 
//dos alunos que estão cursando ambas as disciplinas. O número de alunos de ambas as turmas é informado pelo usuário. O espaço de memoria 
//necessário para armazenar os códigos das matrículas nas disciplinas deve ser criado dinamicamente de acordo com esse número; 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void* preencher_vetor(int prog[], int num){
    int i;
        for (i =0; i < num; i++){
            printf("\nPreencha esse vetor com as matriculas ( %d ): \n", i);
            scanf("%d", &prog[i]);
            setbuf(stdin, NULL);
        }
}
void* comparando_turmas(int *progI, int *progII, int num, int num2){
    int i;
        for (i = 0; i < num; i++){
            for (int j = 0; j < num2; j++){
                if (progI[i] == progII[j]){
                    printf ("\nMatricula: %d\n", progII[j]);
                }
            }
        }
}
int main (){
    int num, num2;
    
    printf("\nDigite o numero de alunos da turma de prog I: \n");
    scanf("%d", &num);
    setbuf(stdin, NULL);

    int *progI, *progII;

    printf("\t\n....Preenchendo turma prog I....\n");
    progI = (int *) malloc (num * sizeof(int));
    preencher_vetor (progI, num);

    printf("\t\n....Preenchendo turma prog II....\n");
    printf("\nDigite o numero de alunos da turma de prog II: \n");
    scanf("%d", &num2);
    setbuf(stdin, NULL);
    progII = (int *) malloc (num2 * sizeof(int));
    preencher_vetor (progII, num2);

    printf("\n\t....Os alunos que frequetam ambas as turmas....\n");
    comparando_turmas (progI, progII, num, num2);

    return 0;
}

   