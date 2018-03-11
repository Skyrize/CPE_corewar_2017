/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#include <asm.h>
#include <my.h>
#include "../include/test.h"

Test(revert_short, test_zero)
{
	short test = 0;
	short got = revert_short(test);
	short expected = 0;

	cr_assert_eq(got, expected,
		"ERROR: reverted %d, expected %d but got %d.\n",
		test, expected, got);
}

Test(revert_short, test_random_positive)
{
	short test = 13;
	short got = revert_short(test);
	short expected = 3328;

	cr_assert_eq(got, expected,
		"ERROR: reverted %d, expected %d but got %d.\n",
		test, expected, got);
}

Test(revert_short, test_random_negative)
{
	short test = -8;
	short got = revert_short(test);
	short expected = -1793;

	cr_assert_eq(got, expected,
		"ERROR: reverted %d, expected %d but got %d.\n",
		test, expected, got);
}

Test(revert_short, test_big_positive)
{
	short test = 2243;
	short got = revert_short(test);
	short expected = -15608;

	cr_assert_eq(got, expected,
		"ERROR: reverted %d, expected %d but got %d.\n",
		test, expected, got);
}

Test(revert_short, test_big_negative)
{
	short test = -8222;
	short got = revert_short(test);
	short expected = -7457;

	cr_assert_eq(got, expected,
		"ERROR: reverted %d, expected %d but got %d.\n",
		test, expected, got);
}
