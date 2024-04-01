/*
** Função : o progrma deve, usando a
função eh_numero_perfeito, exibir todos os números perfeitos entre 1 e 100000.
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/
#include <stdio.h>

int ehNumeroPerfeito(int n) {
    int somaDivisores = 0;
    
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            somaDivisores += i;
        }
    }
    return somaDivisores == n;
}

int main() {
    printf("Números perfeitos entre 1 e 100.000:\n");
    for (int i = 1; i <= 100000; ++i) {
        if (ehNumeroPerfeito(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
