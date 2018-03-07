/*
** EPITECH PROJECT, 2017
** asm
** File description:
** main.c created: 07/02/18 14:15
*/

#include <my.h>
#include <fcntl.h>
#include <unistd.h>
#include <asm.h>

void print_help(void)
{
	my_putstr("USAGE\n\t./asm file_name[.s]\n\n");
	my_putstr("DESCRIPTION\n\tfile_name\tfile in assembly");
	my_putstr(" language to be converted into file_name.cor, an\n"
			  "\t\t\texecutable in the Virtual Machine.\n");
}

bool is_file_exists(char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

void error_handling(int ac, char **av)
{
	if (ac < 2) {
		my_putstr("USAGE: ./asm file_name[.s] ....\n");
		exit(84);
	}
	for (int i = 1; i < ac; i++)
	{
		if (my_strcmp(av[i], "-h") == 0) {
			print_help();
			exit(0);
		} else if (!is_file_exists(av[i])) {
			my_putstr("Error in function open: No such file");
			my_putstr("or directory.\n");
			exit(84);
		}
	}
}

int main(int ac, char **av)
{
	error_handling(ac, av);
	get_fd(av[1]);
	check_syntax();
	int fd = create_file(av[1]);
	put_header(fd);
	close(fd);
	return (0);
}