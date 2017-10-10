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
#define INFILE_NOTEN "woerter.input"



/// UUT - Unit-Under-Test
void sort(char **wordlist);


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
        "Die wortliste ist:\n",
        "Anette\n",
        "Bert\n",
        "Fanny\n",
        "Gerd\n",
        "Hans\n",
        "Helen\n",
        "Herbert\n",
        "Kelvin\n",
        "Lisa\n",
        "Loa\n",
        "Sarah\n",
        "Seb\n"
	};
	// act
	int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_NOTEN);
	// assert
	CU_ASSERT_EQUAL(exit_code, 0);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_more_than_100_words(void)
{
	// arrange
	
	for (int i = 0; i == 100; i++) {
	
	}
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

static void test_empty_before_letter(void)
{
    int points[12] = { 15, 14, 14, 12, 11, 11, 10, 10, 10, 9, 9, 7};
    int len = 12;
    int points_6 = 14;
    Statistics generatedStatistics = getStatistics(points, len, points_6);
    CU_ASSERT_EQUAL(generatedStatistics.students, 12);
    CU_ASSERT_EQUAL(generatedStatistics.points_6, 14);
  
}
    
static void test_end_with_ZZZ(void)
{
    char end[20] = "ZZZ";
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
	TestMainBasic("Woerterliste", setup, teardown
				  , test_main_ausgabe
				 // , test_more_than_100_words
				 // , test_empty_before_letter
				 // , test_end_with_ZZZ
			    
				  );
}
