/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <assert.h>
#include "list.h"
#include "person.h"




void insert(void) {
    List *lneu = &l;
    Person newp;
    (void)printf("Geben Sie eine Person ein: <Name> <Vorname> <Alter>");
    scanf("%s %s %d", &newp.name, &newp.firstname, &newp.age);

    List *temp = lneu->next;
    lneu->next = malloc(sizeof(List)); 
    lneu = lneu->next;
    lneu.pcontent = newp;
    lneu->next = temp;
    
       
    if(strcmp(*l.pcontent.name, *lneu.pcontent.name) > 0){
     l = &(*l).next;  
    } else if (strcmp(*l.pcontent.fistname, *lneu.pcontent.firstname) > 0 && strcmp(*l.pcontent.name, *lneu.pcontent.name) == 0) {
        l = &(*l).next; 
    } else if (*l.pcontent.age > *lneu.pcontent.age && strcmp(*l.pcontent.fistname, *lneu.pcontent.firstname) == 0 && strcmp(*l.pcontent.name, *lneu.pcontent.name) == 0) {
        l = &(*l).next; 
    }
        lneu.next = l.next;
        l.next = lneu;
}


