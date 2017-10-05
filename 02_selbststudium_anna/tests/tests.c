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
Date berechne_folgetag(Date start_date);
int teste_gueltigkeit(Date start_date);

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
static void test_berechnung_schaltjahr(void)
{
	// arrange
	Date start_date = {28, 02, 2004};
	Date next_date = {29, 02, 2004};
	// act
	Date result_date = berechne_folgetag(start_date);
	// assert
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

// tests
static void test_berechnung_monatwechsel(void)
{
	// arrange
	Date start_date = {30, 4, 2016};
	Date next_date = {1, 5, 2016};
	// act
	Date result_date = berechne_folgetag(start_date);
	// assert
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

// tests
static void test_berechnung_jahreswechsel(void)
{
	// arrange
	Date start_date = {31, 12, 2004};
	Date next_date = {1, 1, 2005};
	// act
	Date result_date = berechne_folgetag(start_date);
	// assert
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

// tests
static void test_berechnung_erstes_datum(void)
{
	// arrange
	Date start_date = {1, 1, 1583};
	Date next_date = {2, 1, 1583};
	// act
	Date result_date = berechne_folgetag(start_date);
	// assert
	CU_ASSERT_EQUAL(next_date.day, result_date.day);
	CU_ASSERT_EQUAL(next_date.month, result_date.month);
	CU_ASSERT_EQUAL(next_date.year, result_date.year);
}

// tests
static void test_teste_gueltigkeit_vor_erstem_datum(void)
{
	// arrange
	Date start_date = {31, 12, 1582};
	// act
	int gueltig = teste_gueltigkeit(start_date);
	// assert
	CU_ASSERT_EQUAL(1, gueltig);
}

// tests
static void test_teste_gueltigkeit_von_datum_tag(void)
{
	// arrange
	Date start_date = {32, 12, 2014};
	// act
	int gueltig = teste_gueltigkeit(start_date);
	// assert
	CU_ASSERT_EQUAL(1, gueltig);
}

// tests
static void test_teste_gueltigkeit_von_datum_monat(void)
{
	// arrange
	Date start_date = {31, 13, 2014};
	// act
	int gueltig = teste_gueltigkeit(start_date);
	// assert
	CU_ASSERT_EQUAL(1, gueltig);
}

// tests
static void test_teste_gueltigkeit_von_datum_in_zukunft(void)
{
	// arrange
	Date start_date = {15, 11, 2022};
	// act
	int gueltig = teste_gueltigkeit(start_date);
	// assert
	CU_ASSERT_EQUAL(0, gueltig);
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Berechung Datum", setup, teardown
				  , test_berechnung_schaltjahr
				  , test_berechnung_monatwechsel
				  , test_berechnung_jahreswechsel
				  , test_berechnung_erstes_datum
				  , test_teste_gueltigkeit_vor_erstem_datum
				  , test_teste_gueltigkeit_von_datum_tag
				  , test_teste_gueltigkeit_von_datum_monat
				  , test_teste_gueltigkeit_von_datum_in_zukunft
				  );
}
