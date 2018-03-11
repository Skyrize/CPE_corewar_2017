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

Test(comma_to_spaces, simple_replace_test)
{
	char *line = my_strdup("simple,test,format");
	char *expected = "simple test format";
	char *got = comma_to_spaces(line);

	cr_assert_str_eq(got, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, got);
	free(line);
}

Test(comma_to_spaces, no_replace_test)
{
	char *line = my_strdup("simple test format");
	char *expected = "simple test format";
	char *got = comma_to_spaces(line);

	cr_assert_str_eq(got, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, got);
	free(line);
}

Test(comma_to_spaces, all_replace_test)
{
	char *line = my_strdup(",,,,,,,,");
	char *expected = "        ";
	char *got = comma_to_spaces(line);

	cr_assert_str_eq(got, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, got);
	free(line);
}
