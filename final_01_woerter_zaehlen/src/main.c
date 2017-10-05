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
 * @brief Counts the number of words and characters for a given line of text.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Main entry point.
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
            zeichen++;
            text[zeichen + 1] = getchar();
            if (text[zeichen + 1] != ' ' && 
                text[zeichen + 1] != '\t' && 
                text[zeichen + 1] != '\n') {
   		        woerter++;
   		    }
      
       } 
       zeichen++;
    }

    (void)printf("Text contains %d characters and %d words.\n", zeichen, woerter);

	return EXIT_SUCCESS;
}

