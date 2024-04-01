/*
** Função : apresentar a sequência de fibonacci para o limite max estabelecido.
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>

// Função para calcular a sequência de Fibonacci até o valor máximo especificado
int* fibonacciMax(int max) {
    int* fibonacci = (int*)malloc(2 * sizeof(int)); // Aloca o array inicial com tamanho 2
    if (fibonacci == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    fibonacci[0] = 0; // Primeiro número da sequência
    fibonacci[1] = 1; // Segundo número da sequência
    int tamanho = 2; // Tamanho inicial do array
    int indice = 2; // Índice do próximo número a ser calculado

    while (1) {
        int proximo = fibonacci[indice - 1] + fibonacci[indice - 2]; // Próximo número da sequência
        if (proximo > max) {
            break; // Se ultrapassar o máximo, termina o loop
        }
        
        fibonacci = (int*)realloc(fibonacci, (tamanho + 1) * sizeof(int)); // Realoca o array para incluir o próximo número
        if (fibonacci == NULL) {
            printf("Erro ao realocar memória.\n");
            exit(1);
        }

        fibonacci[indice++] = proximo; // Adiciona o próximo número ao array
        tamanho++; // Aumenta o tamanho do array
    }

    return fibonacci; // Retorna a sequência de Fibonacci
}

int main() {
    int maximo;
    printf("Digite o número máximo para a sequência de Fibonacci: ");
    scanf("%d", &maximo);

    int* fibonacci = fibonacciMax(maximo);

    printf("Sequência de Fibonacci até %d:\n", maximo);
    printf("{ ");
    for (int i = 0; fibonacci[i] <= maximo; ++i) {
        printf("%d ", fibonacci[i]);
    }
    printf("}\n");

    free(fibonacci); // Libera a memória alocada para o array

    return 0;
}
