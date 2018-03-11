/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#include <asm.h>
#include <my.h>
#include "../include/test.h"

Test(clear_header, test_header_changed)
{
	header_t test1 = {600, "test", 2, "NONE"};
	header_t *var1 = &test1;
	header_t test = {600, "test", 2, "NONE"};
	header_t *var = &test;
	char *first = (char *)var;
	char *str;

	clear_header(var);
	str = (char *)var1;
	cr_assert_str_neq(first, str, "ERROR: header hasn't changed.\n");
}

Test(clear_header, test_header_cleared)
{
	header_t test = {600, "test", 2, "NONE"};
	header_t *var = &test;
	char *str;

	clear_header(var);
	str = (char *)var;
	for (int i = 0; i < sizeof(var); i++) {
		cr_assert(str[i] == 0, "ERROR: var[%d] isn't equal to 0", i);
	}
}
