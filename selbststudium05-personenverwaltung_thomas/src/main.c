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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include <person.h>

ListElement le;

int main(void)
{
    le.next = &le;
    char inputChar = ' ';
    while (inputChar != 'E') {
        (void)printf("I(nsert), R(emove), S(how), C(lear), E(nd):\n");
        (void)scanf(" %c", &inputChar);
        switch(inputChar) {
            case 'I': (void)insertPerson();
            break;
            case 'R': (void)removePerson();
            break;
            case 'S': (void)showList();
            break;
            case 'C': (void)clearList();
            break;
        }
    }
    

}


