# Caixa eletronico - Atividade 2

Projeto introdutorio em C, seguindo o roteiro escolhido da atividade.
Saldo inicial: R$600,00. O programa permite corrigir entradas invalidas e
encerra depois de realizar um unico saque valido.

## Arquivos

- `caixa_eletronico.c`: codigo principal, usando apenas `stdio.h`.
- `caixa_eletronico.por`: algoritmo para o Portugol WebStudio.
- `portugol.txt`: copia identica do arquivo `.por`.
- `caixa_eletronico.exe`: executavel gerado a partir do C.

## Compilar e executar

Salve os arquivos antes de compilar. No PowerShell, na pasta `ling_C`:

```powershell
gcc -std=c11 -Wall -Wextra Projeto_Caixa/caixa_eletronico.c -o Projeto_Caixa/caixa_eletronico.exe
```

Se a compilacao terminar sem erros, execute:

```powershell
.\Projeto_Caixa\caixa_eletronico.exe
```

Digite um inteiro, como `123`, e pressione Enter. Nao inclua `R$` nem centavos.
Se houver erro, informe outro valor quando solicitado. Para outro saque depois
de uma operacao concluida, execute novamente o programa.

## Validacao e calculo

- Entrada com letras, decimais ou numeros extras: mensagem de entrada invalida.
- Zero ou valor negativo: mensagem de valor invalido.
- Valor acima de 600: saldo insuficiente.
- Em todos esses casos, a leitura se repete sem realizar o saque.
- Valor positivo ate 600: distribui notas de 100, 50, 20, 10, 5 e 2 e moedas de 1.
- Somente quantidades positivas aparecem, com valores no formato `R$00,00`.

O C usa `while` para repetir a leitura e `getchar` para limpar e verificar o
restante da linha. A leitura com `%9d` limita o numero a nove caracteres para
evitar estouro de inteiro. Fim da entrada encerra o C sem realizar o saque.

O Portugol le uma cadeia e utiliza as bibliotecas Tipos e Texto para validar
o formato e limitar a nove caracteres antes de converter para inteiro.
A distribuicao e as regras de saque sao iguais nos dois algoritmos.
O C permite espacos externos ao numero; no Portugol, digite somente o numero.
O Portugol ainda precisa ser executado no WebStudio para validacao nesse ambiente.

## Testes

| Entrada | Resultado |
| --- | --- |
| 50 | 1 nota de R$50,00 |
| 95 | 1 nota de R$50,00, 2 de R$20,00 e 1 de R$05,00 |
| 123 | 1 nota de R$100,00, 1 de R$20,00, 1 de R$02,00 e 1 moeda de R$01,00 |
| 1005, depois 50 | Saldo insuficiente, nova leitura e saque de R$50,00 |
| abc, 12,50, 0, -2, depois 123 | Erros sucessivos, nova leitura e saque de R$123,00 |

O roteiro escolhido inclui R$2 e R$1, portanto aceita 123. A restricao de
multiplos de 5 do outro PDF nao foi adotada.

## Entrega

O roteiro exige codigo C, arquivo Portugol e relatorio PDF com evidencias.
O relatorio PDF ainda nao esta nesta pasta. Para entregar, utilize os nomes
`GRUPO_NN_codigo.c`, `GRUPO_NN_portugol.por` e `GRUPO_NN_testes.pdf`,
substituindo NN pelo numero do grupo.

Se o Windows informar um bloqueio de Controle de Aplicativo, solicite a
autorizacao do executavel ao administrador do computador.
