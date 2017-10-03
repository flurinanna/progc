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
#include "list.h"
#include "person.h"


Person pers;
List l;

/**
 * @brief Main entry point.
 */
int main(void)
{


char befehl = ' ';
l.next = &l;

    printf("Geben Sie einen der folgenden Befehle ein: I(nsert), R(emove), S(how), C(lear), E(nd)");
    scanf("%c", &befehl);
    


if(befehl == 'I') {
    (void)insert();
} else if (befehl == 'R') {
    (void)removeElement();
} else if (befehl == 'S') {
    (void)show();
} else if (befehl == 'C') {
    (void)clear();
} else if (befehl == 'E') {
    return 0;
} else {
    return 1;
}


	return EXIT_SUCCESS;

}







