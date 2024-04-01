/*
** Função : o progrma deve mostrar todos os números de Armstrong entre 1 e 100, com ajuda da função eh_numero_armstrong.
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Funções
int contarDigitos(int num) {
    int contagem = 0;
    while (num != 0) {
        num /= 10;
        contagem++;
    }
    return contagem;
}

bool ehNumeroArmstrong(int num) {
    int original = num;
    int soma = 0;
    int nDigitos = contarDigitos(num);
    while (num != 0) {
        int digito = num % 10;
        soma += pow(digito, nDigitos);
        num /= 10;
    }
    return soma == original;
}

int main() {
    printf("Números de Armstrong entre 1 e 100:\n");
    for (int i = 1; i <= 100; i++) {
        if (ehNumeroArmstrong(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
