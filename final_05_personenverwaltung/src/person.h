#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>

typedef struct {
    char name[20];
    char firstname[20];
    unsigned age;
} Person;

int comparePerson(Person a, Person b);
Person createPerson();
void printPerson(const Person person);


#endif
