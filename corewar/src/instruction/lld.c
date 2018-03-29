/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int read_t_dir_lld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_int(tab + ((pc->idx + 2) % MEM_SIZE));
	int new_num = get_int(tab + (IDX_ADRESS) % MEM_SIZE));
	int get_registre = *(tab + ((pc->idx + 2) % MEM_SIZE));

	if (get_registre < 1 && get_registre > 16)
		return (2);
	assign_new_value_to_new_registre(new_num, get_registre, champ, pc);
	return (2);
}

int read_t_ind_lld(byte *tab, pc_t *pc, champ_t *champ)
{
	int get_num = get_short_int(tab + ((pc->idx + 2) % MEM_SIZE));
	int new_num = get_int(tab + IDX_ADRESS) % MEM_SIZE);
	int get_registre = *(tab + ((pc->idx + 4) % MEM_SIZE));

	if (get_registre < 1 && get_registre > 16)
		return (4);
	assign_new_value_to_new_registre(new_num, get_registre, champ, pc);
	return (4);
}

int operate_lld(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + pc->idx + 1));

	if (parameters[1] != 1) {
		assign_champ_carry_false(champ, pc);
		return (compute_bytes_read(champ, pc, parameters) + 1);
	}
	if (parameters[0] == T_DIR) {
		return (read_t_dir_lld(tab, pc, champ) + 2);
	} else if (parameters[0] == T_IND) {
		return (read_t_ind_lld(tab, pc, champ) + 2);
	}
	return (0);
}