/*
** EPITECH PROJECT, 2017
** asm
** File description:
** args.c created: 06/03/18 15:02
*/

#include <op.h>
#include <asm.h>
#include <stdlib.h>
#include <my.h>

byte get_param_bytecode(char **words, int param_nbr)
{
	byte reg[3] = {0x40, 0x10, 0x4};
	byte dir[3] = {0x80, 0x20, 0x8};
	byte ind[3] = {0xC0, 0x30, 0xC};
	byte bin = 0;

	for (int i = 0; i < param_nbr; i++) {
		if (words[i + 1][0] == 'r') {
			bin += reg[i];
		} else if (words[i + 1][0] == DIRECT_CHAR) {
			bin += dir[i];
		} else {
			bin += ind[i];
		}
	}
	return (bin);
}

//TODO FILL
int get_label_args(char *str)
{
	return (0);
}

int get_arg(char *str, args_type_t arg_type)
{
	int res;
	int len = my_strlen(str);

	if (arg_type == T_REG) {
		if (len < 2 || len > 3)
			return (ERROR_INT);
		res = my_getnbr(&str[1]);
		if (res < 1 || res > REG_NUMBER)
			return (ERROR_INT);
	} else if (arg_type == T_DIR) {
		if (len < 2)
			return (ERROR_INT);
		if (str[1] == LABEL_CHAR)
			res = get_label_args(str);
		else
			res = my_getnbr(&str[1]);
	} else {
		res = my_getnbr(str);
	}
	return (res);
}

int *get_operation_args(char **words, args_type_t *args_types)
{
	byte args_nbr = op_tab[get_fnc_idx(words[0])].nbr_args;
	int *res = malloc(sizeof(*res) * (args_nbr + 1));
	int length = my_array_length((void **) words);

	if (length < args_nbr + 1) {
		free(res);
		return (NULL);
	}
	for (int i = 0; i < args_nbr; i++) {
		res[i] = get_arg(words[i + 1], args_types[i]);
		if (res[i] == ERROR_INT) {
			my_putstr("cannot handle parameters\n");
			exit(84);
		}
	}
	res[args_nbr] = '\0';
	return (res);
}