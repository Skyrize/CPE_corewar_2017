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

Test(clean_str_asm, simple_replace_test)
{
	char *line = my_strdup("        \tsimple,test\tformat");
	char *expected = "simple test format";

	clean_str_asm(&line);
	cr_assert_str_eq(line, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, line);
}

Test(clean_str_asm, no_replace_test)
{
	char *line = my_strdup("simple test format");
	char *expected = "simple test format";

	clean_str_asm(&line);
	cr_assert_str_eq(line, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, line);
}

Test(clean_str_asm, all_replace_test)
{
	char *line = my_strdup("        ,,\t\t\t,,");
	char *expected = "";

	clean_str_asm(&line);
	cr_assert_str_eq(line, expected, "ERROR: expected '%s' but got '%s'.\n",
	expected, line);
}
