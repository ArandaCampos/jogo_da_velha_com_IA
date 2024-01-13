#include "list.h"

void freeList(pList a)
{
    pList aux;
    if (a != NULL) aux = a->next; else return;

    free(a);
    freeList(aux);
}

pList insert(pList list, int n)
{
    pList new     = (pList)malloc(sizeof(tList)), aux = list;
    new->n        = n;
    new->notLose  = 0.0;
    new->lose     = 0.0;
    new->next     = NULL;

    if(list == NULL) return new;

    while(aux->next != NULL) aux = aux->next;
    aux->next = new;

    return list;
}
