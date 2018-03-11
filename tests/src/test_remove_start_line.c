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

Test(remove_start_line, simple_replace_test)
{
	char *line = my_strdup("        simple test format");
	char *expected = "simple test format";
	char *got = remove_start_line(line);

	cr_assert_str_eq(got, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, got);
	free(line);
}

Test(remove_start_line, no_replace_test)
{
	char *line = my_strdup("simple test format");
	char *expected = "simple test format";
	char *got = remove_start_line(line);

	cr_assert_str_eq(got, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, got);
	free(line);
}

Test(remove_start_line, all_replace_test)
{
	char *line = my_strdup("        ");
	char *expected = "";
	char *got = remove_start_line(line);

	cr_assert_str_eq(got, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, got);
	free(line);
}
