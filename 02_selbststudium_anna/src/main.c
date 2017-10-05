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
 * @brief calculation date of next day
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

typedef struct {
    int day;
    int month;
    int year;
} Date;


Date start_date;
int d, m, y;

Date berechne_folgetag(Date start_date);
int teste_gueltigkeit(Date start_date);

/**
 * @brief Read an input-date and prints out the date of the day
 * after the input-date.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if more than one argument is given.
 */
int main(void)
{
    scanf("%d%d%d\n", &d, &m, &y);
    start_date.day = d;
    start_date.month = m;
    start_date.year = y;

//function call to test the input value 
int testwert = teste_gueltigkeit(start_date);


//if the given date is ok > function call to calculate the date of the next day and print out the result
    if (testwert == 0) {   
    Date next_date = berechne_folgetag(start_date);     
    (void)printf("Der Folgetag ist %d %d %d\n", next_date.day, next_date.month, next_date.year);
	    return EXIT_SUCCESS;
	} else { 
	    return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}



/**
 * @brief calculates the date one day after the input-date
 * @param Date start_date
 */
Date berechne_folgetag(Date start_date) 
{
//case: change of year
    if (start_date.month == Dec && start_date.day == 31) {
        start_date.year++;
        start_date.month = 1;
        start_date.day = 1;
//case: change of month
    } else if ((start_date.month == Jan || 
                start_date.month == Mar ||
                start_date.month == May ||
                start_date.month == Jul ||
                start_date.month == Aug ||
                start_date.month == Oct) && start_date.day == 31) {
        start_date.month++;
        start_date.day = 1;
    } else if ((start_date.month == Apr ||
                start_date.month == Jun ||
                start_date.month == Sep ||
                start_date.month == Nov) && start_date.day == 30) {
        start_date.month++;
        start_date.day = 1;
//case: month february
    } else if(start_date.month == Feb && start_date.day == 28) {
           if ((start_date.year%4 == 0 && 
                start_date.year%100 != 0)|| 
                (start_date.year%400 == 0)) {
                start_date.day++;
           }else {
                start_date.month++;
                start_date.day = 1;
           }
    } else {
//case: change of day
        start_date.day++;
    }
    return start_date;  
}


/**
 * @brief test, if the given input is a correct date
 * @param Date start_date
 */
int teste_gueltigkeit(const Date start_date) 
{
//test, if it is in the range
    if (start_date.year >= 1583 && start_date.day >= 1 && 
            start_date.day <= 31 && start_date.month >= 1 &&
            start_date.month <= 12) {
        return EXIT_SUCCESS;
//test, if its out of the range
    } else if (start_date.day < 1 || start_date.day > 31 ||
            start_date.month < 1 || start_date.month > 12 ||
            start_date.year < 1583) {
        return EXIT_FAILURE;
//any other cases
    } else {
        return EXIT_FAILURE;
    }
}




