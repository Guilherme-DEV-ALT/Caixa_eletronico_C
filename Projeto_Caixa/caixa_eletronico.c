#include <stdio.h>

int main(void)
{
    int saldo = 600, valorSaque, restante;
    int notas100, notas50, notas20, notas10, notas5, notas2, moedas1;
    int leitura, caractere, entradaValida, saqueValido = 0;

    printf("Saldo disponivel: R$%02d,00\n", saldo);

    // Repete a leitura ate receber um saque valido.
    while (saqueValido == 0) {
        printf("Digite o valor do saque em reais inteiros: ");
        // Limita a leitura para evitar numeros fora do alcance de int.
        leitura = scanf("%9d", &valorSaque);
        if (leitura == EOF) {
            printf("\nEntrada encerrada. Nenhum saque realizado.\n");
            return 0;
        }

        entradaValida = (leitura == 1);
        // Limpa a linha e rejeita letras, decimais ou numeros extras.
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
            if (caractere != ' ' && caractere != '\t' && caractere != '\r') {
                entradaValida = 0;
            }
        }

        if (entradaValida == 0) {
            printf("Entrada invalida. Digite apenas um valor inteiro.\n");
        } else if (valorSaque <= 0) {
            printf("Valor de saque invalido. Informe um valor maior que zero.\n");
        } else if (valorSaque > saldo) {
            printf("Saldo insuficiente. Informe um valor ate R$%02d,00.\n", saldo);
        } else {
            saqueValido = 1; // Libera o calculo somente depois da validacao.
        }
    } // Em caso de erro, solicita outro valor.

    // Com moedas de R$1, todo valor inteiro positivo pode ser distribuido.
    restante = valorSaque;
    // Divisao inteira calcula a quantidade; modulo calcula o restante.
    notas100 = restante / 100;
    restante = restante % 100;

    notas50 = restante / 50;
    restante = restante % 50;

    notas20 = restante / 20;
    restante = restante % 20;

    notas10 = restante / 10;
    restante = restante % 10;

    notas5 = restante / 5;
    restante = restante % 5;

    notas2 = restante / 2;
    restante = restante % 2;
    moedas1 = restante;

    printf("Saque realizado: R$%02d,00\n", valorSaque);
    printf("Notas e moedas entregues:\n");
    // Cada bloco entre chaves pertence ao seu if; exibe apenas quantidades positivas.
    if (notas100 > 0) {
        printf("%d nota(s) de R$100,00\n", notas100);
    }
    if (notas50 > 0) {
        printf("%d nota(s) de R$50,00\n", notas50);
    }
    if (notas20 > 0) {
        printf("%d nota(s) de R$20,00\n", notas20);
    }
    if (notas10 > 0) {
        printf("%d nota(s) de R$10,00\n", notas10);
    }
    if (notas5 > 0) {
        printf("%d nota(s) de R$05,00\n", notas5);
    }
    if (notas2 > 0) {
        printf("%d nota(s) de R$02,00\n", notas2);
    }
    if (moedas1 > 0) {
        printf("%d moeda(s) de R$01,00\n", moedas1);
    }

    return 0;
}

