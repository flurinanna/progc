#include <string.h>
#include <person.h>

int comparePerson(Person a, Person b) {
    int c = strcmp(a.name, b.name);
    if (c == 0) {
        c = strcmp(a.firstname, b.firstname);
    } 
    if (c == 0) {
        c = a.age - b.age;
    }
    return c;
}    

