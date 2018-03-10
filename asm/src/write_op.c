/*
** EPITECH PROJECT, 2017
** asm
** File description:
** write_op.c created: 08/03/18 18:15
*/

#include <asm.h>
#include <my.h>
#include <unistd.h>

bool is_printing_coding_byte(byte ins_tag)
{
	if (ins_tag == 0x1 || ins_tag == 0x09 || \
	ins_tag == 0x0c || ins_tag == 0x0f) {
		return (false);
	}
	return (true);
}

void write_std_operation(instruction_t *op, int fd)
{
	write(fd, &(op->instruction_code), 1);
	if (is_printing_coding_byte(op->instruction_code))
		write(fd, &(op->coding_byte), 1);
	for (int i = 0; i < op->nbr_args; i++) {
		if (op->args_types[i] == T_REG) {
			byte a = (byte) op->args[i];
			write(fd, &a, 1);
			counter(1);
		}else if(op->args_types[i] == T_DIR) {
			int a = op->args[i];
			a = revert_int(a);
			write(fd, &a, 4);
			counter(4);
		} else {
			short a = revert_short((short) op->args[i]);
			write(fd, &a, 2);
			counter(2);
		}
	}
}

void write_operation_index(instruction_t *op, int fd)
{
	write(fd, &(op->instruction_code), 1);
	if (is_printing_coding_byte(op->instruction_code))
		write(fd, &(op->coding_byte), 1);
	for (int i = 0; i < op->nbr_args; i++) {
		if (op->args_types[i] == T_REG) {
			byte a = (byte) op->args[i];
			write(fd, &a, 1);
			counter(1);
		} else {
			short a = revert_short((short) op->args[i]);
			write(fd, &a, 2);
			counter(2);
		}
	}
}

void write_operation(instruction_t *op, int fd)
{
	byte a = op->instruction_code;

	if (a == 0x09 || a == 0x0a || a == 0x0b || a == 0x0c ||
		a == 0x0e || a == 0x0f)
		write_operation_index(op, fd);
	else
		write_std_operation(op, fd);
}

void write_operations(int fd)
{
	instruction_t *ins_list = *get_instructions();

	if (!ins_list)
		return;
	for(; ins_list; ins_list = ins_list->next) {
		write_operation(ins_list, fd);
	}
}