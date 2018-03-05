/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int read_t_dir_lld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_int(tab + pc->idx + 1);
	int new_num = get_int(tab + (pc->idx + (get_num)));
	int get_registre = *(tab + pc->idx + 2);

	assign_new_value_to_new_registre(new_num, get_registre, champ, pc);
	return (pc->idx + 2);
}

int read_t_ind_lld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_short_int(tab + pc->idx + 1);
	int new_num = get_short_int(tab + (pc->idx + (get_num)));
	int get_registre = *(tab + pc->idx + 4);

	assign_new_value_to_new_registre(get_num, get_registre, champ, pc);
	return (pc->idx + 4);
}

int operate_lld(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(my_getnbr(tab + pc->idx + 1));

	if (parameters[0] == T_DIR)
		return (read_t_dir_lld(tab, pc, champ));
	else if (parameters[0] == T_IND)
		return (read_t_ind_lld(tab, pc, champ));
	return (0);
}