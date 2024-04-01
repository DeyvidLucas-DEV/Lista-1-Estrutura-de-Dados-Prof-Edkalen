/*
** Função : o programa deve retornar o resultado das funções fatorial e fatorial_duplo para os números números 2-20, com intuito de montar uma tabela de exemplo incluindo suas diferenças e também escrever a tabela em um arquivo txt.
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>

// Funções:
int fatorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int fatorialDuplo(int n) {
    int resultado = 1;
    for (int i = n; i > 0; i -= 2) {
        resultado *= i;
    }
    return resultado;
}

int main(void) {
    const int TAMANHO_MAX = 20;

    FILE *arquivo = fopen("arquivo.txt", "w"); // Abrir arquivo (desafio)
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    printf("------------TABELA DE EXEMPLO-------------\n");
    printf("N\t| Fatorial\t| Fatorial Duplo\t| Diferença\n");
    printf("-------------------------------------------\n");
    for (int i = 2; i <= TAMANHO_MAX; ++i) {
        int fatorNormal = fatorial(i);
        int fatorDuplo = fatorialDuplo(i);
        int diferenca = fatorNormal - fatorDuplo;
        printf("%d\t| %-10d\t| %-15d\t| %-9d\n", i, fatorNormal, fatorDuplo, diferenca);
        // Escrever no arquivo
        fprintf(arquivo, "%d\t| %-10d\t| %-15d\t| %-9d\n", i, fatorNormal, fatorDuplo, diferenca);
    }
    fclose(arquivo); // Fechar arquivo (desafio)

    return 0;
}eturn 0;
}