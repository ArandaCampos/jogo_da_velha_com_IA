#ifndef IA_H
    #define IA_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "list.h"

    #define RED    "\x1b[31m"
    #define RESET  "\x1b[0m"

    #ifdef __unix__
        #include <unistd.h>
    	#define clear() system("clear")
    #elif defined(_WIN32) || defined(WIN32)
        #include <Windows.h>
    	#define clear() system("cls")
    #endif

    // main.c
    void draw(int [], int);
    int getPosition(int [], int);
    int isValid(int [], int);
    int randomSelection(pList);
    // ia.c
    pList calculateChances(pList);
    pList getGreaterChances(pList);
    pList takeTheEmptyOnes(int);
    int canWinNextRound(int [], int);
    int isThereWinner(int []);
    int winner(int [], int);
    void getChance(int [], pList, int);
    int getMove(int []);

# endif
