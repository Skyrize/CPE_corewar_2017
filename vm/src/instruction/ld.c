/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void assign_new_value_to_new_registre(int new_num, int num_of_registre,
						champ_t *champ, pc_t *pc)
{
	while (champ != NULL) {
		if (champ->program_number == pc->champ_owner) {
			champ->reg[num_of_registre - 1] = new_num;
			champ->carry = true;
		}
		champ = champ->next;
	}
}

int read_t_dir_ld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_int(tab + ((pc->idx + 2) % MEM_SIZE));
	int get_registre = *(tab + ((pc->idx + 6) % MEM_SIZE));

	if (get_registre < 1 && get_registre > 16)
		return (4);
	assign_new_value_to_new_registre(get_num, get_registre, champ, pc);
	return (4);
}

int read_t_ind_ld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_short_int(tab + ((pc->idx + 2) % MEM_SIZE));
	int new_num = get_int(tab + ((pc->idx + (get_num % IDX_MOD))
	% MEM_SIZE));
	int get_registre = *(tab + ((pc->idx + 4) % MEM_SIZE));

	if (get_registre < 1 && get_registre > 16)
		return (2);
	assign_new_value_to_new_registre(new_num, get_registre, champ, pc);
	return (2);
}

void assign_champ_carry_false(champ_t *champ, pc_t *pc)
{
	while (champ) {
		if (champ->program_number == pc->champ_owner)
			champ->carry = false;
		champ = champ->next;
	}
}

void assign_champ_carry_true(champ_t *champ, pc_t *pc)
{
	while (champ) {
		if (champ->program_number == pc->champ_owner)
			champ->carry = true;
		champ = champ->next;
	}
}

int operate_ld(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + ((pc->idx + 1)
	% MEM_SIZE)));

	if (parameters[1] != 1) {
		assign_champ_carry_false(champ, pc);
		return (compute_bytes_read(champ, pc, parameters) + 1);
	}
	if (parameters[0] == T_DIR)
		return (read_t_dir_ld(tab, pc, champ) + 2);
	else if (parameters[0] == T_IND)
		return (read_t_ind_ld(tab, pc, champ) + 2);
	return (0);
}