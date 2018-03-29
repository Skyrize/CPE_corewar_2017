/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#include <op.h>
#include <asm.h>
#include <my.h>
#include "../include/test.h"

Test(counter, test_one_call_positive)
{
	int to_add = 5;
	int got = counter(to_add);
	int expected = 5;

	cr_assert_eq(expected, got, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}

Test(counter, test_one_call_negative)
{
	int to_add = -5;
	int got = counter(to_add);
	int expected = -5;

	cr_assert_eq(expected, got, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}

Test(counter, test_many_calls_positive)
{
	int to_add = 5;
	int expected = 50;
	int got;

	for (int i = 0; i < 10; i++)
		got  = counter(to_add);
	cr_assert_eq(expected, got, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}

Test(counter, test_many_calls_negative)
{
	int to_add = -5;
	int expected = -50;
	int got;

	for (int i = 0; i < 10; i++)
		got  = counter(to_add);
	cr_assert_eq(expected, got, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}

Test(counter, test_call_zero)
{
	int to_add = 0;
	int got = counter(to_add);
	int expected = 0;

	cr_assert_eq(expected, got, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}
