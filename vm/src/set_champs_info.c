/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** main
*/

#include "vm.h"

int reverse_int(int nb)
{
	union data number;
	char tmp;

	number.nbr = nb;
	tmp = number.str[0];
	number.str[0] = number.str[3];
	number.str[3] = tmp;
	tmp = number.str[1];
	number.str[1] = number.str[2];
	number.str[2] = tmp;
	return (number.nbr);
}

void set_champs_info(champ_t *champs, int nb_champs, char **str)
{
	int fd = open(str[1], O_RDONLY);
	int magic_number;

	champs = malloc(sizeof(*champs));
	read(fd, &magic_number, 4);
	magic_number = reverse_int(magic_number);
	if (magic_number != COREWAR_EXEC_MAGIC) {
		my_printf("%s : Invalid Champion\n", str[1]);
		exit(84);
	}
	return;
	// for (int i = 2; i < nb_champs; i++) {

	// }
}