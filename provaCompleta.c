#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Declaração da struct aluno e definindo como um novo tipo no meu código
typedef struct {
    int matricula;
    char nome[20];
    float notas[3];
} aluno;

// Definindo as assinaturas das funções utilizadas no código
void questao1();
void questao2();
void questao3();
void questao4();
float retornaMedia(aluno aluno);
int quantidadeAprovados(aluno *turma, int tamanho);
void ordena(aluno *turma, int tamanho);
int *matriculasAprovados(aluno *turma, int tamanho);

int main(){
    setlocale(LC_ALL,"");

    // Loop principal para manter o menu em execução até que o usuário decida sair
    while(1==1){
        printf("\nDigite o número da questão que deseja executar\n Questão 1\n Questão 1\n Questão 2\n Questão 3\n Questão 4\n Sair digite 0\n");
        int escolha;
        scanf("%d",&escolha);

        // Estrutura de controle switch para executar a função correspondente à escolha do usuário
        switch(escolha){
            case 1:
                questao1();
                break;
            case 2:
                questao2();
                break;
            case 3:
                questao3();
                break;
            case 4:
                questao4();
                break;
            case 0:
                return 0; // Encerra o programa se o usuário escolher sair
            default:
                printf("Questão inválida");
        }
    }
}

// Implementação das funções usadas no código

// Função para resolver a primeira questão
void questao1() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Valor inválido");
        return; // Retorna à função main se o tamanho do vetor for inválido
    }
    int vet[n];
    printf("Digite os elementos do vetor\n");

    // Preenchimento do vetor pelo usuário
    for (int i = 0; i < n; i++) {
        printf("Informe o valor número %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // Contagem de ocorrências de cada número no vetor e impressão do resultado
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (vet[i] == vet[j]) {
                count++;
            }
        }
        printf("Número %d, quantidade: %d\n", vet[i], count);
    }
    return;
}

// Função para resolver a segunda questão
void questao2() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Valor inválido");
        return; // Retorna à função main se o tamanho do vetor for inválido
    }
    int vet[n];
    printf("Digite os elementos do vetor\n");

    // Preenchimento do vetor pelo usuário
    for (int i = 0; i < n; i++) {
        printf("Informe o valor número %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // Cálculo da maior diferença absoluta entre elementos consecutivos
    int maior = 0;
    for (int i = 0; i < n - 1; i++) {
        int dif = vet[i] - vet[i + 1];
        if (dif < 0) {
            dif *= -1;
        }
        if (dif > maior) {
            maior = dif;
        }
    }
    printf("A maior altura de um degrau na sequência é %d", maior);
    return;
}

// Função para resolver a terceira questão
void questao3() {
    int n;
    printf("Digite a razão da matriz: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Valor inválido");
        return; // Retorna à função main se a razão da matriz for inválida
    }

    int mat[n][n];
    printf("Digite os elementos da matriz\n");

    int media[n];
    for (int i = 0; i < n; i++) {
        media[i] = 0;
        for (int j = 0; j < n; j++) {
            printf("Informe o valor na posição (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
            media[i] += mat[i][j];
        }
    }

    // Cálculo e impressão da média de cada linha da matriz
    for (int i = 0; i < n; i++) {
        printf("A média da linha %d é %d\n", i + 1, media[i] / n);
    }
}

// Função para resolver a quarta questão
void questao4() {
    // Array de alunos com suas respectivas matrículas, nomes e notas
    aluno alunos[] = {
        {61810, "Isabela", {6.0, 6.5, 5.5}},
        {78101, "Rafael", {5.5, 6.0, 6.0}},
        {12125, "Ana", {9.0, 9.0, 8.5}},
        {91965, "Carlos", {8.5, 8.0, 7.5}},
        {20056, "Mariana", {7.5, 7.0, 8.0}},
        {89010, "Luiz", {8.0, 8.5, 8.5}},
        {34562, "Juliana", {9.0, 8.0, 7.0}},
        {62860, "Fernando", {7.0, 8.0, 7.5}},
        {12665, "Thiago", {6.0, 5.0, 5.5}},
        {28856, "Camila", {5.5, 6.0, 5.0}}
    };

    int tamanho = sizeof(alunos) / sizeof(aluno);

    // Impressão dos alunos
    printf("Alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%dº aluno [Nome: %s][Matrícula: %d]\n", i + 1, alunos[i].nome, alunos[i].matricula);
    }

    // Menu para escolha da ação
    printf("\nQual ação deseja realizar?\n");
    printf("1- Calcular média de um aluno\n");
    printf("2- Quantidade de alunos com média maior ou igual a 7\n");
    printf("3- Ordenar alunos por média crescente e mostrar\n");
    printf("4- Alocar memória para matrículas dos alunos aprovados\n");

    int opcao;
    scanf("%d", &opcao);

    // Estrutura de controle switch para executar ação de acordo com a escolha do usuário
    switch (opcao) {
        case 1:
            printf("Digite o numero do aluno: ");
            int numero;
            scanf("%d", &numero);
            printf("%.2f",retornaMedia(alunos[numero-1]));
            break;
        case 2:
            printf("Quantidade de alunos com média maior ou igual a 7: %d\n", quantidadeAprovados(alunos,tamanho));
            break;
        case 3:
            ordena(alunos, tamanho);
            break;
        case 4:
            matriculasAprovados(alunos, tamanho);
            break;
        default:
            printf("Opção inválida.\n");
    }
}

// Função para calcular a média de um aluno
float retornaMedia(aluno aluno) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += aluno.notas[i];
    }
    return soma / 3;
}

// Função para contar a quantidade de alunos aprovados
int quantidadeAprovados(aluno *turma, int tamanho) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (retornaMedia(turma[i]) >= 7) {
            contador++;
        }
    }
    return contador;
}

// Função para ordenar alunos por média crescente e mostrar
void ordena(aluno *turma, int tamanho) {
    // Algoritmo de ordenação bubble sort
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (retornaMedia(turma[j]) > retornaMedia(turma[j + 1])) {
                aluno aux = turma[j];
                turma[j] = turma[j + 1];
                turma[j + 1] = aux;
            }
        }
    }

    // Impressão dos alunos ordenados por média
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s\n Media: %f\n Matrícula: %d\n", turma[i].nome,
               retornaMedia(turma[i]), turma[i].matricula);
    }
}

// Função para alocar memória para matrículas dos alunos aprovados
int *matriculasAprovados(aluno *turma, int tamanho) {
    // Contagem da quantidade de alunos aprovados
    int *tamanhoVetor;
    *tamanhoVetor = quantidadeAprovados(turma, tamanho);

    // Alocação de memória para armazenar as matrículas dos alunos aprovados
    int *matriculas = (int *)malloc((*tamanhoVetor + 1) * sizeof(int));

    // Verificação de erro na alocação de memória
    if (matriculas == NULL) {
        printf("Erro\n");
        return NULL;
    }

    // Preenchimento do array de matrículas com as matrículas dos alunos aprovados
    int indice = 0;
    for (int i = 0; i < tamanho; i++) {
        if (retornaMedia(turma[i]) >= 7) {
            matriculas[indice] = turma[i].matricula;
            indice++;
        }
    }
    matriculas[indice] = -1; // Marcador de fim do array
    return matriculas;
}
