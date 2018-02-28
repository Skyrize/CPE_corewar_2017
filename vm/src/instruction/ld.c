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
	while (champ->next != NULL) {
		if (champ->program_number == pc->champ_owner) {
			champ->reg[num_of_registre] = new_num;
			champ->carry = true;
		}
		champ = champ->next;
	}
}

int read_t_dir_ld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = (tab + pc->idx + 1);
	int new_num = (tab + (pc->idx + (get_num % IDX_MOD));
	int get_registre = (tab + pc->idx + 2);
	assign_new_value_to_new_registre(new_num, get_registre);
	return (pc->idx + 2);
}

int read_t_ind_ld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_int(tab + pc->idx + 1);
	int new_num = get_int(tab + (pc->idx + (get_num % IDX_MOD));
	int get_registre = (tab + pc->idx + 4);
	assign_new_value_to_new_registre(get_num, get_registre);
	return (pc->idx + 4);
}

int operate_ld(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(my_getnbr(tab + pc->idx + 1));

	if (parameters[0] == T_DIR)
		return (read_t_dir_ld(tab, pc, champ));
	else if (parameters[0] == T_IND)
		return (read_t_ind_ld(tab, pc, champ));
	return (0);
}