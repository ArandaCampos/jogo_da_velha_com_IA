#ifndef GULOSO_H
    #define GULOSO_H

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

    void draw(int [], int);
    int getPosition(int [], int);
    int isValid(int [], int);
    int isThereWinner(int []);
    pList takeTheEmptyOnes(int);
    int winner(int [], int);
    void getChance(int [], pList, int);
    int getMove(int []);

# endif
