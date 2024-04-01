/*
** Função : o progrma deve receber um número inteiro positivo n como
entrada e informar ao usuário se n é um número feliz/infeliz .
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdbool.h>

// Funções
int somaQuadradosDigitos(int num) {
    int soma = 0;
    while (num > 0) {
        int digito = num % 10;
        soma += digito * digito;
        num /= 10;
    }
    return soma;
}

bool ehNumeroFeliz(int num) {
    int visitados[1000] = {0}; // Array para armazenar 
    while (num != 1 && !visitados[num]) {
        visitados[num] = 1;
        num = somaQuadradosDigitos(num);
    }
    return num == 1;
}

int main() {
    int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);
    if (ehNumeroFeliz(numero)) {
        printf("%d é um número feliz.\n", numero);
    } else {
        printf("%d é um número infeliz.\n", numero);
    }
    return 0;
}
