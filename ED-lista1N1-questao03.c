/*
** Função : receber dois números, exibir seus divisores próprios e dizer se são amigáveis. o programa também deve buscar pares de números amigáveis até um valor máximo informado pelo usuário.
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
int num1, num2;

void saoAmigaveis(int num1, int num2) {
  int somaDivisores1 = 0, somaDivisores2 = 0;

  // Exibir divisores de num1
  printf("Divisores de %d: ", num1);
  for (int i = 1; i < num1; i++) {
      if (num1 % i == 0) {
          printf("%d ", i);
          somaDivisores1 += i;
      }
  }
  printf("\nSoma dos divisores de %d: %d\n", num1, somaDivisores1);
  printf("Divisores de %d: ", num2);
  for (int i = 1; i < num2; i++) {
      if (num2 % i == 0) {
          printf("%d ", i);
          somaDivisores2 += i;
      }
  }
  printf("\nSoma dos divisores de %d: %d\n", num2, somaDivisores2);
   if (somaDivisores1 == num2 && somaDivisores2 == num1) {
          printf("%d e %d são números amigáveis!!!\n", num1, num2);
      } else {
          printf("%d e %d NÃO são números amigáveis!!!\n", num1, num2);
      }
  }
void verificarPares(int n) {
    printf("Pares de números amigáveis até %d:\n", n);
  for (int i = 1; i <= n; i++) {
      int somaDivisores1 = 0;
      for (int k = 1; k < i; k++) {
          if (i % k == 0) {
              somaDivisores1 += k;
          }
      }
      for (int j = i + 1; j <= n; j++) {
          int somaDivisores2 = 0;
          for (int k = 1; k < j; k++) {
              if (j % k == 0) {
                  somaDivisores2 += k;
              }
          }
          if (somaDivisores1 == j && somaDivisores2 == i) {
              printf("%d e %d\n", i, j);
          }
      }
  }
}

int main(void) {

  printf("Digite dois números para verificar se são amigáveis: ");
  scanf("%d %d", &num1, &num2);
  saoAmigaveis(num1, num2);

  int valor;
  printf("\nDigite um valor n para verificar pares de números amigáveis até esse valor: ");
  scanf("%d", &valor);
  verificarPares(valor);

  return 0;
}