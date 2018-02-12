/*
** EPITECH PROJECT, 2017
** asm
** File description:
** io.c created: 12/02/18 19:05
*/

#include <fcntl.h>
#include <my.h>

int get_fd(char *name)
{
	static int fd = -2;

	if (fd == -2) {
		fd = open(name, O_RDONLY);
		if (fd == -1) {
			my_printf("Can't open %s.\n", name);
			exit(84);
		}
	}
	return (fd);
}