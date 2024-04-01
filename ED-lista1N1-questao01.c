/*
** Função : O programa calcula a PF crescente e depois faz o mesmo exibindo o resultado da decrescente. É exibido uma tabela de exemplos com um x fixo e um n variante(vice e versa)- ao final essa tabela é salva em um arquivo txt.
** Autor : Deyvid Lucas da Cunha AMorim P3-Ciência da computação (noturno turma A)
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>

int calculaPotenciaFatorialCrescente(int x, int n) {
    int resultado = 1;
    for (int i = 0; i < n; ++i) {
        resultado *= (x + i);
    }
    return resultado;
}


int calculaPotenciaFatorialDecrescente(int x, int n) {
    int resultado = 1;
    for (int i = 0; i < n; ++i) {
        resultado *= (x - i);
    }
    return resultado;
}

int main(void) {
    printf("Calculadora de Potência Fatorial Crescente! Digite um número natural e sua potência (separados por espaço):\n");

    int base, potencia;
    while (1) {
        scanf("%d %d", &base, &potencia);
        if (base >= 0 && potencia >= 0) {
            break;
        } else {
            printf("Você deve inserir dois números naturais! Tente novamente:\n");
        }
    }

    int crescente = calculaPotenciaFatorialCrescente(base, potencia);
    printf("O resultado da PF crescente é: %d\n\n", crescente);

    printf("Agora a Potência Fatorial Decrescente! Digite um número natural 'x' e sua potência 'n' (separados por espaço):\n");

    while (1) {
        scanf("%d %d", &base, &potencia);
        if (base >= 0 && potencia >= 0) {
            break;
        } else {
            printf("Você deve inserir dois números naturais! Tente novamente:\n");
        }
    }

    int decrescente = calculaPotenciaFatorialDecrescente(base, potencia);
    printf("O resultado da PF decrescente é: %d\n\n", decrescente);


    // Abrir arquivo (desafio)
    FILE *arquivo = fopen("arquivo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    printf("------------TABELA DE EXEMPLO-------------\n");
    printf("Base\t| Potencia\t| Crescente\t| Decrescente\n");
    printf("-------------------------------------------\n");

    // Tabela 
    int baseFixa = 2; 
    for (int potencia = 2; potencia <= 10; ++potencia) {
        int crescente = calculaPotenciaFatorialCrescente(baseFixa, potencia);
        int decrescente = calculaPotenciaFatorialDecrescente(baseFixa, potencia);
        printf("%d\t| %d\t\t| %d\t\t| %d\n", baseFixa, potencia, crescente, decrescente);
        fprintf(arquivo, "%d\t| %d\t\t| %d\t\t| %d\n", baseFixa, potencia, crescente, decrescente); // Escreve no arquivo
    }
    printf("===========================================\n");
    int potenciaFixa = 4; 
    for (int base = 2; base <= 10; ++base) {
        int crescente = calculaPotenciaFatorialCrescente(base, potenciaFixa);
        int decrescente = calculaPotenciaFatorialDecrescente(base, potenciaFixa);
        printf("%d\t| %d\t\t| %d\t\t| %d\n", base, potenciaFixa, crescente, decrescente);
        fprintf(arquivo, "%d\t| %d\t\t| %d\t\t| %d\n", base, potenciaFixa, crescente, decrescente);
    }
    fclose(arquivo);
    printf("\nA tabela exemplo foi salva no arquivo texto gerado!\n");

    return 0;
}