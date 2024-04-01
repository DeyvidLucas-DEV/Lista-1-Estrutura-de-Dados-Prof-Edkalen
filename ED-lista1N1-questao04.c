/*
** Função : o programa deve receber um número e dizer se ele é automórfico ou não. Em seguida, o programa deve pedir um limite n para o usuário e imprimir todos os números automórficos até o limite n.
** Autor : Deyvid Lucas da Cunha Amorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funções

int ehNumeroAutomorfico(int num) {
    int quadrado = num * num;
    int temp = num; 
    int numDigitos = 0;
    while (temp > 0) {
        numDigitos++; 
        temp /= 10;
    }
    int divisor = pow(10, numDigitos);
    return quadrado % divisor == num; 
}

int* verificarNumerosAutomorficos(int limiteSuperior, int* numAutomorficosEncontrados) {
    int* automorficos = malloc(limiteSuperior * sizeof(int)); 
    if (automorficos == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    *numAutomorficosEncontrados = 0; 
    for (int i = 2; i <= limiteSuperior; i++) {
        if (ehNumeroAutomorfico(i)) {
            automorficos[*numAutomorficosEncontrados] = i;
            (*numAutomorficosEncontrados)++;
        }
    }

    return automorficos;
}

int main() {
    int numeroVerificar;
    printf("Digite um número para verificar se é automórfico: ");
    scanf("%d", &numeroVerificar);

    if (ehNumeroAutomorfico(numeroVerificar)) {
        printf("É automórfico\n");
    } else {
        printf("Não é automórfico\n");
    }

    int limiteSuperior;
    printf("Digite um limite superior para verificar os números automórficos (limite <= 1000): ");
    scanf("%d", &limiteSuperior);

    if (limiteSuperior <= 0 || limiteSuperior > 1000) {
        printf("Limite inválido. O limite deve estar entre 1 e 1000.\n");
        return 1;
    }

    int numAutomorficosEncontrados;
    int* automorficos = verificarNumerosAutomorficos(limiteSuperior, &numAutomorficosEncontrados);

    printf("Números automórficos entre 2 e %d:\n", limiteSuperior);
    for (int i = 0; i < numAutomorficosEncontrados; i++) {
        printf("%d ", automorficos[i]);
    }
    printf("\n");

    free(automorficos); 

    return 0;
}
