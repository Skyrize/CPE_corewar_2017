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

void write_operation(instruction_t *op, int fd)
{
	write(fd, &(op->instruction_code), 1);
	if (is_printing_coding_byte(op->instruction_code))
		write(fd, &(op->coding_byte), 1);
	my_printf("op %x nbr_args=%d\n", op->instruction_code, op->nbr_args);
	for (int i = 0; i < op->nbr_args; i++) {
		my_printf("arg id=%d content=%d\n", i, op->args[i]);
		if (op->args_types[i] == T_REG) {
			byte a = (byte) op->args[i];
			write(fd, &a, sizeof(byte));
		}else if(op->args_types[i] == T_DIR) {
			int a = op->args[i];
			revert_int(a);
			write(fd, &a, sizeof(int));
		} else {
			short a = revert_short((short) op->args[i]);
			my_printf("sizeof(short)=%d\n", sizeof(short));
			write(fd, &a, sizeof(short));
		}
	}
}

void write_operations(int fd)
{
	instruction_t *ins_list = *get_instructions();

	if (!ins_list)
		return;
	for(; ins_list; ins_list = ins_list->next) {
		my_printf("writing instruction %x\n", ins_list->instruction_code);
		write_operation(ins_list, fd);
	}
}