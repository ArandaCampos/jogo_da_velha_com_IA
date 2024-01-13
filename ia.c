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

pList getGreaterChances(pList chance)
{
    pList aux = NULL;

    for (aux = chance->next; aux != NULL; aux = aux->next)
    {
        if (aux->notLose / (aux->notLose + aux->lose) > chance->notLose / (chance->notLose + chance->lose))
        {
            chance = removeItem(chance, chance->n);
            aux = chance;
        }
        else if (aux->notLose / (aux->notLose + aux->lose) < chance->notLose / (chance->notLose + chance->lose))
        {
            chance = removeItem(chance, aux->n);
            aux = chance;
        }
    }

    return chance;
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

    // Há ganhador
    if (isThereWinner(game) == 1)
    {
        if (player == 2) chance->notLose += 1;
        else chance->lose += 1;
        return;
    }

    move = takeTheEmptyOnes(game);
    // Caso tabuleiro cheio, retorne
    if (move == NULL)
    {
        chance->notLose += 1;
        return;
    }

    // Inverte o jogador
    if (player == 1) player = 2;
    else player = 1;

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
    pList chances = NULL,
          aux   = NULL;

    chances = takeTheEmptyOnes(game);

    for(aux = chances; aux != NULL; aux = aux->next)
    {
        game[aux->n] = 2;
        getChance(game, aux, 2);
        game[aux->n] = 0;
    }

    chances = getGreaterChances(chances);
    n = randomSelection(chances);

    freeList(chances);

    return n;
}
