/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** main
*/

#include "vm.h"

char *get_str(int fd)
{
	char last_char = 1;
	size_t bytes_read = 1;
	char *ret = malloc(1);
	unsigned int pos = 0;

	while (bytes_read == 1 && last_char != 0) {
		bytes_read = read(fd, &last_char, 1);
		if (bytes_read == 0)
			return (0);
		else if (bytes_read == -1)
			exit(84);
		ret[pos] = last_char;
		pos++;
		ret = realloc(ret, pos + 1);
	}
	ret[pos] = 0;
	return (ret);
}

int get_int(int fd)
{
	char *content = malloc(4);
	size_t bytes_read;

	bytes_read = read(fd, content, 4);
	if (bytes_read == 0)
		return (0);
	else if (bytes_read == -1)
		exit(84);
	return (*((int *)content));
}