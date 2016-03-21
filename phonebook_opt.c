#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"


/* FILL YOUR OWN IMPLEMENTATION HERE! */


entry *findName(char lastname[], entry *pHead[])
{

    unsigned int n = BKDRHash(lastname);

    while (pHead[n] != NULL) {
        if (strcasecmp(lastname, pHead[n]->lastName) == 0)
            return pHead[n];
        pHead[n] = pHead[n]->pNext;
    }
    return NULL;
}

void *append(char lastName[], entry *e[])
{
    unsigned int n = BKDRHash(lastName);

    entry *temp;

    if ( e[n]->pNext == NULL )
        temp = e[n];
    else
        temp = e[n]->pNext;

    temp->pNext = (entry *) malloc(sizeof(entry));
    temp = temp->pNext;

    strcpy(temp->lastName, lastName);
    temp->pNext = NULL;

}

unsigned int BKDRHash(char lastName[])
{
    unsigned int seed = 31;
    unsigned int hash = 0;
    int i=0;
    while(lastName[i] != '\0') {
        hash = hash * seed + lastName[i];
        ++i;
    }

    return hash %= TABLE_SIZE;
}

void freeList(entry *e)
{
    entry *temp;
    while(e) {
        temp = e->pNext;
        free(e);
        e = temp;
    }
}
