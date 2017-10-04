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

enum {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

typedef struct {
int day;
int month;
int year;
} Date;

Date calculateNextDate(Date start_date);


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
int main(int argc, char* argv[])
{
	Date next_date;
	int day, month, year;
	
	if (argc < 2) {
	
	    scanf("%d%d%d", &day, &month, &year);
	    Date start_date = {day, month, year};
	    next_date = calculateNextDate(start_date);
	    printf("Next date: %d %d %d\n", next_date.day, next_date.month, next_date.year);
	    
	    
	} else {
	    return EXIT_FAILURE;
	} 
	    
	// end students to add code
	return EXIT_SUCCESS;
}

Date calculateNextDate(Date start_date) {
    Date next_date = start_date;
    int days;
    if (start_date.month == Jan || 
        start_date.month == Mar || 
        start_date.month == May || 
        start_date.month == Jul || 
        start_date.month == Aug || 
        start_date.month == Oct ||
        start_date.month == Dec) {
        days = 31;
    } else if (start_date.month == Apr || 
        start_date.month == Jun || 
        start_date.month == Sep || 
        start_date.month == Nov) {
        days = 30;
    } else {
        if ((start_date.year % 4 == 0 && start_date.year % 100 != 0) || (start_date.year % 400 == 0)) {
            days = 29;
        } else {
            days = 28;
          }
    }
    
    next_date.day++;
    if (next_date.day > days) {
        next_date.day = 1;
        next_date.month++;
    }
    
    if (next_date.month > 12) {
        next_date.month = Jan;
        next_date.year++;
    }
          
    
    return next_date;

}

