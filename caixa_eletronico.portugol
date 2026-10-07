programa
{
    inclua biblioteca Tipos --> tipos
    inclua biblioteca Texto --> texto

    funcao inicio()
    {
        inteiro saldo = 600, valorSaque = 0, restante
        inteiro notas100, notas50, notas20, notas10, notas5, notas2, moedas1
        cadeia entrada
        logico saqueValido = falso

        escreva("Saldo disponivel: R$", saldo, ",00\n")
        // Solicita outro valor sempre que a entrada ou o saque for invalido.
        enquanto (nao saqueValido) {
            escreva("Digite o valor do saque em reais inteiros: ")
            leia(entrada)
            // Valida o texto antes de converter, evitando erro de execucao.
            se (texto.numero_caracteres(entrada) > 9 ou nao tipos.cadeia_e_inteiro(entrada, 10)) {
                escreva("Entrada invalida. Digite apenas um valor inteiro.\n")
            }
            senao {
                valorSaque = tipos.cadeia_para_inteiro(entrada, 10)
                se (valorSaque <= 0) {
                    escreva("Valor de saque invalido. Informe um valor maior que zero.\n")
                }
                senao se (valorSaque > saldo) {
                    escreva("Saldo insuficiente. Informe um valor ate R$", saldo, ",00\n")
                }
                senao {
                    saqueValido = verdadeiro
                }
            }
        } // O calculo comeca somente depois de validar o saque.

        // Com moedas de R$1, todo valor inteiro positivo pode ser distribuido.
        restante = valorSaque
        // Divisao inteira calcula a quantidade; modulo calcula o restante.
        notas100 = restante / 100
        restante = restante % 100

        notas50 = restante / 50
        restante = restante % 50

        notas20 = restante / 20
        restante = restante % 20

        notas10 = restante / 10
        restante = restante % 10

        notas5 = restante / 5
        restante = restante % 5

        notas2 = restante / 2
        restante = restante % 2
        moedas1 = restante

        escreva("Saque realizado: R$")
        se (valorSaque < 10) {
            escreva("0")
        }
        escreva(valorSaque, ",00\nNotas e moedas entregues:\n")
        // Exibe somente quantidades positivas.
        se (notas100 > 0) {
            escreva(notas100, " nota(s) de R$100,00\n")
        }
        se (notas50 > 0) {
            escreva(notas50, " nota(s) de R$50,00\n")
        }
        se (notas20 > 0) {
            escreva(notas20, " nota(s) de R$20,00\n")
        }
        se (notas10 > 0) {
            escreva(notas10, " nota(s) de R$10,00\n")
        }
        se (notas5 > 0) {
            escreva(notas5, " nota(s) de R$05,00\n")
        }
        se (notas2 > 0) {
            escreva(notas2, " nota(s) de R$02,00\n")
        }
        se (moedas1 > 0) {
            escreva(moedas1, " moeda(s) de R$01,00\n")
        }
    }
}
