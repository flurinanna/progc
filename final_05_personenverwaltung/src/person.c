#include <string.h>
#include <person.h>

int comparePerson(const Person a, const Person b) {
    int c = strcmp(a.name, b.name);
    if (c == 0) {
        c = strcmp(a.firstname, b.firstname);
    } 
    if (c == 0) {
        c = a.age - b.age;
    }
    return c;
}   

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

void printPerson(const Person person) {
    printf("%s %s, %d\n", person.name, person.firstname, person.age);
}

