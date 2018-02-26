/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"

/*
** Code à implementer plus tard.
int bytesToInt(byte *num_champ, unsigned length_total)
{
	int num_tmp = 0;
	int j = 0;

	for (int i = length_total - 1 ; i >= 0 ; --i) {
		val += (num_champ[i] & 0xFF) << (8 * j);
		++j;
	}
	return (num_tmp);
}
** End.
*/

int char_to_int(byte *num_champ)
{
	return (*(int) *num_champ);
}

void operate_live(champ_t *champ, pc_t *pc, byte *tab)
{
	byte *num_champ = malloc(4);
	int j = 0;

	for (int i = pc->idx ; i != pc->indx + 4 ; i++)
		num_champ[j++] = tab[i];
	if (char_to_int(num_champ) == champ->program_number)
		my_printf("Le champion : ")
	free(num_champ);
}