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

Test(is_label_present, simple_test)
{
	char *words[5] = {"no label", "no label", "label:", "no label", NULL};
	int got = is_label_present(words);
	int expected = 2;

	cr_assert_eq(got, expected, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}

Test(is_label_present, no_label_test)
{
	char *words[5] = {"no label", "no label", "no label", "no label", NULL};
	int got = is_label_present(words);
	int expected = -1;

	cr_assert_eq(got, expected, "ERROR: expected '%d' but got '%d'.\n",
	expected, got);
}
