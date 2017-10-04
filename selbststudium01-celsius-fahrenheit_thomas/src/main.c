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
 * 
 * @brief Calculation of Temperature Fahrenheit to Celsius 
 */
#include <stdio.h>
#include <stdlib.h>

double calculate (int fheit);

/**
 * @brief Prints out a table of values between -100 and 200 degrees Fahrenheit. 
 *        If an int Argument is given, it converts this int value from 
 *        Fahrenheit to Celsius and prints it out (in addition to the table).
 * @param[in] argv  argv[1] Temperature in Fahrenheit (optional)
 */
int main(int argc, char* argv[])
{	
    // printing out the table from -100 to 200 degrees Fahrenheit
    (void)printf("F'heit    Celsius\n");
	(void)printf("-----------------\n");
	int fheit = -100;
	double celsius;
	while (fheit <= 200) {
	    celsius = calculate(fheit);
	    (void)printf("  %4d    %7.2f\n", fheit, celsius);
	    fheit += 20;
	}
	
	// if there was an argument passed into the program, a custom calculation is
	// made here with that argument and printed out.
	if (argc == 2) {
	    int fheit_custom = atoi(argv[1]);  // atoi converts the argument to int
	    double celsius_custom = calculate (fheit_custom);
	    (void)printf("-----------------\n");
	    (void)printf("Custom calculation: \n");
	    (void)printf("  %4d    %7.2f\n", fheit_custom, celsius_custom);        
	} 
	    
	return EXIT_SUCCESS;
}

/**
* calculates the celsius value for a fahrenheit value.
* @param int Fahrenheit
*/
double calculate (int fheit) {
    double celsius = 0.0;
    celsius = (5.0*(fheit-32))/9.0;  
    return celsius;
}
