#include <list.h>

void insertPerson(void) {
    ListElement *pointer = &le;
    Person newPerson;
    (void)printf("Name: ");
    (void)scanf("%s", newPerson.name);
    (void)printf("Firstname: ");
    (void)scanf("%s", newPerson.firstname);
    (void)printf("Age: ");
    (void)scanf("%d", &newPerson.age);
    while (pointer->next != &le && comparePerson(newPerson, pointer->next->content) > 0 ) {
        pointer=pointer->next;
    } 
    ListElement *temp = pointer->next;
    pointer->next = malloc(sizeof(ListElement));
    pointer=pointer->next;
    pointer->content = newPerson;
    pointer->next = temp;     

    (void)printf("Person added successfully: %s %s, %d\n", newPerson.name, newPerson.firstname, newPerson.age);
}

void removePerson(void) {
    ListElement *pointer = &le;
    Person to_remove;
    (void)printf("Name: ");
    (void)scanf("%s", to_remove.name);
    (void)printf("Firstname: ");
    (void)scanf("%s", to_remove.firstname);
    int success = 0;
     while (pointer->next != &le && success != 1) {

        if (strcmp(to_remove.name, pointer->next->content.name) == 0 && strcmp(to_remove.firstname, pointer->next->content.firstname) == 0) {
            ListElement *tmp = pointer->next;
            pointer->next = pointer->next->next;
            free(tmp);
            success = 1;
            
        }
        pointer=pointer->next;
    } 
    
    if (success == 1) {
        (void)printf("Person removed successfully\n");
    } else {
        (void)printf("Couldn't find specified Person\n");
    }
}

void showList(void) {
    ListElement *pointer = &le;
    printf("Erfasste Personen: \n");
	printf("--------------------------------------------------------\n");
    while (pointer->next != &le) {
        pointer = pointer->next;
        printf("%s %s, %d\n", pointer->content.name, pointer->content.firstname, pointer->content.age);
    }
}

void clearList(void) {
     ListElement *pointer = &le;
     while (pointer->next != &le) {
        ListElement *tmp = pointer->next;
        pointer->next = pointer->next->next;
        free(tmp);
     }
    (void)printf("List cleared successfully\n");
}
