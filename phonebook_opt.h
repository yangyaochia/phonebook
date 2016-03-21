#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH 1
#define TABLE_SIZE 4409

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

typedef struct informationEntry {
    char *firstName;
    char *email;
    char *phone;
    char *cell;
    char *addr1;
    char *addr2;
    char *city;
    char *state;
    char *zip;

}   infoEntry;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];

    infoEntry *detail;

    struct __PHONE_BOOK_ENTRY *pNext;
} entry;
/*
entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
*/

entry *findName(char lastname[], entry *pHead[]);
void *append(char lastName[], entry *e[]);
unsigned int BKDRHash(char lastName[]);
void freeList(entry *e);

#endif
