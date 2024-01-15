## Jogo da Velha com IA
![Badge de licença](http://img.shields.io/static/v1?label=LICENÇA&message=GNU&color=sucess&style=for-the-badge)   ![Badge Concluido](http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=sucess&style=for-the-badge)   ![Badge versionamento](http://img.shields.io/static/v1?label=VERSAO&message=1.3&color=sucess&style=for-the-badge)

### Sobre

Jogo da velha

### Bora ver como ficou?

![Jogo_da_velha_IA](https://github.com/ArandaCampos/jogo_da_velha_com_IA/assets/87876734/f4d3fe15-101c-4747-8ad2-1efd9c0a966c)

### Pré-requisitos

    compilador de linguagem C

### Instalação

    # Clone o repositório
    >> git clone https://github.com/ArandaCampos/jogo_da_vilha_com_IA.git

    # Compile o código (exemplo com gcc)
    >> gcc ai.c list.c main.c -o jogo

    # rode no terminal
    >> ./jogo

E está pronto para usá-lo 💻

### Conclusões

#### Análise do algoritmo (MiniMax)

&emsp;Com posse do estado atual da partida, o algoritmo  verifica se há uma movimentação para ganhar a partida já na próxima rodada (melhor caso). Caso não haja, ele realiza as demais jogadas possíveis e verifica se houve ganhador. Esta lógica é repetida até que haja um ganhador ou cesse todas as jogadas.</br>
&emsp;Ao fim, o código agrupa as movimentações em "derrotas" (&beta;) e "não derrotas" (&alpha;) e calcula a "chance de não derrota" (&gamma;).

&gamma; = $\sum (&alpha;) \div \sum (&alpha; + &phi;)$

&emsp;A movimentação com maior chance de não derrota (&gamma;) será escolhida.

#### Complexidade de tempo

  - O(n!)

#### Análise dos resultados (v 1.3)

  - Resultados:</br>


Resultado | 1ª | 2ª | 3ª | 4ª | 5ª | 6ª | 7ª | 8ª | 9ª | 10ª | (%) |
--------- | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
`Vitória` | - | - | - | - | x | - | - | x | - | - |  `20%` |
`Derrota` | - | - | - | - | - | - | - | - | - | - |  ` 0%` |
`Empate`  | x | x | x | x | - | x | x | - | x | x |  `80%` |

  - O algoritmo consegue responder bem a todos os contextos, alternando-se entre momentos agressivos e defensivos conforme a necessidade. Além disso, ele consegue realizar jogadas complexas - com 4 etapas até a conclusão - e defender-se delas.
