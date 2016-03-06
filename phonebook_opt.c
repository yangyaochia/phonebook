#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "phonebook_opt.h"

unsigned int hash(hash_table *hashtable , char *str)
{
    unsigned int hash_value = 0;
    while(*str)
        hash_value = (hash_value << 5) - hash_value + (*str++);
    return (hash_value % SIZE);
}

hash_table *create_hash_table()
{
    int i;
    hash_table *new_table;

    /* Allocate memory for hashtable*/
    new_table = malloc(sizeof(hash_table));
    new_table->table = malloc(sizeof(entry *) * SIZE );

    /* Initialize the elements of the table */
    for(i=0; i<SIZE; i++)
        new_table->table[i] = NULL;

    return new_table;
}

entry *findName(char *lastName, hash_table *hashtable)
{
    entry *list;
    unsigned int hash_value = hash(hashtable , lastName);

    /* Go to the correct list based on the hash_value and see the
    String is in the list or not */
    for(list = hashtable->table[hash_value] ; list!=NULL ; list = list->pNext) {
        if(strcmp(lastName,list->lastName)==0)
            return list;
    }

    /* Can't Found */
    return NULL;
}

void append(char *lastName,hash_table *hashtable)
{
    entry *new_entry;
    unsigned int hash_value = hash(hashtable , lastName);

    new_entry = (entry *) malloc(sizeof(entry));

    /* Insert into table list */
    strcpy(new_entry->lastName , lastName);
    new_entry->pNext = hashtable->table[hash_value];
    hashtable->table[hash_value] = new_entry;
}
