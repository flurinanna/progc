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




char word[20];
char *wordlist[100];
char *wkopie;
size_t listlaenge;
int anzworte = 0;
int wortzaehler = 0;


/*
** function to sort the words in wordlist
**
*/
void sort(char **wordlist) {
    for(int z = 0; z < anzworte; z++) {
        for(wortzaehler = 0; wortzaehler < anzworte - 1; wortzaehler++) {
            //compare words
            if(strcmp(*(wordlist + wortzaehler), 
                      *(wordlist + (wortzaehler+1))) > 0) {
                //swap words
                char *temp = wordlist[wortzaehler];  
                wordlist[wortzaehler] = wordlist[wortzaehler + 1];
                wordlist[wortzaehler + 1] = temp;
            }
        }
    }
}


/**
 * @brief Main entry point. Reads several Words as input, finish input
 * with 'ZZZ'.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) on failure.
 */
int main(void)
{
    printf("Gib Wörter ein:\n");
    while(anzworte < 100 && !(strlen(word) == 3 && word[0]=='Z' 
                            && word[1]=='Z' && word[2]=='Z')) {
        //read word 
        scanf("%s", word); 
        listlaenge = strlen(word) + 1;
        //generate dynamic an array with the right size
        wkopie = malloc(sizeof(char)*listlaenge);
        strcpy(wkopie, word);
        //safe word in wordlist
        wordlist[anzworte] = wkopie;
        anzworte++;
    }
    anzworte--;
    //make alphabetic order
    sort(wordlist);
    //print out wortlist
    printf("Die Wortliste ist:\n");
    for(int k = 0; k < anzworte; k++) {
        printf("%s\n", wordlist[k]);
    }
return EXIT_SUCCESS;

}







