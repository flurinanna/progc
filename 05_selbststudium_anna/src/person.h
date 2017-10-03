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

#ifndef _PERSON_H_
#define _PERSON_H_

/**
 * @brief           Entry point for calculating.
 * @param[in] text  Text to be processed.
 * @return          Calculated value.
 */


typedef struct {
    char name[20];
    char firstname[20];
    unsigned age;
} Person;

#endif
