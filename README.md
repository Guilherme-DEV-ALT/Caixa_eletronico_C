# Caixa eletronico - Atividade 2

Projeto introdutorio em C, seguindo o roteiro escolhido da atividade.
Saldo inicial: R$600,00. O programa permite corrigir entradas invalidas,
realizar varios saques e consultar o saldo durante o mesmo atendimento.
Cada saque aprovado desconta do saldo disponivel.

## Arquivos

- `caixa_eletronico.c`: codigo principal, usando apenas `stdio.h`.
- `caixa_eletronico.portugol`: algoritmo para o Portugol WebStudio.
- `caixa_eletronico.exe`: gerado localmente pela compilacao e ignorado pelo Git.

## Compilar e executar

Salve os arquivos antes de compilar. No PowerShell, na pasta `ling_C`:

```powershell
gcc -std=c11 -Wall -Wextra caixa_eletronico.c -o caixa_eletronico.exe
```

Se a compilacao terminar sem erros, execute:

```powershell
.\caixa_eletronico.exe
```

Digite um inteiro, como `123`, e pressione Enter. Nao inclua `R$` nem centavos.
Se houver erro, informe outro valor quando solicitado. Apos o saque, o programa
mostra o saldo atualizado e pergunta se deseja realizar uma nova transacao:

- `1`: consultar saldo, sem alterar o valor disponivel.
- `2`: realizar novo saque, respeitando o saldo restante.
- `3`: sair e encerrar o atendimento.

O menu reaparece apos cada saque ou consulta. Quando o saldo chega a zero,
uma tentativa de novo saque informa saldo insuficiente e retorna ao menu.
O saldo volta a R$600,00 ao iniciar uma nova execucao do programa.

## Validacao e calculo

- Entrada com letras, decimais ou numeros extras: mensagem de entrada invalida.
- Zero ou valor negativo: mensagem de valor invalido.
- Valor acima do saldo atual: saldo insuficiente.
- Em todos esses casos, a leitura se repete sem realizar o saque.
- Valor positivo ate o saldo atual: desconta do saldo e distribui notas de
  100, 50, 20, 10, 5 e 2 e moedas de 1.
- Somente quantidades positivas aparecem nas notas e moedas entregues.
- Opcao de menu invalida: solicita novamente, sem alterar o saldo.

O C usa `while` para repetir a leitura e `getchar` para limpar e verificar o
restante da linha. A leitura com `%9d` limita o numero a nove caracteres para
evitar estouro de inteiro. No uso interativo, a opcao `3` encerra o atendimento.
Se a entrada padrao for fechada externamente, o C tambem encerra, evitando
repeticoes sem possibilidade de receber novos dados.

O Portugol le uma cadeia e utiliza as bibliotecas Tipos e Texto para validar
o formato e limitar a nove caracteres antes de converter para inteiro.
A distribuicao e as regras de saque sao iguais nos dois algoritmos.
O C permite espacos externos ao numero; no Portugol, digite somente o numero.
O Portugol ainda precisa ser executado no WebStudio para validacao nesse ambiente.

## Testes

| Entrada | Resultado |
| --- | --- |
| 95, depois 3 | Entrega R$95,00, mostra saldo de R$505,00 e encerra |
| 123, 1, 2, 100, 1, 3 | Saques de R$123,00 e R$100,00; consultas mostram R$477,00 e R$377,00 |
| 500, 2, 101, 100, 1, 3 | Recusa R$101,00 com saldo de R$100,00; aceita R$100,00 e consulta saldo zero |
| 600, 2, 1, 3 | Saca todo o saldo; novo saque e recusado; permite consultar e sair |
| 50, abc, 4, 1, 3 | Opcoes invalidas repetem o menu; a consulta continua mostrando R$550,00 |


## Entrega

O roteiro exige codigo C, arquivo Portugol e relatorio PDF com evidencias.
`GRUPO_NN_codigo.c`, `GRUPO_NN_portugol.por` e `GRUPO_NN_testes.pdf`,
