#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Declara��o da struct aluno e definindo como um novo tipo no meu c�digo
typedef struct {
    int matricula;
    char nome[20];
    float notas[3];
} aluno;

// Definindo as assinaturas das fun��es utilizadas no c�digo
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

    // Loop principal para manter o menu em execu��o at� que o usu�rio decida sair
    while(1==1){
        printf("\nDigite o n�mero da quest�o que deseja executar\n Quest�o 1\n Quest�o 1\n Quest�o 2\n Quest�o 3\n Quest�o 4\n Sair digite 0\n");
        int escolha;
        scanf("%d",&escolha);

        // Estrutura de controle switch para executar a fun��o correspondente � escolha do usu�rio
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
                return 0; // Encerra o programa se o usu�rio escolher sair
            default:
                printf("Quest�o inv�lida");
        }
    }
}

// Implementa��o das fun��es usadas no c�digo

// Fun��o para resolver a primeira quest�o
void questao1() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Valor inv�lido");
        return; // Retorna � fun��o main se o tamanho do vetor for inv�lido
    }
    int vet[n];
    printf("Digite os elementos do vetor\n");

    // Preenchimento do vetor pelo usu�rio
    for (int i = 0; i < n; i++) {
        printf("Informe o valor n�mero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // Contagem de ocorr�ncias de cada n�mero no vetor e impress�o do resultado
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (vet[i] == vet[j]) {
                count++;
            }
        }
        printf("N�mero %d, quantidade: %d\n", vet[i], count);
    }
    return;
}

// Fun��o para resolver a segunda quest�o
void questao2() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Valor inv�lido");
        return; // Retorna � fun��o main se o tamanho do vetor for inv�lido
    }
    int vet[n];
    printf("Digite os elementos do vetor\n");

    // Preenchimento do vetor pelo usu�rio
    for (int i = 0; i < n; i++) {
        printf("Informe o valor n�mero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // C�lculo da maior diferen�a absoluta entre elementos consecutivos
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
    printf("A maior altura de um degrau na sequ�ncia � %d", maior);
    return;
}

// Fun��o para resolver a terceira quest�o
void questao3() {
    int n;
    printf("Digite a raz�o da matriz: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Valor inv�lido");
        return; // Retorna � fun��o main se a raz�o da matriz for inv�lida
    }

    int mat[n][n];
    printf("Digite os elementos da matriz\n");

    int media[n];
    for (int i = 0; i < n; i++) {
        media[i] = 0;
        for (int j = 0; j < n; j++) {
            printf("Informe o valor na posi��o (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
            media[i] += mat[i][j];
        }
    }

    // C�lculo e impress�o da m�dia de cada linha da matriz
    for (int i = 0; i < n; i++) {
        printf("A m�dia da linha %d � %d\n", i + 1, media[i] / n);
    }
}

// Fun��o para resolver a quarta quest�o
void questao4() {
    // Array de alunos com suas respectivas matr�culas, nomes e notas
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

    // Impress�o dos alunos
    printf("Alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d� aluno [Nome: %s][Matr�cula: %d]\n", i + 1, alunos[i].nome, alunos[i].matricula);
    }

    // Menu para escolha da a��o
    printf("\nQual a��o deseja realizar?\n");
    printf("1- Calcular m�dia de um aluno\n");
    printf("2- Quantidade de alunos com m�dia maior ou igual a 7\n");
    printf("3- Ordenar alunos por m�dia crescente e mostrar\n");
    printf("4- Alocar mem�ria para matr�culas dos alunos aprovados\n");

    int opcao;
    scanf("%d", &opcao);

    // Estrutura de controle switch para executar a��o de acordo com a escolha do usu�rio
    switch (opcao) {
        case 1:
            printf("Digite o numero do aluno: ");
            int numero;
            scanf("%d", &numero);
            printf("%.2f",retornaMedia(alunos[numero-1]));
            break;
        case 2:
            printf("Quantidade de alunos com m�dia maior ou igual a 7: %d\n", quantidadeAprovados(alunos,tamanho));
            break;
        case 3:
            ordena(alunos, tamanho);
            break;
        case 4:
            matriculasAprovados(alunos, tamanho);
            break;
        default:
            printf("Op��o inv�lida.\n");
    }
}

// Fun��o para calcular a m�dia de um aluno
float retornaMedia(aluno aluno) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += aluno.notas[i];
    }
    return soma / 3;
}

// Fun��o para contar a quantidade de alunos aprovados
int quantidadeAprovados(aluno *turma, int tamanho) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (retornaMedia(turma[i]) >= 7) {
            contador++;
        }
    }
    return contador;
}

// Fun��o para ordenar alunos por m�dia crescente e mostrar
void ordena(aluno *turma, int tamanho) {
    // Algoritmo de ordena��o bubble sort
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (retornaMedia(turma[j]) > retornaMedia(turma[j + 1])) {
                aluno aux = turma[j];
                turma[j] = turma[j + 1];
                turma[j + 1] = aux;
            }
        }
    }

    // Impress�o dos alunos ordenados por m�dia
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s\n Media: %f\n Matr�cula: %d\n", turma[i].nome,
               retornaMedia(turma[i]), turma[i].matricula);
    }
}

// Fun��o para alocar mem�ria para matr�culas dos alunos aprovados
int *matriculasAprovados(aluno *turma, int tamanho) {
    // Contagem da quantidade de alunos aprovados
    int *tamanhoVetor;
    *tamanhoVetor = quantidadeAprovados(turma, tamanho);

    // Aloca��o de mem�ria para armazenar as matr�culas dos alunos aprovados
    int *matriculas = (int *)malloc((*tamanhoVetor + 1) * sizeof(int));

    // Verifica��o de erro na aloca��o de mem�ria
    if (matriculas == NULL) {
        printf("Erro\n");
        return NULL;
    }

    // Preenchimento do array de matr�culas com as matr�culas dos alunos aprovados
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
