/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#include <asm.h>
#include <my.h>
#include "include/test.h"

Test(revert_int, test_zero)
{
	int test = 0;
	int got = revert_int(test);

	cr_assert_eq(got, 0,
		"ERROR: reverted %d, expected 218103808 but got %d.\n",
		test, got);
}

Test(revert_int, test_random_positive)
{
	int test = 13;
	int got = revert_int(test);

	cr_assert_eq(got, 218103808,
		"ERROR: reverted %d, expected 218103808 but got %d.\n",
		test, got);
}

Test(revert_int, test_random_negative)
{
	int test = -8;
	int got = revert_int(test);

	cr_assert_eq(got, -117440513,
		"ERROR: reverted %d, expected 218103808 but got %d.\n",
		test, got);
}

Test(revert_int, test_big_positive)
{
	int test = 24077743;
	int got = revert_int(test);

	cr_assert_eq(got, -1352306943,
		"ERROR: reverted %d, expected 218103808 but got %d.\n",
		test, got);
}

Test(revert_int, test_big_negative)
{
	int test = -82849022;
	int got = revert_int(test);

	cr_assert_eq(got, 47386619,
		"ERROR: reverted %d, expected 218103808 but got %d.\n",
		test, got);
}
