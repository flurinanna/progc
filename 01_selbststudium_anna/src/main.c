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
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 */
 
   double fahrenheit[40];
   double celsius[40];
   int arraygroesse = 0;

 
void berechne_celsius(const double fahrenheit[])
{
int i = 0;
int len = arraygroesse + 1; 
for (i = 0; i < len; i++) {
    celsius[i] = 5*(fahrenheit[i] - 32)/9;
	(void)printf("%6d    %6.2f\n", (int)fahrenheit[i], celsius[i]);
    }
}

/**
 * @brief Main entry point.
 */
int main(void)
{
   double f = -100;
   
   while(f < 200) {
        fahrenheit[arraygroesse] = f;
        f += 20;
        arraygroesse++;
   }
   	(void)printf("F'heit    Celsius\n");
   	(void)printf("-----------------\n");
    berechne_celsius(fahrenheit);
    return 0;
}
