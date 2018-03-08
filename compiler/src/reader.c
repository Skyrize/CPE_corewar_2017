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

//TODO remove
void log_instruction_list()
{
	instruction_t **root = get_instructions();
	instruction_t *tmp = *root;

	for (; tmp; tmp = tmp->next) {
		my_printf("%x\n", tmp->instruction_code);
	}
}

void check_syntax(void)
{
	int fd = get_fd(NULL);
	char *line = get_next_line(fd);
	bool is_valid = true;

	while (line) {
		is_valid = is_line_valid(line);
		free(line);
		line = get_next_line(fd);
	}
	log_instruction_list();
}