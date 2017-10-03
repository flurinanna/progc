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
#include <math.h>


typedef struct {
    int eins;
    int zwei; 
    int drei; 
    int vier; 
    int fuenf; 
    int sechs;
} Noten;


int ptzahlen[100];
int minptzahl = 0;
int bestmark, worstmark, anzstudenten = 0;
//Noten n;
void get_statistik(Noten n);
Noten berechne_noten(int minptzahl, int ptzahlen[100], int anzstudenten);

/**
 * @brief Main entry point.
 */
int main(void)
{
//Punkte einlesen
int i = 0;
//Noten noten;

    for(i = 0; i < 100; i++) {
    printf("Geben Sie die Punktezahl des Studierenden ein: ");
    scanf("%d\n", &ptzahlen[i]);  
    anzstudenten++;
    }
    
//minimale Punktzahl eingeben:
    printf("Geben Sie die minimale Punktezahl für die Note 6 ein: ");
    scanf("%d\n", &minptzahl);
//Note berechnen 
    Noten not;
    not = berechne_noten(minptzahl, ptzahlen, anzstudenten);
//Statistik ausgeben
    get_statistik(not);
    
	return EXIT_SUCCESS;

}

Noten berechne_noten(int minptzahl,int ptzahlen[100], int anzstudenten) {
    int i = 0;
    double note;
    Noten n = {0,0,0,0,0,0};
//note berechnen
    for (i = 0; i < anzstudenten; i++){
        note = 1 + (5*ptzahlen[i])/minptzahl;
        //abrunden oder aufrunden
        int testwert = (int)note - note;
        if(testwert <= 0.5){
            double ceil(double note);
        } else {
            double floor(double note);
        }
       //anzahl vorkommen jeder note
       if (note == 6){
            n.sechs++;
            bestmark = 6;
       } else if (note == 5){
            n.fuenf++;
            if(bestmark < 5){
            bestmark = 5;
            }
            if(worstmark > 5){
            worstmark = 5;
            }
       } else if (note == 4){
            n.vier++;
            if(bestmark < 4){
            bestmark = 4;
            }
            if(worstmark > 4){
            worstmark = 4;
            }
       } else if (note == 3){
            n.drei++;
            if(bestmark < 3){
            bestmark = 3;
            }
            if(worstmark > 3){
            worstmark = 3;
            }
       } else if (note == 2){
            n.zwei++;
            if(bestmark < 2){
            bestmark = 2;
            }
            if(worstmark > 2){
            worstmark = 2;
            }
       } else if (note == 1){
            n.eins++;
            worstmark = 1;
            if(bestmark < 1){
            bestmark = 1;
            }
       } else {
       }
    }
   
    return n; 
}

void get_statistik(Noten n) {
    (void)printf("----------------------------------------------------\n Statistics (%d students, %d points needes for mark 6): \n\n", anzstudenten, minptzahl);
    
      (void)printf("Mark 6: %d\n Mark 5: %d\n Mark 4: %d\n Mark 3: %d\n Mark 2: %d\n Mark 1: %d\n\n", n.sechs, n.fuenf, n.vier, n.drei, n.zwei, n.eins);
      
      double averagemark = (double)bestmark/worstmark;
      int markgroesservier = anzstudenten - (n.drei + n.zwei + n.eins);
      double prozent = markgroesservier/anzstudenten*100;
      (void)printf("Best mark: %d\n Worst mark: %d\n Average mark: %f\n Mark >= 4: %d students (%.2f %)\n------------------------------------------------------------", bestmark, worstmark, averagemark, markgroesservier, prozent);
}





