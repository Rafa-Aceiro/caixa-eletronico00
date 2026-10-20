/*
 * COMPONENTE CURRICULAR: Algoritmos e Pensamento Computacional (APC) - UNICID
 * ATIVIDADE 2 (A2.2): SISTEMA DE CAIXA ELETRONICO (ATM)
 * Versao em C do algoritmo originalmente escrito em Portugol.
 *
 * Compilar: gcc atm.c -o atm
 * Executar: ./atm
 */

#include <stdio.h>

int main(void) {

    /* ---------------- DECLARACAO DE VARIAVEIS ---------------- */
    int saldo = 1000;          /* saldo disponivel na conta */
    int valorSaque;            /* valor solicitado pelo usuario */
    int valorRestante;         /* valor ainda nao distribuido em notas */

    int qtdNotas100, qtdNotas50, qtdNotas20, qtdNotas10;   /* contadores de notas */
    int qtdNotas5, qtdNotas2, qtdMoedas1;                  /* contadores de notas/moeda menores */

    /* ---------------- ALGORITMO ---------------- */

    /* 1) Entrada de dados */
    printf("=== CAIXA ELETRONICO (ATM) ===\n");
    printf("Saldo disponivel: R$ %d\n", saldo);
    printf("Digite o valor do saque: ");
    if (scanf("%d", &valorSaque) != 1) {
        printf("ERRO: entrada invalida. Digite um numero inteiro.\n");
        return 1;
    }

    /* 2) Validacao 1: valor precisa ser positivo */
    if (valorSaque <= 0) {
        printf("ERRO: valor invalido. Digite um valor maior que zero.\n");
    } else {

        /* 3) Validacao 2: saldo suficiente */
        if (valorSaque > saldo) {
            printf("ERRO: saldo insuficiente. Saque maximo permitido: R$ %d\n", saldo);
        } else {

            /* 4) Calculo encadeado: divisao inteira (/) da a quantidade
             *    e o modulo (%) da o que sobrou para a proxima cedula */
            valorRestante = valorSaque;

            qtdNotas100 = valorRestante / 100;
            valorRestante = valorRestante % 100;

            qtdNotas50 = valorRestante / 50;
            valorRestante = valorRestante % 50;

            qtdNotas20 = valorRestante / 20;
            valorRestante = valorRestante % 20;

            qtdNotas10 = valorRestante / 10;
            valorRestante = valorRestante % 10;

            qtdNotas5 = valorRestante / 5;
            valorRestante = valorRestante % 5;

            qtdNotas2 = valorRestante / 2;
            valorRestante = valorRestante % 2;

            qtdMoedas1 = valorRestante / 1;
            valorRestante = valorRestante % 1;

            /* 5) Verificacao de consistencia: o resto final deve ser zero */
            if (valorRestante == 0) {

                /* 6) Exibicao: apenas cedulas/moedas com quantidade maior que zero */
                printf("Saque de R$ %d autorizado.\n", valorSaque);
                printf("Notas entregues:\n");

                if (qtdNotas100 > 0) {
                    printf("%d nota(s) de 100\n", qtdNotas100);
                }
                if (qtdNotas50 > 0) {
                    printf("%d nota(s) de 50\n", qtdNotas50);
                }
                if (qtdNotas20 > 0) {
                    printf("%d nota(s) de 20\n", qtdNotas20);
                }
                if (qtdNotas10 > 0) {
                    printf("%d nota(s) de 10\n", qtdNotas10);
                }
                if (qtdNotas5 > 0) {
                    printf("%d nota(s) de 5\n", qtdNotas5);
                }
                if (qtdNotas2 > 0) {
                    printf("%d nota(s) de 2\n", qtdNotas2);
                }
                if (qtdMoedas1 > 0) {
                    printf("%d moeda(s) de 1\n", qtdMoedas1);
                }

            } else {
                printf("ERRO: nao foi possivel compor o valor com as cedulas disponiveis.\n");
            }
        }
    }

    return 0;
}
