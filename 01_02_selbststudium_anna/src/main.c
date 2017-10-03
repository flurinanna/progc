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

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if more than one argument is given.
 */
 

int main()
{

    int text[100];
    int woerter = 0, zeichen = 0;
    
    text[zeichen] = getchar();
    if(text[zeichen] != 0) {
        woerter++;
    } else {
        return EXIT_FAILURE;
    }
    while(text[zeichen] != '\n') {
       text[zeichen + 1] = getchar();
           if (text[zeichen + 1] == ' ' || text[zeichen + 1] == '\t')      {
                woerter++;
           } // fall zwei leerschläge nacheinander fehlt...
       zeichen++;
    }

    (void)printf("Die Zeile enthält %d Zeichen und %d Woerter\n", zeichen, woerter);

	return EXIT_SUCCESS;
}


