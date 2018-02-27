/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** main
*/

#include "vm.h"

int check_help(int size, char **str)
{
	if (size == 2
	&& (my_strcmp(str[1], "-h") == 0
	|| my_strcmp(str[1], "--help") == 0)) {
		my_printf("USAGE\n\t\t./corewar [prog_name] [prog2_name] ...");
		my_printf("\n\nDESCRIPTION\n\t\tprog_name is a program ");
		my_printf("compiled by the asm in .cor\n\t\t\t");
		my_printf("the number of program has to be between 2 and 4.\n");
		return (1);
	}
	return (0);
}

int error_args_handling(int size, char **str)
{
	int fd = 0;

	if (size < 3 || size > 5)
		return (84);
	for (int i = 1; i < size; i++) {
		fd = open(str[i], O_RDONLY);
		if (fd == -1)
			return (84);
		close(fd);
	}
	return (0);
}

int main(int ac, char **av)
{
	champ_t *champs = NULL;
	char vm[MEM_SIZE] = {0};

	if (check_help(ac, av) == 1)
		return (0);
	if (error_args_handling(ac, av) == 84)
		return (84);
	champs = set_champs_info(champs, ac - 1, av);
	memory_allocation_to_champs(vm, champs, ac - 1, av + 1);
	while (champs != NULL) {
		my_printf("[%d] %s | Size = %d\n", champs->program_number, champs->program_name, champs->size);
		champs = champs->next;
	}
	for (int i = 0; i < MEM_SIZE; i++)
		my_printf("%d\n", vm[i]);
	//start_cycle_game(vm, champs);
	return (0);
}
