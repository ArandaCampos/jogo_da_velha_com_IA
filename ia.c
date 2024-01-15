#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <Windows.h>
#endif

const int WINNER[8][3] = {
    {0, 1, 2},
    {0, 3, 6},
    {0, 4, 8},
    {1, 4, 7},
    {2, 5, 8},
    {2, 4, 6},
    {3, 4, 5},
    {6, 7, 8},
};

int randomSelection(pList chances)
{
    int key = 0;
    pList aux = chances;

    for (;aux != NULL; aux = aux->next ) key++;

    srand( (unsigned)time(NULL) );
    key = rand() % key;

    for (; key != 0; key-- ) chances = chances->next;

    return chances->n;
}

pList calculateChances(pList options)
{
    pList aux = options;

    for (; options != NULL; options = options->next)
    {
        if (options->notLose + options->lose == 0) options->lose = 1.0;
        options->chance = options->notLose / (options->notLose + options->lose);
    }

    return aux;
}

pList getGreaterChances(pList options)
{
    pList aux = NULL;

    for (aux = options->next; aux != NULL; aux = aux->next)
    {
        if (aux->chance > options->chance)
        {
            options = removeItem(options, options->n);
            aux = options;
        }
        else if (aux->chance < options->chance)
        {
            options = removeItem(options, aux->n);
            aux = options;
        }
    }

    return options;
}

int canWinNextRound(int game[], int player)
{
    int opponent = 0;

    if (player == 1) opponent = 2;
    else opponent = 1;

    for (int i = 0; i < 8; i++)
    {
        if (game[WINNER[i][0]] != opponent && game[WINNER[i][1]] != opponent && game[WINNER[i][2]] != opponent)
        {
            if (game[WINNER[i][0]] == game[WINNER[i][1]] && game[WINNER[i][0]] == player) return 1;
            else if (game[WINNER[i][0]] == game[WINNER[i][2]] && game[WINNER[i][0]] == player) return 1;
            else if (game[WINNER[i][1]] == game[WINNER[i][2]] && game[WINNER[i][1]] == player) return 1;
        }
    }
    return 0;
}

int isThereWinner(int game[])
{
    for (int i = 0; i < 8; i++)
    {
        if (game[WINNER[i][0]] == game[WINNER[i][1]] && game[WINNER[i][1]] == game[WINNER[i][2]] && game[WINNER[i][2]] != 0)
        {  // houve ganhador
            return 1;
        }
    }
    return 0;
}

pList takeTheEmptyOnes(int game[])
{
    pList emptyOnes = NULL;
    for (int i = 0; i < 9; i++)
        if (game[i] == 0)
            emptyOnes = insert(emptyOnes, i);

    return emptyOnes;
}

void getChance(int game[], pList chance, int player)
{
    pList move = NULL;

    move = takeTheEmptyOnes(game);

    // Há ganhador
    if (isThereWinner(game) == 1)
    {
        if (player == 2)
            chance->notLose += length(move) + 1;
        else
            chance->lose += length(move) + 1;
        freeList(move);
        return;
    }
    // Em caso de velha
    if (move == NULL)
        chance->notLose += 1;

    // Inverte o jogador
    if (player == 1) player = 2;
    else player = 1;

    // Há vitória eminente
    if (canWinNextRound(game,player) == 1)
    {
        if (player == 2)
            chance->notLose += length(move) + 1;
        else
            chance->lose += length(move) + 1;
        freeList(move);
        return;
    }

    for (; move != NULL; move = move->next)
    {
        game[move->n] = player;
        getChance(game, chance, player);
        game[move->n] = 0;
    }

    freeList(move);
    return;
}

int getMove(int game[])
{

    int n = 0;
    pList options = NULL,
          aux   = NULL;

    options = takeTheEmptyOnes(game);

    for(aux = options; aux != NULL; aux = aux->next)
    {
        game[aux->n] = 2;
        getChance(game, aux, 2);
        game[aux->n] = 0;
    }

    options = calculateChances(options);
    options = getGreaterChances(options);
    n = randomSelection(options);

    freeList(options);

    return n;
}
