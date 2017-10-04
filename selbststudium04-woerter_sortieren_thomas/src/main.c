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

char *wordlist[100];
int words = 0;
	
void saveToWordlist(char *word);
void sortWordlist(void);
void printWordlist(void);


/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments
 *                  with argv[0] being the command call
 *                  argv[1] the 1st argument, ...
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if more than one argument is given.
 */
int main(void)
{
	char word[20];

	
  /*  scanf("%s", word);
	size_t n = strlen(word);
	char *entry = (char*) malloc((n+1)*sizeof(char));
	strcpy(entry, word);
	saveToWordlist(entry);
	words++;  */
	
	while (!(strlen(word)==3 && word[0] == 'Z' && word[1] == 'Z' && word[2] == 'Z') && words <= 100) {
	    scanf("%s", word);
	    size_t n = strlen(word);
	    char *entry = malloc((n+1)*sizeof(char));
	    strcpy(entry, word);
	    saveToWordlist(entry);
	    words++;
	}
	words--;
	(void)sortWordlist();
	(void)printWordlist();
	EXIT_SUCCESS;
	
}

void saveToWordlist(char *word) {
    wordlist[words]=word;
    
    //printf("%s\n", *(wordlist+words));
}

void sortWordlist(void) {
    for(int a = 0; a < words; a++) {
        for(int i = 0; i < words-1; i++) {
            if(strcmp(wordlist[i], wordlist[i+1]) > 0) {
                char *temp = wordlist[i];
                wordlist[i] = wordlist[i+1];
                wordlist[i+1] = temp;
            }
        }
    }
       

}

void printWordlist(void) {
    for(int i = 0; i < words; i++) {
        printf("%s\n", *(wordlist+i));
    }
    

}


