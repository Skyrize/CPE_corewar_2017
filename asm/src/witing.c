/*
** EPITECH PROJECT, 2017
** asm
** File description:
** witing.c created: 02/03/18 16:10
*/

#include <asm.h>
#include <fcntl.h>
#include <my.h>
#include <unistd.h>
#include <op.h>

int create_file(char *source_filename)
{
	char *new_filename = my_strdup(source_filename);
	int len = my_strlen(new_filename);

	if (my_strcmp(&new_filename[len - 2], ".s") == 0) {
		new_filename[len - 2] = '\0';
		new_filename = my_str_append(new_filename, ".cor");
	} else {
		new_filename = my_str_append(new_filename, ".cor");
	}
	int fd = open(new_filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	free(new_filename);
	return (fd);
}

void clear_header(header_t *var)
{
	char *str = (char *)var;

	for (int i = 0; i < sizeof(*var); ++i)
		str[i] = 0;
}

void put_header(int fd)
{
	int magic = revert_int(COREWAR_EXEC_MAGIC);
	header_t *header = malloc(sizeof(*header));
	ssize_t written;
	cmd_data *data = get_cmd_data();

	clear_header(header);
	header->magic = magic;
	header->prog_size = revert_int(1);
	my_strcpy(header->comment, data->description);
	my_strcpy(header->prog_name, data->name);
	written = write(fd, header, sizeof(*header));
	free(header);
	if (written != sizeof(*header)) {
		my_putstr("cannot write in file\n");
		exit(84);
	}
}