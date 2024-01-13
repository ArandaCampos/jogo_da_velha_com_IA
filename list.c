#include "list.h"

void freeList(pList a)
{
    pList aux;
    if (a != NULL) aux = a->next; else return;

    free(a);
    freeList(aux);
}

pList removeItem(pList list, int n)
{
    pList aux   = NULL,
          first = list;

    while (list != NULL)
    {
        // Localizou o item
        if (list->n == n)
        {
            // Caso seja o primeiro da lista
            if (aux == NULL)
            {
                aux = list;
                list = list->next;
                aux->next = NULL;
                first = list;
                freeList(aux);
            }
            // Caso não seja o primeiro item
            else
            {
                //list = list->next;
                aux->next = list->next;
                list->next = NULL;
                freeList(list);
                list = aux->next;
            }
        }
        else
        {
            aux = list;
            list = list->next;

        }
    }

    return first;
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
