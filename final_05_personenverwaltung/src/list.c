#include <list.h>

/*
** function to insert a new person to the list.
**
*/
void insertPerson(void) {  
    // create new person
    Person newPerson = createPerson();
    // go to correct position in the list
    ListElement *pointer = &le;
    while (pointer->next != &le && 
           comparePerson(newPerson, pointer->next->content) > 0 ) {
        pointer=pointer->next;
    } 
    // create new list element and point it to the new person
    ListElement *temp = pointer->next;
    pointer->next = malloc(sizeof(ListElement));
    pointer=pointer->next;
    pointer->content = newPerson;
    pointer->next = temp;     
    // print out info on newly added person
    (void)printf("Person added successfully: %s %s, %d\n", 
                 newPerson.name, newPerson.firstname, newPerson.age);
}

/*
** function to remove a person from the list.
**
*/
void removePerson(void) {
    // create person object with the attributes of the person that 
    // shall be removed.  
    Person to_remove = createPerson();
    // go through the list and look for a match.
    ListElement *pointer = &le;
    int success = 0;
     while (pointer->next != &le && success != 1) {

        if (comparePerson(to_remove, pointer->next->content) == 0) {
            ListElement *tmp = pointer->next;
            pointer->next = pointer->next->next;
            free(tmp);
            success = 1;        
        }
        pointer=pointer->next;
    } 
    // print out a message whether person was removed or not found.
    if (success == 1) {
        (void)printf("Person removed successfully\n");
    } else {
        (void)printf("Couldn't find specified Person\n");
    }
}

/*
** function to print out all persons stored in the list.
*/
void showList(void) {
    ListElement *pointer = &le;
    printf("Erfasste Personen: \n");
	printf("--------------------------------------------------------\n");
    while (pointer->next != &le) {
        pointer = pointer->next;
        printPerson(pointer->content);
        
    }
}

/*
** function to delete all persons stored in the list.
*/
void clearList(void) {
     ListElement *pointer = &le;
     while (pointer->next != &le) {
        ListElement *tmp = pointer->next;
        pointer->next = pointer->next->next;
        free(tmp);
     }
    (void)printf("List cleared successfully\n");
}
