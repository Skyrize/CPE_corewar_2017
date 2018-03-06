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
			champ->reg[num_of_registre - 1] = new_num;
			//my_printf("TOTO : %d && %d--> || %c\n", champ->reg[num_of_registre - 1], num_of_registre - 1, champ->reg[num_of_registre - 1]);
			champ->carry = true;
		}
		champ = champ->next;
	}
}

int read_t_dir_ld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_int(tab + pc->idx + 2);
	int new_num = get_int(tab + (pc->idx + (get_num % IDX_MOD)));
	int get_registre = *(tab + pc->idx + 2);

	assign_new_value_to_new_registre(new_num, get_registre, champ, pc);
	return (2);
}

int read_t_ind_ld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_short_int(tab + pc->idx + 2);
	int new_num = get_int(tab + (pc->idx + (get_num % IDX_MOD)));
	int get_registre = *(tab + pc->idx + 4);

	//printf("get num : %d && new_num : %d && %d [[[[[ get_num % IDX_MOD : %d ] PC IDX : %d]]]\n", get_num, new_num, get_registre, get_num % IDX_MOD, pc->idx);
	assign_new_value_to_new_registre(new_num, get_registre, champ, pc);
	return (4);
}

int operate_ld(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + pc->idx + 1));

	if (parameters[0] == T_DIR)
		return (read_t_dir_ld(tab, pc, champ) + 1);
	else if (parameters[0] == T_IND)
		return (read_t_ind_ld(tab, pc, champ) + 1);
	return (0);
}