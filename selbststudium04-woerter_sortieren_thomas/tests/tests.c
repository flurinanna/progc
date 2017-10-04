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



#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

/// @brief The stimulus for the right-angled triangles
#define INFILE_NOTEN "stim-noten.input"



/// UUT - Unit-Under-Test
void saveToWordlist(char *word);
void sortWordlist(void);
void printWordlist(void);


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
	        "Insert points needed for a 6: \n",
		    "--------------------------------------------------------\n",
            "Statistics (20 students, 19 points needed for mark 6):\n",
            "Mark 6: 2\n",
            "Mark 5: 7\n",
            "Mark 4: 7\n",
            "Mark 3: 4\n",
            "Mark 2: 0\n",
            "Mark 1: 0\n\n",
            "Best mark:    6\n",
            "Worst mark:   3\n",
            "Average mark: 4.35\n"
            "Mark >= 4: 16 students 80 Percent\n",
            "--------------------------------------------------------\n",
            "Enter new minimal points for grade 6(y/n?)\n"

	};
	// act
	int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_NOTEN);
	// assert
	CU_ASSERT_EQUAL(exit_code, 0);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_getMark(void)
{
	// arrange
	// act
	int points1 = 24;
	int points2 = 23;
	int points_6 = 30;
	int mark1 = 0;
	int mark2 = 0;
	// printf("%f", d);
	// assert
	mark1 = getMark(points1, points_6);
	mark2 = getMark(points2, points_6);
	CU_ASSERT_EQUAL(5, mark1);
	CU_ASSERT_EQUAL(5, mark2);
}

static void test_getStatistics(void)
{
    int points[12] = { 15, 14, 14, 12, 11, 11, 10, 10, 10, 9, 9, 7};
    int len = 12;
    int points_6 = 14;
    Statistics generatedStatistics = getStatistics(points, len, points_6);
    CU_ASSERT_EQUAL(generatedStatistics.students, 12);
    CU_ASSERT_EQUAL(generatedStatistics.points_6, 14);
  
}
    


/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Notenstatistik", setup, teardown
				  , test_main_ausgabe
				  , test_getMark
				  , test_getStatistics
			    
				  );
}
