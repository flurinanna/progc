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
 * @returns Returns EXIT_SUCCESS (=0) on success,
 */
int main(void)
{	
    char zeichen[100];
    zeichen[0] = getchar();
    int anz_woerter = 1;
    int i = 1;       
    while(zeichen[i-1] != '\n') {
	    zeichen[i] = getchar();
	    if (zeichen[i] == ' ' || zeichen[i] == '\t') {
	        anz_woerter++;
	    }
	    i++;
	}           
	    
    printf("%s\n", zeichen);
    printf("Text contains %d characters and %d words.\n", i-1, anz_woerter);
	   
	return EXIT_SUCCESS;
}

