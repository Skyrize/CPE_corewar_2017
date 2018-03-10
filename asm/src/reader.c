/*
** EPITECH PROJECT, 2017
** asm
** File description:
** reader.c created: 12/02/18 18:41
*/

#include <my.h>
#include <asm.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

bool *is_label_turn(void)
{
	static bool *res = NULL;

	if (res == NULL) {
		res = malloc(sizeof(*res));
		*res = true;
	}
	return (res);
}

void reset_things(int fd)
{
	instruction_t **root = get_instructions();
	int tmp;

	tmp = counter(0);
	counter(-tmp);
	tmp = counter_b(0);
	counter_b(-tmp);
	*root = NULL;
	lseek(fd, 0, SEEK_SET);
}

void check_syntax(void)
{
	int fd = get_fd(NULL);
	char *line = get_next_line(fd);
	bool is_valid = true;
	bool *label_turn = is_label_turn();

	while (line) {
		is_valid = is_line_valid(line);
		free(line);
		line = get_next_line(fd);
	}
	*label_turn = false;
	reset_things(fd);
	line = get_next_line(fd);
	while (line) {
		is_valid = is_line_valid(line);
		free(line);
		line = get_next_line(fd);
	}
}