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
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"
#include <string.h>

#include <list.h>
#include <person.h>



#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

/// @brief The stimulus for the right-angled triangles
#define INFILE_PERSONEN "stim-personen.input"



/// UUT - Unit-Under-Test
void insertPerson(void);
void removePerson(void);
void showList(void);
void clearList(void);


#define EPSILON 0.001

// setup & cleanup
static int setup(void)
{
	remove_file_if_exists(OUTFILE);
	remove_file_if_exists(ERRFILE);
	return 0; // success
}

static int teardown(void)
{
	// Do nothing.
	// Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
	return 0; // success
}


// tests

static void test_main_ausgabe(void)
{
	// arrange
	const char *out_txt[] = {
	        "Erfasste Personen: \n",
		    "--------------------------------------------------------\n",
            "Albrecht Albert, 64\n",
            "Dreier Fritz, 48\n",
            "Dreier Max, 14\n",
            "Meier Hans, 77\n",
            "Meyer Peter, 41\n",
            "Zingg Barbara, 27\n",
            "--------------------------------------------------------\n",
            "I(nsert), R(emove), S(how), C(lear), E(nd):"

	};
	// act
	int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_PERSONEN);
	// assert
	CU_ASSERT_EQUAL(exit_code, 0);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_insertPerson(void)
{
	
	
	CU_ASSERT_EQUAL(5, 1);
	CU_ASSERT_EQUAL(5, 1);
}

static void test_removePerson(void)
{
    int points[12] = { 15, 14, 14, 12, 11, 11, 10, 10, 10, 9, 9, 7};
    int len = 12;
    int points_6 = 14;
    
    CU_ASSERT_EQUAL(1, 12);
  
}
 
static void test_clearList(void)
{
    int points[12] = { 15, 14, 14, 12, 11, 11, 10, 10, 10, 9, 9, 7};
    int len = 12;
    int points_6 = 14;
    CU_ASSERT_EQUAL(1, 12);
  
}    

static void test_comparePerson(void)
{
    Person a = { "Meier", "Franz", 50 };
    Person b = { "Weber", "Regula", 43 };
    Person c = { "Weber", "Dominik", 14 };
    Person d = { "Weber", "Dominik", 40 };
    
    int result1 = comparePerson(a, b);
    int result2 = comparePerson(b, a);
    int result3 = comparePerson(b, c);
    int result4 = comparePerson(c, d);
    
    CU_ASSERT(result1 < 0);
    CU_ASSERT(result2 > 0);
    CU_ASSERT(result3 > 0);
    CU_ASSERT(result4 < 0);
  
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Personenverwaltung", setup, teardown
				  , test_main_ausgabe
				  , test_insertPerson
				  , test_removePerson
				  , test_clearList
				  , test_comparePerson
			    
				  );
}
