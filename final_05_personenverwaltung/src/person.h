#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>

typedef struct {
    char name[20];
    char firstname[20];
    unsigned age;
} Person;

int compare_person(Person a, Person b);
Person create_person();
void print_person(const Person person);

#endif
