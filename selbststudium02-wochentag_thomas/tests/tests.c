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


#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

typedef struct {
int day;
int month;
int year;
} Date;

/// UUT - Unit-Under-Test
Date calculateNextDate(Date start_date);


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
/*static void test_main_ausgabe(void)
{
	// arrange
	const char *out_txt[] = { 
	        "F'heit    Celsius\n",
	        "-----------------\n",
	        "  -100     -73.33\n",
	        "   -80     -62.22\n",
	        "   -60     -51.11\n",
	        "   -40     -40.00\n",
	        "   -20     -28.89\n",
	        "     0     -17.78\n",
	        "    20      -6.67\n",
	        "    40       4.44\n",
	        "    60      15.56\n",
	        "    80      26.67\n",
	        "   100      37.78\n",
	        "   120      48.89\n",
	        "   140      60.00\n",
	        "   160      71.11\n",
	        "   180      82.22\n",
	        "   200      93.33\n"

	    }; 
	        
	// act
	int exit_code = system(XSTR(TARGET) " 1>" OUTFILE);
	// assert
	CU_ASSERT_EQUAL(exit_code, 0);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
} */

static void test_umrechnung1(void)
{
	// arrange
	// act
	Date start_date = { 28, 2, 2004 };
	Date next_date = { 29, 2, 2004 };
	// printf("%f", d);
	// assert
	Date result_date = calculateNextDate(start_date);
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

static void test_umrechnung2(void)
{
	// arrange
	// act
	Date start_date = { 5, 4, 2016 };
	Date next_date = { 6, 4, 2016 };
	// printf("%f", d);
	// assert
	Date result_date = calculateNextDate(start_date);
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

static void test_umrechnung3(void)
{
	// arrange
	// act
	Date start_date = { 30, 4, 2016 };
	Date next_date = { 1, 5, 2016 };
	// printf("%f", d);
	// assert
	Date result_date = calculateNextDate(start_date);
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

static void test_umrechnung4(void)
{
	// arrange
	// act
	Date start_date = { 31, 12, 2016 };
	Date next_date = { 1, 1, 2017 };
	// printf("%f", d);
	// assert
	Date result_date = calculateNextDate(start_date);
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

static void test_umrechnung5(void)
{
	// arrange
	// act
	Date start_date = { 28, 2, 2000 };
	Date next_date = { 29, 2, 2000 };
	// printf("%f", d);
	// assert
	Date result_date = calculateNextDate(start_date);
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}


/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Datum Berechnung", setup, teardown
		//		  , test_main_ausgabe
			      , test_umrechnung1
			      , test_umrechnung2
			      , test_umrechnung3
			      , test_umrechnung4
			      , test_umrechnung5
				  );
}
