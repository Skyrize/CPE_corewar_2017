/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#include <op.h>
#include <asm.h>
#include <my.h>
#include "include/test.h"

Test(is_label_chars, random_true_label_test)
{
	char *words = {"test_random_label_1234567890"};
	bool got = is_label_chars(words);
	bool expected = true;

	cr_assert_eq(got, expected, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}

Test(is_label_chars, empty_word_test)
{
	char *words = "";
	bool got = is_label_chars(words);
	bool expected = true;

	cr_assert_eq(got, expected, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}

Test(is_label_chars, false_label_test)
{
	char *words = {"test not a label"};
	bool got = is_label_chars(words);
	bool expected = false;

	cr_assert_eq(got, expected, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}
