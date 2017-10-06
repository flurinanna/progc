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

    int text[100];  // int array to save the text entered (in ASCII-Code).
    int woerter = 0, zeichen = 0; // counters for words and chars.
    
    text[zeichen] = getchar();  // first char is read.
    if(text[zeichen] != '\n') { // if no text is entered the program terminates.
        woerter++;
    } else {
        return EXIT_FAILURE;
    }
    while(text[zeichen] != '\n') {  // text is read char by char.
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

    (void)printf("Text contains %d characters and %d words.\n",
                 zeichen, woerter); // counters are printed.

	return EXIT_SUCCESS;
}

