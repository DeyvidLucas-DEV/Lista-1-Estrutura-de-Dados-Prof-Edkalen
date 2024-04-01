/*
** Função : o progrma deve receber um número inteiro positivo n como
entrada e dizer se esse número é carmichael. o programa também deve listar os números carmichael até o limite escolhido pelo usuário .
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/


#include <stdio.h>
#include <stdbool.h>
// Funções
int mdc(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para calcular a potência modular
int modPow(int a, int b, int m) {
    if (b == 0) {
        return 1;
    }
    int temp = modPow(a, b / 2, m);
    if (b % 2 == 0) {
        return (temp * temp) % m;
    } else {
        return ((temp * temp) % m * a) % m;
    }
}

// Função para verificar se um número é Carmichael
bool ehNumeroCarmichael(int n) {
    if (n == 2) {
        for (int a = 3; a < n; a += 2) {
            if (modPow(a, 2, n) != 1) {
                return false;
            }
        }
        return true;
    }

    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    for (int a = 2; a < n; a++) {
        if (mdc(a, n) == 1) {
            if (modPow(a, n, n) != 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int numero, limite;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);
    bool ehCarmichael = ehNumeroCarmichael(numero);

    // Imprimir uma mensagem com base no resultado
    if (ehCarmichael) {
        printf("%d é um número de Carmichael\n", numero);
    } else {
        printf("%d não é um número de Carmichael\n", numero);
    }


    printf("Digite um limite inteiro positivo: ");
    scanf("%d", &limite);
    printf("Números de Carmichael até %d: ", limite);
    for (int i = 2; i <= limite; i++) {
        if (ehNumeroCarmichael(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
