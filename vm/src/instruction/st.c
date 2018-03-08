/*
** EPITECH PROJECT, 2018
** nul
** File description:
** null
*/

#include "vm.h"

void operate_st(champ_t *champs, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + (pc->idx + 1) % MEM_SIZE));
	int register_number = 

	if (parameters[0] != T_REG) {
		assign_champ_carry
	}
}