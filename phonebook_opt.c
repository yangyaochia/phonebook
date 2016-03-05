#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "phonebook_opt.h"

unsigned int hash(hash_table *hashtable , char *str)
{
    unsigned int hash_value = 0;
    while(*str)
        hash_value = (hash_value << 5) - hash_value + *str++;
    return (hash_value % hashtable->size);
}

hash_table *create_hash_table(int size)
{
    int i;
    hash_table *new_table;
    if(size<1)	return NULL;

    /* Allocate memory for hashtable*/
    new_table = malloc(sizeof(hash_table));
    new_table->table = malloc(sizeof(entry *) * size );

    /* Initialize the elements of the table */
    for(i=0; i<size; i++)
        new_table->table[i] = NULL;
    new_table->size = size;

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

    /* Check does the lastName already exist or not */
    new_entry = findName(lastName , hashtable);
    if(new_entry != NULL) return;

    new_entry = NULL;
    new_entry = (entry *) malloc(sizeof(entry));

    /* Insert into table list */
    memcpy(new_entry->lastName , lastName , strlen(lastName));
    new_entry->pNext = hashtable->table[hash_value];
    hashtable->table[hash_value] = new_entry;
}
