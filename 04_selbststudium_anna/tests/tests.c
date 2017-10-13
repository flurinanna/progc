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
void save_to_list(char *wkopie);
void print_list(char **wordlist);

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
	    "Gib Woerter ein:\n",
        "Die Wortliste ist:\n\n",
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

static void test_sort_empty_word(void)
{
	// arrange
	char *ada = "ada";
	char *bob = "bob";
    char *empty = "";
    char *wordlist[100];
    wordlist[0] = bob;
    wordlist[1] = empty;
    wordlist[2] = ada;
    // act
    (void)sort(wordlist);
    // assert
	CU_ASSERT_EQUAL(wordlist[1], ada);
	CU_ASSERT_EQUAL(wordlist[0], empty);
	CU_ASSERT_EQUAL(wordlist[2], bob);
}
    
static void test_sort_two_equal_word(void)
{
    // arrange
    char ada[20] = "ada";
    char *wordlist[100] = {ada, ada};
    // act
    (void)sort(wordlist);    
    // assert
    CU_ASSERT_EQUAL(wordlist[0], ada);
    CU_ASSERT_EQUAL(wordlist[1], "");
}

    
static void test_save(void)
{
    // arrange
    char *ada = "ada";
    char *wordlist[100];
    // act
    (void)save_to_list(ada);
    char test_ada = *wordlist[0];
    // assert
    CU_ASSERT_EQUAL(test_ada, "ada"); 
}


/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Woerterliste", setup, teardown
				  , test_main_ausgabe
				  , test_sort_two_equal_word
				  , test_sort_empty_word
				  , test_save
				  );
}
