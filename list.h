#ifndef LIST_H
#define LIST_H

    #include <stdlib.h>

    typedef struct list{
        int n;
        float notLose;
        float lose;
        float chance;
        struct list* next;
    } tList;
    typedef tList* pList;

    void freeList(pList);
    pList insert(pList, int);
    pList removeItem(pList, int);
    int length(pList);

#endif
