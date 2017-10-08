#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <person.h>

typedef struct LE ListElement;

struct LE {
    Person content;
    ListElement *next;
};

ListElement le;

void insertPerson(void);
void removePerson(void);
void showList(void);
void clearList(void);



#endif
