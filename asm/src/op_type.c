/*
** EPITECH PROJECT, 2017
** asm
** File description:
** op_type.c created: 10/03/18 18:09
*/

#include <asm.h>

bool is_index_operation(byte op_code)
{
	byte a = op_code;

	if (a == 0x09 || a == 0x0a || a == 0x0b || a == 0x0c ||
	    a == 0x0e || a == 0x0f)
		return (true);
	return (false);
}

int get_arg_size(args_type_t type, bool is_idx)
{
	switch (type) {
		case T_REG:
			return (1);
		case T_IND:
			return (2);
		case T_DIR:
			return ((is_idx) ? 2 : 4);
		default:
			return (0);
	}
}

int compute_fnc_size(instruction_t *op)
{
	bool is_idx = is_index_operation(op->instruction_code);
	int res = 0;

	res += (is_printing_coding_byte(op->instruction_code)) ? 2 : 1;
	for (int i = 0; i < op->nbr_args; i++) {
		res += get_arg_size(op->args_types[i], is_idx);
	}
	return (res);
}

bool is_label_arg(char *str)
{
	if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
		return (true);
	return (false);
}