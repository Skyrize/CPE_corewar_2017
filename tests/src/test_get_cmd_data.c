/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#include <asm.h>
#include <my.h>
#include "include/test.h"

Test(get_cmd_data, test_data_first_call)
{
	cmd_data *data = get_cmd_data();

	cr_assert_str_eq(data->name, "",
	"ERROR: data->name is %s but should be empty.\n",
	data->name);
	cr_assert_str_eq(data->description, "",
	"ERROR: data->description is %s but should be empty.\n",
	data->description);
}

Test(get_cmd_data, test_data_second_call)
{
	cmd_data *data = get_cmd_data();
	cmd_data *data2 = get_cmd_data();

	cr_assert(sizeof(data) == sizeof(data2),
	"ERROR: after a second call, data returned has not the same size.\n");
}
