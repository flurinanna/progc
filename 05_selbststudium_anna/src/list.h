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

#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

/**
 * @brief           Entry point for calculating.
 * @param[in] text  Text to be processed.
 * @return          Calculated value.
 */
 

typedef struct L List;

struct L {
    Person pcontent;
    List *next;
};

List l;
 
void insert();

void removeElement();

void show();

void clear();

void end();


#endif
