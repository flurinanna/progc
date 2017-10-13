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

void insert_person(void);
void remove_person(void);
void show_list(void);
void clear_list(void);

#endif
