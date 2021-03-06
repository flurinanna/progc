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
 * @brief program to store person data in a list, providing the options to
 *        insert and remove persons and to show and clear the list.
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
            case 'I': (void)insert_person();
            break;
            case 'R': (void)remove_person();
            break;
            case 'S': (void)show_list();
            break;
            case 'C': (void)clear_list();
            break;
        }
    }
}


