## Jogo da Velha com IA
![Badge de licença](http://img.shields.io/static/v1?label=LICENÇA&message=GNU&color=sucess&style=for-the-badge)   ![Badge Concluido](http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=sucess&style=for-the-badge)   ![Badge versionamento](http://img.shields.io/static/v1?label=VERSAO&message=1.2&color=sucess&style=for-the-badge)

### Sobre
Jogo da velha contra o computador

### Bora ver como está ficando?

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

#### Análise do algoritmo

  O algoritmo de Inteligência Artificial, ao receber de entrada o estado atual do jogo, simula todas as jogadas possíveis até o fim do jogo. A partir disso, a IA contabiliza as "derrotas" (b) e "não derrotas" (a) que, ao final, serão convertidos em chances de não derrota.</br>

  chance de não perder = $\sum (Não derrotas) \div \sum (Todas as partidas)$

  A jogada que obtiver a maior chance de não derrota será escolhida.

#### Complexidade de tempo

  - O(n!)

#### Análise dos resultados

  O algoritmo consegue responder bem a maioria dos contextos. Em raros casos onde a derrota e não derrota estão eminente, ele opta pela primeira opção, permitindo que o jogo resulte em empate - "velha". Ademais, a IA consegue se defender e realizar jogadas complexas (que necessitam de mais rodadas para serem concluídas, como o do gif acima).
