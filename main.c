#include "ia.h"

int main()
{
    int game[] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    };
    int player = 1,
        win    = 0,
        round  = 0,
        run    = 1;

    while (run == 1)
    {

        for (int i = 0; i < 9; i++)
            game[i] = 0;

        draw(game, player);

        while (round < 9 && win == 0){
            getPosition(game, player);
            draw(game, player);
            win = winner(game, player);

            if (player == 1) player = 2;
            else player = 1;

            round++;
        }
        // reinicia as variáveis
        player = 1;
        win    = 0;
        round  = 0;

        printf("\nPressione 1 para jogar novamente ou 0 para finalizar: ");
        scanf("%d", &run);
    }

    printf("\n");
    return 0;
}

void draw(int game[], int player)
{
    clear();

    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++ )
        {
            if ( game[i * 3 + j] == 0 ) printf(RED " %d " RESET, i * 3 + j + 1);
            else if ( game[i * 3 + j] == 1 ) printf(" x ");
            else printf(" o ");

            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---+---+---\n");
    }
    printf("\n");
    return;

}

int getPosition(int game[], int player)
{
    int position = -1;

    do {
        if (player == 1)
        {
            printf("\nJogador " RED "x: " RESET);
            scanf("%d", &position);
            position--;
        }
        else{
            position = getMove(game);
        }
    } while (isValid(game, position) != 1);

    game[position] = player;

    return position;
}

int isValid(int game[], int position)
{
    if (position < 0 || position > 8 || game[position] != 0)
    {
        printf("Esta jogada inválida\n");
        return 0;
    }
    return 1;
}

int winner(int game[], int player)
{
    int WINNER[8][3] = {
        {0, 1, 2},
        {0, 3, 6},
        {0, 4, 8},
        {1, 4, 7},
        {2, 5, 8},
        {2, 4, 6},
        {3, 4, 5},
        {6, 7, 8},
    };

    for (int i = 0; i < 8; i++)
    {
        if (game[WINNER[i][0]] == player && game[WINNER[i][1]] == player && game[WINNER[i][2]] == player){
            if (player == 1)
                printf("\nJogador " RED "x venceu!" RESET "\n");
            else
                printf("\nJogador " RED "o venceu!" RESET "\n");
            return 1;
        }
    }
    return 0;
}
