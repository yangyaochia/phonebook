#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include<string.h>
#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    while (pHead != NULL) {
        if (strcmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    //strcpy(e->lastName, lastName);
    memcpy(e->lastName,lastName,strlen(lastName));
    e->pNext = NULL;

    return e;
}
