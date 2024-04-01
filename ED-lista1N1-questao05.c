#include <stdio.h>
/*
** Função : o programa deve receber um número inteiro positivo n como
** entrada e calcular a soma dos fatoriais inversos até o termo n.
** Autor : Deyvid Lucas da Cunha Amorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/
// Funções:

int fatorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; ++i) {
        resultado *= i;
    }
    return resultado;
}

double somaFatoriaisInversos(int n) {
    double soma = 0.0;
    for (int i = 1; i <= n; ++i) {
        soma += 1.0 / fatorial(i);
    }
    return soma;
}

int main() {
    int n;
    printf("Digite um número inteiro positivo n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O número deve ser positivo.\n");
        return 1;
    }

    double resultado = somaFatoriaisInversos(n);
    printf("A soma dos fatoriais inversos de 1 a %d é: %.6lf\n", n, resultado);

    return 0;
}
