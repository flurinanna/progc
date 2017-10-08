#include <string.h>
#include <person.h>

/*
** function to compare if two given persons have the same attribute values.
** @param Person a, Person b
** @return int match
*/
int comparePerson(const Person a, const Person b) {
    int match = strcmp(a.name, b.name);
    if (match == 0) {
        match = strcmp(a.firstname, b.firstname);
    } 
    if (match == 0) {
        match = a.age - b.age;
    }
    return match;
}   

/*
** function to create a new person according to user input.
*/
Person createPerson() {
    Person newPerson;
    (void)printf("Name: ");
    (void)scanf("%s", newPerson.name);
    (void)printf("Firstname: ");
    (void)scanf("%s", newPerson.firstname);
    (void)printf("Age: ");
    (void)scanf("%d", &newPerson.age);
    return newPerson;
} 

/*
** function to print out a given persons attributes.
** @param Person person
*/
void printPerson(const Person person) {
    printf("%s %s, %d\n", person.name, person.firstname, person.age);
}

