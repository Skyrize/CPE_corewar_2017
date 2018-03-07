/*
** EPITECH PROJECT, 2017
** asm
** File description:
** args.c created: 06/03/18 15:02
*/

#include <op.h>

int get_param_bytecode(char **words, int param_nbr)
{
	int reg[3] = {0x40, 0x10, 0x4};
	int dir[3] = {0x80, 0x20, 0x8};
	int ind[3] = {0xC0, 0x30, 0xC};
	int bin = 0;

	for (int i = 0; i < param_nbr; ++i) {
		if (words[i + 1][0] == 'r')
			bin += reg[i];
		else if (words[i + 1][0] == DIRECT_CHAR)
			bin += dir[i];
		else
			bin += ind[i];
	}
	return (bin);
}